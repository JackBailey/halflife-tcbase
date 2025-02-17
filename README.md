Half-Life 1 Total Conversion base
======================

This repository is meant to serve as a base for other mod creators who want to create a total conversion, but don't want to waste time on cutting out all the un-needed vanilla game code.

This is based off of [Solokiller's Half-Life Updated repository](https://github.com/Solokiller/halflife-updated), which fixes a lot of vanilla bugs and updates the project files to work with Visual Studio 2019.

Changes from the original codebase:
- added env_model (by Magic Nipples; ported from SoHL)
- added env_music (by Shepard; FMOD implementation)
- added player_freeze (by Shepard; ported from SoHL)
- weapons are fully server-sided
- fixed being unable to use things while reloading or switching weapons
- changed default weapon tracer frequency from 4 to 1 (always trace)
- added new TANK bullet types for func_tank
- monsters lose collision as soon as they die instead of after their death anim ends
- removed unused bullet types
- removed viewroll and WON bob
- removed useless entities (cdaudio stuff, cyclers, cine monsters...)
- removed Half-Life monsters and weapons (left zombie and crowbar as placeholders)
- removed HEV suit
- removed a bunch of unused code (TFC and #if 0 stuff)
- commented out "error" messages about being unable to find certain files that will almost always be missing

Credits & special thanks:
- Magic Nipples: Porting env_model to vanilla HL1
- Shepard: Writing the FMOD implementation, porting player_freeze to vanilla HL1 and generally being a cool guy
- James: Being extremely supportive and helping out with more things than I can be bothered to remember

Main mod files will be hosted on the releases page (yes, you need some of them even if you're gonna re-compile the code anyway).
Please note that any mod using FMOD needs to have an FMOD logo somewhere in-game (like the main menu)!
The logo files will be included in every build of this base.

I don't use GitHub very actively, so if you have any questions or suggestions please forward them to me through Discord: jay!#2754


Half Life 1 SDK LICENSE
======================

Half Life 1 SDK Copyright© Valve Corp.  

THIS DOCUMENT DESCRIBES A CONTRACT BETWEEN YOU AND VALVE CORPORATION (“Valve”).  PLEASE READ IT BEFORE DOWNLOADING OR USING THE HALF LIFE 1 SDK (“SDK”). BY DOWNLOADING AND/OR USING THE SOURCE ENGINE SDK YOU ACCEPT THIS LICENSE. IF YOU DO NOT AGREE TO THE TERMS OF THIS LICENSE PLEASE DON’T DOWNLOAD OR USE THE SDK.

You may, free of charge, download and use the SDK to develop a modified Valve game running on the Half-Life engine.  You may distribute your modified Valve game in source and object code form, but only for free. Terms of use for Valve games are found in the Steam Subscriber Agreement located here: http://store.steampowered.com/subscriber_agreement/ 

You may copy, modify, and distribute the SDK and any modifications you make to the SDK in source and object code form, but only for free.  Any distribution of this SDK must include this license.txt and third_party_licenses.txt.  
 
Any distribution of the SDK or a substantial portion of the SDK must include the above copyright notice and the following: 

DISCLAIMER OF WARRANTIES.  THE SOURCE SDK AND ANY OTHER MATERIAL DOWNLOADED BY LICENSEE IS PROVIDED “AS IS”.  VALVE AND ITS SUPPLIERS DISCLAIM ALL WARRANTIES WITH RESPECT TO THE SDK, EITHER EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, TITLE AND FITNESS FOR A PARTICULAR PURPOSE.  

LIMITATION OF LIABILITY.  IN NO EVENT SHALL VALVE OR ITS SUPPLIERS BE LIABLE FOR ANY SPECIAL, INCIDENTAL, INDIRECT, OR CONSEQUENTIAL DAMAGES WHATSOEVER (INCLUDING, WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR ANY OTHER PECUNIARY LOSS) ARISING OUT OF THE USE OF OR INABILITY TO USE THE ENGINE AND/OR THE SDK, EVEN IF VALVE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.  
 
 
If you would like to use the SDK for a commercial purpose, please contact Valve at sourceengine@valvesoftware.com.
