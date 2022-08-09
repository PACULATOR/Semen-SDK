/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_WeaponItem_INCLUDED
#define _EntitiesMP_WeaponItem_INCLUDED 1
#include <EntitiesMP/Item.h>
extern DECL_DLL CEntityPropertyEnumType WeaponItemType_enum;
enum WeaponItemType {
  WIT_COLT = 1,
  WIT_SINGLESHOTGUN = 2,
  WIT_DOUBLESHOTGUN = 3,
  WIT_TOMMYGUN = 4,
  WIT_MINIGUN = 5,
  WIT_ROCKETLAUNCHER = 6,
  WIT_GRENADELAUNCHER = 7,
  WIT_SNIPER = 8,
  WIT_FLAMER = 9,
  WIT_LASER = 10,
  WIT_CHAINSAW = 11,
  WIT_CANNON = 12,
  WIT_GHOSTBUSTER = 13,
};
DECL_DLL inline void ClearToDefault(WeaponItemType &e) { e = (WeaponItemType)0; } ;
#define EVENTCODE_EWeaponItem 0x03220000
class DECL_DLL EWeaponItem : public CEntityEvent {
public:
EWeaponItem();
CEntityEvent *MakeCopy(void);
INDEX iWeapon;
INDEX iAmmo;
BOOL bDropped;
};
DECL_DLL inline void ClearToDefault(EWeaponItem &e) { e = EWeaponItem(); } ;
extern "C" DECL_DLL CDLLEntityClass CWeaponItem_DLLClass;
class CWeaponItem : public CItem {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  enum WeaponItemType m_EwitType;
   
#line 178 "C:/MyMod/Sources/EntitiesMP/WeaponItem.es"
void Precache(void);
   
#line 196 "C:/MyMod/Sources/EntitiesMP/WeaponItem.es"
BOOL FillEntityStatistics(EntityStats * pes);
   
#line 207 "C:/MyMod/Sources/EntitiesMP/WeaponItem.es"
void RenderParticles(void);
   
#line 233 "C:/MyMod/Sources/EntitiesMP/WeaponItem.es"
void SetProperties(void);
#define  STATE_CWeaponItem_ItemCollected 0x03220001
  BOOL 
#line 387 "C:/MyMod/Sources/EntitiesMP/WeaponItem.es"
ItemCollected(const CEntityEvent &__eeInput);
#define  STATE_CWeaponItem_Main 1
  BOOL 
#line 419 "C:/MyMod/Sources/EntitiesMP/WeaponItem.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x03220002_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x03220003_Main_02(const CEntityEvent &__eeInput);
  BOOL H0x03220004_Main_03(const CEntityEvent &__eeInput);
  BOOL H0x03220005_Main_04(const CEntityEvent &__eeInput);
  BOOL H0x03220006_Main_05(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_WeaponItem_INCLUDED
