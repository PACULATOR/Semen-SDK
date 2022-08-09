/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_ModelDestruction_INCLUDED
#define _EntitiesMP_ModelDestruction_INCLUDED 1
#include <EntitiesMP/ModelHolder2.h>
#include <EntitiesMP/BasicEffects.h>
#include <EntitiesMP/Debris.h>
#include <EntitiesMP/BloodSpray.h>
#include <EntitiesMP/SoundHolder.h>
#define EVENTCODE_ERangeModelDestruction 0x00d90000
class DECL_DLL ERangeModelDestruction : public CEntityEvent {
public:
ERangeModelDestruction();
CEntityEvent *MakeCopy(void);
};
DECL_DLL inline void ClearToDefault(ERangeModelDestruction &e) { e = ERangeModelDestruction(); } ;
extern DECL_DLL CEntityPropertyEnumType DestructionDebrisType_enum;
enum DestructionDebrisType {
  DDT_STONE = 1,
  DDT_WOOD = 2,
  DDT_PALM = 3,
  DDT_CHILDREN_CUSTOM = 4,
};
DECL_DLL inline void ClearToDefault(DestructionDebrisType &e) { e = (DestructionDebrisType)0; } ;
extern "C" DECL_DLL CDLLEntityClass CModelDestruction_DLLClass;
class CModelDestruction : public CEntity {
public:
virtual const CTString &GetName(void) const { return m_strName; };
virtual BOOL IsTargetable(void) const { return TRUE; };
virtual BOOL IsImportant(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  CTString m_strName;
  CTString m_strDescription;
  CEntityPointer m_penModel0;
  CEntityPointer m_penModel1;
  CEntityPointer m_penModel2;
  CEntityPointer m_penModel3;
  CEntityPointer m_penModel4;
  FLOAT m_fHealth;
  enum DestructionDebrisType m_ddtDebris;
  INDEX m_ctDebris;
  FLOAT m_fDebrisSize;
  enum EntityInfoBodyType m_eibtBodyType;
  enum SprayParticlesType m_sptType;
  FLOAT m_fParticleSize;
  BOOL m_bRequireExplosion;
  FLOAT m_fDebrisLaunchPower;
  enum DebrisParticlesType m_dptParticles;
  enum BasicEffectType m_betStain;
  FLOAT m_fLaunchCone;
  FLOAT m_fRndRotH;
  FLOAT m_fRndRotP;
  FLOAT m_fRndRotB;
  FLOAT m_fParticleLaunchPower;
  COLOR m_colParticles;
  ANIMATION m_iStartAnim;
  BOOL m_bDebrisImmaterialASAP;
  INDEX m_ctDustFall;
  FLOAT m_fMinDustFallHeightRatio;
  FLOAT m_fMaxDustFallHeightRatio;
  FLOAT m_fDustStretch;
  FLOAT m_fDebrisDustRandom;
  FLOAT m_fDebrisDustStretch;
  CEntityPointer m_penShake;
   
#line 85 "C:/MyMod/Sources/EntitiesMP/ModelDestruction.es"
void Precache(void);
   
#line 104 "C:/MyMod/Sources/EntitiesMP/ModelDestruction.es"
CAnimData * GetAnimData(SLONG slPropertyOffset);
   
#line 117 "C:/MyMod/Sources/EntitiesMP/ModelDestruction.es"
const CTString & GetDescription(void)const;
   
#line 130 "C:/MyMod/Sources/EntitiesMP/ModelDestruction.es"
void CheckOneModelTarget(CEntityPointer & pen);
   
#line 139 "C:/MyMod/Sources/EntitiesMP/ModelDestruction.es"
class CModelHolder2 * GetNextPhase(void);
   
#line 154 "C:/MyMod/Sources/EntitiesMP/ModelDestruction.es"
INDEX GetModelsCount(void)const;
   
#line 165 "C:/MyMod/Sources/EntitiesMP/ModelDestruction.es"
class CModelHolder2 * GetModel(INDEX iModel);
   
#line 172 "C:/MyMod/Sources/EntitiesMP/ModelDestruction.es"
void SpawnDebris(CModelHolder2 * penmhDestroyed);
#define  STATE_CModelDestruction_Main 1
  BOOL 
#line 294 "C:/MyMod/Sources/EntitiesMP/ModelDestruction.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_ModelDestruction_INCLUDED
