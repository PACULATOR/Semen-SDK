/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"

#include "StdH.h"

#include <EntitiesMP/HazeMarker.h>
#include <EntitiesMP/HazeMarker_tables.h>
void CHazeMarker::SetDefaultProperties(void) {
  m_faType = FA_EXP ;
  m_fDensity = 0.1f;
  m_fNear = 100.0f;
  m_fFar = 1000.0f;
  m_bVisibleFromOutside = FALSE ;
  m_iSize = 32;
  m_colBase = (C_WHITE  | CT_OPAQUE );
  m_colUp = (C_BLACK  | CT_TRANSPARENT );
  m_colDown = (C_BLACK  | CT_TRANSPARENT );
  m_colNorth = (C_BLACK  | CT_TRANSPARENT );
  m_colSouth = (C_BLACK  | CT_TRANSPARENT );
  m_colEast = (C_BLACK  | CT_TRANSPARENT );
  m_colWest = (C_BLACK  | CT_TRANSPARENT );
  CMarker::SetDefaultProperties();
}
  
#line 38 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
const CTString & CHazeMarker::GetHazeName(void) 
#line 39 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
{
#line 40 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
return m_strName ;
#line 41 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
}
  
#line 44 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
void CHazeMarker::GetHaze(class CHazeParameters & hpHaze,FLOAT3D & vViewDir) 
#line 45 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
{
#line 47 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
COLOR colDir  = C_BLACK  , colMul ;
#line 48 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
FLOAT fR  = 0.0f , fG  = 0.0f , fB  = 0.0f , fA  = 0.0f;
#line 49 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
FLOAT fSum  = 255.0f / (Abs  (vViewDir  (1)) + Abs  (vViewDir  (2)) + Abs  (vViewDir  (3)));
#line 51 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
if(vViewDir  (1) < 0.0f){
#line 52 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (COLOR) (- vViewDir  (1) * fSum );
#line 53 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (colMul  << CT_RSHIFT ) | (colMul  << CT_GSHIFT ) | (colMul  << CT_BSHIFT ) | (colMul  << CT_ASHIFT );
#line 54 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colDir  = AddColors  (colDir  , MulColors  (m_colWest  , colMul ));
#line 55 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
}
#line 56 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
if(vViewDir  (1) > 0.0f){
#line 57 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (COLOR) (+ vViewDir  (1) * fSum );
#line 58 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (colMul  << CT_RSHIFT ) | (colMul  << CT_GSHIFT ) | (colMul  << CT_BSHIFT ) | (colMul  << CT_ASHIFT );
#line 59 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colDir  = AddColors  (colDir  , MulColors  (m_colEast  , colMul ));
#line 60 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
}
#line 61 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
if(vViewDir  (2) < 0.0f){
#line 62 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (COLOR) (- vViewDir  (2) * fSum );
#line 63 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (colMul  << CT_RSHIFT ) | (colMul  << CT_GSHIFT ) | (colMul  << CT_BSHIFT ) | (colMul  << CT_ASHIFT );
#line 64 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colDir  = AddColors  (colDir  , MulColors  (m_colDown  , colMul ));
#line 65 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
}
#line 66 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
if(vViewDir  (2) > 0.0f){
#line 67 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (COLOR) (+ vViewDir  (2) * fSum );
#line 68 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (colMul  << CT_RSHIFT ) | (colMul  << CT_GSHIFT ) | (colMul  << CT_BSHIFT ) | (colMul  << CT_ASHIFT );
#line 69 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colDir  = AddColors  (colDir  , MulColors  (m_colUp  , colMul ));
#line 70 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
}
#line 71 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
if(vViewDir  (3) < 0.0f){
#line 72 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (COLOR) (- vViewDir  (3) * fSum );
#line 73 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (colMul  << CT_RSHIFT ) | (colMul  << CT_GSHIFT ) | (colMul  << CT_BSHIFT ) | (colMul  << CT_ASHIFT );
#line 74 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colDir  = AddColors  (colDir  , MulColors  (m_colNorth  , colMul ));
#line 75 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
}
#line 76 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
if(vViewDir  (3) > 0.0f){
#line 77 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (COLOR) (+ vViewDir  (3) * fSum );
#line 78 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colMul  = (colMul  << CT_RSHIFT ) | (colMul  << CT_GSHIFT ) | (colMul  << CT_BSHIFT ) | (colMul  << CT_ASHIFT );
#line 79 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colDir  = AddColors  (colDir  , MulColors  (m_colSouth  , colMul ));
#line 80 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
}
#line 83 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
colDir  = AddColors  (colDir  , m_colBase );
#line 86 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
hpHaze  . hp_colColor  = colDir ;
#line 87 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
hpHaze  . hp_atType  = (AttenuationType ) m_faType ;
#line 88 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
hpHaze  . hp_fDensity  = m_fDensity ;
#line 89 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
hpHaze  . hp_fNear  = m_fNear ;
#line 90 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
hpHaze  . hp_fFar  = m_fFar ;
#line 91 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
hpHaze  . hp_iSize  = m_iSize ;
#line 92 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
hpHaze  . hp_ulFlags  = 0;
#line 93 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
if(m_bVisibleFromOutside ){
#line 94 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
hpHaze  . hp_ulFlags  |= HPF_VISIBLEFROMOUTSIDE ;
#line 95 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
}
#line 96 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
}
BOOL CHazeMarker::
#line 100 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CHazeMarker_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CHazeMarker::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 102 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
InitAsEditorModel  ();
#line 103 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 104 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 107 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
SetModel  (MODEL_MARKER );
#line 108 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 111 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
if(m_strName  == "Marker"){
#line 112 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
m_strName  = "Haze marker";
#line 113 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
}
#line 116 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
m_fDensity  = ClampDn  (m_fDensity  , 1E-6f);
#line 117 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
m_fFar  = ClampDn  (m_fFar  , 0.001f);
#line 118 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
m_fNear  = Clamp  (m_fNear  , 0.0f , m_fFar  - 0.0005f);
#line 119 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
ASSERT  (m_fNear  >= 0 && m_fNear  < m_fFar );
#line 121 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
m_iSize  = 1 << INDEX (Log2  (m_iSize ));
#line 122 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
m_iSize  = Clamp  (m_iSize  , INDEX (2) , INDEX (256));
#line 124 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
Return(STATE_CURRENT,EVoid());
#line 124 "C:/MyMod/Sources/EntitiesMP/HazeMarker.es"
return TRUE; ASSERT(FALSE); return TRUE;};