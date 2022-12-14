/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/Light.es"

#include "StdH.h"

#include <EntitiesMP/Light.h>
#include <EntitiesMP/Light_tables.h>
#line 33 "C:/MyMod/Sources/EntitiesMP/Light.es"


void CLight_OnInitClass(void)
{
  // init lens flares effects
  InitLensFlares();
}

void CLight_OnEndClass(void)
{
  // close lens flares effects
  CloseLensFlares();
}


void CLight::SetDefaultProperties(void) {
  m_colColor = C_GRAY ;
  m_colAmbient = C_BLACK ;
  m_rFallOffRange = 8.0f;
  m_rHotSpotRange = 0.0f;
  m_itIllumination = 0;
  m_ltType = LT_POINT ;
  m_strDescription = "";
  m_strName = "Light";
  m_bDarkLight = FALSE ;
  m_fNearClip = 0.1f;
  m_fFarClip = 0.01f;
  m_bSubstractSectorAmbient = FALSE ;
  m_bRenderAsSmallLight = FALSE ;
  m_lftLensFlare = LFT_NONE ;
  m_bBackground = FALSE ;
  m_bLensFlareOnly = FALSE ;
  m_fnmLightAnimation = CTString("");
  m_iLightAnimation = 0;
  m_tmOffsetPhase = 0.0f;
  m_aoLightAnimation.SetData(NULL);

  m_bTargetable = FALSE ;
  m_bDynamic = FALSE ;
  m_bDiffusion = TRUE ;
  m_fnmAmbientLightAnimation = CTString("");
  m_iAmbientLightAnimation = 0;
  m_aoAmbientLightAnimation.SetData(NULL);

  CEntity::SetDefaultProperties();
}
  
#line 94 "C:/MyMod/Sources/EntitiesMP/Light.es"
CAnimData * CLight::GetAnimData(SLONG slPropertyOffset) 
#line 95 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 96 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(slPropertyOffset  == offsetof  (CLight  , m_iLightAnimation ))
#line 97 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 98 "C:/MyMod/Sources/EntitiesMP/Light.es"
return m_aoLightAnimation  . GetData  ();
#line 99 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 100 "C:/MyMod/Sources/EntitiesMP/Light.es"
else if(slPropertyOffset  == offsetof  (CLight  , m_iAmbientLightAnimation ))
#line 101 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 102 "C:/MyMod/Sources/EntitiesMP/Light.es"
return m_aoAmbientLightAnimation  . GetData  ();
#line 103 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 104 "C:/MyMod/Sources/EntitiesMP/Light.es"
else 
#line 105 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 106 "C:/MyMod/Sources/EntitiesMP/Light.es"
return CEntity  :: GetAnimData  (slPropertyOffset );
#line 107 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 108 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
  
#line 110 "C:/MyMod/Sources/EntitiesMP/Light.es"
BOOL CLight::IsTargetable(void)const 
#line 111 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 112 "C:/MyMod/Sources/EntitiesMP/Light.es"
return m_bTargetable ;
#line 113 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
  
#line 115 "C:/MyMod/Sources/EntitiesMP/Light.es"
BOOL CLight::IsImportant(void)const 
#line 116 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 117 "C:/MyMod/Sources/EntitiesMP/Light.es"
return (m_ltType  == LT_DIRECTIONAL );
#line 118 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
  
#line 121 "C:/MyMod/Sources/EntitiesMP/Light.es"
BOOL CLight::HandleEvent(const CEntityEvent & ee) 
#line 122 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 124 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(ee  . ee_slEvent  == EVENTCODE_ERangeModelDestruction )
#line 125 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 127 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_colColor  = C_BLACK ;
#line 128 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_colAmbient  = C_BLACK ;
#line 129 "C:/MyMod/Sources/EntitiesMP/Light.es"
CLightSource  lsNew ;
#line 130 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetupLightSource  (lsNew );
#line 131 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_lsLightSource  . SetLightSource  (lsNew );
#line 132 "C:/MyMod/Sources/EntitiesMP/Light.es"
return TRUE ;
#line 134 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 135 "C:/MyMod/Sources/EntitiesMP/Light.es"
else if(ee  . ee_slEvent  == EVENTCODE_EChangeAnim )
#line 136 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 137 "C:/MyMod/Sources/EntitiesMP/Light.es"
EChangeAnim  & eChange  = (EChangeAnim  &) ee ;
#line 140 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_iLightAnimation  = eChange  . iLightAnim ;
#line 141 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_aoLightAnimation  . GetData  () != NULL )
#line 142 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 143 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_aoLightAnimation  . PlayAnim  (m_iLightAnimation  , eChange  . bLightLoop  ? AOF_LOOPING  : 0);
#line 144 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 147 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_iAmbientLightAnimation  = eChange  . iAmbientLightAnim ;
#line 148 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_aoAmbientLightAnimation  . GetData  () != NULL )
#line 149 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 150 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_aoAmbientLightAnimation  . PlayAnim  (m_iAmbientLightAnimation  , eChange  . bAmbientLightLoop  ? AOF_LOOPING  : 0);
#line 151 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 154 "C:/MyMod/Sources/EntitiesMP/Light.es"
if((m_aoLightAnimation  . GetData  () == NULL ) && (m_aoAmbientLightAnimation  . GetData  () == NULL ))
#line 155 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 156 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_colColor  = eChange  . colDiffuse ;
#line 157 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_colAmbient  = eChange  . colAmbient ;
#line 158 "C:/MyMod/Sources/EntitiesMP/Light.es"
CLightSource  lsNew ;
#line 159 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetupLightSource  (lsNew );
#line 160 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_lsLightSource  . SetLightSource  (lsNew );
#line 161 "C:/MyMod/Sources/EntitiesMP/Light.es"
return TRUE ;
#line 162 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 163 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 164 "C:/MyMod/Sources/EntitiesMP/Light.es"
return FALSE ;
#line 165 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
  
#line 168 "C:/MyMod/Sources/EntitiesMP/Light.es"
void CLight::MirrorAndStretch(FLOAT fStretch,BOOL bMirrorX) 
#line 169 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 171 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_rFallOffRange  *= fStretch ;
#line 172 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_rHotSpotRange  *= fStretch ;
#line 173 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_fNearClip  *= fStretch ;
#line 174 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_fFarClip  *= fStretch ;
#line 176 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
  
#line 179 "C:/MyMod/Sources/EntitiesMP/Light.es"
CLightSource * CLight::GetLightSource(void) 
#line 180 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 182 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(! m_bdfInitialized  . bdf_bValue ){
#line 184 "C:/MyMod/Sources/EntitiesMP/Light.es"
CLightSource  lsNew ;
#line 185 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetupLightSource  (lsNew );
#line 186 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_lsLightSource  . SetLightSourceWithNoDiscarding  (lsNew );
#line 187 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_bdfInitialized  . bdf_bValue  = TRUE ;
#line 188 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 189 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(! IsPredictor  ()){
#line 190 "C:/MyMod/Sources/EntitiesMP/Light.es"
return & m_lsLightSource ;
#line 191 "C:/MyMod/Sources/EntitiesMP/Light.es"
}else {
#line 192 "C:/MyMod/Sources/EntitiesMP/Light.es"
return NULL ;
#line 193 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 194 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
  
#line 197 "C:/MyMod/Sources/EntitiesMP/Light.es"
void CLight::SetupLightSource(CLightSource & lsNew) 
#line 198 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 199 "C:/MyMod/Sources/EntitiesMP/Light.es"
switch(m_ltType ){
#line 200 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LT_POINT : 
#line 201 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LT_STRONG_POINT : 
#line 202 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_ulFlags  = LSF_CASTSHADOWS ;
#line 203 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 204 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LT_DIRECTIONAL : 
#line 205 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_ulFlags  = LSF_DIRECTIONAL  | LSF_CASTSHADOWS ;
#line 206 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 207 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LT_STRONG_AMBIENT : 
#line 208 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LT_AMBIENT : 
#line 209 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_ulFlags  = 0;
#line 210 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 211 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 212 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_bSubstractSectorAmbient ){lsNew  . ls_ulFlags  |= LSF_SUBSTRACTSECTORAMBIENT ;}
#line 213 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_bLensFlareOnly ){lsNew  . ls_ulFlags  |= LSF_LENSFLAREONLY ;}
#line 214 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_bDynamic ){lsNew  . ls_ulFlags  |= LSF_DYNAMIC ;}
#line 216 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_bDarkLight ){
#line 217 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_ltType  == LT_DIRECTIONAL ){
#line 218 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_ulFlags  &= ~ LSF_DARKLIGHT ;
#line 219 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_bDarkLight  = FALSE ;
#line 220 "C:/MyMod/Sources/EntitiesMP/Light.es"
}else {
#line 221 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_ulFlags  |= LSF_DARKLIGHT ;
#line 222 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 223 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 225 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_bDiffusion ){
#line 226 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_bDynamic  || m_ltType  == LT_AMBIENT  || m_ltType  == LT_STRONG_AMBIENT ){
#line 227 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_ulFlags  &= ~ LSF_DIFFUSION ;
#line 228 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_bDiffusion  = FALSE ;
#line 229 "C:/MyMod/Sources/EntitiesMP/Light.es"
}else {
#line 230 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_ulFlags  |= LSF_DIFFUSION ;
#line 231 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 232 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 234 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_rHotSpot  = m_rHotSpotRange ;
#line 235 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_rFallOff  = m_rFallOffRange ;
#line 236 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_fNearClipDistance  = m_fNearClip ;
#line 237 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_fFarClipDistance  = m_fFarClip ;
#line 239 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_ltType  == LT_STRONG_AMBIENT  || m_ltType  == LT_STRONG_POINT ){
#line 240 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_rHotSpot  = lsNew  . ls_rFallOff  * 0.9f;
#line 241 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 243 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_colColor  = m_colColor ;
#line 244 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_colAmbient  = C_BLACK ;
#line 245 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(lsNew  . ls_ulFlags  & LSF_DIRECTIONAL ){lsNew  . ls_colAmbient  = m_colAmbient ;}
#line 246 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_ubPolygonalMask  = (UBYTE ) m_itIllumination ;
#line 248 "C:/MyMod/Sources/EntitiesMP/Light.es"
switch(m_lftLensFlare )
#line 249 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 250 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_NONE : 
#line 251 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = NULL ;
#line 252 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 253 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_STANDARD : 
#line 254 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftStandard ;
#line 255 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 256 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_STANDARD_REFLECTIONS : 
#line 257 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftStandardReflections ;
#line 258 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 259 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_YELLOW_STAR_RED_RING : 
#line 260 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftYellowStarRedRing ;
#line 261 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 262 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_WHITE_GLOW_STAR_RED_RING : 
#line 263 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftWhiteGlowStarRedRing ;
#line 264 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 265 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_WHITE_GLOW_STAR : 
#line 266 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftWhiteGlowStar ;
#line 267 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 268 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_WHITE_STAR_RED_RING_STREAKS : 
#line 269 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftWhiteStarRedRingStreaks ;
#line 270 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 271 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_WHITE_STAR_RED_REFLECTIONS : 
#line 272 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftWhiteStarRedReflections ;
#line 273 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 274 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_BLUE_STAR_BLUE_REFLECTIONS : 
#line 275 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftBlueStarBlueReflections ;
#line 276 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 277 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_PV_SPACE_SHIP_WINDOW_FLARE : 
#line 278 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftPVSpaceShipWindowFlare ;
#line 279 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 280 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_WHITE_GLOW_STAR_RED_RING_FAR : 
#line 281 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftYellowStarRedRingFar ;
#line 282 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 283 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_WHITE_GLOW_FAR : 
#line 284 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftWhiteGlowFar ;
#line 285 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 286 "C:/MyMod/Sources/EntitiesMP/Light.es"
case LFT_WHITE_GLOW_STAR_NG : 
#line 287 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_plftLensFlare  = & _lftWhiteGlowStarNG ;
#line 288 "C:/MyMod/Sources/EntitiesMP/Light.es"
break ;
#line 289 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 293 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_paoLightAnimation  = NULL ;
#line 294 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_aoLightAnimation  . GetData  () != NULL ){
#line 295 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_paoLightAnimation  = & m_aoLightAnimation ;
#line 296 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 299 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_paoAmbientLightAnimation  = NULL ;
#line 300 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_aoAmbientLightAnimation  . GetData  () != NULL ){
#line 301 "C:/MyMod/Sources/EntitiesMP/Light.es"
lsNew  . ls_paoAmbientLightAnimation  = & m_aoAmbientLightAnimation ;
#line 302 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 303 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
  
#line 307 "C:/MyMod/Sources/EntitiesMP/Light.es"
SLONG CLight::GetUsedMemory(void) 
#line 308 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 310 "C:/MyMod/Sources/EntitiesMP/Light.es"
SLONG  slUsedMemory  = sizeof  (CLight ) - sizeof  (CEntity ) + CEntity  :: GetUsedMemory  ();
#line 312 "C:/MyMod/Sources/EntitiesMP/Light.es"
slUsedMemory  += m_strDescription  . Length  ();
#line 313 "C:/MyMod/Sources/EntitiesMP/Light.es"
slUsedMemory  += m_strName  . Length  ();
#line 314 "C:/MyMod/Sources/EntitiesMP/Light.es"
slUsedMemory  += m_fnmLightAnimation  . Length  ();
#line 315 "C:/MyMod/Sources/EntitiesMP/Light.es"
slUsedMemory  += m_fnmAmbientLightAnimation  . Length  ();
#line 316 "C:/MyMod/Sources/EntitiesMP/Light.es"
slUsedMemory  += 2 * sizeof  (CAnimObject);
#line 317 "C:/MyMod/Sources/EntitiesMP/Light.es"
return slUsedMemory ;
#line 318 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
BOOL CLight::
#line 322 "C:/MyMod/Sources/EntitiesMP/Light.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CLight_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CLight::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 325 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_rFallOffRange  < 0){
#line 326 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_rFallOffRange  = 0.0f;
#line 327 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 328 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_rHotSpotRange  < 0){
#line 329 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_rHotSpotRange  = 0.0f;
#line 330 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 332 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_rHotSpotRange  > m_rFallOffRange ){
#line 333 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_rHotSpotRange  = m_rFallOffRange ;
#line 334 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 343 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_fNearClip  <= 0.01f){
#line 344 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_fNearClip  = 0.01f;
#line 345 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 347 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_fFarClip  <= 0){
#line 348 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_fFarClip  = 0.0f;
#line 349 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 352 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_ltType  != LT_DIRECTIONAL ){
#line 353 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_colAmbient  = C_BLACK ;
#line 354 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 356 "C:/MyMod/Sources/EntitiesMP/Light.es"
InitAsEditorModel  ();
#line 357 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 358 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 361 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_bRenderAsSmallLight )
#line 362 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 363 "C:/MyMod/Sources/EntitiesMP/Light.es"
GetModelObject  () -> mo_Stretch  = FLOAT3D (0.25f , 0.25f , 0.25f);
#line 364 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 365 "C:/MyMod/Sources/EntitiesMP/Light.es"
else 
#line 366 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 368 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_ltType  != LT_DIRECTIONAL ){
#line 369 "C:/MyMod/Sources/EntitiesMP/Light.es"
const float  LIGHT_MINSIZE  = 0.5f;
#line 370 "C:/MyMod/Sources/EntitiesMP/Light.es"
FLOAT fFactor  = Log2  (m_rFallOffRange ) * LIGHT_MINSIZE ;
#line 371 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(fFactor  < LIGHT_MINSIZE ){
#line 372 "C:/MyMod/Sources/EntitiesMP/Light.es"
fFactor  = LIGHT_MINSIZE ;
#line 373 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 374 "C:/MyMod/Sources/EntitiesMP/Light.es"
GetModelObject  () -> mo_Stretch  = FLOAT3D (fFactor  , fFactor  , fFactor );
#line 375 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 376 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 378 "C:/MyMod/Sources/EntitiesMP/Light.es"
CTString strType ;
#line 379 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_ltType  == LT_POINT  || m_ltType  == LT_STRONG_POINT )
#line 380 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 381 "C:/MyMod/Sources/EntitiesMP/Light.es"
strType  = "point";
#line 383 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetModel  (MODEL_LIGHT_SOURCE );
#line 385 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetModelMainTexture  (TEXTURE_POINT_LIGHT );
#line 386 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 388 "C:/MyMod/Sources/EntitiesMP/Light.es"
else if(m_ltType  == LT_AMBIENT )
#line 389 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 390 "C:/MyMod/Sources/EntitiesMP/Light.es"
strType  = "ambient";
#line 392 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetModel  (MODEL_LIGHT_SOURCE );
#line 394 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetModelMainTexture  (TEXTURE_AMBIENT_LIGHT );
#line 395 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 397 "C:/MyMod/Sources/EntitiesMP/Light.es"
else if(m_ltType  == LT_STRONG_AMBIENT )
#line 398 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 399 "C:/MyMod/Sources/EntitiesMP/Light.es"
strType  = "ambient";
#line 401 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetModel  (MODEL_LIGHT_SOURCE );
#line 403 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetModelMainTexture  (TEXTURE_REAL_AMBIENT_LIGHT );
#line 404 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 406 "C:/MyMod/Sources/EntitiesMP/Light.es"
else if(m_ltType  == LT_DIRECTIONAL )
#line 407 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 408 "C:/MyMod/Sources/EntitiesMP/Light.es"
strType  = "directional";
#line 410 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetModel  (MODEL_SPOT_LIGHT );
#line 412 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetModelMainTexture  (TEXTURE_SPOT_LIGHT );
#line 413 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 415 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_bDarkLight )
#line 416 "C:/MyMod/Sources/EntitiesMP/Light.es"
{
#line 417 "C:/MyMod/Sources/EntitiesMP/Light.es"
strType  = strType  + ", dark";
#line 418 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 421 "C:/MyMod/Sources/EntitiesMP/Light.es"
try {
#line 422 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_aoLightAnimation  . SetData_t  (m_fnmLightAnimation );
#line 423 "C:/MyMod/Sources/EntitiesMP/Light.es"
}catch  (char  * strError ){
#line 424 "C:/MyMod/Sources/EntitiesMP/Light.es"
WarningMessage  (TRANS  ("Cannot load '%s': %s") , (CTString &) m_fnmLightAnimation  , strError );
#line 425 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_fnmLightAnimation  = "";
#line 426 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 427 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_aoLightAnimation  . GetData  () != NULL ){
#line 428 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_aoLightAnimation  . PlayAnim  (m_iLightAnimation  , AOF_LOOPING );
#line 429 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_aoLightAnimation  . OffsetPhase  (m_tmOffsetPhase  * m_aoLightAnimation  . GetCurrentAnimLength  ());
#line 430 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 433 "C:/MyMod/Sources/EntitiesMP/Light.es"
try {
#line 434 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_aoAmbientLightAnimation  . SetData_t  (m_fnmAmbientLightAnimation );
#line 435 "C:/MyMod/Sources/EntitiesMP/Light.es"
}catch  (char  * strError ){
#line 436 "C:/MyMod/Sources/EntitiesMP/Light.es"
WarningMessage  (TRANS  ("Cannot load '%s': %s") , (CTString &) m_fnmAmbientLightAnimation  , strError );
#line 437 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_fnmAmbientLightAnimation  = "";
#line 438 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 439 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_aoAmbientLightAnimation  . GetData  () != NULL ){
#line 440 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_aoAmbientLightAnimation  . PlayAnim  (m_iAmbientLightAnimation  , AOF_LOOPING );
#line 441 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_aoAmbientLightAnimation  . OffsetPhase  (m_tmOffsetPhase  * m_aoAmbientLightAnimation  . GetCurrentAnimLength  ());
#line 442 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 445 "C:/MyMod/Sources/EntitiesMP/Light.es"
CLightSource  lsNew ;
#line 446 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetupLightSource  (lsNew );
#line 449 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(m_bBackground ){
#line 450 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetFlags  (GetFlags  () | ENF_BACKGROUND );
#line 451 "C:/MyMod/Sources/EntitiesMP/Light.es"
}else {
#line 452 "C:/MyMod/Sources/EntitiesMP/Light.es"
SetFlags  (GetFlags  () & ~ ENF_BACKGROUND );
#line 453 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 456 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_lsLightSource  . ls_penEntity  = this ;
#line 457 "C:/MyMod/Sources/EntitiesMP/Light.es"
if(! m_bdfInitialized  . bdf_bValue ){
#line 458 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_lsLightSource  . SetLightSourceWithNoDiscarding  (lsNew );
#line 459 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_bdfInitialized  . bdf_bValue  = TRUE ;
#line 460 "C:/MyMod/Sources/EntitiesMP/Light.es"
}else {
#line 461 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_lsLightSource  . SetLightSource  (lsNew );
#line 462 "C:/MyMod/Sources/EntitiesMP/Light.es"
}
#line 464 "C:/MyMod/Sources/EntitiesMP/Light.es"
m_strDescription  . PrintF  ("%s:%g-%g" , 
#line 465 "C:/MyMod/Sources/EntitiesMP/Light.es"
strType  , m_rHotSpotRange  , m_rFallOffRange );
#line 467 "C:/MyMod/Sources/EntitiesMP/Light.es"
Return(STATE_CURRENT,EVoid());
#line 467 "C:/MyMod/Sources/EntitiesMP/Light.es"
return TRUE; ASSERT(FALSE); return TRUE;};