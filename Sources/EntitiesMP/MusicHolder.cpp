/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"

#include "StdH.h"
#include "EntitiesMP/EnemyBase.h"
#include "EntitiesMP/EnemySpawner.h"
#include "EntitiesMP/Trigger.h"
#include "EntitiesMP/Woman.h"

#include <EntitiesMP/MusicHolder.h>
#include <EntitiesMP/MusicHolder_tables.h>
CEntityEvent *EChangeMusic::MakeCopy(void) { CEntityEvent *peeCopy = new EChangeMusic(*this); return peeCopy;}
EChangeMusic::EChangeMusic() : CEntityEvent(EVENTCODE_EChangeMusic) {;
 ClearToDefault(mtType);
 ClearToDefault(fnMusic);
 ClearToDefault(fVolume);
 ClearToDefault(bForceStart);
};
#line 26 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"

#define MUSIC_VOLUMEMIN   0.02f     // minimum volume (considered off)
#define MUSIC_VOLUMEMAX   0.98f     // maximum volume (considered full)

float FadeInFactor(TIME fFadeTime)
{
  return (float) pow(MUSIC_VOLUMEMAX/MUSIC_VOLUMEMIN, 1/(fFadeTime/_pTimer->TickQuantum));
}
float FadeOutFactor(TIME fFadeTime)
{
  return (float) pow(MUSIC_VOLUMEMIN/MUSIC_VOLUMEMAX, 1/(fFadeTime/_pTimer->TickQuantum));
}

void CMusicHolder::SetDefaultProperties(void) {
  m_strName = "MusicHolder";
  m_fScoreMedium = 100.0f;
  m_fScoreHeavy = 1000.0f;
  m_fnMusic0 = CTFILENAME("");
  m_fnMusic1 = CTFILENAME("");
  m_fnMusic2 = CTFILENAME("");
  m_fnMusic3 = CTFILENAME("");
  m_fnMusic4 = CTFILENAME("");
  m_fVolume0 = 1.0f;
  m_fVolume1 = 1.0f;
  m_fVolume2 = 1.0f;
  m_fVolume3 = 1.0f;
  m_fVolume4 = 1.0f;
  m_penBoss = NULL;
  m_penCounter = NULL;
  m_ctEnemiesInWorld = 0;
  m_penRespawnMarker = NULL;
  m_ctSecretsInWorld = 0;
  m_tmFade = 1.0f;
  m_mtCurrentMusic = MT_LIGHT ;
  m_fCurrentVolume0a = 1.0f;
  m_fCurrentVolume0b = 1.0f;
  m_fCurrentVolume1a = 1.0f;
  m_fCurrentVolume1b = 1.0f;
  m_fCurrentVolume2a = 1.0f;
  m_fCurrentVolume2b = 1.0f;
  m_fCurrentVolume3a = 1.0f;
  m_fCurrentVolume3b = 1.0f;
  m_fCurrentVolume4a = 1.0f;
  m_fCurrentVolume4b = 1.0f;
  m_soMusic0a.SetOwner(this);
m_soMusic0a.Stop_internal();
  m_soMusic0b.SetOwner(this);
m_soMusic0b.Stop_internal();
  m_soMusic1a.SetOwner(this);
m_soMusic1a.Stop_internal();
  m_soMusic1b.SetOwner(this);
m_soMusic1b.Stop_internal();
  m_soMusic2a.SetOwner(this);
m_soMusic2a.Stop_internal();
  m_soMusic2b.SetOwner(this);
m_soMusic2b.Stop_internal();
  m_soMusic3a.SetOwner(this);
m_soMusic3a.Stop_internal();
  m_soMusic3b.SetOwner(this);
m_soMusic3b.Stop_internal();
  m_soMusic4a.SetOwner(this);
m_soMusic4a.Stop_internal();
  m_soMusic4b.SetOwner(this);
m_soMusic4b.Stop_internal();
  m_iSubChannel0 = 1;
  m_iSubChannel1 = 1;
  m_iSubChannel2 = 1;
  m_iSubChannel3 = 1;
  m_iSubChannel4 = 1;
  CRationalEntity::SetDefaultProperties();
}
  
#line 115 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
void CMusicHolder::CountEnemies(void) 
#line 116 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
{
#line 117 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_ctEnemiesInWorld  = 0;
#line 118 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_ctSecretsInWorld  = 0;
#line 120 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
{FOREACHINDYNAMICCONTAINER  (GetWorld  () -> wo_cenEntities  , CEntity  , iten ){
#line 121 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CEntity  * pen  = iten ;
#line 123 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(IsDerivedFromClass  (pen  , "Enemy Base")){
#line 124 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CEnemyBase  * penEnemy  = (CEnemyBase  *) pen ;
#line 126 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(! penEnemy  -> m_bTemplate ){
#line 128 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_ctEnemiesInWorld  ++;
#line 130 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(IsOfClass  (pen  , "Woman")){
#line 131 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(((CWoman  *) & * pen ) -> m_bKamikazeCarrier ){m_ctEnemiesInWorld  ++;}
#line 132 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 133 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 135 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else if(IsDerivedFromClass  (pen  , "Enemy Spawner")){
#line 136 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CEnemySpawner  * penSpawner  = (CEnemySpawner  *) pen ;
#line 138 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(penSpawner  -> m_estType  != EST_TELEPORTER ){
#line 140 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_ctEnemiesInWorld  += penSpawner  -> m_ctTotal ;
#line 142 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(penSpawner  -> m_penTarget ){
#line 143 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(IsOfClass  (penSpawner  -> m_penTarget  , "Woman")){
#line 144 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(((CWoman  *) & * penSpawner  -> m_penTarget ) -> m_bKamikazeCarrier ){m_ctEnemiesInWorld  += penSpawner  -> m_ctTotal ;}
#line 145 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 146 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 147 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 149 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else if(IsDerivedFromClass  (pen  , "Trigger")){
#line 150 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CTrigger  * penTrigger  = (CTrigger  *) pen ;
#line 152 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(penTrigger  -> m_fScore  > 0){
#line 154 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_ctSecretsInWorld  ++;
#line 155 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 156 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 157 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}}
#line 158 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
  
#line 161 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
void CMusicHolder::CheckOldFussMakers(void) 
#line 162 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
{
#line 163 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
TIME  tmNow  = _pTimer  -> CurrentTick  ();
#line 164 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
TIME  tmTooOld  = tmNow  - 10.0f;
#line 165 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CDynamicContainer  < CEntity  > cenOldFussMakers ;
#line 167 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
{FOREACHINDYNAMICCONTAINER  (m_cenFussMakers  , CEntity  , itenFussMaker ){
#line 168 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CEnemyBase  & enFussMaker  = (CEnemyBase  &) * itenFussMaker ;
#line 170 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(enFussMaker  . m_tmLastFussTime  < tmTooOld ){
#line 172 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
cenOldFussMakers  . Add  (& enFussMaker );
#line 173 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 174 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}}
#line 176 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
{FOREACHINDYNAMICCONTAINER  (cenOldFussMakers  , CEntity  , itenOldFussMaker ){
#line 177 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CEnemyBase  & enOldFussMaker  = (CEnemyBase  &) * itenOldFussMaker ;
#line 179 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
enOldFussMaker  . RemoveFromFuss  ();
#line 180 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}}
#line 181 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
  
#line 184 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
INDEX CMusicHolder::GetFussMakersScore(void) {
#line 185 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
INDEX iScore  = 0;
#line 186 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
{FOREACHINDYNAMICCONTAINER  (m_cenFussMakers  , CEntity  , itenFussMaker ){
#line 187 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CEnemyBase  & enFussMaker  = (CEnemyBase  &) * itenFussMaker ;
#line 188 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
iScore  += enFussMaker  . m_iScore ;
#line 189 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}}
#line 190 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
return iScore ;
#line 191 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
  
#line 194 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
void CMusicHolder::ChangeMusicChannel(enum MusicType mtType,const CTFileName & fnNewMusic,FLOAT fNewVolume) 
#line 195 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
{
#line 196 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
INDEX & iSubChannel  = (& m_iSubChannel0 ) [ mtType  ];
#line 198 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(fnNewMusic  != ""){
#line 199 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
iSubChannel  = (iSubChannel  + 1) % 2;
#line 200 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 202 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
FLOAT & fVolume  = (& m_fVolume0 ) [ mtType  ];
#line 203 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CSoundObject & soMusic  = (& m_soMusic0a ) [ mtType  * 2 + iSubChannel  ];
#line 204 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
FLOAT & fCurrentVolume  = (& m_fCurrentVolume0a ) [ mtType  * 2 + iSubChannel  ];
#line 207 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
ULONG  ulFlags ;
#line 208 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(mtType  == MT_EVENT ){
#line 209 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
ulFlags  = SOF_MUSIC ;
#line 210 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else {
#line 211 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
ulFlags  = SOF_MUSIC  | SOF_LOOP  | SOF_NONGAME ;
#line 212 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 215 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
fVolume  = fNewVolume ;
#line 217 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(fnNewMusic  != ""){
#line 218 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
PlaySound  (soMusic  , fnNewMusic  , ulFlags );
#line 220 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
fCurrentVolume  = MUSIC_VOLUMEMIN ;
#line 221 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
soMusic  . Pause  ();
#line 222 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
soMusic  . SetVolume  (fCurrentVolume  , fCurrentVolume );
#line 223 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 224 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
  
#line 227 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
void CMusicHolder::FadeOutChannel(INDEX iChannel,INDEX iSubChannel) 
#line 228 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
{
#line 230 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
FLOAT & fVolume  = (& m_fVolume0 ) [ iChannel  ];
#line 231 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CSoundObject & soMusic  = (& m_soMusic0a ) [ iChannel  * 2 + iSubChannel  ];
#line 232 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
FLOAT & fCurrentVolume  = (& m_fCurrentVolume0a ) [ iChannel  * 2 + iSubChannel  ];
#line 235 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(! soMusic  . IsPlaying  ()){return ;}
#line 238 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(soMusic  . IsPaused  ()){return ;}
#line 241 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(fCurrentVolume  < MUSIC_VOLUMEMIN ){
#line 243 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
soMusic  . Pause  ();
#line 244 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else {
#line 246 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
fCurrentVolume  *= FadeOutFactor  (m_tmFade );
#line 247 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
soMusic  . SetVolume  (fCurrentVolume  * fVolume  , fCurrentVolume  * fVolume );
#line 248 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 249 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
  
#line 252 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
void CMusicHolder::FadeInChannel(INDEX iChannel,INDEX iSubChannel) 
#line 253 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
{
#line 255 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
FLOAT & fVolume  = (& m_fVolume0 ) [ iChannel  ];
#line 256 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CSoundObject & soMusic  = (& m_soMusic0a ) [ iChannel  * 2 + iSubChannel  ];
#line 257 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
FLOAT & fCurrentVolume  = (& m_fCurrentVolume0a ) [ iChannel  * 2 + iSubChannel  ];
#line 260 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(! soMusic  . IsPlaying  ()){return ;}
#line 263 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(soMusic  . IsPaused  ()){
#line 264 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
soMusic  . Resume  ();
#line 265 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 267 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(fCurrentVolume  < MUSIC_VOLUMEMAX ){
#line 268 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
fCurrentVolume  *= FadeInFactor  (m_tmFade );
#line 269 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
fCurrentVolume  = ClampUp  (fCurrentVolume  , 1.0f);
#line 270 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 271 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
soMusic  . SetVolume  (fCurrentVolume  * fVolume  , fCurrentVolume  * fVolume );
#line 272 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
  
#line 275 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
void CMusicHolder::CrossFadeOneChannel(enum MusicType mtType) 
#line 276 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
{
#line 277 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
INDEX iSubChannelActive  = (& m_iSubChannel0 ) [ mtType  ];
#line 278 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
INDEX iSubChannelInactive  = (iSubChannelActive  + 1) % 2;
#line 280 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(mtType  == m_mtCurrentMusic ){
#line 282 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
FadeInChannel  (mtType  , iSubChannelActive );
#line 284 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
FadeOutChannel  (mtType  , iSubChannelInactive );
#line 286 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else {
#line 288 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
FadeOutChannel  (mtType  , 0);
#line 289 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
FadeOutChannel  (mtType  , 1);
#line 290 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 291 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
BOOL CMusicHolder::
#line 295 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CMusicHolder_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CMusicHolder::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 298 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
InitAsEditorModel  ();
#line 299 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 300 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 303 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
SetModel  (MODEL_MARKER );
#line 304 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 307 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
SetTimerAfter(_pTimer  -> TickQuantum );
Jump(STATE_CURRENT, 0x00de0001, FALSE, EBegin());return TRUE;}BOOL CMusicHolder::H0x00de0001_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00de0001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00de0002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CMusicHolder::H0x00de0002_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00de0002
;
#line 310 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
ChangeMusicChannel  (MT_LIGHT  , m_fnMusic0  , m_fVolume0 );
#line 311 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
ChangeMusicChannel  (MT_MEDIUM  , m_fnMusic1  , m_fVolume1 );
#line 312 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
ChangeMusicChannel  (MT_HEAVY  , m_fnMusic2  , m_fVolume2 );
#line 313 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
ChangeMusicChannel  (MT_EVENT  , m_fnMusic3  , m_fVolume3 );
#line 314 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
ChangeMusicChannel  (MT_CONTINUOUS  , m_fnMusic4  , m_fVolume4 );
#line 317 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_mtCurrentMusic  = MT_LIGHT ;
#line 318 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_fCurrentVolume0a  = MUSIC_VOLUMEMAX  * 0.98f;
#line 319 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_tmFade  = 0.01f;
#line 320 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CrossFadeOneChannel  (MT_LIGHT );
#line 324 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
SetTimerAfter(_pTimer  -> TickQuantum );
Jump(STATE_CURRENT, 0x00de0003, FALSE, EBegin());return TRUE;}BOOL CMusicHolder::H0x00de0003_Main_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00de0003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00de0004, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CMusicHolder::H0x00de0004_Main_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00de0004
;
#line 327 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CountEnemies  ();
#line 330 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
Jump(STATE_CURRENT,0x00de0007, FALSE, EInternal());return TRUE;}BOOL CMusicHolder::H0x00de0007_Main_07(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00de0007
if(!(TRUE )){ Jump(STATE_CURRENT,0x00de0008, FALSE, EInternal());return TRUE;}
#line 332 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x00de0005, FALSE, EBegin());return TRUE;}BOOL CMusicHolder::H0x00de0005_Main_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00de0005
switch(__eeInput.ee_slEvent){case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;

#line 334 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
UnsetTimer();Jump(STATE_CURRENT,0x00de0006, FALSE, EInternal());return TRUE;
#line 335 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EChangeMusic):{const EChangeMusic&ecm= (EChangeMusic&)__eeInput;

#line 339 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
ChangeMusicChannel  (ecm  . mtType  , ecm  . fnMusic  , ecm  . fVolume );
#line 341 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(ecm  . bForceStart ){
#line 343 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_mtCurrentMusic  = ecm  . mtType ;
#line 344 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 346 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
UnsetTimer();Jump(STATE_CURRENT,0x00de0006, FALSE, EInternal());return TRUE;
#line 347 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 348 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}return TRUE;}BOOL CMusicHolder::H0x00de0006_Main_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00de0006

#line 350 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CheckOldFussMakers  ();
#line 352 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
FLOAT fFussScore  = GetFussMakersScore  ();
#line 354 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(m_mtCurrentMusic  == MT_EVENT ){
#line 356 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(! m_soMusic3a  . IsPlaying  () && ! m_soMusic3b  . IsPlaying  ()){
#line 358 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_mtCurrentMusic  = MT_LIGHT ;
#line 359 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 360 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 362 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(m_mtCurrentMusic  == MT_HEAVY ){
#line 364 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(fFussScore  <= 0.0f){
#line 366 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_mtCurrentMusic  = MT_LIGHT ;
#line 367 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 369 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else if(m_mtCurrentMusic  == MT_MEDIUM ){
#line 371 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(fFussScore  <= 0.0f){
#line 373 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_mtCurrentMusic  = MT_LIGHT ;
#line 375 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else if(fFussScore  >= m_fScoreHeavy ){
#line 377 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_mtCurrentMusic  = MT_HEAVY ;
#line 378 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 380 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else if(m_mtCurrentMusic  == MT_LIGHT ){
#line 382 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(fFussScore  >= m_fScoreHeavy ){
#line 384 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_mtCurrentMusic  = MT_HEAVY ;
#line 386 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else if(fFussScore  >= m_fScoreMedium ){
#line 388 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_mtCurrentMusic  = MT_MEDIUM ;
#line 389 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 390 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 393 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
if(m_mtCurrentMusic  == MT_LIGHT ){
#line 394 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_tmFade  = 2.0f;
#line 395 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else if(m_mtCurrentMusic  == MT_MEDIUM ){
#line 396 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_tmFade  = 1.0f;
#line 397 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else if(m_mtCurrentMusic  == MT_HEAVY ){
#line 398 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_tmFade  = 1.0f;
#line 399 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}else if(m_mtCurrentMusic  == MT_EVENT  || m_mtCurrentMusic  == MT_CONTINUOUS ){
#line 400 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
m_tmFade  = 0.5f;
#line 401 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}
#line 404 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CrossFadeOneChannel  (MT_LIGHT );
#line 405 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CrossFadeOneChannel  (MT_MEDIUM );
#line 406 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CrossFadeOneChannel  (MT_HEAVY );
#line 407 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CrossFadeOneChannel  (MT_EVENT );
#line 408 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
CrossFadeOneChannel  (MT_CONTINUOUS );Jump(STATE_CURRENT,0x00de0007, FALSE, EInternal());return TRUE;
#line 409 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
}BOOL CMusicHolder::H0x00de0008_Main_08(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00de0008

#line 410 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
Return(STATE_CURRENT,EVoid());
#line 410 "C:/MyMod/Sources/EntitiesMP/MusicHolder.es"
return TRUE; ASSERT(FALSE); return TRUE;};