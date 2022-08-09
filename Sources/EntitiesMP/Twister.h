/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_Twister_INCLUDED
#define _EntitiesMP_Twister_INCLUDED 1
#include <EntitiesMP/AirElemental.h>
#include <EntitiesMP/Elemental.h>
#include <EntitiesMP/Spinner.h>
#define EVENTCODE_ETwister 0x01fb0000
class DECL_DLL ETwister : public CEntityEvent {
public:
ETwister();
CEntityEvent *MakeCopy(void);
CEntityPointer penOwner;
FLOAT fSize;
FLOAT fDuration;
INDEX sgnSpinDir;
BOOL bGrow;
BOOL bMovingAllowed;
};
DECL_DLL inline void ClearToDefault(ETwister &e) { e = ETwister(); } ;
extern "C" DECL_DLL CDLLEntityClass CTwister_DLLClass;
class CTwister : public CMovableModelEntity {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  CEntityPointer m_penOwner;
  FLOAT m_fSize;
  FLOAT3D m_vSpeed;
  INDEX m_sgnSpinDir;
  BOOL m_bGrow;
  FLOAT m_tmLastMove;
  FLOAT3D m_aSpeedRotation;
  BOOL m_bMoving;
  BOOL m_bMovingAllowed;
  FLOAT3D m_vDesiredPosition;
  FLOAT3D m_vDesiredAngle;
  FLOAT m_fStopTime;
  FLOAT m_fActionRadius;
  FLOAT m_fActionTime;
  FLOAT m_fDiffMultiply;
  FLOAT m_fUpMultiply;
  BOOL m_bFadeOut;
  FLOAT m_fFadeStartTime;
  FLOAT m_fFadeTime;
  FLOAT m_fStartTime;
  CSoundObject m_soSpin;
   
#line 95 "C:/MyMod/Sources/EntitiesMP/Twister.es"
void * GetEntityInfo(void);
   
#line 100 "C:/MyMod/Sources/EntitiesMP/Twister.es"
void ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 101 "C:/MyMod/Sources/EntitiesMP/Twister.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection);
   
#line 107 "C:/MyMod/Sources/EntitiesMP/Twister.es"
void RenderParticles(void);
   
#line 130 "C:/MyMod/Sources/EntitiesMP/Twister.es"
BOOL AdjustShadingParameters(FLOAT3D & vLightDirection,COLOR & colLight,COLOR & colAmbient);
   
#line 147 "C:/MyMod/Sources/EntitiesMP/Twister.es"
void SpinEntity(CEntity * pen);
   
#line 232 "C:/MyMod/Sources/EntitiesMP/Twister.es"
void PreMoving(void);
#define  STATE_CTwister_Main 1
  BOOL 
#line 252 "C:/MyMod/Sources/EntitiesMP/Twister.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x01fb0001_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x01fb0002_Main_02(const CEntityEvent &__eeInput);
  BOOL H0x01fb0003_Main_03(const CEntityEvent &__eeInput);
  BOOL H0x01fb0004_Main_04(const CEntityEvent &__eeInput);
  BOOL H0x01fb0005_Main_05(const CEntityEvent &__eeInput);
  BOOL H0x01fb0006_Main_06(const CEntityEvent &__eeInput);
  BOOL H0x01fb0007_Main_07(const CEntityEvent &__eeInput);
  BOOL H0x01fb0008_Main_08(const CEntityEvent &__eeInput);
  BOOL H0x01fb0009_Main_09(const CEntityEvent &__eeInput);
  BOOL H0x01fb000a_Main_10(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_Twister_INCLUDED
