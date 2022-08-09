/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"

#include "StdH.h"

#include <EntitiesMP/GradientMarker.h>
#include <EntitiesMP/GradientMarker_tables.h>
void CGradientMarker::SetDefaultProperties(void) {
  m_fHeight = -10.0f;
  m_bDarkLight = TRUE ;
  m_colColor0 = (C_GRAY  | CT_OPAQUE );
  m_colColor1 = (C_WHITE  | CT_OPAQUE );
  CMarker::SetDefaultProperties();
}
  
#line 27 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
const CTString & CGradientMarker::GetGradientName(void) 
#line 28 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
{
#line 29 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
return m_strName ;
#line 30 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
}
  
#line 32 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
BOOL CGradientMarker::GetGradient(INDEX iGradient,class CGradientParameters & gpGradient) 
#line 33 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
{
#line 34 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
const FLOATmatrix3D & m  = GetRotationMatrix  ();
#line 35 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
gpGradient  . gp_vGradientDir  (1) = m  (1 , 2);
#line 36 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
gpGradient  . gp_vGradientDir  (2) = m  (2 , 2);
#line 37 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
gpGradient  . gp_vGradientDir  (3) = m  (3 , 2);
#line 38 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
FLOAT fPos  = gpGradient  . gp_vGradientDir  % GetPlacement  () . pl_PositionVector ;
#line 39 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
gpGradient  . gp_bDark  = m_bDarkLight ;
#line 40 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
if(m_fHeight  >= 0 && m_fHeight  < + 0.001f){m_fHeight  = + 0.001f;}
#line 41 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
if(m_fHeight  <= 0 && m_fHeight  > - 0.001f){m_fHeight  = - 0.001f;}
#line 42 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
gpGradient  . gp_fH0  = fPos ;
#line 43 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
gpGradient  . gp_fH1  = fPos  + m_fHeight ;
#line 44 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
gpGradient  . gp_col0  = m_colColor0 ;
#line 45 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
gpGradient  . gp_col1  = m_colColor1 ;
#line 46 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
return TRUE ;
#line 47 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
}
  
#line 49 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
void CGradientMarker::UncacheShadowsForGradient(void) 
#line 50 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
{
#line 52 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
FOREACHINDYNAMICCONTAINER  (GetWorld  () -> wo_cenEntities  , CEntity  , iten ){
#line 54 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
if(IsOfClass  (& * iten  , "WorldBase")){
#line 56 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
((CWorldBase  *) & * iten ) -> UncacheShadowsForGradient  (this );
#line 57 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
}
#line 58 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
}
#line 59 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
}
  
#line 61 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
void CGradientMarker::SetPlacement_internal(const CPlacement3D & plNew,const FLOATmatrix3D & mRotation,BOOL bNear) 
#line 62 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
{
#line 63 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
CEntity  :: SetPlacement_internal  (plNew  , mRotation  , bNear );
#line 64 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
UncacheShadowsForGradient  ();
#line 65 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
}
  
#line 67 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
void CGradientMarker::OnEnd(void) 
#line 68 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
{
#line 69 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
UncacheShadowsForGradient  ();
#line 70 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
CEntity  :: OnEnd  ();
#line 71 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
}
BOOL CGradientMarker::
#line 75 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGradientMarker_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGradientMarker::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 77 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
InitAsEditorModel  ();
#line 78 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 79 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 82 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
SetModel  (MODEL_MARKER );
#line 83 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 86 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
if(m_strName  == "Marker"){
#line 87 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
m_strName  = "Gradient marker";
#line 88 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
}
#line 90 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
UncacheShadowsForGradient  ();
#line 91 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
Return(STATE_CURRENT,EVoid());
#line 91 "C:/MyMod/Sources/EntitiesMP/GradientMarker.es"
return TRUE; ASSERT(FALSE); return TRUE;};