/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"

#include "StdH.h"
#include "EntitiesMP/BackgroundViewer.h"
#include "EntitiesMP/WorldSettingsController.h"
#include "EntitiesMP/EnemyBase.h"

#include <EntitiesMP/SeriousBomb.h>
#include <EntitiesMP/SeriousBomb_tables.h>
CEntityEvent *ESeriousBomb::MakeCopy(void) { CEntityEvent *peeCopy = new ESeriousBomb(*this); return peeCopy;}
ESeriousBomb::ESeriousBomb() : CEntityEvent(EVENTCODE_ESeriousBomb) {;
 ClearToDefault(penOwner);
};
#line 14 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"

void CSeriousBomb_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) 
{
  pdec->  PrecacheSound(SOUND_BLOW);
};

void CSeriousBomb::SetDefaultProperties(void) {
  m_penOwner = NULL;
  m_soBlow.SetOwner(this);
m_soBlow.Stop_internal();
  CRationalEntity::SetDefaultProperties();
}
  
#line 42 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
void CSeriousBomb::ShakeItBaby(FLOAT tmShaketime,FLOAT fPower,FLOAT fFade,BOOL bFadeIn) 
#line 43 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
{
#line 44 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 45 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
if(pwsc  != NULL ){
#line 46 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_tmShakeStarted  = tmShaketime ;
#line 47 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_vShakePos  = GetPlacement  () . pl_PositionVector ;
#line 48 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_fShakeFalloff  = 450.0f;
#line 49 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_fShakeFade  = fFade ;
#line 51 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_fShakeIntensityZ  = 0;
#line 52 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_tmShakeFrequencyZ  = 5.0f;
#line 53 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_fShakeIntensityY  = 0.1f * fPower ;
#line 54 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_tmShakeFrequencyY  = 5.0f;
#line 55 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_fShakeIntensityB  = 2.5f * fPower ;
#line 56 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_tmShakeFrequencyB  = 7.2f;
#line 58 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_bShakeFadeIn  = bFadeIn ;
#line 59 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
}
#line 60 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
}
  
#line 62 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
void CSeriousBomb::Glare(FLOAT fStart,FLOAT fEnd,FLOAT fFinR,FLOAT fFoutR) 
#line 63 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
{
#line 64 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 65 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
if(pwsc  != NULL )
#line 66 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
{
#line 67 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_colGlade  = C_WHITE ;
#line 68 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_tmGlaringStarted  = _pTimer  -> CurrentTick  () + fStart ;
#line 69 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_tmGlaringEnded  = pwsc  -> m_tmGlaringStarted  + fEnd ;
#line 70 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_fGlaringFadeInRatio  = fFinR ;
#line 71 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
pwsc  -> m_fGlaringFadeOutRatio  = fFoutR ;
#line 72 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
}
#line 73 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
}
  
#line 76 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
void CSeriousBomb::ExplodeBomb(void) 
#line 77 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
{
#line 79 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
{FOREACHINDYNAMICCONTAINER  (this  -> GetWorld  () -> wo_cenEntities  , CEntity  , iten ){
#line 80 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
CEntity  * pen  = iten ;
#line 81 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
if(IsDerivedFromClass  (pen  , "Enemy Base")){
#line 82 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
CEnemyBase  * penEnemy  = (CEnemyBase  *) pen ;
#line 83 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
if(penEnemy  -> m_bBoss  == TRUE  || DistanceTo  (this  , penEnemy ) > 250.0f){
#line 84 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
continue ;
#line 85 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
}
#line 86 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
this  -> InflictDirectDamage  (pen  , this  , DMT_EXPLOSION  , penEnemy  -> GetHealth  () + 100.0f , pen  -> GetPlacement  () . pl_PositionVector  , FLOAT3D (0 , 1 , 0));
#line 87 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
}
#line 88 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
}}
#line 89 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
}
BOOL CSeriousBomb::
#line 93 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CSeriousBomb_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_ESeriousBomb, "CSeriousBomb::Main expects 'ESeriousBomb' as input!");  const ESeriousBomb &esb = (const ESeriousBomb &)__eeInput;
#line 95 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
InitAsVoid  ();
#line 97 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
if(!(esb  . penOwner )){ Jump(STATE_CURRENT,0x01620007, FALSE, EInternal());return TRUE;}
#line 98 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
m_penOwner  = esb  . penOwner ;
#line 100 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
m_soBlow  . Set3DParameters  (500.0f , 250.0f , 3.0f , 1.0f);
#line 101 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
PlaySound  (m_soBlow  , SOUND_BLOW  , SOF_3D );
#line 102 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
if(_pNetwork  -> IsPlayerLocal  (m_penOwner )){IFeel_PlayEffect  ("SeriousBombBlow");}
#line 105 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
Glare  (1.0f , 2.8f , 0.3f , 0.3f);
#line 107 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
ShakeItBaby  (_pTimer  -> CurrentTick  () , 4.0f , 1.0f , TRUE );
#line 108 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
SetTimerAfter(1.5f);
Jump(STATE_CURRENT, 0x01620001, FALSE, EBegin());return TRUE;}BOOL CSeriousBomb::H0x01620001_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01620001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01620002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CSeriousBomb::H0x01620002_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01620002
;
#line 111 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
ShakeItBaby  (_pTimer  -> CurrentTick  () , 8.0f , 2.0f , FALSE );
#line 114 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
ExplodeBomb  ();
#line 115 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
SetTimerAfter(0.25f);
Jump(STATE_CURRENT, 0x01620003, FALSE, EBegin());return TRUE;}BOOL CSeriousBomb::H0x01620003_Main_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01620003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01620004, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CSeriousBomb::H0x01620004_Main_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01620004
;
#line 116 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
ExplodeBomb  ();
#line 117 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
SetTimerAfter(1.75f);
Jump(STATE_CURRENT, 0x01620005, FALSE, EBegin());return TRUE;}BOOL CSeriousBomb::H0x01620005_Main_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01620005
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01620006, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CSeriousBomb::H0x01620006_Main_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01620006
;Jump(STATE_CURRENT,0x01620007, FALSE, EInternal());return TRUE;}BOOL CSeriousBomb::H0x01620007_Main_07(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01620007

#line 120 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
Destroy  ();
#line 121 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
Return(STATE_CURRENT,EVoid());
#line 121 "C:/MyMod/Sources/EntitiesMP/SeriousBomb.es"
return TRUE; ASSERT(FALSE); return TRUE;};