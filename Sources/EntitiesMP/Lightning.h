/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_Lightning_INCLUDED
#define _EntitiesMP_Lightning_INCLUDED 1
extern "C" DECL_DLL CDLLEntityClass CLightning_DLLClass;
class CLightning : public CMovableModelEntity {
public:
virtual BOOL IsTargetable(void) const { return TRUE; };
virtual const CTString &GetName(void) const { return m_strName; };
  DECL_DLL virtual void SetDefaultProperties(void);
  CEntityPointer m_penTarget;
  CEntityPointer m_penwsc;
  CTString m_strName;
  FLOAT m_tmLightningStart;
  CSoundObject m_soThunder;
  BOOL m_bBackground;
  CEntityPointer m_penLight;
  ANIMATION m_iLightAnim;
  INDEX m_iSoundPlaying;
  FLOAT m_fLightningPower;
  FLOAT m_fSoundDelay;
   
#line 50 "C:/MyMod/Sources/EntitiesMP/Lightning.es"
void Precache(void);
   
#line 59 "C:/MyMod/Sources/EntitiesMP/Lightning.es"
CAnimData * GetAnimData(SLONG slPropertyOffset);
   
#line 82 "C:/MyMod/Sources/EntitiesMP/Lightning.es"
void RenderParticles(void);
#define  STATE_CLightning_LightningStike 0x025f0000
  BOOL 
#line 100 "C:/MyMod/Sources/EntitiesMP/Lightning.es"
LightningStike(const CEntityEvent &__eeInput);
  BOOL H0x025f0001_LightningStike_01(const CEntityEvent &__eeInput);
  BOOL H0x025f0002_LightningStike_02(const CEntityEvent &__eeInput);
  BOOL H0x025f0003_LightningStike_03(const CEntityEvent &__eeInput);
  BOOL H0x025f0004_LightningStike_04(const CEntityEvent &__eeInput);
  BOOL H0x025f0005_LightningStike_05(const CEntityEvent &__eeInput);
  BOOL H0x025f0006_LightningStike_06(const CEntityEvent &__eeInput);
  BOOL H0x025f0007_LightningStike_07(const CEntityEvent &__eeInput);
  BOOL H0x025f0008_LightningStike_08(const CEntityEvent &__eeInput);
#define  STATE_CLightning_Main 1
  BOOL 
#line 164 "C:/MyMod/Sources/EntitiesMP/Lightning.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x025f0009_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x025f000a_Main_02(const CEntityEvent &__eeInput);
  BOOL H0x025f000b_Main_03(const CEntityEvent &__eeInput);
  BOOL H0x025f000c_Main_04(const CEntityEvent &__eeInput);
  BOOL H0x025f000d_Main_05(const CEntityEvent &__eeInput);
  BOOL H0x025f000e_Main_06(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_Lightning_INCLUDED
