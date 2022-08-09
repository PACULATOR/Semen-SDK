/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/Guffy.es"

#include "StdH.h"
#include "ModelsMP/Enemies/Guffy/Guffy.h"

#include <EntitiesMP/Guffy.h>
#include <EntitiesMP/Guffy_tables.h>
#line 11 "C:/MyMod/Sources/EntitiesMP/Guffy.es"

// info structure
static EntityInfo eiGuffy = {
  EIBT_FLESH, 800.0f,
  0.0f, 1.9f, 0.0f,     // source (eyes)
  0.0f, 1.0f, 0.0f,     // target (body)
};

#define FIRE_LEFT_ARM   FLOAT3D(-0.56f, +1.125f, -1.32f)
#define FIRE_RIGHT_ARM  FLOAT3D(+0.50f, +1.060f, -0.82f)

//#define FIRE_DEATH_LEFT   FLOAT3D( 0.0f, 7.0f, -2.0f)
//#define FIRE_DEATH_RIGHT  FLOAT3D(3.75f, 4.2f, -2.5f)


void CGuffy::SetDefaultProperties(void) {
  m_iLoopCounter = 0;
  m_fSize = 1.0f;
  m_bWalkSoundPlaying = FALSE ;
  m_fThreatDistance = 5.0f;
  m_bEnemyToTheLeft = FALSE ;
  m_soFire1.SetOwner(this);
m_soFire1.Stop_internal();
  m_soFire2.SetOwner(this);
m_soFire2.Stop_internal();
  CEnemyBase::SetDefaultProperties();
}
  CTString CGuffy::GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath) 
#line 64 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
{
#line 65 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
CTString str ;
#line 66 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
str  . PrintF  (TRANS  ("Guffy gunned %s down") , strPlayerName );
#line 67 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
return str ;
#line 68 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  const CTFileName & CGuffy::GetComputerMessageName(void)const {
#line 71 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
static DECLARE_CTFILENAME  (fnmSoldier  , "DataMP\\Messages\\Enemies\\Guffy.txt");
#line 72 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
return fnmSoldier ;
#line 73 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 88 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::Precache(void) {
#line 89 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
CEnemyBase  :: Precache  ();
#line 92 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PrecacheModel  (MODEL_GUFFY );
#line 93 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PrecacheTexture  (TEXTURE_GUFFY );
#line 96 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PrecacheModel  (MODEL_GUN );
#line 97 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PrecacheTexture  (TEXTURE_GUN );
#line 100 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PrecacheSound  (SOUND_IDLE );
#line 101 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PrecacheSound  (SOUND_SIGHT );
#line 102 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PrecacheSound  (SOUND_DEATH );
#line 103 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PrecacheSound  (SOUND_FIRE );
#line 104 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PrecacheSound  (SOUND_WOUND );
#line 107 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PrecacheClass  (CLASS_PROJECTILE  , PRT_GUFFY_PROJECTILE );
#line 108 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 111 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void * CGuffy::GetEntityInfo(void) {
#line 112 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
return & eiGuffy ;
#line 113 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 124 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 125 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection) 
#line 126 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
{
#line 128 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
if(! IsOfClass  (penInflictor  , "Guffy")){
#line 129 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
CEnemyBase  :: ReceiveDamage  (penInflictor  , dmtType  , fDamageAmmount  , vHitPoint  , vDirection );
#line 130 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
#line 131 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 135 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::StandingAnim(void) {
#line 136 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
StartModelAnim  (GUFFY_ANIM_IDLE  , AOF_LOOPING  | AOF_NORESTART );
#line 137 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 142 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::RunningAnim(void) {
#line 143 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
StartModelAnim  (GUFFY_ANIM_RUN  , AOF_LOOPING  | AOF_NORESTART );
#line 144 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 145 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::WalkingAnim(void) {
#line 146 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
RunningAnim  ();
#line 147 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 148 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::RotatingAnim(void) {
#line 149 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
StartModelAnim  (GUFFY_ANIM_RUN  , AOF_LOOPING  | AOF_NORESTART );
#line 150 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 153 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::IdleSound(void) {
#line 154 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PlaySound  (m_soSound  , SOUND_IDLE  , SOF_3D );
#line 155 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 156 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::SightSound(void) {
#line 157 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PlaySound  (m_soSound  , SOUND_SIGHT  , SOF_3D );
#line 158 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 159 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::WoundSound(void) {
#line 160 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PlaySound  (m_soSound  , SOUND_WOUND  , SOF_3D );
#line 161 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 162 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::DeathSound(void) {
#line 163 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PlaySound  (m_soSound  , SOUND_DEATH  , SOF_3D );
#line 164 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 167 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::FireRocket(FLOAT3D & vPos) {
#line 168 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
CPlacement3D plRocket ;
#line 169 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
plRocket  . pl_PositionVector  = vPos ;
#line 170 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
plRocket  . pl_OrientationAngle  = ANGLE3D (0 , - 5.0f - FRnd  () * 10.0f , 0);
#line 171 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
plRocket  . RelativeToAbsolute  (GetPlacement  ());
#line 172 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
CEntityPointer penProjectile  = CreateEntity  (plRocket  , CLASS_PROJECTILE );
#line 173 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
ELaunchProjectile  eLaunch ;
#line 174 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
eLaunch  . penLauncher  = this ;
#line 175 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
eLaunch  . prtType  = PRT_GUFFY_PROJECTILE ;
#line 176 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
penProjectile  -> Initialize  (eLaunch );
#line 177 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 180 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
void CGuffy::EnemyPostInit(void) 
#line 181 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
{
#line 183 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_soSound  . Set3DParameters  (160.0f , 50.0f , 1.0f , 1.0f);
#line 184 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_soFire1  . Set3DParameters  (160.0f , 50.0f , 1.0f , 1.0f);
#line 185 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_soFire2  . Set3DParameters  (160.0f , 50.0f , 1.0f , 1.0f);
#line 186 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 189 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
INDEX CGuffy::AnimForDamage(FLOAT fDamage) {
#line 190 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
INDEX iAnim ;
#line 191 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
iAnim  = GUFFY_ANIM_WOUND ;
#line 192 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
StartModelAnim  (iAnim  , 0);
#line 193 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
return iAnim ;
#line 194 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 197 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
INDEX CGuffy::AnimForDeath(void) {
#line 198 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
INDEX iAnim ;
#line 199 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
FLOAT3D vFront ;
#line 200 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
GetHeadingDirection  (0 , vFront );
#line 201 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
FLOAT fDamageDir  = m_vDamage  % vFront ;
#line 202 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
if(fDamageDir  < 0){
#line 203 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
iAnim  = GUFFY_ANIM_DEATHBACKWARD ;
#line 204 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}else {
#line 205 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
iAnim  = GUFFY_ANIM_DEATHFORWARD ;
#line 206 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
#line 208 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
StartModelAnim  (iAnim  , 0);
#line 209 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
return iAnim ;
#line 210 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
  
#line 213 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
FLOAT CGuffy::WaitForDust(FLOAT3D & vStretch) {
#line 214 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
vStretch  = FLOAT3D (1 , 1 , 2) * 1.5f;
#line 215 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
if(GetModelObject  () -> GetAnim  () == GUFFY_ANIM_DEATHBACKWARD )
#line 216 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
{
#line 217 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
return 0.48f;
#line 218 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
#line 219 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
else if(GetModelObject  () -> GetAnim  () == GUFFY_ANIM_DEATHFORWARD )
#line 220 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
{
#line 221 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
return 1.0f;
#line 222 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
#line 223 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
return - 1.0f;
#line 224 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
BOOL CGuffy::
#line 230 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
Fire(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGuffy_Fire
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGuffy::Fire expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 232 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
StartModelAnim  (GUFFY_ANIM_FIRE  , AOF_LOOPING );
#line 235 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x01580001, FALSE, EBegin());return TRUE;}BOOL CGuffy::H0x01580001_Fire_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01580001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01580002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGuffy::H0x01580002_Fire_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01580002
;
#line 237 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
FLOATmatrix3D m ;
#line 238 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
FLOAT3D fLookRight  = FLOAT3D (1.0f , 0.0f , 0.0f);
#line 239 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
MakeRotationMatrixFast  (m  , GetPlacement  () . pl_OrientationAngle );
#line 240 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
fLookRight  = fLookRight  * m ;
#line 241 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
BOOL bEnemyRight  = fLookRight  % (m_penEnemy  -> GetPlacement  () . pl_PositionVector  - GetPlacement  () . pl_PositionVector );
#line 243 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
if(bEnemyRight  >= 0){
#line 244 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
ShootProjectile  (PRT_GUFFY_PROJECTILE  , FIRE_LEFT_ARM  * m_fSize  , ANGLE3D (0 , 0 , 0));
#line 245 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PlaySound  (m_soFire1  , SOUND_FIRE  , SOF_3D );
#line 247 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
ShootProjectile  (PRT_GUFFY_PROJECTILE  , FIRE_RIGHT_ARM  * m_fSize  , ANGLE3D (- 9 , 0 , 0));
#line 248 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PlaySound  (m_soFire2  , SOUND_FIRE  , SOF_3D );
#line 249 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}else {
#line 250 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
ShootProjectile  (PRT_GUFFY_PROJECTILE  , FIRE_LEFT_ARM  * m_fSize  , ANGLE3D (9 , 0 , 0));
#line 251 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PlaySound  (m_soFire1  , SOUND_FIRE  , SOF_3D );
#line 253 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
ShootProjectile  (PRT_GUFFY_PROJECTILE  , FIRE_RIGHT_ARM  * m_fSize  , ANGLE3D (0 , 0 , 0));
#line 254 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
PlaySound  (m_soFire2  , SOUND_FIRE  , SOF_3D );
#line 255 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
#line 257 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
SetTimerAfter(1.0f);
Jump(STATE_CURRENT, 0x01580003, FALSE, EBegin());return TRUE;}BOOL CGuffy::H0x01580003_Fire_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01580003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01580004, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGuffy::H0x01580004_Fire_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01580004
;
#line 259 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
StopMoving  ();
#line 261 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
MaybeSwitchToAnotherPlayer  ();
#line 264 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
StandingAnimFight  ();
#line 265 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
SetTimerAfter(FRnd  () * 0.25f + 0.25f);
Jump(STATE_CURRENT, 0x01580005, FALSE, EBegin());return TRUE;}BOOL CGuffy::H0x01580005_Fire_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01580005
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01580006, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGuffy::H0x01580006_Fire_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01580006
;
#line 267 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
Return(STATE_CURRENT,EReturn  ());
#line 267 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CGuffy::
#line 296 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGuffy_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGuffy::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 298 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
InitAsModel  ();
#line 299 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
SetPhysicsFlags  (EPF_MODEL_WALKING );
#line 300 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
SetCollisionFlags  (ECF_MODEL );
#line 301 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
SetFlags  (GetFlags  () | ENF_ALIVE );
#line 302 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
SetHealth  (210.0f);
#line 303 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fMaxHealth  = 210.0f;
#line 304 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
en_fDensity  = 2000.0f;
#line 307 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
SetModel  (MODEL_GUFFY );
#line 308 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fSize  = 1.5f;
#line 309 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
SetModelMainTexture  (TEXTURE_GUFFY );
#line 310 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
AddAttachment  (GUFFY_ATTACHMENT_GUNRIGHT  , MODEL_GUN  , TEXTURE_GUN );
#line 311 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
AddAttachment  (GUFFY_ATTACHMENT_GUNLEFT  , MODEL_GUN  , TEXTURE_GUN );
#line 312 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
GetModelObject  () -> StretchModel  (FLOAT3D (m_fSize  , m_fSize  , m_fSize ));
#line 313 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
ModelChangeNotify  ();
#line 314 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
CModelObject * pmoRight  = & GetModelObject  () -> GetAttachmentModel  (GUFFY_ATTACHMENT_GUNRIGHT ) -> amo_moModelObject ;
#line 315 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
pmoRight  -> StretchModel  (FLOAT3D (- 1 , 1 , 1));
#line 316 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fBlowUpAmount  = 10000.0f;
#line 317 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_iScore  = 3000;
#line 320 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
if(m_fStepHeight  == - 1){
#line 321 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fStepHeight  = 4.0f;
#line 322 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
}
#line 324 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
StandingAnim  ();
#line 326 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fWalkSpeed  = FRnd  () + 2.5f;
#line 327 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_aWalkRotateSpeed  = AngleDeg  (FRnd  () * 10.0f + 500.0f);
#line 328 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fAttackRunSpeed  = FRnd  () + 5.0f;
#line 329 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_aAttackRotateSpeed  = AngleDeg  (FRnd  () * 50 + 245.0f);
#line 330 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fCloseRunSpeed  = FRnd  () + 5.0f;
#line 331 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_aCloseRotateSpeed  = AngleDeg  (FRnd  () * 50 + 245.0f);
#line 333 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fAttackDistance  = 150.0f;
#line 334 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fCloseDistance  = 0.0f;
#line 335 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fStopDistance  = 25.0f;
#line 336 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fAttackFireTime  = 5.0f;
#line 337 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fCloseFireTime  = 5.0f;
#line 338 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fIgnoreRange  = 250.0f;
#line 340 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fBodyParts  = 5;
#line 341 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
m_fDamageWounded  = 100.0f;
#line 344 "C:/MyMod/Sources/EntitiesMP/Guffy.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_MainLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};