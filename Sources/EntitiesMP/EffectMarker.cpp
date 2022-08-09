/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"

#include "StdH.h"
#include "EntitiesMP/Effector.h"
#include "EntitiesMP/BackgroundViewer.h"
#include "EntitiesMP/WorldSettingsController.h"

#include <EntitiesMP/EffectMarker.h>
#include <EntitiesMP/EffectMarker_tables.h>
#line 29 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"

extern void CBasicEffect_OnPrecache(CDLLEntityClass *pdec, INDEX iUser);

void CEffectMarker::SetDefaultProperties(void) {
  m_emtType = EMT_NONE ;
  m_penModel = NULL;
  m_tmEffectLife = 10.0f;
  m_penModel2 = NULL;
  m_penEffector = NULL;
  m_fShakeFalloff = 250.0f;
  m_fShakeFade = 3.0f;
  m_fShakeIntensityY = 0.1f;
  m_fShakeFrequencyY = 5.0f;
  m_fShakeIntensityB = 2.5f;
  m_fShakeFrequencyB = 7.2f;
  m_fShakeIntensityZ = 0.0f;
  m_fShakeFrequencyZ = 5.0f;
  m_betType = BET_ROCKET ;
  m_fStretch = 1.0f;
  m_colColor = COLOR(C_WHITE  | CT_TRANSPARENT );
  CMarker::SetDefaultProperties();
}
  
#line 66 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
void CEffectMarker::Precache(void) 
#line 67 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 68 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
switch(m_betType )
#line 69 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 70 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_BASIC_EFFECT : 
#line 71 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CDLLEntityClass  * pdec  = & CBasicEffect_DLLClass ;
#line 73 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CBasicEffect_OnPrecache  (pdec  , m_emtType );
#line 74 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 75 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 76 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
  
#line 79 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
BOOL CEffectMarker::IsTargetValid(SLONG slPropertyOffset,CEntity * penTarget) 
#line 80 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 81 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(penTarget  == NULL )
#line 82 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 83 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
return FALSE ;
#line 84 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 86 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(slPropertyOffset  == offsetof  (CEffectMarker  , m_penModel ) || 
#line 87 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
slPropertyOffset  == offsetof  (CEffectMarker  , m_penModel2 ))
#line 88 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 89 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
return IsOfClass  (penTarget  , "ModelHolder2");
#line 90 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 91 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
return TRUE ;
#line 92 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
  
#line 95 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
BOOL CEffectMarker::HandleEvent(const CEntityEvent & ee) 
#line 96 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 97 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(ee  . ee_slEvent  == EVENTCODE_ETrigger )
#line 98 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 99 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
switch(m_emtType )
#line 100 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 101 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_SET_PLACEMENT : 
#line 102 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 103 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && m_penModel2  != NULL )
#line 104 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 105 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penModel  -> Teleport  (m_penModel2  -> GetPlacement  () , FALSE );
#line 106 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 107 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 108 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 109 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_SET_PARENT : 
#line 110 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 111 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && m_penModel2  != NULL )
#line 112 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 113 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penModel  -> SetParent  (m_penModel2 );
#line 114 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 115 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 116 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 117 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_CLEAR_PARENT : 
#line 118 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 119 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL )
#line 120 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 121 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penModel  -> SetParent  (NULL );
#line 122 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 123 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 124 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 125 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_SHAKE_IT_BABY : 
#line 126 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 128 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CWorldSettingsController  * pwsc  = NULL ;
#line 130 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CBackgroundViewer  * penBcgViewer  = (CBackgroundViewer  *) GetWorld  () -> GetBackgroundViewer  ();
#line 131 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(penBcgViewer  != NULL  && penBcgViewer  -> m_penWorldSettingsController  != NULL )
#line 132 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 133 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  = (CWorldSettingsController  *) & * penBcgViewer  -> m_penWorldSettingsController ;
#line 134 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmShakeStarted  = _pTimer  -> CurrentTick  ();
#line 135 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_vShakePos  = GetPlacement  () . pl_PositionVector ;
#line 136 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fShakeFalloff  = m_fShakeFalloff ;
#line 137 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fShakeFade  = m_fShakeFade ;
#line 138 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fShakeIntensityZ  = m_fShakeIntensityZ ;
#line 139 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmShakeFrequencyZ  = m_fShakeFrequencyZ ;
#line 140 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fShakeIntensityY  = m_fShakeIntensityY ;
#line 141 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmShakeFrequencyY  = m_fShakeFrequencyY ;
#line 142 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fShakeIntensityB  = m_fShakeIntensityB ;
#line 143 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmShakeFrequencyB  = m_fShakeFrequencyB ;
#line 144 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_bShakeFadeIn  = FALSE ;
#line 145 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 146 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 147 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 148 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_HIDE_ENTITY : 
#line 149 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 150 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penTarget  != NULL )
#line 151 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 152 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penTarget  -> SetFlags  (m_penTarget  -> GetFlags  () | ENF_HIDDEN );
#line 153 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 154 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 155 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 156 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_SHOW_ENTITY : 
#line 157 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 158 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penTarget  != NULL )
#line 159 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 160 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penTarget  -> SetFlags  (m_penTarget  -> GetFlags  () & ~ ENF_HIDDEN );
#line 161 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 162 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 163 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 164 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_PLAYER_APPEAR : 
#line 165 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2"))
#line 166 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 167 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo  = m_penModel  -> GetModelObject  ();
#line 168 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(pmo  != NULL )
#line 169 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 171 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 172 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 173 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 174 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 175 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_PORTAL_LIGHTNING ;
#line 176 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 177 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 178 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 179 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 180 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 181 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_APPEARING_BIG_BLUE_FLARE : 
#line 182 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 184 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = GetPlacement  ();
#line 185 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 186 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 187 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 188 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . fSize  = 1.0f;
#line 189 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_SIZING_BIG_BLUE_FLARE ;
#line 190 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 191 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 192 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 193 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_BLEND_MODELS : 
#line 194 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2") && 
#line 195 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penModel2  != NULL  && IsOfClass  (m_penModel2  , "ModelHolder2"))
#line 196 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 197 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penEffector  == NULL )
#line 198 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 199 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo1  = m_penModel  -> GetModelObject  ();
#line 200 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo2  = m_penModel2  -> GetModelObject  ();
#line 201 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(pmo1  != NULL  && pmo2  != NULL )
#line 202 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 204 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 205 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 206 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 207 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 208 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_MORPH_MODELS ;
#line 209 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 210 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel2  = m_penModel2 ;
#line 211 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 212 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = penFX ;
#line 213 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 214 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 215 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
else 
#line 216 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 217 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  -> SendEvent  (ETrigger  ());
#line 218 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 219 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 220 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 221 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_DISAPPEAR_MODEL : 
#line 222 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2"))
#line 223 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 224 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penEffector  == NULL )
#line 225 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 226 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo  = m_penModel  -> GetModelObject  ();
#line 227 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(pmo  != NULL )
#line 228 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 230 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 231 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 232 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 233 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 234 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_DISAPPEAR_MODEL ;
#line 235 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 236 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 237 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = penFX ;
#line 238 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 239 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 240 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
else 
#line 241 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 242 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  -> SendEvent  (ETrigger  ());
#line 243 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 244 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 245 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 246 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_APPEAR_MODEL : 
#line 247 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2"))
#line 248 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 249 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penEffector  == NULL )
#line 250 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 251 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo  = m_penModel  -> GetModelObject  ();
#line 252 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(pmo  != NULL )
#line 253 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 255 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 256 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 257 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 258 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 259 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_APPEAR_MODEL ;
#line 260 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 261 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 262 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = penFX ;
#line 263 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 264 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 265 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
else 
#line 266 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 267 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  -> SendEvent  (ETrigger  ());
#line 268 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 269 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 270 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 271 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_BASIC_EFFECT : 
#line 272 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 274 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plEffect  = GetPlacement  ();
#line 275 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CEntityPointer penEffect  = CreateEntity  (plEffect  , CLASS_BASIC_EFFECT );
#line 276 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffect  eSpawnEffect ;
#line 277 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnEffect  . colMuliplier  = C_WHITE  | CT_OPAQUE ;
#line 278 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnEffect  . betType  = m_betType ;
#line 279 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnEffect  . vStretch  = FLOAT3D (m_fStretch  , m_fStretch  , m_fStretch );
#line 280 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
penEffect  -> Initialize  (eSpawnEffect );
#line 281 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 282 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 283 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_GLARE : 
#line 284 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 285 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(pwsc  != NULL )
#line 286 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 287 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_colGlade  = m_colColor ;
#line 288 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmGlaringStarted  = _pTimer  -> CurrentTick  ();
#line 289 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_tmGlaringEnded  = pwsc  -> m_tmGlaringStarted  + m_tmEffectLife  , 
#line 290 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fGlaringFadeInRatio  = 0.2f;
#line 291 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
pwsc  -> m_fGlaringFadeOutRatio  = 0.7f;
#line 292 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 293 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 294 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 295 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 296 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
else if(ee  . ee_slEvent  == EVENTCODE_EActivate )
#line 297 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 298 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
switch(m_emtType )
#line 299 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 300 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_APPEAR_DISAPPEAR : 
#line 301 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2"))
#line 302 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 303 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo  = m_penModel  -> GetModelObject  ();
#line 304 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(pmo  != NULL )
#line 305 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 307 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 308 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 309 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 310 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 311 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_APPEAR_MODEL_NOW ;
#line 312 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 313 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 314 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = penFX ;
#line 315 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 316 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 317 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 318 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 319 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 320 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
else if(ee  . ee_slEvent  == EVENTCODE_EDeactivate )
#line 321 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 322 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
switch(m_emtType )
#line 323 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 324 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
case EMT_APPEAR_DISAPPEAR : 
#line 325 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(m_penModel  != NULL  && IsOfClass  (m_penModel  , "ModelHolder2"))
#line 326 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 327 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CModelObject * pmo  = m_penModel  -> GetModelObject  ();
#line 328 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
if(pmo  != NULL )
#line 329 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
{
#line 331 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CPlacement3D plFX  = m_penModel  -> GetPlacement  ();
#line 332 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
CEntity  * penFX  = CreateEntity  (plFX  , CLASS_EFFECTOR );
#line 333 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
ESpawnEffector  eSpawnFX ;
#line 334 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . tmLifeTime  = m_tmEffectLife ;
#line 335 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . eetType  = ET_DISAPPEAR_MODEL_NOW ;
#line 336 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
eSpawnFX  . penModel  = m_penModel ;
#line 337 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
penFX  -> Initialize  (eSpawnFX );
#line 338 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = penFX ;
#line 339 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 340 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 341 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
break ;
#line 342 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 343 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
#line 344 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
return FALSE ;
#line 345 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
}
BOOL CEffectMarker::
#line 349 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEffectMarker_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEffectMarker::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 352 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
InitAsEditorModel  ();
#line 353 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 354 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 357 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
SetModel  (MODEL_MARKER );
#line 358 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 360 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
m_penEffector  = NULL ;
#line 361 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
Return(STATE_CURRENT,EVoid());
#line 361 "C:/MyMod/Sources/EntitiesMP/EffectMarker.es"
return TRUE; ASSERT(FALSE); return TRUE;};