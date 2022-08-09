/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/BigHead.es"

#include "StdH.h"
#include "ModelsMP/Enemies/Mental/Mental.h"

#include <EntitiesMP/BigHead.h>
#include <EntitiesMP/BigHead_tables.h>
#line 16 "C:/MyMod/Sources/EntitiesMP/BigHead.es"

// info structure
static EntityInfo eiMental = {
  EIBT_FLESH, 200.0f,
  0.0f, 1.5f, 0.0f,     // source (eyes)
  0.0f, 1.0f, 0.0f,     // target (body)
};

#define GREET_SENSE_RANGE 10.0f
#define GREET_SENSE_DELAY 30.0f


void CBigHead::SetDefaultProperties(void) {
  m_fnmHeadTex = CTString("");
  m_fnmNameSnd = CTString("");
  m_tmLastGreetTime = -100.0f;
  m_bhtType = BHT_NORMAL ;
  m_bIgnorePlayer = FALSE ;
  m_bPlayingWalkSound = FALSE ;
  m_bSleeping = FALSE ;
  m_tmLastWalkingSoundTime = -100.0f;
  m_tmWalkingSound = 5.0f;
  CEnemyBase::SetDefaultProperties();
}
  
#line 72 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
BOOL CBigHead::HandleEvent(const CEntityEvent & ee) 
#line 73 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
{
#line 74 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(m_bIgnorePlayer ){
#line 75 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(ee  . ee_slEvent  == EVENTCODE_ETouch ){
#line 76 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
ETouch  & et  = (ETouch  &) ee ;
#line 77 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(IsOfClass  (et  . penOther  , "Player")){
#line 78 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return TRUE ;
#line 79 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 80 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 81 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 82 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return CEnemyBase  :: HandleEvent  (ee );
#line 83 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 86 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void * CBigHead::GetEntityInfo(void) 
#line 87 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
{
#line 88 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return & eiMental ;
#line 89 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 91 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void CBigHead::Precache(void) 
#line 92 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
{
#line 93 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
CEnemyBase  :: Precache  ();
#line 94 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_SIGHT );
#line 95 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_IDLE );
#line 96 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_WOUND );
#line 97 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_DEATH );
#line 98 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_WALKZOMBIE );
#line 99 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PrecacheSound  (SOUND_WALKSAINT );
#line 100 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_aps  . Precache  (m_fnmNameSnd );
#line 101 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_apt  . Precache  (m_fnmHeadTex );
#line 102 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 104 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
INDEX CBigHead::GetWalkAnim(void) 
#line 105 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
{
#line 106 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(m_bhtType  == BHT_ZOMBIE ){
#line 107 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return MENTAL_ANIM_WALKZOMBIE ;
#line 108 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}else if(m_bhtType  == BHT_SAINT ){
#line 109 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return MENTAL_ANIM_WALKANGEL ;
#line 110 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}else {
#line 111 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return MENTAL_ANIM_RUN ;
#line 112 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 113 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 116 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
INDEX CBigHead::AnimForDamage(FLOAT fDamage) {
#line 117 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
INDEX iAnim ;
#line 118 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
iAnim  = MENTAL_ANIM_PANIC ;
#line 119 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (iAnim  , 0);
#line 120 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return iAnim ;
#line 121 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 124 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
INDEX CBigHead::AnimForDeath(void) {
#line 125 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
INDEX iAnim ;
#line 126 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
iAnim  = MENTAL_ANIM_DEATH ;
#line 127 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (iAnim  , 0);
#line 128 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return iAnim ;
#line 129 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 131 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void CBigHead::DeathNotify(void) {
#line 133 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
en_fDensity  = 500.0f;
#line 134 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 137 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void CBigHead::StandingAnim(void) {
#line 138 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (MENTAL_ANIM_GROUNDREST  , AOF_LOOPING  | AOF_NORESTART );
#line 139 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 140 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void CBigHead::WalkingAnim(void) {
#line 141 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PlayWalkSound  ();
#line 142 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (GetWalkAnim  () , AOF_LOOPING  | AOF_NORESTART );
#line 144 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(! m_bIgnorePlayer  && _pTimer  -> CurrentTick  () > m_tmLastGreetTime  + GREET_SENSE_DELAY ){
#line 145 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fSenseRange  = GREET_SENSE_RANGE ;
#line 146 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bDeaf  = FALSE ;
#line 147 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 148 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 149 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void CBigHead::RunningAnim(void) 
#line 150 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
{
#line 151 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PlayWalkSound  ();
#line 152 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (GetWalkAnim  () , AOF_LOOPING  | AOF_NORESTART );
#line 153 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 154 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void CBigHead::RotatingAnim(void) {
#line 155 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
RunningAnim  ();
#line 156 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 158 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void CBigHead::PlayWalkSound(void) 
#line 159 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
{
#line 160 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
INDEX iSound  = SOUND_WALKZOMBIE ;
#line 161 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(m_bhtType  == BHT_ZOMBIE ){
#line 162 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
iSound  = SOUND_WALKZOMBIE ;
#line 163 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}else if(m_bhtType  == BHT_SAINT ){
#line 164 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
iSound  = SOUND_WALKSAINT ;
#line 165 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}else {
#line 166 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return ;
#line 167 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 168 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(! m_bPlayingWalkSound  || _pTimer  -> CurrentTick  () - m_tmLastWalkingSoundTime  > m_tmWalkingSound ){
#line 169 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = TRUE ;
#line 170 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_tmLastWalkingSoundTime  = _pTimer  -> CurrentTick  ();
#line 171 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , iSound  , SOF_3D );
#line 172 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 173 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 176 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void CBigHead::IdleSound(void) {
#line 177 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(m_bIgnorePlayer ){
#line 178 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return ;
#line 179 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 180 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , SOUND_IDLE  , SOF_3D );
#line 181 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = FALSE ;
#line 182 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 184 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void CBigHead::SightSound(void) {
#line 185 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , SOUND_SIGHT  , SOF_3D );
#line 186 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = FALSE ;
#line 187 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 188 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void CBigHead::WoundSound(void) {
#line 189 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , SOUND_WOUND  , SOF_3D );
#line 190 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = FALSE ;
#line 191 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
  
#line 192 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
void CBigHead::DeathSound(void) {
#line 193 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , SOUND_DEATH  , SOF_3D );
#line 194 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = FALSE ;
#line 195 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
BOOL CBigHead::
#line 198 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
Fire(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBigHead_Fire
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBigHead::Fire expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 200 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(!(CalcDist  (m_penEnemy ) <= m_fStopDistance  * 1.1f)){ Jump(STATE_CURRENT,0x01540003, FALSE, EInternal());return TRUE;}
#line 201 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(m_fnmNameSnd  != ""){
#line 202 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PlaySound  (m_soSound  , m_fnmNameSnd  , SOF_3D );
#line 203 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bPlayingWalkSound  = FALSE ;
#line 204 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 205 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bBlind  = TRUE ;
#line 206 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bDeaf  = TRUE ;
#line 207 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fSenseRange  = 0.0f;
#line 208 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_tmLastGreetTime  = _pTimer  -> CurrentTick  ();
#line 209 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SetTargetNone  ();
#line 210 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (MENTAL_ANIM_GREET  , 0);
#line 211 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SetTimerAfter(GetModelObject  () -> GetCurrentAnimLength  ());
Jump(STATE_CURRENT, 0x01540001, FALSE, EBegin());return TRUE;}BOOL CBigHead::H0x01540001_Fire_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01540002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBigHead::H0x01540002_Fire_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540002
;
#line 212 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
StandingAnim  ();
#line 213 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
Return(STATE_CURRENT,EReconsiderBehavior  ());
#line 213 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return TRUE;Jump(STATE_CURRENT,0x01540003, FALSE, EInternal());return TRUE;}BOOL CBigHead::H0x01540003_Fire_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540003

#line 215 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
Return(STATE_CURRENT,EReturn  ());
#line 215 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CBigHead::
#line 218 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
Sleep(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBigHead_Sleep
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBigHead::Sleep expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 221 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (MENTAL_ANIM_SNORE  , AOF_LOOPING );
#line 223 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x01540005, FALSE, EBegin());return TRUE;}BOOL CBigHead::H0x01540005_Sleep_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540005
switch(__eeInput.ee_slEvent){case(EVENTCODE_ETrigger):{const ETrigger&eTrigger= (ETrigger&)__eeInput;

#line 229 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
Jump(STATE_CURRENT, STATE_CBigHead_WakeUp, TRUE, EVoid());return TRUE;
#line 230 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}ASSERT(FALSE);break;default:{
#line 238 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return TRUE;
#line 239 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}ASSERT(FALSE);break;
#line 240 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}return TRUE;}BOOL CBigHead::H0x01540006_Sleep_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540006
 ASSERT(FALSE); return TRUE;};BOOL CBigHead::
#line 243 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
WakeUp(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBigHead_WakeUp
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBigHead::WakeUp expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 246 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SightSound  ();
#line 247 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
StartModelAnim  (MENTAL_ANIM_GETUP  , 0);
#line 248 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SetTimerAfter(GetModelObject  () -> GetCurrentAnimLength  ());
Jump(STATE_CURRENT, 0x01540008, FALSE, EBegin());return TRUE;}BOOL CBigHead::H0x01540008_WakeUp_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540008
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01540009, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBigHead::H0x01540009_WakeUp_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01540009
;
#line 253 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
Return(STATE_CURRENT,EReturn  ());
#line 253 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CBigHead::
#line 257 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
PreMainLoop(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBigHead_PreMainLoop
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBigHead::PreMainLoop expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 260 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(!(m_bSleeping )){ Jump(STATE_CURRENT,0x0154000d, FALSE, EInternal());return TRUE;}
#line 261 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bSleeping  = FALSE ;
#line 263 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x0154000b, FALSE, EBegin());return TRUE;}BOOL CBigHead::H0x0154000b_PreMainLoop_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0154000b
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 265 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
Call(STATE_CURRENT, STATE_CBigHead_Sleep, TRUE, EVoid());return TRUE;
#line 266 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}ASSERT(FALSE);break;case(EVENTCODE_EReturn):{const EReturn&e= (EReturn&)__eeInput;

#line 268 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
UnsetTimer();Jump(STATE_CURRENT,0x0154000c, FALSE, EInternal());return TRUE;
#line 269 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}ASSERT(FALSE);break;case(EVENTCODE_EDeath):{const EDeath&eDeath= (EDeath&)__eeInput;

#line 273 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_Die, FALSE, eDeath );return TRUE;
#line 274 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 275 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}return TRUE;}BOOL CBigHead::H0x0154000c_PreMainLoop_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0154000c
Jump(STATE_CURRENT,0x0154000d, FALSE, EInternal());return TRUE;}BOOL CBigHead::H0x0154000d_PreMainLoop_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0154000d

#line 277 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
Return(STATE_CURRENT,EReturn  ());
#line 277 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CBigHead::
#line 283 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBigHead_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBigHead::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 285 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
InitAsModel  ();
#line 286 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SetPhysicsFlags  (EPF_MODEL_WALKING  | EPF_HASLUNGS );
#line 287 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SetCollisionFlags  (ECF_MODEL );
#line 288 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SetFlags  (GetFlags  () | ENF_ALIVE );
#line 289 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SetHealth  (20.0f);
#line 290 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fMaxHealth  = 20.0f;
#line 291 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
en_tmMaxHoldBreath  = 5.0f;
#line 292 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
en_fDensity  = 2000.0f;
#line 293 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fBlowUpSize  = 2.0f;
#line 296 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SetModel  (MODEL_MENTAL );
#line 297 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
SetModelMainTexture  (TEXTURE_MENTAL );
#line 298 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
AddAttachment  (0 , MODEL_HEAD  , TEXTURE_MENTAL );
#line 299 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(m_fnmHeadTex  != ""){
#line 301 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
try {
#line 302 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
CAttachmentModelObject  * pamoHead  = GetModelObject  () -> GetAttachmentModel  (0);
#line 303 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(pamoHead  != NULL ){
#line 304 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
pamoHead  -> amo_moModelObject  . mo_toTexture  . SetData_t  (m_fnmHeadTex );
#line 305 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 307 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}catch  (char  * strError ){
#line 309 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
CPrintF  ("%s\n" , strError );
#line 310 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
AddAttachment  (0 , MODEL_HEAD  , TEXTURE_MENTAL );
#line 311 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 312 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 313 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(m_bhtType  == BHT_ZOMBIE ){
#line 314 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
AddAttachment  (MENTAL_ATTACHMENT_HORNS  , MODEL_HORNS  , TEXTURE_HORNS );
#line 315 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}else if(m_bhtType  == BHT_SAINT ){
#line 316 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
AddAttachment  (MENTAL_ATTACHMENT_AURA  , MODEL_AURA  , TEXTURE_AURA );
#line 317 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 320 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fWalkSpeed  = FRnd  () + 1.5f;
#line 321 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_aWalkRotateSpeed  = AngleDeg  (FRnd  () * 10.0f + 500.0f);
#line 322 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fAttackRunSpeed  = FRnd  () * 2.0f + 6.0f;
#line 323 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_aAttackRotateSpeed  = AngleDeg  (FRnd  () * 50 + 245.0f);
#line 324 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fCloseRunSpeed  = FRnd  () * 2.0f + 6.0f;
#line 325 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_aCloseRotateSpeed  = AngleDeg  (FRnd  () * 50 + 245.0f);
#line 327 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fAttackDistance  = 50.0f;
#line 328 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fCloseDistance  = 0.0f;
#line 329 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fStopDistance  = 5.0f;
#line 330 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fAttackFireTime  = 0.1f;
#line 331 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fCloseFireTime  = 0.1f;
#line 332 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fIgnoreRange  = 200.0f;
#line 334 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fBlowUpAmount  = 65.0f;
#line 335 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fBodyParts  = 4;
#line 336 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fDamageWounded  = 1.0f;
#line 337 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_iScore  = 0;
#line 338 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
if(m_bIgnorePlayer ){
#line 339 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bBlind  = TRUE ;
#line 340 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bDeaf  = TRUE ;
#line 341 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fSenseRange  = 0;
#line 342 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}else {
#line 343 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_bBlind  = TRUE ;
#line 344 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
m_fSenseRange  = GREET_SENSE_RANGE ;
#line 345 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
}
#line 348 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
const FLOAT fSize  = 0.6f;
#line 349 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
GetModelObject  () -> StretchModel  (FLOAT3D (fSize  , fSize  , fSize ));
#line 350 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
ModelChangeNotify  ();
#line 351 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
StandingAnim  ();
#line 354 "C:/MyMod/Sources/EntitiesMP/BigHead.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_MainLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};