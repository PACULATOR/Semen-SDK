/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_BasicEffects_INCLUDED
#define _EntitiesMP_BasicEffects_INCLUDED 1
#include <EntitiesMP/Light.h>
extern DECL_DLL CEntityPropertyEnumType BasicEffectType_enum;
enum BasicEffectType {
  BET_NONE = 0,
  BET_ROCKET = 1,
  BET_ROCKET_PLANE = 2,
  BET_GRENADE = 3,
  BET_GRENADE_PLANE = 4,
  BET_EXPLOSIONSTAIN = 5,
  BET_SHOCKWAVE = 6,
  BET_LASERWAVE = 7,
  BET_BLOODSPILL = 10,
  BET_BLOODSTAIN = 11,
  BET_BLOODSTAINGROW = 19,
  BET_BLOODEXPLODE = 12,
  BET_CANNON = 13,
  BET_CANNON_PLANE = 14,
  BET_CANNONEXPLOSIONSTAIN = 15,
  BET_CANNONSHOCKWAVE = 16,
  BET_TELEPORT = 17,
  BET_BOMB = 18,
  BET_BULLETTRAIL = 20,
  BET_GIZMO_SPLASH_FX = 21,
  BET_GIZMOSTAIN = 22,
  BET_BULLETSTAINSTONE = 30,
  BET_BULLETSTAINSAND = 31,
  BET_BULLETSTAINWATER = 32,
  BET_BULLETSTAINUNDERWATER = 33,
  BET_BULLETSTAINSTONENOSOUND = 34,
  BET_BULLETSTAINSANDNOSOUND = 35,
  BET_BULLETSTAINWATERNOSOUND = 36,
  BET_BULLETSTAINUNDERWATERNOSOUND = 37,
  BET_BULLETSTAINREDSAND = 38,
  BET_BULLETSTAINREDSANDNOSOUND = 39,
  BET_LIGHT_CANNON = 40,
  BET_CANNON_NOLIGHT = 41,
  BET_BULLETSTAINGRASS = 42,
  BET_BULLETSTAINWOOD = 43,
  BET_BULLETSTAINGRASSNOSOUND = 44,
  BET_BULLETSTAINWOODNOSOUND = 45,
  BET_EXPLOSION_DEBRIS = 46,
  BET_EXPLOSION_SMOKE = 47,
  BET_SUMMONERSTAREXPLOSION = 48,
  BET_COLLECT_ENERGY = 49,
  BET_GROWING_SWIRL = 50,
  BET_DISAPPEAR_DUST = 52,
  BET_DUST_FALL = 53,
  BET_BULLETSTAINSNOW = 54,
  BET_BULLETSTAINSNOWNOSOUND = 55,
};
DECL_DLL inline void ClearToDefault(BasicEffectType &e) { e = (BasicEffectType)0; } ;
#define EVENTCODE_ESpawnEffect 0x02590000
class DECL_DLL ESpawnEffect : public CEntityEvent {
public:
ESpawnEffect();
CEntityEvent *MakeCopy(void);
enum BasicEffectType betType;
FLOAT3D vNormal;
FLOAT3D vDirection;
FLOAT3D vStretch;
COLOR colMuliplier;
};
DECL_DLL inline void ClearToDefault(ESpawnEffect &e) { e = ESpawnEffect(); } ;
extern "C" DECL_DLL CDLLEntityClass CBasicEffect_DLLClass;
class CBasicEffect : public CRationalEntity {
public:
virtual CEntity *GetPredictionPair(void) { return m_penPrediction; };
virtual void SetPredictionPair(CEntity *penPair) { m_penPrediction = penPair; };
  DECL_DLL virtual void SetDefaultProperties(void);
  enum BasicEffectType m_betType;
  FLOAT m_fWaitTime;
  FLOAT m_fFadeTime;
  BOOL m_bFade;
  FLOAT m_fFadeStartTime;
  FLOAT m_fFadeStartAlpha;
  FLOAT3D m_vNormal;
  FLOAT3D m_vStretch;
  FLOAT3D m_vDirection;
  FLOAT m_fDepthSortOffset;
  FLOAT m_fFadeInSpeed;
  FLOAT m_tmSpawn;
  FLOAT m_tmWaitAfterDeath;
  BOOL m_bLightSource;
  CAnimObject m_aoLightAnimation;
  INDEX m_iLightAnimation;
  COLOR m_colMultiplyColor;
  CSoundObject m_soEffect;
  FLOAT m_fSoundTime;
  enum EffectParticlesType m_eptType;
  FLOAT m_tmWhenShot;
  FLOAT3D m_vGravity;
  CEntityPointer m_penPrediction;
CLightSource m_lsLightSource;
  DECL_DLL   void DumpSync_t(CTStream & strm,INDEX iExtensiveSyncCheck);
   
#line 334 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void Read_t(CTStream * istr);
   
#line 344 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
CLightSource * GetLightSource(void);
   
#line 354 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void SetupLightSource(void);
   
#line 421 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void RenderParticles(void);
   
#line 474 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
BOOL AdjustShadingParameters(FLOAT3D & vLightDirection,COLOR & colLight,COLOR & colAmbient);
   
#line 494 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
FLOAT GetDepthSortOffset(void);
   
#line 505 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void SetNonLoopingTexAnims(void);
   
#line 515 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void SetNormalForHalfFaceForward(void);
   
#line 522 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void SetNormal(void);
   
#line 529 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void SetNormalWithRandomBanking(void);
   
#line 537 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void FindGravityVectorFromSector(void);
   
#line 558 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void SetNormalAndDirection(void);
   
#line 585 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void RandomBanking(void);
   
#line 592 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void Stretch(void);
   
#line 598 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void ParentToNearestPolygonAndStretch(void);
   
#line 659 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void ProjectileExplosion(void);
   
#line 676 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void ProjectilePlaneExplosion(void);
   
#line 688 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BombExplosion(void);
   
#line 703 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void GizmoSplashFX(void);
   
#line 715 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void ExplosionDebris(void);
   
#line 724 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void CollectEnergy(void);
   
#line 733 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void GrowingSwirl(void);
   
#line 742 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void DisappearDust(void);
   
#line 751 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void DustFall(void);
   
#line 760 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void SniperResidue(void);
   
#line 771 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void ExplosionSmoke(void);
   
#line 781 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void GrenadeExplosion(void);
   
#line 797 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void GrenadePlaneExplosion(void);
   
#line 809 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void CannonExplosion(BOOL bLoVolume,BOOL bNoLight);
   
#line 841 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void CannonPlaneExplosion(void);
   
#line 853 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void Stain(void);
   
#line 863 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void CannonStain(void);
   
#line 879 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void ShockWave(void);
   
#line 892 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void CannonShockWave(void);
   
#line 906 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void LaserWave(void);
   
#line 924 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void TeleportEffect(void);
   
#line 944 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void SummonerStarExplosion();
   
#line 959 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BulletStainSand(BOOL bSound);
   
#line 984 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BulletStainRedSand(BOOL bSound);
   
#line 1010 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BulletStainStone(BOOL bSound,BOOL bSmoke);
   
#line 1037 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BulletStainWater(BOOL bSound);
   
#line 1062 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BulletTrail(void);
   
#line 1073 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BulletStainGrass(BOOL bSound);
   
#line 1098 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BulletStainWood(BOOL bSound);
   
#line 1123 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BulletStainSnow(BOOL bSound);
   
#line 1154 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BloodExplode(void);
   
#line 1188 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BloodStain(void);
   
#line 1226 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BloodStainGrow(void);
   
#line 1263 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void GizmoStain(void);
   
#line 1299 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
void BloodSpill(COLOR colBloodSpillColor);
#define  STATE_CBasicEffect_Main 1
  BOOL 
#line 1344 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x02590001_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x02590002_Main_02(const CEntityEvent &__eeInput);
#define  STATE_CBasicEffect_EffectLoop 0x02590003
  BOOL 
#line 1442 "C:/MyMod/Sources/EntitiesMP/BasicEffects.es"
EffectLoop(const CEntityEvent &__eeInput);
  BOOL H0x02590004_EffectLoop_01(const CEntityEvent &__eeInput);
  BOOL H0x02590005_EffectLoop_02(const CEntityEvent &__eeInput);
  BOOL H0x02590006_EffectLoop_03(const CEntityEvent &__eeInput);
  BOOL H0x02590007_EffectLoop_04(const CEntityEvent &__eeInput);
  BOOL H0x02590008_EffectLoop_05(const CEntityEvent &__eeInput);
  BOOL H0x02590009_EffectLoop_06(const CEntityEvent &__eeInput);
  BOOL H0x0259000a_EffectLoop_07(const CEntityEvent &__eeInput);
  BOOL H0x0259000b_EffectLoop_08(const CEntityEvent &__eeInput);
  BOOL H0x0259000c_EffectLoop_09(const CEntityEvent &__eeInput);
  BOOL H0x0259000d_EffectLoop_10(const CEntityEvent &__eeInput);
  BOOL H0x0259000e_EffectLoop_11(const CEntityEvent &__eeInput);
  BOOL H0x0259000f_EffectLoop_12(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_BasicEffects_INCLUDED
