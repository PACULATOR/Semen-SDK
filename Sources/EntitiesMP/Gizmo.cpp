/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"

#include "StdH.h"
#include "Models/Enemies/Gizmo/Gizmo.h"

#include <EntitiesMP/Gizmo.h>
#include <EntitiesMP/Gizmo_tables.h>
#line 10 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"

// info structure
static EntityInfo eiGizmo = {
  EIBT_FLESH, 100.0f,
  0.0f, 1.3f, 0.0f,     // source (eyes)
  0.0f, 1.0f, 0.0f,     // target (body)
};

#define EXPLODE_GIZMO   2.5f

void CGizmo::SetDefaultProperties(void) {
  m_bExploded = FALSE ;
  CEnemyBase::SetDefaultProperties();
}
  CTString CGizmo::GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath) 
#line 46 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 47 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
CTString str ;
#line 48 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
str  . PrintF  (TRANS  ("%s ate a marsh hopper") , strPlayerName );
#line 49 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
return str ;
#line 50 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  const CTFileName & CGizmo::GetComputerMessageName(void)const {
#line 52 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
static DECLARE_CTFILENAME  (fnm  , "Data\\Messages\\Enemies\\Gizmo.txt");
#line 53 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
return fnm ;
#line 54 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  
#line 56 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
void * CGizmo::GetEntityInfo(void) 
#line 57 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 58 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
return & eiGizmo ;
#line 59 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  
#line 61 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
void CGizmo::Precache(void) 
#line 62 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 63 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
CEnemyBase  :: Precache  ();
#line 64 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PrecacheSound  (SOUND_SIGHT );
#line 65 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PrecacheSound  (SOUND_IDLE );
#line 66 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PrecacheSound  (SOUND_JUMP );
#line 67 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PrecacheSound  (SOUND_DEATH_JUMP );
#line 68 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PrecacheClass  (CLASS_BASIC_EFFECT  , BET_GIZMO_SPLASH_FX );
#line 69 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PrecacheClass  (CLASS_BLOOD_SPRAY );
#line 70 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  
#line 72 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
void CGizmo::SightSound(void) {
#line 73 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PlaySound  (m_soSound  , SOUND_SIGHT  , SOF_3D );
#line 74 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  
#line 76 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
void CGizmo::RunningAnim(void) 
#line 77 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 78 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
StartModelAnim  (GIZMO_ANIM_RUN  , 0);
#line 79 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  
#line 81 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
void CGizmo::MortalJumpAnim(void) 
#line 82 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 83 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
StartModelAnim  (GIZMO_ANIM_RUN  , 0);
#line 84 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  
#line 86 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
void CGizmo::StandAnim(void) 
#line 87 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 88 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
StartModelAnim  (GIZMO_ANIM_IDLE  , AOF_LOOPING  | AOF_NORESTART );
#line 89 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  
#line 92 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
void CGizmo::IdleSound(void) {
#line 93 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PlaySound  (m_soSound  , SOUND_IDLE  , SOF_3D );
#line 94 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  
#line 99 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
void CGizmo::BlowUpNotify(void) {
#line 100 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
Explode  ();
#line 101 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  
#line 104 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
void CGizmo::Explode(void) 
#line 105 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 106 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
if(! m_bExploded )
#line 107 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 108 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_bExploded  = TRUE ;
#line 110 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
CPlacement3D plSpray  = GetPlacement  ();
#line 111 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
CEntity  * penSpray  = CreateEntity  (plSpray  , CLASS_BLOOD_SPRAY );
#line 112 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
penSpray  -> SetParent  (this );
#line 113 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
ESpawnSpray  eSpawnSpray ;
#line 114 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
eSpawnSpray  . colBurnColor  = C_WHITE  | CT_OPAQUE ;
#line 115 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
eSpawnSpray  . fDamagePower  = 2.0f;
#line 116 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
eSpawnSpray  . fSizeMultiplier  = 1.0f;
#line 117 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
eSpawnSpray  . sptType  = SPT_SLIME ;
#line 118 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
eSpawnSpray  . vDirection  = en_vCurrentTranslationAbsolute  / 8.0f;
#line 119 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
eSpawnSpray  . penOwner  = this ;
#line 120 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
penSpray  -> Initialize  (eSpawnSpray );
#line 123 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
CPlacement3D plSplash  = GetPlacement  ();
#line 124 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
CEntityPointer penSplash  = CreateEntity  (plSplash  , CLASS_BASIC_EFFECT );
#line 125 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
ESpawnEffect  ese ;
#line 126 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
ese  . colMuliplier  = C_WHITE  | CT_OPAQUE ;
#line 127 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
ese  . betType  = BET_GIZMO_SPLASH_FX ;
#line 128 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
penSplash  -> Initialize  (ese );
#line 129 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
#line 130 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  
#line 134 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
BOOL CGizmo::ShouldBlowUp(void) 
#line 135 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 136 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
return TRUE ;
#line 137 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
  void CGizmo::LeaveStain(BOOL bGrow) 
#line 142 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 143 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
ESpawnEffect  ese ;
#line 144 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT3D vPoint ;
#line 145 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOATplane3D vPlaneNormal ;
#line 146 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT fDistanceToEdge ;
#line 148 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOATaabbox3D box ;
#line 149 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
GetBoundingBox  (box );
#line 152 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
if(GetNearestPolygon  (vPoint  , vPlaneNormal  , fDistanceToEdge ))
#line 153 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 155 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
if((vPoint  - GetPlacement  () . pl_PositionVector ) . Length  () < 0.5f)
#line 156 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 157 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT fStretch  = box  . Size  () . Length  ();
#line 159 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
ese  . colMuliplier  = C_WHITE  | CT_OPAQUE ;
#line 160 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
ese  . betType  = BET_GIZMOSTAIN ;
#line 161 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
ese  . vStretch  = FLOAT3D (fStretch  * 0.75f , fStretch  * 0.75f , 1.0f);
#line 162 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
ese  . vNormal  = FLOAT3D (vPlaneNormal );
#line 163 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
ese  . vDirection  = FLOAT3D (0 , 0 , 0);
#line 164 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT3D vPos  = vPoint  + ese  . vNormal  / 50.0f * (FRnd  () + 0.5f);
#line 165 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
CEntityPointer penEffect  = CreateEntity  (CPlacement3D (vPos  , ANGLE3D (0 , 0 , 0)) , CLASS_BASIC_EFFECT );
#line 166 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
penEffect  -> Initialize  (ese );
#line 167 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
#line 168 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
#line 169 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
BOOL CGizmo::
#line 176 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PerformAttack(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGizmo_PerformAttack
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGizmo::PerformAttack expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 178 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
Jump(STATE_CURRENT,0x014f0005, FALSE, EInternal());return TRUE;}BOOL CGizmo::H0x014f0005_PerformAttack_05(const CEntityEvent &__eeInput)
#line 179 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x014f0005
if(!(TRUE )){ Jump(STATE_CURRENT,0x014f0006, FALSE, EInternal());return TRUE;}
#line 182 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
if(ShouldCeaseAttack  ())
#line 183 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 184 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetTargetNone  ();
#line 185 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
Return(STATE_CURRENT,EReturn  ());
#line 185 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
return TRUE;
#line 186 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
#line 189 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetDesiredTranslation  (FLOAT3D (0.0f , 0.0f , 0.0f));
#line 190 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetDesiredRotation  (ANGLE3D (0 , 0 , 0));
#line 193 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT fWaitTime  = 0.25f + FRnd  () * 0.4f;
#line 194 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetTimerAfter(fWaitTime );
Jump(STATE_CURRENT, 0x014f0001, FALSE, EBegin());return TRUE;}BOOL CGizmo::H0x014f0001_PerformAttack_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x014f0001
switch(__eeInput.ee_slEvent)
#line 195 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_ESound):{const ESound&e= (ESound&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EWatch):{const EWatch&e= (EWatch&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x014f0002, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 200 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}return TRUE;}BOOL CGizmo::H0x014f0002_PerformAttack_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x014f0002

#line 202 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
STATE_CGizmo_JumpOnce, TRUE;
Jump(STATE_CURRENT, 0x014f0003, FALSE, EBegin());return TRUE;}BOOL CGizmo::H0x014f0003_PerformAttack_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x014f0003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CGizmo_JumpOnce, TRUE, EVoid());return TRUE;case EVENTCODE_EReturn: Jump(STATE_CURRENT,0x014f0004, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CGizmo::H0x014f0004_PerformAttack_04(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x014f0004
const EReturn&__e= (EReturn&)__eeInput;
;Jump(STATE_CURRENT,0x014f0005, FALSE, EInternal());return TRUE;
#line 203 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}BOOL CGizmo::H0x014f0006_PerformAttack_06(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x014f0006
 ASSERT(FALSE); return TRUE;};BOOL CGizmo::
#line 206 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
JumpOnce(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGizmo_JumpOnce
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGizmo::JumpOnce expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 210 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_vDesiredPosition  = m_penEnemy  -> GetPlacement  () . pl_PositionVector ;
#line 211 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fMoveFrequency  = 0.1f;
#line 213 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
if(CalcPlaneDist  (m_penEnemy ) < 10.0f)
#line 214 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 216 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fMoveSpeed  = m_fCloseRunSpeed  * 1.5f;
#line 217 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_aRotateSpeed  = m_aCloseRotateSpeed  * 0.5f;
#line 218 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT fSpeedX  = 0.0f;
#line 219 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT fSpeedY  = 10.0f;
#line 220 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT fSpeedZ  = - m_fMoveSpeed ;
#line 222 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
if(! IsInFrustum  (m_penEnemy  , CosFast  (30.0f)))
#line 223 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 225 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_aRotateSpeed  = m_aCloseRotateSpeed  * 1.5f;
#line 227 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
fSpeedY  /= 2.0f;
#line 228 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
fSpeedZ  /= 4.0f;
#line 229 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PlaySound  (m_soSound  , SOUND_JUMP  , SOF_3D );
#line 230 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
#line 231 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
else 
#line 232 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 233 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PlaySound  (m_soSound  , SOUND_DEATH_JUMP  , SOF_3D );
#line 234 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
#line 235 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT3D vTranslation  (fSpeedX  , fSpeedY  , fSpeedZ );
#line 236 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetDesiredTranslation  (vTranslation );
#line 237 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
MortalJumpAnim  ();
#line 238 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
#line 240 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
else 
#line 241 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 242 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fMoveSpeed  = m_fCloseRunSpeed ;
#line 243 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_aRotateSpeed  = m_aCloseRotateSpeed ;
#line 245 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT fSpeedX  = (FRnd  () - 0.5f) * 10.0f;
#line 246 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT fSpeedY  = FRnd  () * 5.0f + 5.0f;
#line 247 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT fSpeedZ  = - m_fMoveSpeed  - FRnd  () * 2.5f;
#line 248 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT3D vTranslation  (fSpeedX  , fSpeedY  , fSpeedZ );
#line 249 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetDesiredTranslation  (vTranslation );
#line 250 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
RunningAnim  ();
#line 251 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
PlaySound  (m_soSound  , SOUND_JUMP  , SOF_3D );
#line 252 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
#line 255 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
Jump(STATE_CURRENT,0x014f000a, FALSE, EInternal());return TRUE;}BOOL CGizmo::H0x014f000a_JumpOnce_03(const CEntityEvent &__eeInput)
#line 256 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x014f000a
if(!(TRUE )){ Jump(STATE_CURRENT,0x014f000b, FALSE, EInternal());return TRUE;}
#line 258 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fMoveSpeed  = 0.0f;
#line 259 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_aRotateSpeed  = m_aCloseRotateSpeed ;
#line 260 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
FLOAT3D vTranslation  = GetDesiredTranslation  ();
#line 261 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetDesiredMovement  ();
#line 262 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetDesiredTranslation  (vTranslation );
#line 264 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetTimerAfter(m_fMoveFrequency );
Jump(STATE_CURRENT, 0x014f0008, FALSE, EBegin());return TRUE;}BOOL CGizmo::H0x014f0008_JumpOnce_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x014f0008
switch(__eeInput.ee_slEvent)
#line 265 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_ESound):{const ESound&e= (ESound&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EWatch):{const EWatch&e= (EWatch&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x014f0009, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_ETouch):
#line 271 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{const ETouch&etouch= (ETouch&)__eeInput;

#line 273 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
if(etouch  . penOther  -> GetRenderType  () & RT_BRUSH )
#line 274 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 275 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
Return(STATE_CURRENT,EReturn  ());
#line 275 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
return TRUE;
#line 276 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
#line 278 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
else if(IsDerivedFromClass  (etouch  . penOther  , "Player"))
#line 279 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
{
#line 280 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
InflictDirectDamage  (etouch  . penOther  , this  , DMT_IMPACT  , 10.0f , 
#line 281 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
GetPlacement  () . pl_PositionVector  , - en_vGravityDir );
#line 282 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetHealth  (- 10000.0f);
#line 283 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_vDamage  = FLOAT3D (0 , 10000 , 0);
#line 284 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SendEvent  (EDeath  ());
#line 285 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}
#line 287 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
return TRUE;
#line 288 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 289 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}return TRUE;}BOOL CGizmo::H0x014f0009_JumpOnce_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x014f0009
Jump(STATE_CURRENT,0x014f000a, FALSE, EInternal());return TRUE;
#line 290 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
}BOOL CGizmo::H0x014f000b_JumpOnce_04(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x014f000b
 ASSERT(FALSE); return TRUE;};BOOL CGizmo::
#line 296 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGizmo_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGizmo::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 298 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
InitAsModel  ();
#line 299 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetPhysicsFlags  (EPF_MODEL_WALKING  | EPF_HASLUNGS );
#line 300 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetCollisionFlags  (ECF_MODEL );
#line 301 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetFlags  (GetFlags  () | ENF_ALIVE );
#line 302 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetHealth  (9.5f);
#line 303 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fMaxHealth  = 9.5f;
#line 304 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
en_tmMaxHoldBreath  = 5.0f;
#line 305 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
en_fDensity  = 2000.0f;
#line 306 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fBlowUpSize  = 2.0f;
#line 309 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetModel  (MODEL_GIZMO );
#line 310 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
SetModelMainTexture  (TEXTURE_GIZMO );
#line 312 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fWalkSpeed  = FRnd  () + 1.5f;
#line 313 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_aWalkRotateSpeed  = AngleDeg  (FRnd  () * 10.0f + 500.0f);
#line 314 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fAttackRunSpeed  = FRnd  () * 5.0f + 15.0f;
#line 315 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_aAttackRotateSpeed  = AngleDeg  (FRnd  () * 100 + 600.0f);
#line 316 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fCloseRunSpeed  = FRnd  () * 5.0f + 15.0f;
#line 317 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_aCloseRotateSpeed  = AngleDeg  (360.0f);
#line 319 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fAttackDistance  = 400.0f;
#line 320 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fCloseDistance  = 250.0f;
#line 321 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fStopDistance  = 0.0f;
#line 322 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fAttackFireTime  = 2.0f;
#line 323 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fCloseFireTime  = 0.5f;
#line 324 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fIgnoreRange  = 500.0f;
#line 326 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fBlowUpAmount  = 0.0f;
#line 327 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fBodyParts  = 0;
#line 328 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_fDamageWounded  = 0.0f;
#line 329 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_iScore  = 500;
#line 330 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
m_sptType  = SPT_SLIME ;
#line 332 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
en_fDeceleration  = 150.0f;
#line 335 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
GetModelObject  () -> StretchModel  (FLOAT3D (1.25f , 1.25f , 1.25f));
#line 336 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
ModelChangeNotify  ();
#line 337 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
StandingAnim  ();
#line 340 "C:/MyMod/Sources/EntitiesMP/Gizmo.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_MainLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};