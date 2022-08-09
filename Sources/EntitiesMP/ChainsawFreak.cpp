/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"

#include "StdH.h"
#include "ModelsMP/Enemies/ChainSawFreak/Freak.h"
#include "ModelsMP/Enemies/ChainSawFreak/Saw.h"

#include <EntitiesMP/ChainsawFreak.h>
#include <EntitiesMP/ChainsawFreak_tables.h>
#line 11 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"

#define FREAK_SIZE 1.05f
  
// info structure
static EntityInfo eiChainsawFreak = {
  EIBT_FLESH, 350.0f,
  0.0f, 2.5f*FREAK_SIZE, 0.0f,     // source (eyes)
  0.0f, 1.5f*FREAK_SIZE, 0.0f,     // target (body)
};

#define HIT_DISTANCE 4.0f

void CChainsawFreak::SetDefaultProperties(void) {
  m_bRunAttack = FALSE ;
  m_bSawHit = FALSE ;
  m_penLastTouched = NULL;
  m_soFeet.SetOwner(this);
m_soFeet.Stop_internal();
  m_bRunSoundPlaying = FALSE ;
  m_iRunType = 0;
  m_bAttacking = FALSE ;
  m_fSightSoundBegin = 0.0f;
  CEnemyRunInto::SetDefaultProperties();
}
  CTString CChainsawFreak::GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath) 
#line 60 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
{
#line 61 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
CTString str ;
#line 62 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
str  . PrintF  (TRANS  ("Chainsaw freak dismembered %s") , strPlayerName );
#line 63 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
return str ;
#line 64 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 66 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::Precache(void) {
#line 67 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
CEnemyBase  :: Precache  ();
#line 68 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PrecacheSound  (SOUND_IDLE );
#line 69 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PrecacheSound  (SOUND_RUN );
#line 71 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PrecacheSound  (SOUND_ATTACK );
#line 72 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PrecacheSound  (SOUND_WOUND );
#line 73 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PrecacheSound  (SOUND_DEATH );
#line 74 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PrecacheSound  (SOUND_SIGHT );
#line 75 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 78 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void * CChainsawFreak::GetEntityInfo(void) {
#line 79 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
return & eiChainsawFreak ;
#line 80 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 82 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
FLOAT CChainsawFreak::GetCrushHealth(void) 
#line 83 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
{
#line 84 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
return 60.0f;
#line 85 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  const CTFileName & CChainsawFreak::GetComputerMessageName(void)const {
#line 88 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
static DECLARE_CTFILENAME  (fnm  , "DataMP\\Messages\\Enemies\\ChainsawFreak.txt");
#line 89 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
return fnm ;
#line 90 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 99 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 100 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection) 
#line 101 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
{
#line 103 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(! IsOfClass  (penInflictor  , "ChainsawFreak")){
#line 104 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
CEnemyBase  :: ReceiveDamage  (penInflictor  , dmtType  , fDamageAmmount  , vHitPoint  , vDirection );
#line 105 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 106 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 108 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::AdjustDifficulty(void) 
#line 109 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
{
#line 111 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 114 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
INDEX CChainsawFreak::AnimForDeath(void) {
#line 115 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
INDEX iAnim ;
#line 116 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(en_vCurrentTranslationAbsolute  . Length  () > 5.0f){
#line 117 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
iAnim  = FREAK_ANIM_DEATHRUN ;
#line 118 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}else {
#line 119 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
iAnim  = FREAK_ANIM_DEATHSTAND ;
#line 120 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 121 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
ChangeCollisionBoxIndexWhenPossible  (FREAK_COLLISION_BOX_DEATHRUN );
#line 122 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StartModelAnim  (iAnim  , 0);
#line 123 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_bAttacking  = FALSE ;
#line 124 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
DeactivateRunningSound  ();
#line 125 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
return iAnim ;
#line 126 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 128 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
FLOAT CChainsawFreak::WaitForDust(FLOAT3D & vStretch) {
#line 129 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(GetModelObject  () -> GetAnim  () == FREAK_ANIM_DEATHRUN )
#line 130 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
{
#line 131 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vStretch  = FLOAT3D (1 , 1 , 2) * 1.0f;
#line 132 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
return 0.65f;
#line 133 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 134 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
else if(GetModelObject  () -> GetAnim  () == FREAK_ANIM_DEATHSTAND )
#line 135 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
{
#line 136 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vStretch  = FLOAT3D (1 , 1 , 2) * 1.5f;
#line 137 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
return 0.72f;
#line 138 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 139 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
return - 1.0f;
#line 140 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 142 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::DeathNotify() {
#line 143 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
ChangeCollisionBoxIndexWhenPossible  (FREAK_COLLISION_BOX_DEATH );
#line 144 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetCollisionFlags  (ECF_MODEL );
#line 145 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 148 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::StandingAnim(void) {
#line 149 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StartModelAnim  (FREAK_ANIM_IDLE  , AOF_LOOPING  | AOF_NORESTART );
#line 151 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 152 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::WalkingAnim(void) {
#line 153 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StartModelAnim  (FREAK_ANIM_WALK  , AOF_LOOPING  | AOF_NORESTART );
#line 155 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 156 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::RunningAnim(void) {
#line 157 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
switch(m_iRunType )
#line 158 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
{
#line 159 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
case 0: 
#line 160 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StartModelAnim  (FREAK_ANIM_ATTACKRUN  , AOF_LOOPING  | AOF_NORESTART );
#line 161 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
break ;
#line 162 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
case 1: 
#line 163 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StartModelAnim  (FREAK_ANIM_ATTACKRUNFAR  , AOF_LOOPING  | AOF_NORESTART );
#line 164 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
break ;
#line 165 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
case 2: 
#line 166 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StartModelAnim  (FREAK_ANIM_ATTACKCHARGE  , AOF_LOOPING  | AOF_NORESTART );
#line 167 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
break ;
#line 168 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
default  : 
#line 169 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
ASSERTALWAYS  ("Unknown Chainsaw freak run type!");
#line 170 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 172 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 173 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::ChargeAnim(void) {
#line 174 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StartModelAnim  (FREAK_ANIM_RUNSLASHING  , AOF_LOOPING  | AOF_NORESTART );
#line 175 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 176 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::RotatingAnim(void) {
#line 177 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_iRunType  = IRnd  () % 3;
#line 178 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StartModelAnim  (FREAK_ANIM_ATTACKSTART  , AOF_LOOPING  | AOF_NORESTART );
#line 179 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 182 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::IdleSound(void) {
#line 183 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PlaySound  (m_soSound  , SOUND_IDLE  , SOF_3D );
#line 184 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 188 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::WoundSound(void) {
#line 189 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PlaySound  (m_soSound  , SOUND_WOUND  , SOF_3D );
#line 190 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 191 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::DeathSound(void) {
#line 192 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PlaySound  (m_soSound  , SOUND_DEATH  , SOF_3D );
#line 193 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 196 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::ActivateRunningSound(void) 
#line 197 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
{
#line 198 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(! m_bRunSoundPlaying ){
#line 199 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PlaySound  (m_soFeet  , SOUND_RUN  , SOF_3D  | SOF_LOOP );
#line 200 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_bRunSoundPlaying  = TRUE ;
#line 201 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 202 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 203 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::DeactivateRunningSound(void) 
#line 204 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
{
#line 205 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_soFeet  . Stop  ();
#line 206 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_bRunSoundPlaying  = FALSE ;
#line 207 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 214 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::LiveEntityTouched(ETouch etouch) {
#line 215 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(m_penLastTouched  != etouch  . penOther  || _pTimer  -> CurrentTick  () >= m_fLastTouchedTime  + 0.25f){
#line 217 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
FLOAT3D vDirection  = en_vCurrentTranslationAbsolute ;
#line 218 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vDirection  . Normalize  ();
#line 219 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
ANGLE aHitAngle  = FLOAT3D (etouch  . plCollision ) % vDirection ;
#line 221 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(aHitAngle  < 0.0f){
#line 223 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(! IsOfSameClass  (this  , etouch  . penOther )){
#line 224 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
IncreaseKickedMass  (etouch  . penOther );
#line 225 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 226 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PlaySound  (m_soSound  , SOUND_ATTACK  , SOF_3D );
#line 228 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_penLastTouched  = etouch  . penOther ;
#line 229 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fLastTouchedTime  = _pTimer  -> CurrentTick  ();
#line 231 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
FLOAT3D vDirection  = m_penEnemy  -> GetPlacement  () . pl_PositionVector  - GetPlacement  () . pl_PositionVector ;
#line 232 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vDirection  . Normalize  ();
#line 233 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
InflictDirectDamage  (etouch  . penOther  , this  , DMT_CHAINSAW  , - aHitAngle  * 40.0f , 
#line 234 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
FLOAT3D (0 , 0 , 0) , vDirection );
#line 236 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
FLOAT3D vSpeed  = - FLOAT3D (etouch  . plCollision );
#line 237 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vSpeed  = vSpeed  * 10.0f;
#line 238 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
const FLOATmatrix3D & m  = GetRotationMatrix  ();
#line 239 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
FLOAT3D vSpeedRel  = vSpeed  * ! m ;
#line 240 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(vSpeedRel  (1) < - 0.1f){
#line 241 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vSpeedRel  (1) -= 5.0f;
#line 242 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}else {
#line 243 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vSpeedRel  (1) += 5.0f;
#line 244 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 245 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vSpeedRel  (2) = 5.0f;
#line 247 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vSpeed  = vSpeedRel  * m ;
#line 248 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
KickEntity  (etouch  . penOther  , vSpeed );
#line 249 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 250 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 251 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 254 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
BOOL CChainsawFreak::HigherMass(void) {
#line 255 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
return (m_fMassKicked  > 500.0f);
#line 256 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 259 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::EnemyPostInit(void) 
#line 260 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
{
#line 262 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_soFeet  . Set3DParameters  (500.0f , 50.0f , 1.0f , 1.0f);
#line 263 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_bRunSoundPlaying  = FALSE ;
#line 264 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_soSound  . Set3DParameters  (160.0f , 50.0f , 1.0f , 1.0f);
#line 265 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
  
#line 267 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
void CChainsawFreak::PreMoving() {
#line 268 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(! m_bRunSoundPlaying  && _pTimer  -> CurrentTick  () > m_fSightSoundBegin  + 2.0f && m_bAttacking )
#line 269 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
{
#line 270 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
ActivateRunningSound  ();
#line 271 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 272 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
CEnemyBase  :: PreMoving  ();
#line 273 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
BOOL CChainsawFreak::
#line 280 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
Hit(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CChainsawFreak_Hit
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CChainsawFreak::Hit expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 281 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(!(CalcDist  (m_penEnemy ) < HIT_DISTANCE )){ Jump(STATE_CURRENT,0x01560009, FALSE, EInternal());return TRUE;}
#line 283 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StartModelAnim  (FREAK_ANIM_ATTACKSLASH  , 0);
#line 285 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
FLOAT3D vDir  = (m_penEnemy  -> GetPlacement  () . pl_PositionVector  - 
#line 286 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
GetPlacement  () . pl_PositionVector ) . Normalize  ();
#line 287 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vDir  *= ! GetRotationMatrix  ();
#line 288 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vDir  *= m_fCloseRunSpeed  * 1.5f;
#line 289 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vDir  (2) = 1.0f;
#line 291 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
GiveImpulseTranslationRelative  (vDir );
#line 294 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_bSawHit  = FALSE ;
#line 295 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetTimerAfter(0.4f);
Jump(STATE_CURRENT, 0x01560001, FALSE, EBegin());return TRUE;}BOOL CChainsawFreak::H0x01560001_Hit_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01560001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01560002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CChainsawFreak::H0x01560002_Hit_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01560002
;
#line 296 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PlaySound  (m_soSound  , SOUND_ATTACK  , SOF_3D );
#line 297 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(CalcDist  (m_penEnemy ) < HIT_DISTANCE ){m_bSawHit  = TRUE ;}
#line 298 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x01560003, FALSE, EBegin());return TRUE;}BOOL CChainsawFreak::H0x01560003_Hit_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01560003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01560004, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CChainsawFreak::H0x01560004_Hit_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01560004
;
#line 299 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(CalcDist  (m_penEnemy ) < HIT_DISTANCE ){m_bSawHit  = TRUE ;}
#line 300 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x01560005, FALSE, EBegin());return TRUE;}BOOL CChainsawFreak::H0x01560005_Hit_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01560005
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01560006, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CChainsawFreak::H0x01560006_Hit_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01560006
;
#line 301 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(CalcDist  (m_penEnemy ) < HIT_DISTANCE ){m_bSawHit  = TRUE ;}
#line 302 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(m_bSawHit ){
#line 303 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
FLOAT3D vDirection  = m_penEnemy  -> GetPlacement  () . pl_PositionVector  - GetPlacement  () . pl_PositionVector ;
#line 304 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vDirection  . Normalize  ();
#line 305 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
InflictDirectDamage  (m_penEnemy  , this  , DMT_CHAINSAW  , 20.0f , FLOAT3D (0 , 0 , 0) , vDirection );
#line 307 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vDirection  = vDirection  * 10.0f;
#line 309 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
FLOATmatrix3D mDirection ;
#line 310 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
MakeRotationMatrixFast  (mDirection  , ANGLE3D (0.0f , 30.0f , 0.0f));
#line 311 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
vDirection  = vDirection  * mDirection ;
#line 312 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
KickEntity  (m_penEnemy  , vDirection );
#line 313 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 314 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetTimerAfter(0.6f);
Jump(STATE_CURRENT, 0x01560007, FALSE, EBegin());return TRUE;}BOOL CChainsawFreak::H0x01560007_Hit_07(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01560007
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01560008, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CChainsawFreak::H0x01560008_Hit_08(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01560008
;Jump(STATE_CURRENT,0x01560009, FALSE, EInternal());return TRUE;}BOOL CChainsawFreak::H0x01560009_Hit_09(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01560009

#line 318 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fShootTime  = _pTimer  -> CurrentTick  () + 0.5f;
#line 319 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
Return(STATE_CURRENT,EReturn  ());
#line 319 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CChainsawFreak::
#line 322 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
AttackEnemy(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CChainsawFreak_AttackEnemy
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CChainsawFreak::AttackEnemy expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 323 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_bAttacking  = TRUE ;
#line 324 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PlaySound  (m_soSound  , SOUND_SIGHT  , SOF_3D  | SOF_SMOOTHCHANGE );
#line 325 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fSightSoundBegin  = _pTimer  -> CurrentTick  ();
#line 326 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_AttackEnemy, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};BOOL CChainsawFreak::
#line 329 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
BeIdle(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CChainsawFreak_BeIdle
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CChainsawFreak::BeIdle expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 330 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_bAttacking  = FALSE ;
#line 331 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
DeactivateRunningSound  ();
#line 332 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_BeIdle, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};BOOL CChainsawFreak::
#line 336 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
PostRunAwayFromEnemy(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CChainsawFreak_PostRunAwayFromEnemy
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CChainsawFreak::PostRunAwayFromEnemy expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 337 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StartModelAnim  (FREAK_ANIM_ATTACKRUNFAR  , 0);
#line 338 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetTimerAfter(0.25f);
Jump(STATE_CURRENT, 0x0156000d, FALSE, EBegin());return TRUE;}BOOL CChainsawFreak::H0x0156000d_PostRunAwayFromEnemy_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0156000d
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0156000e, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CChainsawFreak::H0x0156000e_PostRunAwayFromEnemy_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0156000e
;
#line 339 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetDesiredTranslation  (FLOAT3D (0 , 0 , 0));
#line 340 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StartModelAnim  (FREAK_ANIM_IDLE  , 0);
#line 341 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetTimerAfter(0.25f);
Jump(STATE_CURRENT, 0x0156000f, FALSE, EBegin());return TRUE;}BOOL CChainsawFreak::H0x0156000f_PostRunAwayFromEnemy_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0156000f
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01560010, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CChainsawFreak::H0x01560010_PostRunAwayFromEnemy_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01560010
;
#line 342 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
Return(STATE_CURRENT,EReturn  ());
#line 342 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CChainsawFreak::
#line 348 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CChainsawFreak_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CChainsawFreak::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 350 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
InitAsModel  ();
#line 351 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetPhysicsFlags  (EPF_MODEL_WALKING );
#line 352 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetCollisionFlags  (ECF_MODEL );
#line 353 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetFlags  (GetFlags  () | ENF_ALIVE );
#line 354 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetHealth  (175.0f);
#line 355 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fMaxHealth  = 175.0f;
#line 356 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
en_fDensity  = 2000.0f;
#line 358 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetModel  (MODEL_FREAK );
#line 359 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
SetModelMainTexture  (TEXTURE_FREAK );
#line 360 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
AddAttachment  (FREAK_ATTACHMENT_CHAINSAW  , MODEL_CHAINSAW  , TEXTURE_CHAINSAW );
#line 361 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
StandingAnim  ();
#line 363 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fWalkSpeed  = FRnd  () + 2.5f;
#line 364 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_aWalkRotateSpeed  = AngleDeg  (FRnd  () * 25.0f + 45.0f);
#line 365 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fAttackRunSpeed  = FRnd  () * 2.0f + 13.0f;
#line 366 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fAttackRotateRunInto  = AngleDeg  (FRnd  () * 30 + 50.0f);
#line 367 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_aAttackRotateSpeed  = m_fAttackRotateRunInto ;
#line 368 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fCloseRunSpeed  = FRnd  () + 10.5f;
#line 369 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_aCloseRotateSpeed  = AngleDeg  (FRnd  () * 50 + 250.0f);
#line 371 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fAttackDistance  = 50.0f;
#line 372 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fCloseDistance  = 7.0f;
#line 373 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fStopDistance  = 0.0f;
#line 374 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fAttackFireTime  = 0.05f;
#line 375 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fCloseFireTime  = 1.0f;
#line 376 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fIgnoreRange  = 150.0f;
#line 378 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fBlowUpAmount  = 1E10f;
#line 379 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fBodyParts  = 6;
#line 380 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fDamageWounded  = 100000.0f;
#line 381 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_iScore  = 1500;
#line 382 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
if(m_fStepHeight  == - 1){
#line 383 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fStepHeight  = 4.0f;
#line 384 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
}
#line 385 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fStopApproachDistance  = 0.0f;
#line 386 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
ASSERT  (m_fStopApproachDistance  < m_fCloseDistance );
#line 387 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_bUseChargeAnimation  = TRUE ;
#line 388 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fChargeDistance  = 20.0f;
#line 389 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_fInertionRunTime  = 0.15f;
#line 390 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_iRunType  = IRnd  () % 3;
#line 392 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
GetModelObject  () -> StretchModel  (FLOAT3D (FREAK_SIZE  , FREAK_SIZE  , FREAK_SIZE ));
#line 393 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
ModelChangeNotify  ();
#line 395 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
m_bAttacking  = FALSE ;
#line 398 "C:/MyMod/Sources/EntitiesMP/ChainsawFreak.es"
Jump(STATE_CURRENT, STATE_CEnemyRunInto_MainLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};