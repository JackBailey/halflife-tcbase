#if _MSC_VER >= 1500 // MSVC++ 9.0 (Visual Studio 2008)
#pragma push_macro("ARRAYSIZE")
#ifdef ARRAYSIZE
#undef ARRAYSIZE
#endif
#define HSPRITE_HL WINDOWS_HSPRITE_HL
#endif
