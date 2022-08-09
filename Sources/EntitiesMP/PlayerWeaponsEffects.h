/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_PlayerWeaponsEffects_INCLUDED
#define _EntitiesMP_PlayerWeaponsEffects_INCLUDED 1
#include <EntitiesMP/Player.h>
extern DECL_DLL CEntityPropertyEnumType WeaponEffectType_enum;
enum WeaponEffectType {
  WET_SHOTGUNSHELL = 0,
  WET_MACHINEGUNSHELL = 1,
};
DECL_DLL inline void ClearToDefault(WeaponEffectType &e) { e = (WeaponEffectType)0; } ;
#define EVENTCODE_EWeaponEffectInit 0x01950000
class DECL_DLL EWeaponEffectInit : public CEntityEvent {
public:
EWeaponEffectInit();
CEntityEvent *MakeCopy(void);
CEntityPointer penOwner;
enum WeaponEffectType EwetEffect;
};
DECL_DLL inline void ClearToDefault(EWeaponEffectInit &e) { e = EWeaponEffectInit(); } ;
extern "C" DECL_DLL CDLLEntityClass CPlayerWeaponsEffects_DLLClass;
class CPlayerWeaponsEffects : public CMovableEntity {
public:
virtual CEntity *GetPredictionPair(void) { return m_penPrediction; };
virtual void SetPredictionPair(CEntity *penPair) { m_penPrediction = penPair; };
  DECL_DLL virtual void SetDefaultProperties(void);
  CEntityPointer m_penOwner;
  enum WeaponEffectType m_EwetEffect;
  CEntityPointer m_penPrediction;
#define  STATE_CPlayerWeaponsEffects_ShotgunShell 0x01950001
  BOOL 
#line 53 "C:/MyMod/Sources/EntitiesMP/PlayerWeaponsEffects.es"
ShotgunShell(const CEntityEvent &__eeInput);
  BOOL H0x01950002_ShotgunShell_01(const CEntityEvent &__eeInput);
  BOOL H0x01950003_ShotgunShell_02(const CEntityEvent &__eeInput);
#define  STATE_CPlayerWeaponsEffects_MachinegunShell 0x01950004
  BOOL 
#line 69 "C:/MyMod/Sources/EntitiesMP/PlayerWeaponsEffects.es"
MachinegunShell(const CEntityEvent &__eeInput);
  BOOL H0x01950005_MachinegunShell_01(const CEntityEvent &__eeInput);
  BOOL H0x01950006_MachinegunShell_02(const CEntityEvent &__eeInput);
#define  STATE_CPlayerWeaponsEffects_Main 1
  BOOL 
#line 86 "C:/MyMod/Sources/EntitiesMP/PlayerWeaponsEffects.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x01950007_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x01950008_Main_02(const CEntityEvent &__eeInput);
  BOOL H0x01950009_Main_03(const CEntityEvent &__eeInput);
  BOOL H0x0195000a_Main_04(const CEntityEvent &__eeInput);
  BOOL H0x0195000b_Main_05(const CEntityEvent &__eeInput);
  BOOL H0x0195000c_Main_06(const CEntityEvent &__eeInput);
  BOOL H0x0195000d_Main_07(const CEntityEvent &__eeInput);
  BOOL H0x0195000e_Main_08(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_PlayerWeaponsEffects_INCLUDED
