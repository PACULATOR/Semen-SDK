/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/Bullet.es"

#include "StdH.h"

#include <EntitiesMP/Bullet.h>
#include <EntitiesMP/Bullet_tables.h>
CEntityEvent *EBulletInit::MakeCopy(void) { CEntityEvent *peeCopy = new EBulletInit(*this); return peeCopy;}
EBulletInit::EBulletInit() : CEntityEvent(EVENTCODE_EBulletInit) {;
 ClearToDefault(penOwner);
 ClearToDefault(fDamage);
};
#line 16 "C:/MyMod/Sources/EntitiesMP/Bullet.es"

void CBullet_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) 
{
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINSTONE);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINSAND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINREDSAND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINWATER);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINSTONENOSOUND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINSANDNOSOUND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINREDSANDNOSOUND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINWATERNOSOUND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BLOODSPILL);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETTRAIL);
}

void CBullet::SetDefaultProperties(void) {
  m_penOwner = NULL;
  m_fDamage = 0.0f;
  m_vTarget = FLOAT3D(0 , 0 , 0);
  m_vTargetCopy = FLOAT3D(0 , 0 , 0);
  m_vHitPoint = FLOAT3D(0 , 0 , 0);
  m_iBullet = 0;
  m_EdtDamage = DMT_BULLET ;
  m_fBulletSize = 0.0f;
  CEntity::SetDefaultProperties();
}
  
#line 56 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
void CBullet::SetDamage(FLOAT fDamage) {
#line 57 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_fDamage  = fDamage ;
#line 58 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
  
#line 61 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
void CBullet::CalcTarget(FLOAT fRange) {
#line 63 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
AnglesToDirectionVector  (GetPlacement  () . pl_OrientationAngle  , m_vTarget );
#line 64 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_vTarget  *= fRange ;
#line 65 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_vTarget  += GetPlacement  () . pl_PositionVector ;
#line 66 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_vTargetCopy  = m_vTarget ;
#line 67 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
  
#line 69 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
void CBullet::CalcTarget(CEntity * pen,FLOAT fRange) {
#line 70 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT3D vTarget ;
#line 73 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
EntityInfo  * peiTarget  = (EntityInfo  *) (pen  -> GetEntityInfo  ());
#line 74 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
GetEntityInfoPosition  (pen  , peiTarget  -> vTargetCenter  , vTarget );
#line 77 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_vTarget  = (vTarget  - GetPlacement  () . pl_PositionVector ) . Normalize  ();
#line 78 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_vTarget  *= fRange ;
#line 79 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_vTarget  += GetPlacement  () . pl_PositionVector ;
#line 80 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_vTargetCopy  = m_vTarget ;
#line 81 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
  
#line 84 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
void CBullet::CalcJitterTarget(FLOAT fR) {
#line 85 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT3D vJitter ;
#line 96 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT fZ  = FRnd  () * 2.0f - 1.0f;
#line 97 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT fA  = FRnd  () * 360.0f;
#line 98 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT fT  = Sqrt  (1 - (fZ  * fZ ));
#line 99 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vJitter  (1) = fT  * CosFast  (fA );
#line 100 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vJitter  (2) = fT  * SinFast  (fA );
#line 101 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vJitter  (3) = fZ ;
#line 102 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vJitter  = vJitter  * fR  * FRnd  ();
#line 105 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_vTarget  = m_vTargetCopy  + vJitter ;
#line 106 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
  
#line 109 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
void CBullet::CalcJitterTargetFixed(FLOAT fX,FLOAT fY,FLOAT fJitter) {
#line 110 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT fRndX  = FRnd  () * 2.0f - 1.0f;
#line 111 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT fRndY  = FRnd  () * 2.0f - 1.0f;
#line 112 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT3D vX  , vY ;
#line 113 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
const FLOATmatrix3D & m  = GetRotationMatrix  ();
#line 114 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vX  (1) = m  (1 , 1);vX  (2) = m  (2 , 1);vX  (3) = m  (3 , 1);
#line 115 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vY  (1) = m  (1 , 2);vY  (2) = m  (2 , 2);vY  (3) = m  (3 , 2);
#line 117 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_vTarget  = m_vTargetCopy  + (vX  * (fX  + fRndX  * fJitter )) + (vY  * (fY  + fRndY  * fJitter ));
#line 118 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
  
#line 121 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
void CBullet::LaunchBullet(BOOL bSound,BOOL bTrail,BOOL bHitFX) 
#line 122 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 124 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
CCastRay  crRay  (m_penOwner  , GetPlacement  () . pl_PositionVector  , m_vTarget );
#line 125 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
crRay  . cr_bHitPortals  = TRUE ;
#line 126 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
crRay  . cr_bHitTranslucentPortals  = TRUE ;
#line 127 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
crRay  . cr_ttHitModels  = CCastRay  :: TT_COLLISIONBOX ;
#line 128 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
crRay  . cr_bPhysical  = FALSE ;
#line 129 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
crRay  . cr_fTestR  = m_fBulletSize ;
#line 130 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT3D vHitDirection ;
#line 131 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
AnglesToDirectionVector  (GetPlacement  () . pl_OrientationAngle  , vHitDirection );
#line 133 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
INDEX ctCasts  = 0;
#line 134 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
while(ctCasts  < 10)
#line 135 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 136 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(ctCasts  == 0)
#line 137 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 139 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
GetWorld  () -> CastRay  (crRay );
#line 140 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 141 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
else 
#line 142 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 144 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
GetWorld  () -> ContinueCast  (crRay );
#line 145 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 146 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
ctCasts  ++;
#line 149 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(crRay  . cr_penHit  == NULL )
#line 150 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 151 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
break ;
#line 152 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 154 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
const FLOAT fDamageMul  = GetSeriousDamageMultiplier  (m_penOwner );
#line 155 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
InflictDirectDamage  (crRay  . cr_penHit  , m_penOwner  , m_EdtDamage  , m_fDamage  * fDamageMul  , 
#line 156 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
crRay  . cr_vHit  , vHitDirection );
#line 158 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_vHitPoint  = crRay  . cr_vHit ;
#line 161 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(crRay  . cr_penHit  -> GetRenderType  () == RT_BRUSH  && crRay  . cr_pbpoBrushPolygon  != NULL )
#line 162 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 163 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
CBrushPolygon  * pbpo  = crRay  . cr_pbpoBrushPolygon ;
#line 164 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT3D vHitNormal  = FLOAT3D (pbpo  -> bpo_pbplPlane  -> bpl_plAbsolute );
#line 166 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
INDEX iSurfaceType  = pbpo  -> bpo_bppProperties  . bpp_ubSurfaceType ;
#line 167 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
BulletHitType  bhtType  = BHT_BRUSH_STONE ;
#line 169 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
INDEX iContent  = pbpo  -> bpo_pbscSector  -> GetContentType  ();
#line 170 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
CContentType  & ct  = GetWorld  () -> wo_actContentTypes  [ iContent  ];
#line 172 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
bhtType  = (BulletHitType ) GetBulletHitTypeForSurface  (iSurfaceType );
#line 174 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(ct  . ct_ulFlags  & CTF_BREATHABLE_GILLS )
#line 175 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 177 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(iSurfaceType  == SURFACE_WATER )
#line 178 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 179 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vHitNormal  = - vHitNormal ;
#line 181 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
bhtType  = BHT_BRUSH_WATER ;
#line 182 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 184 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
else 
#line 185 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 186 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
bhtType  = BHT_BRUSH_UNDER_WATER ;
#line 187 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 188 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 190 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
BOOL bPassable  = pbpo  -> bpo_ulFlags  & (BPOF_PASSABLE  | BPOF_SHOOTTHRU );
#line 191 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(! bPassable  || iSurfaceType  == SURFACE_WATER ){
#line 192 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
SpawnHitTypeEffect  (this  , bhtType  , bSound  , vHitNormal  , crRay  . cr_vHit  , vHitDirection  , FLOAT3D (0.0f , 0.0f , 0.0f));
#line 193 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 194 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(! bPassable ){
#line 195 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
break ;
#line 196 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 198 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}else {
#line 201 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(crRay  . cr_penHit  -> GetEntityInfo  () != NULL ){
#line 202 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(((EntityInfo  *) crRay  . cr_penHit  -> GetEntityInfo  ()) -> Eeibt  == EIBT_FLESH )
#line 203 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 204 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
CEntity  * penOfFlesh  = crRay  . cr_penHit ;
#line 205 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT3D vHitNormal  = (GetPlacement  () . pl_PositionVector  - m_vTarget ) . Normalize  ();
#line 206 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT3D vOldHitPos  = crRay  . cr_vHit ;
#line 207 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT3D vDistance ;
#line 210 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
GetWorld  () -> ContinueCast  (crRay );
#line 211 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(crRay  . cr_penHit  != NULL  && crRay  . cr_pbpoBrushPolygon  != NULL  && 
#line 212 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
crRay  . cr_penHit  -> GetRenderType  () == RT_BRUSH )
#line 213 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 214 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vDistance  = crRay  . cr_vHit  - vOldHitPos ;
#line 215 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vHitNormal  = FLOAT3D (crRay  . cr_pbpoBrushPolygon  -> bpo_pbplPlane  -> bpl_plAbsolute );
#line 216 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 217 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
else 
#line 218 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 219 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vDistance  = FLOAT3D (0.0f , 0.0f , 0.0f);
#line 220 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vHitNormal  = FLOAT3D (0 , 0 , 0);
#line 221 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 223 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(IsOfClass  (penOfFlesh  , "Gizmo") || 
#line 224 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
IsOfClass  (penOfFlesh  , "Beast"))
#line 225 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 227 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
SpawnHitTypeEffect  (this  , BHT_ACID  , bSound  , vHitNormal  , crRay  . cr_vHit  , vHitDirection  , vDistance );
#line 228 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 229 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
else 
#line 230 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 232 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
SpawnHitTypeEffect  (this  , BHT_FLESH  , bSound  , vHitNormal  , crRay  . cr_vHit  , vHitDirection  , vDistance );
#line 233 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 234 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
break ;
#line 235 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 236 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 239 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
break ;
#line 240 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 241 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 243 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(bTrail )
#line 244 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 245 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
SpawnTrail  ();
#line 246 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 247 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
  
#line 250 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
void CBullet::DestroyBullet(void) {
#line 251 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
Destroy  ();
#line 252 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
  
#line 260 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
void CBullet::SpawnTrail(void) 
#line 261 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
{
#line 263 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
const FLOAT3D & v0  = GetPlacement  () . pl_PositionVector ;
#line 264 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
const FLOAT3D & v1  = m_vHitPoint ;
#line 266 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT3D vD  = v1  - v0 ;
#line 267 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT fD  = vD  . Length  ();
#line 269 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(fD  < 1.0f){
#line 271 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
return ;
#line 272 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 275 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT fLen  = Min  (20.0f , fD );
#line 277 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT3D vPos ;
#line 278 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
if(fLen  < fD ){
#line 279 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vPos  = Lerp  (v0  , v1  , FRnd  () * (fD  - fLen ) / fD );
#line 280 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}else {
#line 281 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vPos  = v0 ;
#line 282 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
#line 284 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
ESpawnEffect  ese ;
#line 285 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
UBYTE  ubRndH  = UBYTE  (8 + FRnd  () * 32);
#line 286 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
UBYTE  ubRndS  = UBYTE  (8 + FRnd  () * 32);
#line 287 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
UBYTE  ubRndV  = UBYTE  (224 + FRnd  () * 32);
#line 288 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
UBYTE  ubRndA  = UBYTE  (32 + FRnd  () * 128);
#line 289 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
ese  . colMuliplier  = HSVToColor  (ubRndH  , ubRndS  , ubRndV ) | ubRndA ;
#line 290 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
ese  . betType  = BET_BULLETTRAIL ;
#line 291 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
ese  . vNormal  = vD  / fD ;
#line 292 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
ese  . vStretch  = FLOAT3D (0.1f , fLen  , 1.0f);
#line 295 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
FLOAT3D vBulletIncommingDirection ;
#line 296 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
vBulletIncommingDirection  = (m_vTarget  - GetPlacement  () . pl_PositionVector ) . Normalize  ();
#line 297 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
CPlacement3D plHit  = CPlacement3D (vPos  - vBulletIncommingDirection  * 0.1f , GetPlacement  () . pl_OrientationAngle );
#line 298 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
CEntityPointer penHit  = CreateEntity  (plHit  , CLASS_BASIC_EFFECT );
#line 299 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
penHit  -> Initialize  (ese );
#line 300 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
}
BOOL CBullet::
#line 304 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBullet_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EBulletInit, "CBullet::Main expects 'EBulletInit' as input!");  const EBulletInit &eInit = (const EBulletInit &)__eeInput;
#line 307 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
ASSERT  (eInit  . penOwner  != NULL );
#line 308 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_penOwner  = eInit  . penOwner ;
#line 309 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_fDamage  = eInit  . fDamage ;
#line 311 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
InitAsVoid  ();
#line 312 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 313 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 316 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
m_iBullet  = 0;
#line 317 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
Return(STATE_CURRENT,EVoid());
#line 317 "C:/MyMod/Sources/EntitiesMP/Bullet.es"
return TRUE; ASSERT(FALSE); return TRUE;};