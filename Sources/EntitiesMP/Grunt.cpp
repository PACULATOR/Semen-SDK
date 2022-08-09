/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/Grunt.es"

#include "StdH.h"
#include "ModelsMP/Enemies/Grunt/Grunt.h"

#include <EntitiesMP/Grunt.h>
#include <EntitiesMP/Grunt_tables.h>
#line 15 "C:/MyMod/Sources/EntitiesMP/Grunt.es"

#define STRETCH_SOLDIER   1.2f
#define STRETCH_COMMANDER 1.4f
  
// info structure
static EntityInfo eiGruntSoldier = {
  EIBT_FLESH, 200.0f,
  0.0f, 1.9f*STRETCH_SOLDIER, 0.0f,     // source (eyes)
  0.0f, 1.3f*STRETCH_SOLDIER, 0.0f,     // target (body)
};

static EntityInfo eiGruntCommander = {
  EIBT_FLESH, 250.0f,
  0.0f, 1.9f*STRETCH_COMMANDER, 0.0f,     // source (eyes)
  0.0f, 1.3f*STRETCH_COMMANDER, 0.0f,     // target (body)
};

#define FIREPOS_SOLDIER      FLOAT3D(0.07f, 1.36f, -0.78f)*STRETCH_SOLDIER
#define FIREPOS_COMMANDER_UP  FLOAT3D(0.09f, 1.45f, -0.62f)*STRETCH_COMMANDER
#define FIREPOS_COMMANDER_DN  FLOAT3D(0.10f, 1.30f, -0.60f)*STRETCH_COMMANDER

void CGrunt::SetDefaultProperties(void) {
  m_gtType = GT_SOLDIER ;
  m_soFire1.SetOwner(this);
m_soFire1.Stop_internal();
  m_soFire2.SetOwner(this);
m_soFire2.Stop_internal();
  CEnemyBase::SetDefaultProperties();
}
  CTString CGrunt::GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath) 
#line 74 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
{
#line 75 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
CTString str ;
#line 76 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
str  . PrintF  (TRANS  ("A Grunt sent %s into the halls of Valhalla") , strPlayerName );
#line 77 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return str ;
#line 78 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 81 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void * CGrunt::GetEntityInfo(void) {
#line 82 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
if(m_gtType  == GT_SOLDIER ){
#line 83 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return & eiGruntSoldier ;
#line 84 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}else if(m_gtType  == GT_COMMANDER ){
#line 85 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return & eiGruntSoldier ;
#line 86 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}else {
#line 87 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
ASSERT  ("Unknown grunt type!");
#line 88 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return NULL ;
#line 89 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
#line 90 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  const CTFileName & CGrunt::GetComputerMessageName(void)const {
#line 93 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
static DECLARE_CTFILENAME  (fnmSoldier  , "DataMP\\Messages\\Enemies\\GruntSoldier.txt");
#line 94 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
static DECLARE_CTFILENAME  (fnmCommander  , "DataMP\\Messages\\Enemies\\GruntCommander.txt");
#line 95 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
switch(m_gtType ){
#line 96 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
default  : ASSERT  (FALSE );
#line 97 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
case GT_SOLDIER : return fnmSoldier ;
#line 98 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
case GT_COMMANDER : return fnmCommander ;
#line 99 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
#line 100 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 102 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::Precache(void) {
#line 103 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
CEnemyBase  :: Precache  ();
#line 105 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
if(m_gtType  == GT_SOLDIER ){
#line 106 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PrecacheClass  (CLASS_PROJECTILE  , PRT_GRUNT_PROJECTILE_SOL );
#line 107 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
#line 108 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
if(m_gtType  == GT_COMMANDER ){
#line 109 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PrecacheClass  (CLASS_PROJECTILE  , PRT_GRUNT_PROJECTILE_COM );
#line 110 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
#line 112 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PrecacheSound  (SOUND_IDLE );
#line 113 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PrecacheSound  (SOUND_SIGHT );
#line 114 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PrecacheSound  (SOUND_WOUND );
#line 115 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PrecacheSound  (SOUND_FIRE );
#line 116 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PrecacheSound  (SOUND_DEATH );
#line 117 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 120 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 121 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection) 
#line 122 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
{
#line 123 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
CEnemyBase  :: ReceiveDamage  (penInflictor  , dmtType  , fDamageAmmount  , vHitPoint  , vDirection );
#line 124 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 127 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
INDEX CGrunt::AnimForDamage(FLOAT fDamage) {
#line 128 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
INDEX iAnim ;
#line 129 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
iAnim  = GRUNT_ANIM_WOUND01 ;
#line 130 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StartModelAnim  (iAnim  , 0);
#line 131 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return iAnim ;
#line 132 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 135 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
INDEX CGrunt::AnimForDeath(void) {
#line 136 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
INDEX iAnim ;
#line 137 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
FLOAT3D vFront ;
#line 138 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
GetHeadingDirection  (0 , vFront );
#line 139 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
FLOAT fDamageDir  = m_vDamage  % vFront ;
#line 140 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
if(fDamageDir  < 0){
#line 141 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
iAnim  = GRUNT_ANIM_DEATHBACKWARD ;
#line 142 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}else {
#line 143 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
iAnim  = GRUNT_ANIM_DEATHFORWARD ;
#line 144 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
#line 146 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StartModelAnim  (iAnim  , 0);
#line 147 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return iAnim ;
#line 148 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 150 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
FLOAT CGrunt::WaitForDust(FLOAT3D & vStretch) {
#line 151 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
vStretch  = FLOAT3D (1 , 1 , 2);
#line 152 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
if(GetModelObject  () -> GetAnim  () == GRUNT_ANIM_DEATHBACKWARD )
#line 153 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
{
#line 154 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return 0.5f;
#line 155 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
#line 156 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
else if(GetModelObject  () -> GetAnim  () == GRUNT_ANIM_DEATHFORWARD )
#line 157 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
{
#line 158 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return 1.0f;
#line 159 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
#line 160 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return - 1.0f;
#line 161 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 163 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::DeathNotify(void) {
#line 164 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
ChangeCollisionBoxIndexWhenPossible  (GRUNT_COLLISION_BOX_DEATH );
#line 165 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
en_fDensity  = 500.0f;
#line 166 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 169 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::StandingAnim(void) {
#line 170 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StartModelAnim  (GRUNT_ANIM_IDLE  , AOF_LOOPING  | AOF_NORESTART );
#line 171 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 176 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::RunningAnim(void) {
#line 177 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StartModelAnim  (GRUNT_ANIM_RUN  , AOF_LOOPING  | AOF_NORESTART );
#line 178 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 179 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::WalkingAnim(void) {
#line 180 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
RunningAnim  ();
#line 181 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 182 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::RotatingAnim(void) {
#line 183 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
RunningAnim  ();
#line 184 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 187 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::IdleSound(void) {
#line 188 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PlaySound  (m_soSound  , SOUND_IDLE  , SOF_3D );
#line 189 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 190 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::SightSound(void) {
#line 191 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PlaySound  (m_soSound  , SOUND_SIGHT  , SOF_3D );
#line 192 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 193 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::WoundSound(void) {
#line 194 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PlaySound  (m_soSound  , SOUND_WOUND  , SOF_3D );
#line 195 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 196 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::DeathSound(void) {
#line 197 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PlaySound  (m_soSound  , SOUND_DEATH  , SOF_3D );
#line 198 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
  
#line 201 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
void CGrunt::EnemyPostInit(void) 
#line 202 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
{
#line 204 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_soFire1  . Set3DParameters  (160.0f , 50.0f , 1.0f , 1.0f);
#line 205 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_soFire2  . Set3DParameters  (160.0f , 50.0f , 1.0f , 1.0f);
#line 206 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
BOOL CGrunt::
#line 212 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
Fire(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGrunt_Fire
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGrunt::Fire expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 214 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
if(!(m_gtType  == GT_SOLDIER )){ Jump(STATE_CURRENT,0x01570008, FALSE, EInternal());return TRUE;}
#line 215 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
STATE_CGrunt_SoldierAttack, TRUE;
Jump(STATE_CURRENT, 0x01570001, FALSE, EBegin());return TRUE;}BOOL CGrunt::H0x01570001_Fire_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CGrunt_SoldierAttack, TRUE, EVoid());return TRUE;case EVENTCODE_EEnd: Jump(STATE_CURRENT,0x01570002, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CGrunt::H0x01570002_Fire_02(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570002
const EEnd&__e= (EEnd&)__eeInput;
;Jump(STATE_CURRENT,0x01570007, FALSE, EInternal());return TRUE;}BOOL CGrunt::H0x01570008_Fire_08(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570008
if(!(m_gtType  == GT_COMMANDER )){ Jump(STATE_CURRENT,0x01570006, FALSE, EInternal());return TRUE;}
#line 218 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
STATE_CGrunt_CommanderAttack, TRUE;
Jump(STATE_CURRENT, 0x01570003, FALSE, EBegin());return TRUE;}BOOL CGrunt::H0x01570003_Fire_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CGrunt_CommanderAttack, TRUE, EVoid());return TRUE;case EVENTCODE_EEnd: Jump(STATE_CURRENT,0x01570004, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CGrunt::H0x01570004_Fire_04(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570004
const EEnd&__e= (EEnd&)__eeInput;
;Jump(STATE_CURRENT,0x01570005, FALSE, EInternal());return TRUE;}BOOL CGrunt::H0x01570006_Fire_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570006
{
#line 221 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
ASSERT  (FALSE );
#line 222 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}Jump(STATE_CURRENT,0x01570005, FALSE, EInternal());return TRUE;}
BOOL CGrunt::H0x01570005_Fire_05(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570005
Jump(STATE_CURRENT,0x01570007, FALSE, EInternal());return TRUE;}
BOOL CGrunt::H0x01570007_Fire_07(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570007

#line 223 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
Return(STATE_CURRENT,EReturn  ());
#line 223 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CGrunt::
#line 227 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SoldierAttack(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGrunt_SoldierAttack
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGrunt::SoldierAttack expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 228 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StandingAnimFight  ();
#line 229 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetTimerAfter(0.2f + FRnd  () * 0.25f);
Jump(STATE_CURRENT, 0x0157000a, FALSE, EBegin());return TRUE;}BOOL CGrunt::H0x0157000a_SoldierAttack_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0157000a
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0157000b, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGrunt::H0x0157000b_SoldierAttack_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0157000b
;
#line 231 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StartModelAnim  (GRUNT_ANIM_FIRE  , 0);
#line 232 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
ShootProjectile  (PRT_GRUNT_PROJECTILE_SOL  , FIREPOS_SOLDIER  , ANGLE3D (0 , 0 , 0));
#line 233 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PlaySound  (m_soFire1  , SOUND_FIRE  , SOF_3D );
#line 235 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetTimerAfter(0.15f + FRnd  () * 0.1f);
Jump(STATE_CURRENT, 0x0157000c, FALSE, EBegin());return TRUE;}BOOL CGrunt::H0x0157000c_SoldierAttack_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0157000c
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0157000d, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGrunt::H0x0157000d_SoldierAttack_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0157000d
;
#line 236 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StartModelAnim  (GRUNT_ANIM_FIRE  , 0);
#line 237 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
ShootProjectile  (PRT_GRUNT_PROJECTILE_SOL  , FIREPOS_SOLDIER  , ANGLE3D (0 , 0 , 0));
#line 238 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PlaySound  (m_soFire2  , SOUND_FIRE  , SOF_3D );
#line 241 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetTimerAfter(FRnd  () * 0.333f);
Jump(STATE_CURRENT, 0x0157000e, FALSE, EBegin());return TRUE;}BOOL CGrunt::H0x0157000e_SoldierAttack_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0157000e
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0157000f, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGrunt::H0x0157000f_SoldierAttack_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0157000f
;
#line 242 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
Return(STATE_CURRENT,EEnd  ());
#line 242 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CGrunt::
#line 246 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
CommanderAttack(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGrunt_CommanderAttack
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGrunt::CommanderAttack expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 247 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StandingAnimFight  ();
#line 248 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetTimerAfter(0.2f + FRnd  () * 0.25f);
Jump(STATE_CURRENT, 0x01570011, FALSE, EBegin());return TRUE;}BOOL CGrunt::H0x01570011_CommanderAttack_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570011
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01570012, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGrunt::H0x01570012_CommanderAttack_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570012
;
#line 258 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StartModelAnim  (GRUNT_ANIM_FIRE  , 0);
#line 259 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
ShootProjectile  (PRT_GRUNT_PROJECTILE_COM  , FIREPOS_COMMANDER_DN  , ANGLE3D (- 20 , 0 , 0));
#line 260 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PlaySound  (m_soFire1  , SOUND_FIRE  , SOF_3D );
#line 262 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetTimerAfter(0.035f);
Jump(STATE_CURRENT, 0x01570013, FALSE, EBegin());return TRUE;}BOOL CGrunt::H0x01570013_CommanderAttack_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570013
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01570014, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGrunt::H0x01570014_CommanderAttack_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570014
;
#line 263 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StartModelAnim  (GRUNT_ANIM_FIRE  , 0);
#line 264 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
ShootProjectile  (PRT_GRUNT_PROJECTILE_COM  , FIREPOS_COMMANDER_DN  , ANGLE3D (- 10 , 0 , 0));
#line 265 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PlaySound  (m_soFire2  , SOUND_FIRE  , SOF_3D );
#line 267 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetTimerAfter(0.035f);
Jump(STATE_CURRENT, 0x01570015, FALSE, EBegin());return TRUE;}BOOL CGrunt::H0x01570015_CommanderAttack_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570015
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01570016, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGrunt::H0x01570016_CommanderAttack_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570016
;
#line 268 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StartModelAnim  (GRUNT_ANIM_FIRE  , 0);
#line 269 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
ShootProjectile  (PRT_GRUNT_PROJECTILE_COM  , FIREPOS_COMMANDER_DN  , ANGLE3D (0 , 0 , 0));
#line 270 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PlaySound  (m_soFire1  , SOUND_FIRE  , SOF_3D );
#line 272 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetTimerAfter(0.035f);
Jump(STATE_CURRENT, 0x01570017, FALSE, EBegin());return TRUE;}BOOL CGrunt::H0x01570017_CommanderAttack_07(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570017
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01570018, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGrunt::H0x01570018_CommanderAttack_08(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570018
;
#line 273 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StartModelAnim  (GRUNT_ANIM_FIRE  , 0);
#line 274 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
ShootProjectile  (PRT_GRUNT_PROJECTILE_COM  , FIREPOS_COMMANDER_DN  , ANGLE3D (10 , 0 , 0));
#line 275 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PlaySound  (m_soFire2  , SOUND_FIRE  , SOF_3D );
#line 277 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetTimerAfter(0.035f);
Jump(STATE_CURRENT, 0x01570019, FALSE, EBegin());return TRUE;}BOOL CGrunt::H0x01570019_CommanderAttack_09(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01570019
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0157001a, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGrunt::H0x0157001a_CommanderAttack_10(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0157001a
;
#line 278 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StartModelAnim  (GRUNT_ANIM_FIRE  , 0);
#line 279 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
ShootProjectile  (PRT_GRUNT_PROJECTILE_COM  , FIREPOS_COMMANDER_DN  , ANGLE3D (20 , 0 , 0));
#line 280 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
PlaySound  (m_soFire2  , SOUND_FIRE  , SOF_3D );
#line 282 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetTimerAfter(FRnd  () * 0.5f);
Jump(STATE_CURRENT, 0x0157001b, FALSE, EBegin());return TRUE;}BOOL CGrunt::H0x0157001b_CommanderAttack_11(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0157001b
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0157001c, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CGrunt::H0x0157001c_CommanderAttack_12(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0157001c
;
#line 283 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
Return(STATE_CURRENT,EEnd  ());
#line 283 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CGrunt::
#line 289 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGrunt_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGrunt::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 291 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
InitAsModel  ();
#line 292 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetPhysicsFlags  (EPF_MODEL_WALKING  | EPF_HASLUNGS );
#line 293 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetCollisionFlags  (ECF_MODEL );
#line 294 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetFlags  (GetFlags  () | ENF_ALIVE );
#line 295 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
en_tmMaxHoldBreath  = 5.0f;
#line 296 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
en_fDensity  = 2000.0f;
#line 300 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetModel  (MODEL_GRUNT );
#line 301 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
switch(m_gtType ){
#line 302 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
case GT_SOLDIER : 
#line 304 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetModelMainTexture  (TEXTURE_SOLDIER );
#line 305 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
AddAttachment  (GRUNT_ATTACHMENT_GUN_SMALL  , MODEL_GUN_SOLDIER  , TEXTURE_GUN_SOLDIER );
#line 307 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fWalkSpeed  = FRnd  () + 2.5f;
#line 308 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_aWalkRotateSpeed  = AngleDeg  (FRnd  () * 10.0f + 500.0f);
#line 309 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fAttackRunSpeed  = FRnd  () + 6.5f;
#line 310 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_aAttackRotateSpeed  = AngleDeg  (FRnd  () * 50 + 245.0f);
#line 311 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fCloseRunSpeed  = FRnd  () + 6.5f;
#line 312 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_aCloseRotateSpeed  = AngleDeg  (FRnd  () * 50 + 245.0f);
#line 314 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fAttackDistance  = 80.0f;
#line 315 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fCloseDistance  = 0.0f;
#line 316 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fStopDistance  = 8.0f;
#line 317 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fAttackFireTime  = 2.0f;
#line 318 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fCloseFireTime  = 1.0f;
#line 319 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fIgnoreRange  = 200.0f;
#line 321 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fBlowUpAmount  = 80.0f;
#line 322 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fBodyParts  = 4;
#line 323 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fDamageWounded  = 0.0f;
#line 324 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_iScore  = 500;
#line 325 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetHealth  (40.0f);
#line 326 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fMaxHealth  = 40.0f;
#line 328 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
GetModelObject  () -> StretchModel  (FLOAT3D (STRETCH_SOLDIER  , STRETCH_SOLDIER  , STRETCH_SOLDIER ));
#line 329 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
break ;
#line 331 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
case GT_COMMANDER : 
#line 333 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetModelMainTexture  (TEXTURE_COMMANDER );
#line 334 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
AddAttachment  (GRUNT_ATTACHMENT_GUN_COMMANDER  , MODEL_GUN_COMMANDER  , TEXTURE_GUN_COMMANDER );
#line 336 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fWalkSpeed  = FRnd  () + 2.5f;
#line 337 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_aWalkRotateSpeed  = AngleDeg  (FRnd  () * 10.0f + 500.0f);
#line 338 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fAttackRunSpeed  = FRnd  () + 8.0f;
#line 339 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_aAttackRotateSpeed  = AngleDeg  (FRnd  () * 50 + 245.0f);
#line 340 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fCloseRunSpeed  = FRnd  () + 8.0f;
#line 341 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_aCloseRotateSpeed  = AngleDeg  (FRnd  () * 50 + 245.0f);
#line 343 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fAttackDistance  = 90.0f;
#line 344 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fCloseDistance  = 0.0f;
#line 345 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fStopDistance  = 15.0f;
#line 346 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fAttackFireTime  = 4.0f;
#line 347 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fCloseFireTime  = 2.0f;
#line 349 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fIgnoreRange  = 200.0f;
#line 351 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fBodyParts  = 5;
#line 352 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fDamageWounded  = 0.0f;
#line 353 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_iScore  = 800;
#line 354 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SetHealth  (60.0f);
#line 355 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
m_fMaxHealth  = 60.0f;
#line 357 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
GetModelObject  () -> StretchModel  (FLOAT3D (STRETCH_COMMANDER  , STRETCH_COMMANDER  , STRETCH_COMMANDER ));
#line 358 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
break ;
#line 359 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
}
#line 361 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
ModelChangeNotify  ();
#line 362 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
StandingAnim  ();
#line 365 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_MainLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};