/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/Flame.es"

#include "StdH.h"
#define TM_APPLY_DAMAGE_QUANTUM 0.25f
#define TM_APPLY_WHOLE_DAMAGE 7.5f
#define DAMAGE_AMMOUNT 30.0f
#define MIN_DAMAGE_QUANTUM (DAMAGE_AMMOUNT/TM_APPLY_WHOLE_DAMAGE*TM_APPLY_DAMAGE_QUANTUM)
#define MAX_DAMAGE_QUANTUM (MIN_DAMAGE_QUANTUM*10.0f)
#define DEATH_BURN_TIME 4.0f

#include "EntitiesMP/MovingBrush.h"

#include <EntitiesMP/Flame.h>
#include <EntitiesMP/Flame_tables.h>
CEntityEvent *EFlame::MakeCopy(void) { CEntityEvent *peeCopy = new EFlame(*this); return peeCopy;}
EFlame::EFlame() : CEntityEvent(EVENTCODE_EFlame) {;
 ClearToDefault(penOwner);
 ClearToDefault(penAttach);
};
CEntityEvent *EStopFlaming::MakeCopy(void) { CEntityEvent *peeCopy = new EStopFlaming(*this); return peeCopy;}
EStopFlaming::EStopFlaming() : CEntityEvent(EVENTCODE_EStopFlaming) {;
 ClearToDefault(m_bNow);
};
#line 27 "C:/MyMod/Sources/EntitiesMP/Flame.es"

void CFlame_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) 
{
  pdec->PrecacheModel(MODEL_FLAME);
  pdec->PrecacheTexture(TEXTURE_FLAME);
  pdec->PrecacheSound(SOUND_FLAME);
}

void CFlame::SetDefaultProperties(void) {
  m_penOwner = NULL;
  m_penAttach = NULL;
  m_bLoop = FALSE ;
  m_vHitPoint = FLOAT3D(0.0f , 0.0f , 0.0f);
  m_soEffect.SetOwner(this);
m_soEffect.Stop_internal();
  m_tmStart = 0.0f;
  m_fDamageToApply = 0.0f;
  m_fDamageStep = 0.0f;
  m_fAppliedDamage = 0.0f;
  m_tmFirstStart = 0.0f;
  m_ctFlames = 0;
  m_vPos01 = FLOAT3D(0 , 0 , 0);
  m_vPos02 = FLOAT3D(0 , 0 , 0);
  m_vPos03 = FLOAT3D(0 , 0 , 0);
  m_vPos04 = FLOAT3D(0 , 0 , 0);
  m_vPos05 = FLOAT3D(0 , 0 , 0);
  m_vPos06 = FLOAT3D(0 , 0 , 0);
  m_vPos07 = FLOAT3D(0 , 0 , 0);
  m_vPos08 = FLOAT3D(0 , 0 , 0);
  m_vPos09 = FLOAT3D(0 , 0 , 0);
  m_vPos10 = FLOAT3D(0 , 0 , 0);
  m_vPlaneNormal = FLOAT3D(0 , 0 , 0);
  m_bBurningBrush = FALSE ;
  m_tmDeathParticlesStart = 1e6;
  m_penPrediction = NULL;
  CMovableModelEntity::SetDefaultProperties();
}
  
#line 86 "C:/MyMod/Sources/EntitiesMP/Flame.es"
void CFlame::AddDependentsToPrediction(void) 
#line 87 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 88 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_penOwner  -> AddToPrediction  ();
#line 89 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
  
#line 91 "C:/MyMod/Sources/EntitiesMP/Flame.es"
void CFlame::PostMoving(void) {
#line 92 "C:/MyMod/Sources/EntitiesMP/Flame.es"
CMovableModelEntity  :: PostMoving  ();
#line 95 "C:/MyMod/Sources/EntitiesMP/Flame.es"
CContentType  & ctDn  = GetWorld  () -> wo_actContentTypes  [ en_iDnContent  ];
#line 97 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(! (ctDn  . ct_ulFlags  & CTF_BREATHABLE_LUNGS )){
#line 98 "C:/MyMod/Sources/EntitiesMP/Flame.es"
EStopFlaming  esf ;
#line 99 "C:/MyMod/Sources/EntitiesMP/Flame.es"
esf  . m_bNow  = TRUE ;
#line 100 "C:/MyMod/Sources/EntitiesMP/Flame.es"
SendEvent  (esf );
#line 101 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 104 "C:/MyMod/Sources/EntitiesMP/Flame.es"
en_ulFlags  &= ~ ENF_INRENDERING ;
#line 106 "C:/MyMod/Sources/EntitiesMP/Flame.es"
en_plLastPlacement  = en_plPlacement ;
#line 107 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
  
#line 110 "C:/MyMod/Sources/EntitiesMP/Flame.es"
void CFlame::Read_t(CTStream * istr) 
#line 111 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 112 "C:/MyMod/Sources/EntitiesMP/Flame.es"
CMovableModelEntity  :: Read_t  (istr );
#line 113 "C:/MyMod/Sources/EntitiesMP/Flame.es"
SetupLightSource  ();
#line 114 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
  
#line 116 "C:/MyMod/Sources/EntitiesMP/Flame.es"
BOOL CFlame::IsPointInsidePolygon(const FLOAT3D & vPos,CBrushPolygon * pbpo) 
#line 117 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 118 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOATplane3D & plPlane  = pbpo  -> bpo_pbplPlane  -> bpl_plAbsolute ;
#line 120 "C:/MyMod/Sources/EntitiesMP/Flame.es"
INDEX iMajorAxis1  , iMajorAxis2 ;
#line 121 "C:/MyMod/Sources/EntitiesMP/Flame.es"
GetMajorAxesForPlane  (plPlane  , iMajorAxis1  , iMajorAxis2 );
#line 124 "C:/MyMod/Sources/EntitiesMP/Flame.es"
CIntersector  isIntersector  (vPos  (iMajorAxis1 ) , vPos  (iMajorAxis2 ));
#line 126 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FOREACHINSTATICARRAY  (pbpo  -> bpo_abpePolygonEdges  , CBrushPolygonEdge  , itbpePolygonEdge ){
#line 128 "C:/MyMod/Sources/EntitiesMP/Flame.es"
const FLOAT3D & vVertex0  = itbpePolygonEdge  -> bpe_pbedEdge  -> bed_pbvxVertex0  -> bvx_vAbsolute ;
#line 129 "C:/MyMod/Sources/EntitiesMP/Flame.es"
const FLOAT3D & vVertex1  = itbpePolygonEdge  -> bpe_pbedEdge  -> bed_pbvxVertex1  -> bvx_vAbsolute ;
#line 131 "C:/MyMod/Sources/EntitiesMP/Flame.es"
isIntersector  . AddEdge  (
#line 132 "C:/MyMod/Sources/EntitiesMP/Flame.es"
vVertex0  (iMajorAxis1 ) , vVertex0  (iMajorAxis2 ) , 
#line 133 "C:/MyMod/Sources/EntitiesMP/Flame.es"
vVertex1  (iMajorAxis1 ) , vVertex1  (iMajorAxis2 ));
#line 134 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 136 "C:/MyMod/Sources/EntitiesMP/Flame.es"
return isIntersector  . IsIntersecting  ();
#line 137 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
  
#line 140 "C:/MyMod/Sources/EntitiesMP/Flame.es"
CLightSource * CFlame::GetLightSource(void) 
#line 141 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 142 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(! IsPredictor  ()){
#line 143 "C:/MyMod/Sources/EntitiesMP/Flame.es"
return & m_lsLightSource ;
#line 144 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}else {
#line 145 "C:/MyMod/Sources/EntitiesMP/Flame.es"
return NULL ;
#line 146 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 147 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
  
#line 150 "C:/MyMod/Sources/EntitiesMP/Flame.es"
void CFlame::RenderParticles(void) 
#line 151 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 152 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT fTimeFactor  = CalculateRatio  (_pTimer  -> CurrentTick  () , m_tmFirstStart  , m_tmStart  + TM_APPLY_WHOLE_DAMAGE  , 0.05f , 0.2f);
#line 153 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT fDeathFactor  = 1.0f;
#line 154 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(_pTimer  -> CurrentTick  () > m_tmDeathParticlesStart )
#line 155 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 156 "C:/MyMod/Sources/EntitiesMP/Flame.es"
fDeathFactor  = 1.0f - Clamp  ((_pTimer  -> CurrentTick  () - m_tmDeathParticlesStart ) / DEATH_BURN_TIME  , 0.0f , 1.0f);
#line 157 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 158 "C:/MyMod/Sources/EntitiesMP/Flame.es"
CEntity  * penParent  = GetParent  ();
#line 159 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT fPower  = ClampUp  (m_fDamageStep  - MIN_DAMAGE_QUANTUM  , MAX_DAMAGE_QUANTUM ) / MAX_DAMAGE_QUANTUM ;
#line 160 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(penParent  != NULL )
#line 161 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 162 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if((penParent  -> en_RenderType  == CEntity  :: RT_MODEL  || penParent  -> en_RenderType  == CEntity  :: RT_EDITORMODEL  || 
#line 163 "C:/MyMod/Sources/EntitiesMP/Flame.es"
penParent  -> en_RenderType  == CEntity  :: RT_SKAMODEL  || penParent  -> en_RenderType  == CEntity  :: RT_SKAEDITORMODEL ) && 
#line 164 "C:/MyMod/Sources/EntitiesMP/Flame.es"
(Particle_GetViewer  () != penParent ))
#line 165 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 166 "C:/MyMod/Sources/EntitiesMP/Flame.es"
Particles_Burning  (penParent  , fPower  , fTimeFactor  * fDeathFactor );
#line 167 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 168 "C:/MyMod/Sources/EntitiesMP/Flame.es"
else 
#line 169 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 170 "C:/MyMod/Sources/EntitiesMP/Flame.es"
Particles_BrushBurning  (this  , & m_vPos01  , m_ctFlames  , m_vPlaneNormal  , fPower  , fTimeFactor  * fDeathFactor );
#line 171 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 172 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 173 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
  
#line 176 "C:/MyMod/Sources/EntitiesMP/Flame.es"
void CFlame::SetupLightSource(void) 
#line 177 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 179 "C:/MyMod/Sources/EntitiesMP/Flame.es"
CLightSource  lsNew ;
#line 180 "C:/MyMod/Sources/EntitiesMP/Flame.es"
lsNew  . ls_ulFlags  = LSF_NONPERSISTENT  | LSF_DYNAMIC ;
#line 181 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(m_bBurningBrush )
#line 182 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 183 "C:/MyMod/Sources/EntitiesMP/Flame.es"
UBYTE  ubRndH  = UBYTE  (25 + (FLOAT (rand  ()) / RAND_MAX  - 0.5f) * 28);
#line 184 "C:/MyMod/Sources/EntitiesMP/Flame.es"
UBYTE  ubRndS  = 166;
#line 185 "C:/MyMod/Sources/EntitiesMP/Flame.es"
UBYTE  ubRndV  = 48;
#line 186 "C:/MyMod/Sources/EntitiesMP/Flame.es"
lsNew  . ls_colColor  = HSVToColor  (ubRndH  , ubRndS  , ubRndV );
#line 188 "C:/MyMod/Sources/EntitiesMP/Flame.es"
lsNew  . ls_rFallOff  = 4.0f;
#line 189 "C:/MyMod/Sources/EntitiesMP/Flame.es"
lsNew  . ls_rHotSpot  = 0.2f;
#line 190 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 191 "C:/MyMod/Sources/EntitiesMP/Flame.es"
else 
#line 192 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 193 "C:/MyMod/Sources/EntitiesMP/Flame.es"
lsNew  . ls_colColor  = 0x8F8F5000;
#line 194 "C:/MyMod/Sources/EntitiesMP/Flame.es"
lsNew  . ls_rFallOff  = 6.0f;
#line 195 "C:/MyMod/Sources/EntitiesMP/Flame.es"
lsNew  . ls_rHotSpot  = 0.50f;
#line 196 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 197 "C:/MyMod/Sources/EntitiesMP/Flame.es"
lsNew  . ls_plftLensFlare  = NULL ;
#line 198 "C:/MyMod/Sources/EntitiesMP/Flame.es"
lsNew  . ls_ubPolygonalMask  = 0;
#line 199 "C:/MyMod/Sources/EntitiesMP/Flame.es"
lsNew  . ls_paoLightAnimation  = NULL ;
#line 201 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_lsLightSource  . ls_penEntity  = this ;
#line 202 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_lsLightSource  . SetLightSource  (lsNew );
#line 203 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
BOOL CFlame::
#line 210 "C:/MyMod/Sources/EntitiesMP/Flame.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CFlame_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EFlame, "CFlame::Main expects 'EFlame' as input!");  const EFlame &ef = (const EFlame &)__eeInput;
#line 212 "C:/MyMod/Sources/EntitiesMP/Flame.es"
ASSERT  (ef  . penOwner  != NULL );
#line 213 "C:/MyMod/Sources/EntitiesMP/Flame.es"
ASSERT  (ef  . penAttach  != NULL );
#line 214 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_penOwner  = ef  . penOwner ;
#line 215 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_penAttach  = ef  . penAttach ;
#line 217 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_tmStart  = _pTimer  -> CurrentTick  ();
#line 218 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_tmFirstStart  = m_tmStart ;
#line 219 "C:/MyMod/Sources/EntitiesMP/Flame.es"
SetParent  (ef  . penAttach );
#line 221 "C:/MyMod/Sources/EntitiesMP/Flame.es"
InitAsEditorModel  ();
#line 222 "C:/MyMod/Sources/EntitiesMP/Flame.es"
SetPhysicsFlags  (EPF_MODEL_FLYING );
#line 223 "C:/MyMod/Sources/EntitiesMP/Flame.es"
SetCollisionFlags  (ECF_FLAME );
#line 224 "C:/MyMod/Sources/EntitiesMP/Flame.es"
SetFlags  (GetFlags  () | ENF_SEETHROUGH );
#line 226 "C:/MyMod/Sources/EntitiesMP/Flame.es"
SetModel  (MODEL_FLAME );
#line 227 "C:/MyMod/Sources/EntitiesMP/Flame.es"
SetModelMainTexture  (TEXTURE_FLAME );
#line 228 "C:/MyMod/Sources/EntitiesMP/Flame.es"
ModelChangeNotify  ();
#line 231 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_soEffect  . Set3DParameters  (10.0f , 1.0f , 1.0f , 1.0f);
#line 232 "C:/MyMod/Sources/EntitiesMP/Flame.es"
PlaySound  (m_soEffect  , SOUND_FLAME  , SOF_3D  | SOF_LOOP );
#line 235 "C:/MyMod/Sources/EntitiesMP/Flame.es"
AddToMovers  ();
#line 237 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_bBurningBrush  = FALSE ;
#line 238 "C:/MyMod/Sources/EntitiesMP/Flame.es"
BOOL bAllowFlame  = TRUE ;
#line 239 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(! (ef  . penAttach  -> en_RenderType  == CEntity  :: RT_MODEL  || ef  . penAttach  -> en_RenderType  == CEntity  :: RT_EDITORMODEL  || 
#line 240 "C:/MyMod/Sources/EntitiesMP/Flame.es"
ef  . penAttach  -> en_RenderType  == CEntity  :: RT_SKAMODEL  || ef  . penAttach  -> en_RenderType  == CEntity  :: RT_SKAEDITORMODEL ))
#line 241 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 242 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_bBurningBrush  = TRUE ;
#line 243 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT3D vPos  = GetPlacement  () . pl_PositionVector ;
#line 244 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOATplane3D plPlane ;
#line 245 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT fDistanceToEdge ;
#line 246 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FindSectorsAroundEntity  ();
#line 247 "C:/MyMod/Sources/EntitiesMP/Flame.es"
CBrushPolygon  * pbpo  = NULL ;
#line 248 "C:/MyMod/Sources/EntitiesMP/Flame.es"
pbpo  = GetNearestPolygon  (vPos  , plPlane  , fDistanceToEdge );
#line 249 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT3D vBrushPos  = ef  . penAttach  -> GetPlacement  () . pl_PositionVector ;
#line 250 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOATmatrix3D mBrushRotInv  = ! ef  . penAttach  -> GetRotationMatrix  ();
#line 251 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(pbpo  != NULL  && pbpo  -> bpo_pbscSector  -> bsc_pbmBrushMip  -> bm_pbrBrush  -> br_penEntity  == ef  . penAttach )
#line 252 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 253 "C:/MyMod/Sources/EntitiesMP/Flame.es"
plPlane  = pbpo  -> bpo_pbplPlane  -> bpl_plAbsolute ;
#line 254 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_vPlaneNormal  = (FLOAT3D &) plPlane ;
#line 255 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_vPlaneNormal  . Normalize  ();
#line 257 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT3D vU  , vV ;
#line 259 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(plPlane  (2) < - 0.1f)
#line 260 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 261 "C:/MyMod/Sources/EntitiesMP/Flame.es"
bAllowFlame  = FALSE ;
#line 262 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 265 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(Abs  (plPlane  (2)) > 0.5){
#line 267 "C:/MyMod/Sources/EntitiesMP/Flame.es"
vU  = FLOAT3D (1.0f , 0.0f , 0.0f) * m_vPlaneNormal ;
#line 269 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}else {
#line 271 "C:/MyMod/Sources/EntitiesMP/Flame.es"
vU  = FLOAT3D (0.0f , 1.0f , 0.0f) * m_vPlaneNormal ;
#line 272 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 274 "C:/MyMod/Sources/EntitiesMP/Flame.es"
vU  . Normalize  ();
#line 276 "C:/MyMod/Sources/EntitiesMP/Flame.es"
vV  = vU  * m_vPlaneNormal ;
#line 277 "C:/MyMod/Sources/EntitiesMP/Flame.es"
vV  . Normalize  ();
#line 280 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_ctFlames  = 0;
#line 281 "C:/MyMod/Sources/EntitiesMP/Flame.es"
for(INDEX iTest  = 0;iTest  < 20;iTest  ++)
#line 282 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 283 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT fA  = FRnd  () * 360.0f;
#line 284 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT fR  = FRnd  () * 2.0f;
#line 285 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT3D vRndV  = vV  * fR  * SinFast  (fA );
#line 286 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT3D vRndU  = vU  * fR  * CosFast  (fA );
#line 287 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT3D vRndPos  = vPos ;
#line 288 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(iTest  != 0)
#line 289 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 290 "C:/MyMod/Sources/EntitiesMP/Flame.es"
vRndPos  += vRndV  + vRndU ;
#line 291 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 293 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT3D vProjectedRndPos  = plPlane  . ProjectPoint  (vRndPos );
#line 294 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(IsPointInsidePolygon  (vProjectedRndPos  , pbpo ))
#line 295 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 296 "C:/MyMod/Sources/EntitiesMP/Flame.es"
(& m_vPos01 ) [ m_ctFlames  ] = (vProjectedRndPos  - vBrushPos ) * mBrushRotInv ;
#line 297 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_ctFlames  ++;
#line 298 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(m_ctFlames  == 6){break ;};
#line 299 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 300 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 301 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 302 "C:/MyMod/Sources/EntitiesMP/Flame.es"
else 
#line 303 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 304 "C:/MyMod/Sources/EntitiesMP/Flame.es"
bAllowFlame  = FALSE ;
#line 305 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 306 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 308 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(bAllowFlame )
#line 309 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 310 "C:/MyMod/Sources/EntitiesMP/Flame.es"
SetupLightSource  ();
#line 311 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 313 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_bLoop  = bAllowFlame ;
#line 314 "C:/MyMod/Sources/EntitiesMP/Flame.es"
Jump(STATE_CURRENT,0x01f80004, FALSE, EInternal());return TRUE;}BOOL CFlame::H0x01f80004_Main_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01f80004
if(!(m_bLoop )){ Jump(STATE_CURRENT,0x01f80005, FALSE, EInternal());return TRUE;}
#line 315 "C:/MyMod/Sources/EntitiesMP/Flame.es"
SetTimerAfter(TM_APPLY_DAMAGE_QUANTUM );
Jump(STATE_CURRENT, 0x01f80002, FALSE, EBegin());return TRUE;}BOOL CFlame::H0x01f80002_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01f80002
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 319 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(m_penAttach  == NULL  || (m_penAttach  -> GetFlags  () & ENF_DELETED )){
#line 321 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_bLoop  = FALSE ;
#line 322 "C:/MyMod/Sources/EntitiesMP/Flame.es"
UnsetTimer();Jump(STATE_CURRENT,0x01f80003, FALSE, EInternal());return TRUE;
#line 323 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 325 "C:/MyMod/Sources/EntitiesMP/Flame.es"
const FLOAT fDamageMul  = GetSeriousDamageMultiplier  (m_penOwner );
#line 326 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT fDamageToApply  = fDamageMul  * (m_fDamageToApply  / TM_APPLY_WHOLE_DAMAGE  * TM_APPLY_DAMAGE_QUANTUM ) * m_fDamageStep ;
#line 327 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_penAttach  -> InflictDirectDamage  (m_penAttach  , m_penOwner  , DMT_BURNING  , fDamageToApply  , 
#line 328 "C:/MyMod/Sources/EntitiesMP/Flame.es"
GetPlacement  () . pl_PositionVector  , - en_vGravityDir );
#line 329 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_fAppliedDamage  += fDamageToApply ;
#line 330 "C:/MyMod/Sources/EntitiesMP/Flame.es"
return TRUE;
#line 331 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}ASSERT(FALSE);break;case(EVENTCODE_EFlame):{const EFlame&ef= (EFlame&)__eeInput;

#line 333 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_penOwner  = ef  . penOwner ;
#line 334 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT fTimeLeft  = m_tmStart  + TM_APPLY_WHOLE_DAMAGE  - _pTimer  -> CurrentTick  ();
#line 335 "C:/MyMod/Sources/EntitiesMP/Flame.es"
FLOAT fDamageLeft  = (fTimeLeft  / TM_APPLY_DAMAGE_QUANTUM ) * m_fDamageStep ;
#line 336 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_fDamageToApply  = ClampUp  (fDamageLeft  + DAMAGE_AMMOUNT  , 80.0f);
#line 337 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_tmStart  = _pTimer  -> CurrentTick  ();
#line 338 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_fDamageStep  = m_fDamageToApply  / (TM_APPLY_WHOLE_DAMAGE  / TM_APPLY_DAMAGE_QUANTUM );
#line 339 "C:/MyMod/Sources/EntitiesMP/Flame.es"
return TRUE;
#line 340 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStopFlaming):{const EStopFlaming&esf= (EStopFlaming&)__eeInput;

#line 342 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(! esf  . m_bNow )
#line 343 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 344 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_tmDeathParticlesStart  = _pTimer  -> CurrentTick  ();
#line 345 "C:/MyMod/Sources/EntitiesMP/Flame.es"
return TRUE;
#line 346 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 347 "C:/MyMod/Sources/EntitiesMP/Flame.es"
else 
#line 348 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 349 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_bLoop  = FALSE ;
#line 350 "C:/MyMod/Sources/EntitiesMP/Flame.es"
UnsetTimer();Jump(STATE_CURRENT,0x01f80003, FALSE, EInternal());return TRUE;
#line 351 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}
#line 352 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}ASSERT(FALSE);break;case(EVENTCODE_EBrushDestroyed):{const EBrushDestroyed&e= (EBrushDestroyed&)__eeInput;

#line 354 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_bLoop  = FALSE ;
#line 355 "C:/MyMod/Sources/EntitiesMP/Flame.es"
UnsetTimer();Jump(STATE_CURRENT,0x01f80003, FALSE, EInternal());return TRUE;
#line 356 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x01f80003, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 358 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}return TRUE;}BOOL CFlame::H0x01f80003_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01f80003

#line 359 "C:/MyMod/Sources/EntitiesMP/Flame.es"
if(_pTimer  -> CurrentTick  () > m_tmStart  + TM_APPLY_WHOLE_DAMAGE )
#line 360 "C:/MyMod/Sources/EntitiesMP/Flame.es"
{
#line 361 "C:/MyMod/Sources/EntitiesMP/Flame.es"
m_bLoop  = FALSE ;
#line 362 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}Jump(STATE_CURRENT,0x01f80004, FALSE, EInternal());return TRUE;
#line 363 "C:/MyMod/Sources/EntitiesMP/Flame.es"
}BOOL CFlame::H0x01f80005_Main_04(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01f80005

#line 366 "C:/MyMod/Sources/EntitiesMP/Flame.es"
Destroy  ();
#line 367 "C:/MyMod/Sources/EntitiesMP/Flame.es"
Return(STATE_CURRENT,EVoid());
#line 367 "C:/MyMod/Sources/EntitiesMP/Flame.es"
return TRUE; ASSERT(FALSE); return TRUE;};