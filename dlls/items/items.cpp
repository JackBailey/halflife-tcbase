/***
*
*	Copyright (c) 1996-2001, Valve LLC. All rights reserved.
*	
*	This product contains software technology licensed from Id 
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc. 
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/
/*

===== items.cpp ========================================================

  functions governing the selection/use of weapons for players

*/

#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "weapons.h"
#include "player.h"
#include "skill.h"
#include "items.h"
#include "gamerules.h"
#include "UserMessages.h"


void CItem::Spawn()
{
	pev->movetype = MOVETYPE_TOSS;
	pev->solid = SOLID_TRIGGER;
	UTIL_SetOrigin( pev, pev->origin );
	UTIL_SetSize(pev, Vector(-16, -16, 0), Vector(16, 16, 16));
	SetTouch(&CItem::ItemTouch);

	if (DROP_TO_FLOOR(ENT(pev)) == 0)
	{
		ALERT(at_error, "Item %s fell out of level at %f,%f,%f", STRING( pev->classname ), pev->origin.x, pev->origin.y, pev->origin.z);
		UTIL_Remove( this );
		return;
	}
}

extern int gEvilImpulse101;

void CItem::ItemTouch( CBaseEntity *pOther )
{
	// if it's not a player, ignore
	if ( !pOther->IsPlayer() )
	{
		return;
	}

	CBasePlayer *pPlayer = (CBasePlayer *)pOther;

	// ok, a player is touching this item, but can he have it?
	if ( !g_pGameRules->CanHaveItem( pPlayer, this ) )
	{
		// no? Ignore the touch.
		return;
	}

	if (MyTouch( pPlayer ))
	{
		SUB_UseTargets( pOther, USE_TOGGLE, 0 );
		SetTouch( NULL );
		
		// player grabbed the item. 
		g_pGameRules->PlayerGotItem( pPlayer, this );
		if ( g_pGameRules->ItemShouldRespawn( this ) == GR_ITEM_RESPAWN_YES )
		{
			Respawn(); 
		}
		else
		{
			UTIL_Remove( this );
		}
	}
	else if (gEvilImpulse101)
	{
		UTIL_Remove( this );
	}
}

CBaseEntity* CItem::Respawn()
{
	SetTouch( NULL );
	pev->effects |= EF_NODRAW;

	UTIL_SetOrigin( pev, g_pGameRules->VecItemRespawnSpot( this ) );// blip to whereever you should respawn.

	SetThink ( &CItem::Materialize );
	pev->nextthink = g_pGameRules->FlItemRespawnTime( this ); 
	return this;
}

void CItem::Materialize()
{
	if ( pev->effects & EF_NODRAW )
	{
		// changing from invisible state to visible.
		EMIT_SOUND_DYN( ENT(pev), CHAN_WEAPON, "items/suitchargeok1.wav", 1, ATTN_NORM, 0, 150 );
		pev->effects &= ~EF_NODRAW;
		pev->effects |= EF_MUZZLEFLASH;
	}

	SetTouch( &CItem::ItemTouch );
}



class CItemBattery : public CItem
{
	void Spawn() override
	{ 
		Precache( );
		SET_MODEL(ENT(pev), "models/w_battery.mdl");
		CItem::Spawn( );
	}
	void Precache() override
	{
		PRECACHE_MODEL ("models/w_battery.mdl");
		PRECACHE_SOUND( "items/gunpickup2.wav" );
	}
	BOOL MyTouch( CBasePlayer *pPlayer ) override
	{
		if ( pPlayer->pev->deadflag != DEAD_NO )
		{
			return FALSE;
		}

		if (pPlayer->pev->armorvalue < MAX_NORMAL_BATTERY)
		{
			pPlayer->pev->armorvalue += gSkillData.batteryCapacity;
			pPlayer->pev->armorvalue = V_min(pPlayer->pev->armorvalue, MAX_NORMAL_BATTERY);

			EMIT_SOUND( pPlayer->edict(), CHAN_ITEM, "items/gunpickup2.wav", 1, ATTN_NORM );

			MESSAGE_BEGIN( MSG_ONE, gmsgItemPickup, NULL, pPlayer->pev );
				WRITE_STRING( STRING(pev->classname) );
			MESSAGE_END();

			return TRUE;		
		}
		return FALSE;
	}
};

LINK_ENTITY_TO_CLASS(item_battery, CItemBattery);
