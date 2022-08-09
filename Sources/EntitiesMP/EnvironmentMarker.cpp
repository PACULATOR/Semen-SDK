/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"

#include "StdH.h"

#include <EntitiesMP/EnvironmentMarker.h>
#include <EntitiesMP/EnvironmentMarker_tables.h>
void CEnvironmentMarker::SetDefaultProperties(void) {
  m_fWaitTime = 0.0f;
  m_fRandomTime = 0.0f;
  m_fMarkerRange = 5.0f;
  m_bFixedAnimLength = FALSE ;
  m_bChangeDefaultAnim = FALSE ;
  m_fMoveSpeed = -1.0f;
  m_fRotateSpeed = -1.0f;
  m_fnMdl = CTFILENAME("Models\\Editor\\Axis.mdl");
  m_iAnim = 0;
  m_moAnimData.SetData(NULL);
m_moAnimData.mo_toTexture.SetData(NULL);
  CMarker::SetDefaultProperties();
}
  
#line 32 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
BOOL CEnvironmentMarker::MovesByTargetedRoute(CTString & strTargetProperty)const {
#line 33 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
strTargetProperty  = "Target";
#line 34 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
return TRUE ;
#line 35 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
}
  
#line 37 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
BOOL CEnvironmentMarker::DropsMarker(CTFileName & fnmMarkerClass,CTString & strTargetProperty)const {
#line 38 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
fnmMarkerClass  = CTFILENAME  ("Classes\\EnvironmentMarker.ecl");
#line 39 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
strTargetProperty  = "Target";
#line 40 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
return TRUE ;
#line 41 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
}
  
#line 43 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
CAnimData * CEnvironmentMarker::GetAnimData(SLONG slPropertyOffset) {
#line 44 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
if(slPropertyOffset  == offsetof  (CEnvironmentMarker  , m_iAnim )){
#line 45 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
return m_moAnimData  . GetData  ();
#line 47 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
}else {
#line 48 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
return CEntity  :: GetAnimData  (slPropertyOffset );
#line 49 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
}
#line 50 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
}
  
#line 54 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
void CEnvironmentMarker::SetModelObject(void) {
#line 56 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
try {
#line 58 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
m_moAnimData  . SetData_t  (m_fnMdl );
#line 60 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
}catch  (char  * strError ){
#line 61 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
strError ;
#line 62 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
DECLARE_CTFILENAME  (fnmDefault  , "Models\\Editor\\Axis.mdl");
#line 64 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
try {
#line 66 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
m_moAnimData  . SetData_t  (fnmDefault );
#line 68 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
}catch  (char  * strErrorDefault ){
#line 69 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
FatalError  (TRANS  ("Cannot load default model '%s':\n%s") , 
#line 70 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
(CTString &) fnmDefault  , strErrorDefault );
#line 71 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
}
#line 72 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
}
#line 73 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
}
BOOL CEnvironmentMarker::
#line 77 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnvironmentMarker_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnvironmentMarker::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 78 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
InitAsEditorModel  ();
#line 79 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 80 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 83 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
SetModel  (MODEL_MARKER );
#line 84 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 87 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
SetModelObject  ();
#line 89 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
Return(STATE_CURRENT,EVoid());
#line 89 "C:/MyMod/Sources/EntitiesMP/EnvironmentMarker.es"
return TRUE; ASSERT(FALSE); return TRUE;};