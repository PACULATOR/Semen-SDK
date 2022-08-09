/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_CrateBus_INCLUDED
#define _EntitiesMP_CrateBus_INCLUDED 1
#include <EntitiesMP/SpawnerProjectile.h>
#include <EntitiesMP/EnemyBase.h>
#include <EntitiesMP/BasicEffects.h>
extern "C" DECL_DLL CDLLEntityClass CCrateBus_DLLClass;
class CCrateBus : public CMovableModelEntity {
public:
virtual BOOL IsTargetable(void) const { return TRUE; };
virtual const CTString &GetName(void) const { return m_strName; };
virtual BOOL IsImportant(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  BOOL m_bActive;
  FLOAT m_fExplosionStretch;
  FLOAT m_tmDeath;
  CTString m_strName;
  INDEX m_ctMentals;
  BOOL m_bShowTrail;
  FLOAT m_fStretch;
  CTFileName m_fnmHeadTex01;
  CTFileName m_fnmHeadTex02;
  CTFileName m_fnmHeadTex03;
  CTFileName m_fnmHeadTex04;
  CTFileName m_fnmHeadTex05;
  CTFileName m_fnmHeadTex06;
  CTFileName m_fnmHeadTex07;
  CTFileName m_fnmHeadTex08;
  CTFileName m_fnmHeadTex09;
  CTFileName m_fnmHeadTex10;
  CTFileName m_fnmHeadTex11;
  CTFileName m_fnmHeadTex12;
  CTFileName m_fnmHeadTex13;
  CTFileName m_fnmHeadTex14;
  CTFileName m_fnmHeadTex15;
  CTFileName m_fnmHeadTex16;
  CTFileName m_fnmHeadTex17;
  CTFileName m_fnmHeadTex18;
  CTFileName m_fnmHeadTex19;
  CTFileName m_fnmHeadTex20;
  CTFileName m_fnmHeadTex21;
  CTFileName m_fnmHeadTex22;
  CTFileName m_fnmHeadTex23;
  CTFileName m_fnmHeadTex24;
   
#line 92 "C:/MyMod/Sources/EntitiesMP/CrateBus.es"
void Precache(void);
   
#line 98 "C:/MyMod/Sources/EntitiesMP/CrateBus.es"
void AddRiders();
   
#line 141 "C:/MyMod/Sources/EntitiesMP/CrateBus.es"
void RenderParticles(void);
   
#line 151 "C:/MyMod/Sources/EntitiesMP/CrateBus.es"
void SpawnExplosion(INDEX iCharacter,FLOAT fAddY,FLOAT fSize);
   
#line 192 "C:/MyMod/Sources/EntitiesMP/CrateBus.es"
CPlacement3D GetLerpedPlacement(void)const;
#define  STATE_CCrateBus_Die 0x01600000
  BOOL 
#line 198 "C:/MyMod/Sources/EntitiesMP/CrateBus.es"
Die(const CEntityEvent &__eeInput);
  BOOL H0x01600001_Die_01(const CEntityEvent &__eeInput);
  BOOL H0x01600002_Die_02(const CEntityEvent &__eeInput);
#define  STATE_CCrateBus_Main 1
  BOOL 
#line 274 "C:/MyMod/Sources/EntitiesMP/CrateBus.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x01600003_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x01600004_Main_02(const CEntityEvent &__eeInput);
  BOOL H0x01600005_Main_03(const CEntityEvent &__eeInput);
  BOOL H0x01600006_Main_04(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_CrateBus_INCLUDED
