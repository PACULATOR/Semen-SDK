/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_LarvaOffspring_INCLUDED
#define _EntitiesMP_LarvaOffspring_INCLUDED 1
#include <EntitiesMP/BasicEffects.h>
#include <EntitiesMP/Light.h>
#include <EntitiesMP/Flame.h>
#define EVENTCODE_ELaunchLarvaOffspring 0x01610000
class DECL_DLL ELaunchLarvaOffspring : public CEntityEvent {
public:
ELaunchLarvaOffspring();
CEntityEvent *MakeCopy(void);
CEntityPointer penLauncher;
};
DECL_DLL inline void ClearToDefault(ELaunchLarvaOffspring &e) { e = ELaunchLarvaOffspring(); } ;
extern "C" DECL_DLL CDLLEntityClass CLarvaOffspring_DLLClass;
class DECL_DLL  CLarvaOffspring : public CMovableModelEntity {
public:
virtual CEntity *GetPredictionPair(void) { return m_penPrediction; };
virtual void SetPredictionPair(CEntity *penPair) { m_penPrediction = penPair; };
   virtual void SetDefaultProperties(void);
  CEntityPointer m_penLauncher;
  CEntityPointer m_penTarget;
  FLOAT m_fIgnoreTime;
  FLOAT m_fFlyTime;
  FLOAT m_fStartTime;
  FLOAT m_fDamageAmount;
  FLOAT m_fRangeDamageAmount;
  FLOAT m_fDamageHotSpotRange;
  FLOAT m_fDamageFallOffRange;
  FLOAT m_fSoundRange;
  BOOL m_bExplode;
  FLOAT m_aRotateSpeed;
  FLOAT m_tmExpandBox;
  CSoundObject m_soEffect;
  BOOL bLockedOn;
  CEntityPointer m_penPrediction;
   
#line 63 "C:/MyMod/Sources/EntitiesMP/LarvaOffspring.es"
void PreMoving(void);
   
#line 73 "C:/MyMod/Sources/EntitiesMP/LarvaOffspring.es"
void Precache();
   
#line 82 "C:/MyMod/Sources/EntitiesMP/LarvaOffspring.es"
void InitializeProjectile(void);
   
#line 110 "C:/MyMod/Sources/EntitiesMP/LarvaOffspring.es"
void LarvaTailExplosion(void);
   
#line 158 "C:/MyMod/Sources/EntitiesMP/LarvaOffspring.es"
void ProjectileTouch(CEntityPointer penHit);
   
#line 183 "C:/MyMod/Sources/EntitiesMP/LarvaOffspring.es"
void ProjectileHit(void);
   
#line 202 "C:/MyMod/Sources/EntitiesMP/LarvaOffspring.es"
void SpawnEffect(const CPlacement3D & plEffect,const ESpawnEffect & eSpawnEffect);
   
#line 209 "C:/MyMod/Sources/EntitiesMP/LarvaOffspring.es"
ANGLE GetRotationSpeed(ANGLE aWantedAngle,ANGLE aRotateSpeed,FLOAT fWaitFrequency);
#define  STATE_CLarvaOffspring_LarvaOffspringGuidedSlide 0x01610001
  BOOL 
#line 237 "C:/MyMod/Sources/EntitiesMP/LarvaOffspring.es"
LarvaOffspringGuidedSlide(const CEntityEvent &__eeInput);
  BOOL H0x01610002_LarvaOffspringGuidedSlide_01(const CEntityEvent &__eeInput);
  BOOL H0x01610003_LarvaOffspringGuidedSlide_02(const CEntityEvent &__eeInput);
  BOOL H0x01610004_LarvaOffspringGuidedSlide_03(const CEntityEvent &__eeInput);
  BOOL H0x01610005_LarvaOffspringGuidedSlide_04(const CEntityEvent &__eeInput);
#define  STATE_CLarvaOffspring_Main 1
  BOOL 
#line 324 "C:/MyMod/Sources/EntitiesMP/LarvaOffspring.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x01610006_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x01610007_Main_02(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_LarvaOffspring_INCLUDED