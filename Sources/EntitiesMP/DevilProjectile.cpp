/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"

#include "StdH.h"

#include <EntitiesMP/DevilProjectile.h>
#include <EntitiesMP/DevilProjectile_tables.h>
CEntityEvent *EDevilProjectile::MakeCopy(void) { CEntityEvent *peeCopy = new EDevilProjectile(*this); return peeCopy;}
EDevilProjectile::EDevilProjectile() : CEntityEvent(EVENTCODE_EDevilProjectile) {;
 ClearToDefault(penLauncher);
 ClearToDefault(penTarget);
};
#line 16 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"

#define FLY_TIME  15.0f
#define ROTATE_SPEED 200.0f
#define MOVING_SPEED 30.0f
#define MOVING_FREQUENCY 0.1f

void CDevilProjectile::SetDefaultProperties(void) {
  m_penLauncher = NULL;
  m_penTarget = NULL;
  m_fIgnoreTime = 0.0f;
  m_fStartTime = 0.0f;
  m_vDesiredAngle = FLOAT3D(0 , 0 , 0);
  m_bFly = FALSE ;
  m_soEffect.SetOwner(this);
m_soEffect.Stop_internal();
  CMovableModelEntity::SetDefaultProperties();
}
  
#line 54 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::Read_t(CTStream * istr) 
#line 55 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
{
#line 56 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
CMovableModelEntity  :: Read_t  (istr );
#line 58 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
SetupLightSource  ();
#line 59 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 62 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
CLightSource * CDevilProjectile::GetLightSource(void) 
#line 63 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
{
#line 64 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
if(! IsPredictor  ()){
#line 65 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
return & m_lsLightSource ;
#line 66 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}else {
#line 67 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
return NULL ;
#line 68 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
#line 69 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 72 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::SetupLightSource(void) 
#line 73 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
{
#line 75 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
CLightSource  lsNew ;
#line 76 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
lsNew  . ls_ulFlags  = LSF_NONPERSISTENT  | LSF_DYNAMIC ;
#line 77 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
lsNew  . ls_rHotSpot  = 0.0f;
#line 78 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
lsNew  . ls_colColor  = RGBToColor  (0 , 128 , 128);
#line 79 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
lsNew  . ls_rFallOff  = 5.0f;
#line 80 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
lsNew  . ls_plftLensFlare  = NULL ;
#line 81 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
lsNew  . ls_ubPolygonalMask  = 0;
#line 82 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
lsNew  . ls_paoLightAnimation  = NULL ;
#line 84 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_lsLightSource  . ls_penEntity  = this ;
#line 85 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_lsLightSource  . SetLightSource  (lsNew );
#line 86 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 94 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::CalcHeadingRotation(ANGLE aWantedHeadingRelative,ANGLE & aRotation) {
#line 96 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
aWantedHeadingRelative  = NormalizeAngle  (aWantedHeadingRelative );
#line 99 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
if(aWantedHeadingRelative  < - ROTATE_SPEED  * MOVING_FREQUENCY ){
#line 101 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
aRotation  = - ROTATE_SPEED ;
#line 103 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}else if(aWantedHeadingRelative  > ROTATE_SPEED  * MOVING_FREQUENCY ){
#line 105 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
aRotation  = + ROTATE_SPEED ;
#line 107 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}else {
#line 108 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
aRotation  = aWantedHeadingRelative  / MOVING_FREQUENCY ;
#line 109 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
#line 110 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 113 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::CalcAngleFromPosition() {
#line 115 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
FLOAT3D vTarget ;
#line 118 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
vTarget  = m_penTarget  -> GetPlacement  () . pl_PositionVector ;
#line 119 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
vTarget  += FLOAT3D (m_penTarget  -> en_mRotation  (1 , 2) , 
#line 120 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_penTarget  -> en_mRotation  (2 , 2) , 
#line 121 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_penTarget  -> en_mRotation  (3 , 2)) * 2.0f;
#line 124 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_vDesiredAngle  = (vTarget  - GetPlacement  () . pl_PositionVector ) . Normalize  ();
#line 125 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 128 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::RotateToAngle() {
#line 130 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
ANGLE aRotation ;
#line 131 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
CalcHeadingRotation  (GetRelativeHeading  (m_vDesiredAngle ) , aRotation );
#line 134 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
SetDesiredRotation  (ANGLE3D (aRotation  , 0 , 0));
#line 135 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 138 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::FlyInDirection() {
#line 139 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
RotateToAngle  ();
#line 142 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
FLOAT3D vTarget ;
#line 145 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
vTarget  = m_penTarget  -> GetPlacement  () . pl_PositionVector ;
#line 146 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
vTarget  += FLOAT3D (m_penTarget  -> en_mRotation  (1 , 2) , 
#line 147 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_penTarget  -> en_mRotation  (2 , 2) , 
#line 148 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_penTarget  -> en_mRotation  (3 , 2)) * 2.0f;
#line 151 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
FLOAT3D vTranslation  = (vTarget  - GetPlacement  () . pl_PositionVector ) * ! en_mRotation ;
#line 152 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
vTranslation  (1) = 0.0f;
#line 153 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
vTranslation  . Normalize  ();
#line 154 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
vTranslation  *= MOVING_SPEED ;
#line 157 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
SetDesiredTranslation  (vTranslation );
#line 158 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 161 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::FlyToPosition() {
#line 162 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
CalcAngleFromPosition  ();
#line 163 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
FlyInDirection  ();
#line 164 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 167 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::RotateToPosition() {
#line 168 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
CalcAngleFromPosition  ();
#line 169 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
RotateToAngle  ();
#line 170 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 173 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::StopMoving() {
#line 174 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
StopRotating  ();
#line 175 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
StopTranslating  ();
#line 176 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 179 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::StopRotating() {
#line 180 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
SetDesiredRotation  (ANGLE3D (0 , 0 , 0));
#line 181 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 184 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::StopTranslating() {
#line 185 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
SetDesiredTranslation  (FLOAT3D (0.0f , 0.0f , 0.0f));
#line 186 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
  
#line 193 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
void CDevilProjectile::ProjectileTouch(CEntityPointer penHit) {
#line 195 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
FLOAT3D vDirection ;
#line 196 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
AnglesToDirectionVector  (GetPlacement  () . pl_OrientationAngle  , vDirection );
#line 197 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
InflictDirectDamage  (penHit  , m_penLauncher  , DMT_PROJECTILE  , 15.0f , 
#line 198 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
GetPlacement  () . pl_PositionVector  , vDirection );
#line 199 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
BOOL CDevilProjectile::
#line 207 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
Fly(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDevilProjectile_Fly
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CDevilProjectile::Fly expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 209 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_bFly  = TRUE ;
#line 210 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
Jump(STATE_CURRENT,0x01ff0004, FALSE, EInternal());return TRUE;}BOOL CDevilProjectile::H0x01ff0004_Fly_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01ff0004
if(!(m_bFly  && m_fStartTime  + FLY_TIME  > _pTimer  -> CurrentTick  ())){ Jump(STATE_CURRENT,0x01ff0005, FALSE, EInternal());return TRUE;}
#line 211 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x01ff0002, FALSE, EBegin());return TRUE;}BOOL CDevilProjectile::H0x01ff0002_Fly_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01ff0002
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 213 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
FlyToPosition  ();
#line 214 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
return TRUE;
#line 215 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}ASSERT(FALSE);break;case(EVENTCODE_EPass):{const EPass&epass= (EPass&)__eeInput;

#line 217 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
BOOL bHit ;
#line 219 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
bHit  = epass  . penOther  != m_penLauncher  || _pTimer  -> CurrentTick  () > m_fIgnoreTime ;
#line 221 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
bHit  &= ! IsOfClass  (epass  . penOther  , "Twister");
#line 222 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
if(bHit ){
#line 223 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
ProjectileTouch  (epass  . penOther );
#line 224 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_bFly  = FALSE ;
#line 225 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
UnsetTimer();Jump(STATE_CURRENT,0x01ff0003, FALSE, EInternal());return TRUE;
#line 226 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}
#line 227 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
return TRUE;
#line 228 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETouch):{const ETouch&etouch= (ETouch&)__eeInput;

#line 231 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_fIgnoreTime  = 0.0f;
#line 232 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
return TRUE;
#line 233 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x01ff0003, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 235 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}return TRUE;}BOOL CDevilProjectile::H0x01ff0003_Fly_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01ff0003
Jump(STATE_CURRENT,0x01ff0004, FALSE, EInternal());return TRUE;
#line 236 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
}BOOL CDevilProjectile::H0x01ff0005_Fly_04(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01ff0005

#line 237 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
Return(STATE_CURRENT,EEnd  ());
#line 237 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CDevilProjectile::
#line 241 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CDevilProjectile_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EDevilProjectile, "CDevilProjectile::Main expects 'EDevilProjectile' as input!");  const EDevilProjectile &eLaunch = (const EDevilProjectile &)__eeInput;
#line 243 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
ASSERT  (eLaunch  . penLauncher  != NULL );
#line 244 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
ASSERT  (eLaunch  . penTarget  != NULL );
#line 245 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_penLauncher  = eLaunch  . penLauncher ;
#line 246 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_penTarget  = eLaunch  . penTarget ;
#line 249 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
InitAsModel  ();
#line 250 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
SetPhysicsFlags  (EPF_PROJECTILE_FLYING );
#line 251 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
SetCollisionFlags  (ECF_PROJECTILE_MAGIC );
#line 252 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
SetModel  (MODEL_FLARE );
#line 253 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
SetModelMainTexture  (TEXTURE_FLARE );
#line 256 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
SetupLightSource  ();
#line 259 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_fIgnoreTime  = _pTimer  -> CurrentTick  () + 1.0f;
#line 262 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
m_fStartTime  = _pTimer  -> CurrentTick  ();
#line 263 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
STATE_CDevilProjectile_Fly, TRUE;
Jump(STATE_CURRENT, 0x01ff0006, FALSE, EBegin());return TRUE;}BOOL CDevilProjectile::H0x01ff0006_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01ff0006
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CDevilProjectile_Fly, TRUE, EVoid());return TRUE;case EVENTCODE_EEnd: Jump(STATE_CURRENT,0x01ff0007, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CDevilProjectile::H0x01ff0007_Main_02(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x01ff0007
const EEnd&__e= (EEnd&)__eeInput;
;
#line 266 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
Destroy  ();
#line 268 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
Return(STATE_CURRENT,EVoid());
#line 268 "C:/MyMod/Sources/EntitiesMP/DevilProjectile.es"
return TRUE; ASSERT(FALSE); return TRUE;};