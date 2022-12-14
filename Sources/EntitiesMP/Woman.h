/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_Woman_INCLUDED
#define _EntitiesMP_Woman_INCLUDED 1
#include <EntitiesMP/EnemyFly.h>
extern "C" DECL_DLL CDLLEntityClass CWoman_DLLClass;
class CWoman : public CEnemyFly {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  BOOL m_bKamikazeCarrier;
  RANGE m_rKamikazeDropDistance;
  BOOL m_bKamikazeAttached;
  
#line 61 "C:/MyMod/Sources/EntitiesMP/Woman.es"
virtual CTString GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath);
  
#line 71 "C:/MyMod/Sources/EntitiesMP/Woman.es"
virtual const CTFileName & GetComputerMessageName(void)const;
   
#line 75 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void Precache(void);
   
#line 87 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void * GetEntityInfo(void);
   
#line 96 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 97 "C:/MyMod/Sources/EntitiesMP/Woman.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection);
   
#line 107 "C:/MyMod/Sources/EntitiesMP/Woman.es"
INDEX AnimForDamage(FLOAT fDamage);
   
#line 119 "C:/MyMod/Sources/EntitiesMP/Woman.es"
INDEX AnimForDeath(void);
   
#line 130 "C:/MyMod/Sources/EntitiesMP/Woman.es"
FLOAT WaitForDust(FLOAT3D & vStretch);
   
#line 144 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void DeathNotify(void);
   
#line 150 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void StandingAnim(void);
   
#line 157 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void WalkingAnim(void);
   
#line 164 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void RunningAnim(void);
   
#line 171 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void RotatingAnim(void);
   
#line 178 "C:/MyMod/Sources/EntitiesMP/Woman.es"
FLOAT AirToGroundAnim(void);
   
#line 182 "C:/MyMod/Sources/EntitiesMP/Woman.es"
FLOAT GroundToAirAnim(void);
   
#line 186 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void ChangeCollisionToAir();
   
#line 189 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void ChangeCollisionToGround();
   
#line 194 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void IdleSound(void);
   
#line 197 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void SightSound(void);
   
#line 200 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void WoundSound(void);
   
#line 203 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void DeathSound(void);
   
#line 207 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void AttachKamikaze();
   
#line 217 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void RemoveKamikaze();
   
#line 222 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void DropKamikaze();
   
#line 250 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void PreMoving();
   
#line 267 "C:/MyMod/Sources/EntitiesMP/Woman.es"
void BlowUp(void);
#define  STATE_CWoman_FlyFire 0x01400000
  BOOL 
#line 278 "C:/MyMod/Sources/EntitiesMP/Woman.es"
FlyFire(const CEntityEvent &__eeInput);
  BOOL H0x01400001_FlyFire_01(const CEntityEvent &__eeInput);
  BOOL H0x01400002_FlyFire_02(const CEntityEvent &__eeInput);
  BOOL H0x01400003_FlyFire_03(const CEntityEvent &__eeInput);
  BOOL H0x01400004_FlyFire_04(const CEntityEvent &__eeInput);
  BOOL H0x01400005_FlyFire_05(const CEntityEvent &__eeInput);
  BOOL H0x01400006_FlyFire_06(const CEntityEvent &__eeInput);
#define  STATE_CWoman_FlyHit 0x01400007
  BOOL 
#line 293 "C:/MyMod/Sources/EntitiesMP/Woman.es"
FlyHit(const CEntityEvent &__eeInput);
#define  STATE_CWoman_Death 0x01400008
  BOOL 
#line 317 "C:/MyMod/Sources/EntitiesMP/Woman.es"
Death(const CEntityEvent &__eeInput);
#define  STATE_CWoman_AirToGround 0x01400009
  BOOL 
#line 322 "C:/MyMod/Sources/EntitiesMP/Woman.es"
AirToGround(const CEntityEvent &__eeInput);
#define  STATE_CWoman_FlyOnEnemy 0x0140000a
  BOOL 
#line 327 "C:/MyMod/Sources/EntitiesMP/Woman.es"
FlyOnEnemy(const CEntityEvent &__eeInput);
  BOOL H0x0140000b_FlyOnEnemy_01(const CEntityEvent &__eeInput);
  BOOL H0x0140000c_FlyOnEnemy_02(const CEntityEvent &__eeInput);
  BOOL H0x0140000d_FlyOnEnemy_03(const CEntityEvent &__eeInput);
  BOOL H0x0140000e_FlyOnEnemy_04(const CEntityEvent &__eeInput);
#define  STATE_CWoman_GroundFire 0x0140000f
  BOOL 
#line 351 "C:/MyMod/Sources/EntitiesMP/Woman.es"
GroundFire(const CEntityEvent &__eeInput);
  BOOL H0x01400010_GroundFire_01(const CEntityEvent &__eeInput);
  BOOL H0x01400011_GroundFire_02(const CEntityEvent &__eeInput);
  BOOL H0x01400012_GroundFire_03(const CEntityEvent &__eeInput);
  BOOL H0x01400013_GroundFire_04(const CEntityEvent &__eeInput);
  BOOL H0x01400014_GroundFire_05(const CEntityEvent &__eeInput);
  BOOL H0x01400015_GroundFire_06(const CEntityEvent &__eeInput);
#define  STATE_CWoman_GroundHit 0x01400016
  BOOL 
#line 364 "C:/MyMod/Sources/EntitiesMP/Woman.es"
GroundHit(const CEntityEvent &__eeInput);
  BOOL H0x01400017_GroundHit_01(const CEntityEvent &__eeInput);
  BOOL H0x01400018_GroundHit_02(const CEntityEvent &__eeInput);
  BOOL H0x01400019_GroundHit_03(const CEntityEvent &__eeInput);
  BOOL H0x0140001a_GroundHit_04(const CEntityEvent &__eeInput);
#define  STATE_CWoman_Main 1
  BOOL 
#line 394 "C:/MyMod/Sources/EntitiesMP/Woman.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x0140001b_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x0140001c_Main_02(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_Woman_INCLUDED
