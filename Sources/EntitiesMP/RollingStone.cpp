/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"

#include "StdH.h"

#include <EntitiesMP/RollingStone.h>
#include <EntitiesMP/RollingStone_tables.h>
void CRollingStone::SetDefaultProperties(void) {
  m_fBounce = 0.5f;
  m_fHealth = 400.0f;
  m_fDamage = 1000.0f;
  m_bFixedDamage = FALSE ;
  m_fStretch = 1.0f;
  m_fDeceleration = 0.9f;
  m_fStartSpeed = 50.0f;
  m_vStartDir = ANGLE3D(0 , 0 , 0);
  m_penDeathTarget = NULL;
  m_soBounce0.SetOwner(this);
m_soBounce0.Stop_internal();
  m_soBounce1.SetOwner(this);
m_soBounce1.Stop_internal();
  m_soBounce2.SetOwner(this);
m_soBounce2.Stop_internal();
  m_soBounce3.SetOwner(this);
m_soBounce3.Stop_internal();
  m_soBounce4.SetOwner(this);
m_soBounce4.Stop_internal();
  m_iNextChannel = 0;
  m_soRoll.SetOwner(this);
m_soRoll.Stop_internal();
  m_bRollPlaying = FALSE ;
  m_qA = FLOATquat3D(0 , 1 , 0 , 0);
  m_qALast = FLOATquat3D(0 , 1 , 0 , 0);
  m_fASpeed = 0.0f;
  m_vR = FLOAT3D(0 , 0 , 1);
  CMovableModelEntity::SetDefaultProperties();
}
  
#line 53 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
void CRollingStone::Precache(void) 
#line 54 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
{
#line 55 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
PrecacheClass  (CLASS_DEBRIS );
#line 56 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
PrecacheModel  (MODEL_STONE );
#line 57 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
PrecacheTexture  (TEXTURE_STONE );
#line 58 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
PrecacheSound  (SOUND_BOUNCE );
#line 59 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
PrecacheSound  (SOUND_ROLL );
#line 60 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
  
#line 61 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
void CRollingStone::PostMoving() {
#line 62 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
CMovableModelEntity  :: PostMoving  ();
#line 65 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(en_penReference  != NULL ){
#line 67 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
AdjustSpeeds  (en_vReferencePlane );
#line 69 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}else {
#line 71 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 74 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_qALast  = m_qA ;
#line 76 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOATquat3D qRot ;
#line 77 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
qRot  . FromAxisAngle  (m_vR  , m_fASpeed  * _pTimer  -> TickQuantum  * PI  / 180);
#line 78 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOATmatrix3D mRot ;
#line 79 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
qRot  . ToMatrix  (mRot );
#line 80 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_qA  = qRot  * m_qA ;
#line 81 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(en_ulFlags  & ENF_INRENDERING ){
#line 82 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_qALast  = m_qA ;
#line 83 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 84 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
  
#line 87 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
void CRollingStone::AdjustMipFactor(FLOAT & fMipFactor) 
#line 88 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
{
#line 89 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
fMipFactor  = 0;
#line 91 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOATquat3D qA ;
#line 92 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
qA  = Slerp  (_pTimer  -> GetLerpFactor  () , m_qALast  , m_qA );
#line 94 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOATmatrix3D mA ;
#line 95 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
qA  . ToMatrix  (mA );
#line 96 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
ANGLE3D vA ;
#line 97 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
DecomposeRotationMatrixNoSnap  (vA  , mA );
#line 99 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
CAttachmentModelObject  * amo  = GetModelObject  () -> GetAttachmentModel  (0);
#line 100 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
amo  -> amo_plRelative  . pl_OrientationAngle  = vA ;
#line 101 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
  
#line 103 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
void CRollingStone::AdjustSpeedOnOneAxis(FLOAT & fTraNow,FLOAT & aRotNow,BOOL bRolling) 
#line 104 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
{
#line 111 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fR  = 4.0f * m_fStretch ;
#line 113 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fTraNew  = (2 * aRotNow  * fR  + 5 * fTraNow ) / 7;
#line 114 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT aRotNew  = fTraNew  / fR ;
#line 116 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
fTraNow  = fTraNew ;
#line 117 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
aRotNow  = aRotNew ;
#line 118 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
  
#line 121 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
void CRollingStone::AdjustSpeeds(const FLOAT3D & vPlane) 
#line 122 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
{
#line 124 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(en_vCurrentTranslationAbsolute  . Length  () < 1.0f && m_fASpeed  < 1.0f){
#line 126 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
en_vCurrentTranslationAbsolute  = FLOAT3D (0 , 0 , 0);
#line 127 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_fASpeed  = 0.0f;
#line 128 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
RollSound  (0.0f);
#line 129 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
return ;
#line 130 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 133 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT3D vTranslationNormal ;
#line 134 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT3D vTranslationParallel ;
#line 135 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
GetParallelAndNormalComponents  (en_vCurrentTranslationAbsolute  , vPlane  , vTranslationNormal  , vTranslationParallel );
#line 138 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
BOOL bRolling  = vTranslationNormal  . Length  () < 0.1f;
#line 140 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(bRolling ){
#line 142 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fSpeedTra  = vTranslationParallel  . Length  ();
#line 146 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
RollSound  (fSpeedTra );
#line 147 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}else {
#line 148 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
RollSound  (0);
#line 149 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 155 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT3D vRotFromRot  = m_vR ;
#line 156 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT3D vTraFromRot  = vPlane  * vRotFromRot ;
#line 157 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
vTraFromRot  . Normalize  ();
#line 159 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fTraFromRot  = 0;
#line 160 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fRotFromRot  = m_fASpeed  * PI  / 180.0f;
#line 163 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT3D vTraFromTra  = vTranslationParallel ;
#line 164 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fTraFromTra  = vTraFromTra  . Length  ();
#line 165 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT3D vRotFromTra  = FLOAT3D (1 , 0 , 0);
#line 166 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fRotFromTra  = 0;
#line 167 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(fTraFromTra  > 0.001f){
#line 168 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
vTraFromTra  /= fTraFromTra ;
#line 169 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
vRotFromTra  = vTraFromTra  * vPlane ;
#line 170 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
vRotFromTra  . Normalize  ();
#line 171 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 174 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(Abs  (fRotFromRot ) > 0.01f){
#line 176 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
AdjustSpeedOnOneAxis  (fTraFromRot  , fRotFromRot  , bRolling );
#line 177 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 179 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(Abs  (fTraFromTra ) > 0.01f){
#line 181 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
AdjustSpeedOnOneAxis  (fTraFromTra  , fRotFromTra  , bRolling );
#line 182 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 185 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOATquat3D qTra ;
#line 186 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
qTra  . FromAxisAngle  (vRotFromTra  , fRotFromTra );
#line 187 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOATquat3D qRot ;
#line 188 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
qRot  . FromAxisAngle  (vRotFromRot  , fRotFromRot );
#line 189 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOATquat3D q  = qRot  * qTra ;
#line 190 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT3D vSpeed  = vTraFromTra  * fTraFromTra  + vTraFromRot  * fTraFromRot ;
#line 193 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
en_vCurrentTranslationAbsolute  = vTranslationNormal  + vSpeed ;
#line 194 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
q  . ToAxisAngle  (m_vR  , m_fASpeed );
#line 195 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_fASpeed  *= 180 / PI ;
#line 196 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
  
#line 201 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
void CRollingStone::BounceSound(FLOAT fSpeed) {
#line 202 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fHitStrength  = fSpeed  * fSpeed ;
#line 204 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fVolume  = fHitStrength  / 20.0f;
#line 206 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
fVolume  = Clamp  (fVolume  , 0.0f , 2.0f);
#line 208 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fPitch  = Lerp  (0.2f , 1.0f , Clamp  (fHitStrength  / 100 , 0.0f , 1.0f));
#line 209 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(fVolume  < 0.1f){
#line 210 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
return ;
#line 211 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 212 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
CSoundObject & so  = (& m_soBounce0 ) [ m_iNextChannel  ];
#line 213 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_iNextChannel  = (m_iNextChannel  + 1) % 5;
#line 214 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
so  . Set3DParameters  (200.0f * m_fStretch  , 100.0f * m_fStretch  , fVolume  , fPitch );
#line 215 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
PlaySound  (so  , SOUND_BOUNCE  , SOF_3D );
#line 216 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
  
#line 218 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
void CRollingStone::RollSound(FLOAT fSpeed) 
#line 219 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
{
#line 220 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fHitStrength  = fSpeed  * fSpeed  * m_fStretch  * m_fStretch  * m_fStretch ;
#line 222 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fVolume  = fHitStrength  / 20.0f;
#line 223 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
fVolume  = Clamp  (fVolume  , 0.0f , 1.0f);
#line 224 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fPitch  = Lerp  (0.2f , 1.0f , Clamp  (fHitStrength  / 100 , 0.0f , 1.0f));
#line 225 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(fVolume  < 0.1f){
#line 226 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(m_bRollPlaying ){
#line 227 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_soRoll  . Stop  ();
#line 228 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_bRollPlaying  = FALSE ;
#line 229 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 230 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
return ;
#line 231 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 232 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_soRoll  . Set3DParameters  (200.0f * m_fStretch  , 100.0f * m_fStretch  , fVolume  , fPitch );
#line 234 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(! m_bRollPlaying ){
#line 235 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
PlaySound  (m_soRoll  , SOUND_ROLL  , SOF_3D  | SOF_LOOP );
#line 236 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_bRollPlaying  = TRUE ;
#line 237 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 238 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
BOOL CRollingStone::
#line 242 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CRollingStone_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CRollingStone::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 245 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
InitAsModel  ();
#line 246 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
SetPhysicsFlags  (EPF_ONBLOCK_BOUNCE  | EPF_PUSHABLE  | EPF_MOVABLE  | EPF_TRANSLATEDBYGRAVITY );
#line 247 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
SetCollisionFlags  (ECF_MODEL );
#line 248 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
SetModel  (MODEL_ROLLINGSTONE );
#line 249 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
SetModelMainTexture  (TEXTURE_ROLLINGSTONE );
#line 250 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
AddAttachmentToModel  (this  , * GetModelObject  () , 0 , MODEL_STONESPHERE  , TEXTURE_ROLLINGSTONE  , 0 , 0 , TEXTURE_DETAIL );
#line 252 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
GetModelObject  () -> StretchModel  (FLOAT3D (m_fStretch  , m_fStretch  , m_fStretch ));
#line 253 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
ModelChangeNotify  ();
#line 255 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
en_fBounceDampNormal  = m_fBounce ;
#line 256 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
en_fBounceDampParallel  = m_fBounce ;
#line 257 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
en_fAcceleration  = en_fDeceleration  = m_fDeceleration ;
#line 258 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
en_fCollisionSpeedLimit  = 45.0f;
#line 259 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
en_fCollisionDamageFactor  = 10.0f;
#line 261 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
SetPlacement  (CPlacement3D (GetPlacement  () . pl_PositionVector  , ANGLE3D (0 , 0 , 0)));
#line 262 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_qA  = FLOATquat3D (0 , 1 , 0 , 0);
#line 263 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
m_qALast  = FLOATquat3D (0 , 1 , 0 , 0);
#line 265 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x025c0000, FALSE, EBegin());return TRUE;}BOOL CRollingStone::H0x025c0000_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x025c0000
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x025c0001, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CRollingStone::H0x025c0001_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x025c0001
;
#line 267 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
SetHealth  (m_fHealth );
#line 268 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
AddToMovers  ();
#line 270 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x025c0002, FALSE, EBegin());return TRUE;}BOOL CRollingStone::H0x025c0002_Main_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x025c0002
switch(__eeInput.ee_slEvent){case(EVENTCODE_ETrigger):{const ETrigger&e= (ETrigger&)__eeInput;

#line 272 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT3D v ;
#line 273 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
AnglesToDirectionVector  (m_vStartDir  , v );
#line 274 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
GiveImpulseTranslationAbsolute  (v  * m_fStartSpeed );
#line 276 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
return TRUE;
#line 277 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETouch):
#line 279 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
{const ETouch&eTouch= (ETouch&)__eeInput;

#line 283 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(! m_bFixedDamage )
#line 284 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
{
#line 285 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fDamageFactor  = en_vCurrentTranslationAbsolute  . Length  () / 10.0f;
#line 286 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fAppliedDamage  = fDamageFactor  * m_fDamage ;
#line 288 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
InflictDirectDamage  (eTouch  . penOther  , this  , DMT_CANNONBALL  , fAppliedDamage  , 
#line 289 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
eTouch  . penOther  -> GetPlacement  () . pl_PositionVector  , eTouch  . plCollision );
#line 290 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 291 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
else 
#line 292 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
{
#line 293 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(en_vCurrentTranslationAbsolute  . Length  () != 0.0f)
#line 294 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
{
#line 296 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
InflictDirectDamage  (eTouch  . penOther  , this  , DMT_CANNONBALL  , m_fDamage  , 
#line 297 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
eTouch  . penOther  -> GetPlacement  () . pl_PositionVector  , eTouch  . plCollision );
#line 298 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 299 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 302 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
AdjustSpeeds  (eTouch  . plCollision );
#line 305 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(eTouch  . penOther  -> GetRenderType  () & RT_BRUSH )
#line 306 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
{
#line 307 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
BounceSound  (((FLOAT3D &) eTouch  . plCollision ) % en_vCurrentTranslationAbsolute );
#line 309 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fImpactSpeed  = en_vCurrentTranslationAbsolute  % (- (FLOAT3D &) eTouch  . plCollision );
#line 312 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
if(fImpactSpeed  > 1000)
#line 313 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
{
#line 315 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
ReceiveDamage  (eTouch  . penOther  , DMT_IMPACT  , m_fHealth  * 2.0f , 
#line 316 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT3D (0 , 0 , 0) , FLOAT3D (0 , 0 , 0));
#line 317 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 318 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 319 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
return TRUE;
#line 320 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}ASSERT(FALSE);break;case(EVENTCODE_EDeath):{const EDeath&eDeath= (EDeath&)__eeInput;

#line 322 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
SendToTarget  (m_penDeathTarget  , EET_TRIGGER  , eDeath  . eLastDamage  . penInflictor );
#line 324 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOATaabbox3D box ;
#line 325 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
GetBoundingBox  (box );
#line 326 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT fEntitySize  = box  . Size  () . MaxNorm  ();
#line 328 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
Debris_Begin  (EIBT_ROCK  , DPT_NONE  , BET_NONE  , fEntitySize  , FLOAT3D (1.0f , 2.0f , 3.0f) , FLOAT3D (0 , 0 , 0) , 1.0f , 0.0f);
#line 329 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
for(INDEX iDebris  = 0;iDebris  < 12;iDebris  ++){
#line 330 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
Debris_Spawn  (this  , this  , MODEL_STONE  , TEXTURE_STONE  , 0 , 0 , 0 , IRnd  () % 4 , 0.15f , 
#line 331 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
FLOAT3D (FRnd  () * 0.8f + 0.1f , FRnd  () * 0.8f + 0.1f , FRnd  () * 0.8f + 0.1f));
#line 332 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}
#line 333 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
Destroy  ();
#line 334 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
UnsetTimer();Jump(STATE_CURRENT,0x025c0003, FALSE, EInternal());return TRUE;
#line 335 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 336 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
}return TRUE;}BOOL CRollingStone::H0x025c0003_Main_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x025c0003

#line 339 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
Destroy  ();
#line 341 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
Return(STATE_CURRENT,EVoid());
#line 341 "C:/MyMod/Sources/EntitiesMP/RollingStone.es"
return TRUE; ASSERT(FALSE); return TRUE;};