/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/Shooter.es"

#include "StdH.h"

#include <EntitiesMP/Shooter.h>
#include <EntitiesMP/Shooter_tables.h>
void CShooter::SetDefaultProperties(void) {
  m_fShootingPeriod = 1.0f;
  m_sftType = SFT_WOODEN_DART ;
  m_fHealth = 0.0f;
  m_fCannonBallSize = 1.0f;
  m_fCannonBallPower = 10.0f;
  m_iModelPreFireAnimation = 0;
  m_iTexturePreFireAnimation = 0;
  m_iModelPostFireAnimation = 0;
  m_iTexturePostFireAnimation = 0;
  m_fFlameBurstDuration = 1.0f;
  m_fRndBeginWait = 0.0f;
  m_penSoundLaunch = NULL;
  m_soLaunch.SetOwner(this);
m_soLaunch.Stop_internal();
  m_penFlame = NULL;
  m_bFiring = FALSE ;
  m_bIndestructable = FALSE ;
  m_tmFlameStart = 0.0f;
  CModelHolder2::SetDefaultProperties();
}
  
#line 57 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
void CShooter::Precache(void) {
#line 58 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CModelHolder2  :: Precache  ();
#line 59 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
PrecacheClass  (CLASS_PROJECTILE  , PRT_SHOOTER_WOODEN_DART );
#line 60 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
PrecacheClass  (CLASS_PROJECTILE  , PRT_SHOOTER_FIREBALL );
#line 61 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
PrecacheClass  (CLASS_CANNONBALL );
#line 62 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
  
#line 64 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
void CShooter::ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 65 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection) 
#line 66 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
{
#line 68 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(! m_bIndestructable  && ! IsOfClass  (penInflictor  , "Shooter")){
#line 69 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(m_tmSpraySpawned  <= _pTimer  -> CurrentTick  () - _pTimer  -> TickQuantum  * 8 
#line 70 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
&& m_penDestruction  != NULL ){
#line 72 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CModelDestruction  * penDestruction  = GetDestruction  ();
#line 75 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CPlacement3D plSpray  = CPlacement3D (vHitPoint  , ANGLE3D (0 , 0 , 0));
#line 76 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_penSpray  = CreateEntity  (plSpray  , CLASS_BLOOD_SPRAY );
#line 77 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_penSpray  -> SetParent  (this );
#line 78 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ESpawnSpray  eSpawnSpray ;
#line 79 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eSpawnSpray  . colBurnColor  = C_WHITE  | CT_OPAQUE ;
#line 82 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(fDamageAmmount  > 50.0f){
#line 83 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eSpawnSpray  . fDamagePower  = 3.0f;
#line 84 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}else if(fDamageAmmount  > 25.0f){
#line 85 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eSpawnSpray  . fDamagePower  = 2.0f;
#line 86 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}else {
#line 87 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eSpawnSpray  . fDamagePower  = 1.0f;
#line 88 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 91 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eSpawnSpray  . sptType  = penDestruction  -> m_sptType ;
#line 92 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eSpawnSpray  . fSizeMultiplier  = 1.0f;
#line 95 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FLOAT3D vDn  (- en_mRotation  (1 , 2) , - en_mRotation  (2 , 2) , - en_mRotation  (3 , 2));
#line 98 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FLOAT3D vHitPointRelative  = vHitPoint  - GetPlacement  () . pl_PositionVector ;
#line 99 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FLOAT3D vReflectingNormal ;
#line 100 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
GetNormalComponent  (vHitPointRelative  , vDn  , vReflectingNormal );
#line 101 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
vReflectingNormal  . Normalize  ();
#line 103 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
vReflectingNormal  (1) /= 5.0f;
#line 105 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FLOAT3D vProjectedComponent  = vReflectingNormal  * (vDirection  % vReflectingNormal );
#line 106 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FLOAT3D vSpilDirection  = vDirection  - vProjectedComponent  * 2.0f - vDn  * 0.5f;
#line 108 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eSpawnSpray  . vDirection  = vSpilDirection ;
#line 109 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eSpawnSpray  . penOwner  = this ;
#line 112 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_penSpray  -> Initialize  (eSpawnSpray );
#line 113 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_tmSpraySpawned  = _pTimer  -> CurrentTick  ();
#line 114 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 116 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CRationalEntity  :: ReceiveDamage  (penInflictor  , dmtType  , fDamageAmmount  , vHitPoint  , vDirection );
#line 117 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 118 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
  
#line 121 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
void CShooter::RenderParticles(void) 
#line 122 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
{
#line 124 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(m_sftType  == SFT_FIRE ){
#line 125 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 126 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CModelHolder2  :: RenderParticles  ();
#line 127 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
  
#line 130 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CAnimData * CShooter::GetAnimData(SLONG slPropertyOffset) 
#line 131 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
{
#line 132 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(slPropertyOffset  == offsetof  (CShooter  , m_iModelPreFireAnimation ) || 
#line 133 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
slPropertyOffset  == offsetof  (CShooter  , m_iModelPostFireAnimation )){
#line 134 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return GetModelObject  () -> GetData  ();
#line 135 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}else if(slPropertyOffset  == offsetof  (CShooter  , m_iTexturePreFireAnimation ) || 
#line 136 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
slPropertyOffset  == offsetof  (CShooter  , m_iTexturePostFireAnimation )){
#line 137 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return GetModelObject  () -> mo_toTexture  . GetData  ();
#line 138 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}else {
#line 139 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return CModelHolder2  :: GetAnimData  (slPropertyOffset );
#line 140 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 141 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
  
#line 144 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CEntity * CShooter::ShootProjectile(enum ProjectileType pt,FLOAT3D & vOffset,ANGLE3D & aOffset) {
#line 146 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CPlacement3D pl ;
#line 147 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
pl  = GetPlacement  ();
#line 148 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CEntityPointer penProjectile  = CreateEntity  (pl  , CLASS_PROJECTILE );
#line 149 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ELaunchProjectile  eLaunch ;
#line 150 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . penLauncher  = this ;
#line 151 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . prtType  = pt ;
#line 152 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
penProjectile  -> Initialize  (eLaunch );
#line 154 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return penProjectile ;
#line 155 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
  
#line 158 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
void CShooter::FireFlame(void) {
#line 160 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CPlacement3D plFlame ;
#line 161 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
plFlame  = GetPlacement  ();
#line 163 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FLOAT3D vNormDir ;
#line 164 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
AnglesToDirectionVector  (plFlame  . pl_OrientationAngle  , vNormDir );
#line 165 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
plFlame  . pl_PositionVector  += vNormDir  * 0.1f;
#line 168 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CEntityPointer penFlame  = CreateEntity  (plFlame  , CLASS_PROJECTILE );
#line 170 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ELaunchProjectile  eLaunch ;
#line 171 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . penLauncher  = this ;
#line 172 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . prtType  = PRT_SHOOTER_FLAME ;
#line 173 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
penFlame  -> Initialize  (eLaunch );
#line 175 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(m_penFlame  != NULL  && ! (m_penFlame  -> GetFlags  () & ENF_DELETED )){
#line 176 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
((CProjectile  &) * m_penFlame ) . m_penParticles  = penFlame ;
#line 177 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 179 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
((CProjectile  &) * penFlame ) . m_penParticles  = this ;
#line 181 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_penFlame  = penFlame ;
#line 182 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
  
#line 184 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
void CShooter::StopFlame(void) {
#line 185 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
((CProjectile  &) * m_penFlame ) . m_penParticles  = NULL ;
#line 187 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
  
#line 189 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
void CShooter::PlayFireSound(void) {
#line 191 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(m_penSoundLaunch  != NULL ){
#line 192 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CSoundHolder  & sh  = (CSoundHolder  &) * m_penSoundLaunch ;
#line 193 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_soLaunch  . Set3DParameters  (FLOAT (sh  . m_rFallOffRange ) , FLOAT (sh  . m_rHotSpotRange ) , sh  . m_fVolume  , 1.0f);
#line 194 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
PlaySound  (m_soLaunch  , sh  . m_fnSound  , sh  . m_iPlayType );
#line 195 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 196 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
  
#line 198 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
void CShooter::ShootCannonball() 
#line 199 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
{
#line 201 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CPlacement3D plBall  = GetPlacement  ();
#line 203 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CEntityPointer penBall  = CreateEntity  (plBall  , CLASS_CANNONBALL );
#line 205 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ELaunchCannonBall  eLaunch ;
#line 206 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . penLauncher  = this ;
#line 207 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . fLaunchPower  = 10.0f + m_fCannonBallPower ;
#line 208 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . cbtType  = CBT_IRON ;
#line 209 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . fSize  = m_fCannonBallSize ;
#line 210 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
penBall  -> Initialize  (eLaunch );
#line 211 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
  
#line 213 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
void CShooter::ShootFireball() 
#line 214 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
{
#line 216 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CPlacement3D plBall  = GetPlacement  ();
#line 218 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CEntityPointer penBall  = CreateEntity  (plBall  , CLASS_CANNONBALL );
#line 220 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ELaunchCannonBall  eLaunch ;
#line 221 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . penLauncher  = this ;
#line 222 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . fLaunchPower  = 10.0f + m_fCannonBallPower ;
#line 223 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . cbtType  = CBT_IRON ;
#line 224 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
eLaunch  . fSize  = m_fCannonBallSize ;
#line 225 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
penBall  -> Initialize  (eLaunch );
#line 226 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
BOOL CShooter::
#line 230 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FireOnce(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CShooter_FireOnce
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CShooter::FireOnce expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 232 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(m_sftType  == SFT_FIRE ){Jump(STATE_CURRENT, STATE_CShooter_FlameBurst, TRUE, EVoid());return TRUE;}
#line 234 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
PlayFireSound  ();
#line 236 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
GetModelObject  () -> PlayAnim  (m_iModelPreFireAnimation  , 0);
#line 237 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
GetModelObject  () -> mo_toTexture  . PlayAnim  (m_iTexturePreFireAnimation  , 0);
#line 238 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
SetTimerAfter(GetModelObject  () -> GetAnimLength  (m_iModelPreFireAnimation ));
Jump(STATE_CURRENT, 0x01590001, FALSE, EBegin());return TRUE;}BOOL CShooter::H0x01590001_FireOnce_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01590002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CShooter::H0x01590002_FireOnce_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590002
;
#line 240 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
switch(m_sftType ){
#line 241 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
case SFT_WOODEN_DART : 
#line 242 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ShootProjectile  (PRT_SHOOTER_WOODEN_DART  , FLOAT3D (0.0f , 0.0f , 0.0f) , ANGLE3D (0.0f , 0.0f , 0.0f));
#line 243 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
break ;
#line 244 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
case SFT_GAS : 
#line 245 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
break ;
#line 246 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
case SFT_IRONBALL : 
#line 247 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ShootCannonball  ();
#line 248 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
break ;
#line 249 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
case SFT_FIREBALL : 
#line 250 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ShootProjectile  (PRT_SHOOTER_FIREBALL  , FLOAT3D (0.0f , 0.0f , 0.0f) , ANGLE3D (0.0f , 0.0f , 0.0f));
#line 251 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
break ;
#line 252 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 254 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
GetModelObject  () -> PlayAnim  (m_iModelPostFireAnimation  , 0);
#line 255 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
GetModelObject  () -> mo_toTexture  . PlayAnim  (m_iTexturePostFireAnimation  , 0);
#line 256 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
SetTimerAfter(GetModelObject  () -> GetAnimLength  (m_iModelPostFireAnimation ));
Jump(STATE_CURRENT, 0x01590003, FALSE, EBegin());return TRUE;}BOOL CShooter::H0x01590003_FireOnce_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01590004, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CShooter::H0x01590004_FireOnce_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590004
;
#line 258 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Return(STATE_CURRENT,EEnd  ());
#line 258 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CShooter::
#line 261 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FireContinuous(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CShooter_FireContinuous
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CShooter::FireContinuous expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 264 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(!(m_fRndBeginWait  > 0.0f)){ Jump(STATE_CURRENT,0x01590008, FALSE, EInternal());return TRUE;}
#line 266 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FLOAT fRndWait  = FRnd  () * m_fRndBeginWait  + 0.05;
#line 267 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
SetTimerAfter(fRndWait );
Jump(STATE_CURRENT, 0x01590006, FALSE, EBegin());return TRUE;}BOOL CShooter::H0x01590006_FireContinuous_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590006
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01590007, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CShooter::H0x01590007_FireContinuous_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590007
;Jump(STATE_CURRENT,0x01590008, FALSE, EInternal());return TRUE;}BOOL CShooter::H0x01590008_FireContinuous_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590008

#line 270 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Jump(STATE_CURRENT,0x0159000d, FALSE, EInternal());return TRUE;}BOOL CShooter::H0x0159000d_FireContinuous_08(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0159000d
if(!(m_bFiring )){ Jump(STATE_CURRENT,0x0159000e, FALSE, EInternal());return TRUE;}
#line 271 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
STATE_CShooter_FireOnce, TRUE;
Jump(STATE_CURRENT, 0x01590009, FALSE, EBegin());return TRUE;}BOOL CShooter::H0x01590009_FireContinuous_04(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590009
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CShooter_FireOnce, TRUE, EVoid());return TRUE;case EVENTCODE_EEnd: Jump(STATE_CURRENT,0x0159000a, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CShooter::H0x0159000a_FireContinuous_05(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x0159000a
const EEnd&__e= (EEnd&)__eeInput;
;
#line 272 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
SetTimerAfter(m_fShootingPeriod );
Jump(STATE_CURRENT, 0x0159000b, FALSE, EBegin());return TRUE;}BOOL CShooter::H0x0159000b_FireContinuous_06(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0159000b
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0159000c, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CShooter::H0x0159000c_FireContinuous_07(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0159000c
;Jump(STATE_CURRENT,0x0159000d, FALSE, EInternal());return TRUE;
#line 273 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}BOOL CShooter::H0x0159000e_FireContinuous_09(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0159000e

#line 274 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Return(STATE_CURRENT,EReturn  ());
#line 274 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CShooter::
#line 277 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FlameBurst(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CShooter_FlameBurst
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CShooter::FlameBurst expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 278 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
PlayFireSound  ();
#line 279 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_penFlame  = NULL ;
#line 280 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_tmFlameStart  = _pTimer  -> CurrentTick  ();
#line 281 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Jump(STATE_CURRENT,0x01590012, FALSE, EInternal());return TRUE;}BOOL CShooter::H0x01590012_FlameBurst_03(const CEntityEvent &__eeInput)
#line 282 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
{
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590012
if(!(_pTimer  -> CurrentTick  () < m_tmFlameStart  + m_fFlameBurstDuration )){ Jump(STATE_CURRENT,0x01590013, FALSE, EInternal());return TRUE;}
#line 284 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
SetTimerAfter(0.05f);
Jump(STATE_CURRENT, 0x01590010, FALSE, EBegin());return TRUE;}BOOL CShooter::H0x01590010_FlameBurst_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590010
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01590011, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CShooter::H0x01590011_FlameBurst_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590011
;
#line 285 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
FireFlame  ();Jump(STATE_CURRENT,0x01590012, FALSE, EInternal());return TRUE;
#line 286 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}BOOL CShooter::H0x01590013_FlameBurst_04(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590013

#line 287 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
StopFlame  ();
#line 288 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Return(STATE_CURRENT,EEnd  ());
#line 288 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CShooter::
#line 291 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
MainLoop(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CShooter_MainLoop
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CShooter::MainLoop expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 293 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x01590015, FALSE, EBegin());return TRUE;}BOOL CShooter::H0x01590015_MainLoop_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590015
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 295 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return TRUE;
#line 296 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETrigger):{const ETrigger&e= (ETrigger&)__eeInput;

#line 298 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(! m_bFiring ){
#line 299 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Call(STATE_CURRENT, STATE_CShooter_FireOnce, TRUE, EVoid());return TRUE;
#line 300 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}else {
#line 301 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return TRUE;
#line 302 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 303 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}ASSERT(FALSE);break;case(EVENTCODE_EActivate):{const EActivate&e= (EActivate&)__eeInput;

#line 305 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_bFiring  = TRUE ;
#line 306 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Call(STATE_CURRENT, STATE_CShooter_FireContinuous, TRUE, EVoid());return TRUE;
#line 307 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}ASSERT(FALSE);break;case(EVENTCODE_EDeactivate):{const EDeactivate&e= (EDeactivate&)__eeInput;

#line 309 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_bFiring  = FALSE ;
#line 310 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return TRUE;
#line 311 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}ASSERT(FALSE);break;case(EVENTCODE_EDeath):{const EDeath&e= (EDeath&)__eeInput;

#line 313 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(m_penDestruction  != NULL ){
#line 314 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Jump(STATE_CURRENT, STATE_CModelHolder2_Die, FALSE, EVoid());return TRUE;
#line 315 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}else {
#line 316 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Destroy  ();
#line 317 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Return(STATE_CURRENT,EVoid());
#line 317 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return TRUE;
#line 318 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 319 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}ASSERT(FALSE);break;case(EVENTCODE_EReturn):{const EReturn&e= (EReturn&)__eeInput;

#line 321 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return TRUE;
#line 322 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 323 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}return TRUE;}BOOL CShooter::H0x01590016_MainLoop_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590016
 ASSERT(FALSE); return TRUE;};BOOL CShooter::
#line 326 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CShooter_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CShooter::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 328 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
CModelHolder2  :: InitModelHolder  ();
#line 330 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(m_fHealth  > 0.0f){
#line 331 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
SetHealth  (m_fHealth );
#line 332 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_bIndestructable  = FALSE ;
#line 333 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}else {
#line 334 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
SetHealth  (10000.0f);
#line 335 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_bIndestructable  = TRUE ;
#line 336 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 338 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ClampUp  (m_fCannonBallSize  , 10.0f);
#line 339 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ClampDn  (m_fCannonBallSize  , 0.1f);
#line 340 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ClampUp  (m_fCannonBallPower  , 100.0f);
#line 341 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
ClampDn  (m_fCannonBallPower  , 0.0f);
#line 343 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(m_penSoundLaunch  != NULL  && ! IsOfClass  (m_penSoundLaunch  , "SoundHolder")){
#line 344 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
WarningMessage  ("Entity '%s' is not of class SoundHolder!" , m_penSoundLaunch );
#line 345 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_penSoundLaunch  = NULL ;
#line 346 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 347 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
if(m_penDestruction  != NULL  && ! IsOfClass  (m_penDestruction  , "ModelDestruction")){
#line 348 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
WarningMessage  ("Entity '%s' is not of class ModelDestruction!" , m_penDestruction );
#line 349 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
m_penDestruction  = NULL ;
#line 350 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
}
#line 352 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
SetTimerAfter(_pTimer  -> TickQuantum );
Jump(STATE_CURRENT, 0x01590017, FALSE, EBegin());return TRUE;}BOOL CShooter::H0x01590017_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590017
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01590018, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CShooter::H0x01590018_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01590018
;
#line 354 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Jump(STATE_CURRENT, STATE_CShooter_MainLoop, TRUE, EVoid());return TRUE;
#line 356 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
Return(STATE_CURRENT,EVoid());
#line 356 "C:/MyMod/Sources/EntitiesMP/Shooter.es"
return TRUE; ASSERT(FALSE); return TRUE;};