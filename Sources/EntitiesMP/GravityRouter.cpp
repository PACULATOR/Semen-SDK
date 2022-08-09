/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"

#include "StdH.h"

#include <EntitiesMP/GravityRouter.h>
#include <EntitiesMP/GravityRouter_tables.h>
CEntityEvent *EChangeGravity::MakeCopy(void) { CEntityEvent *peeCopy = new EChangeGravity(*this); return peeCopy;}
EChangeGravity::EChangeGravity() : CEntityEvent(EVENTCODE_EChangeGravity) {;
 ClearToDefault(penNewGravity);
};
void CGravityRouter::SetDefaultProperties(void) {
  CMarker::SetDefaultProperties();
}
  
#line 26 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
const CTString & CGravityRouter::GetForceName(INDEX i) 
#line 27 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
{
#line 28 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
return m_strName ;
#line 29 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
}
  
#line 32 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
void CGravityRouter::GetForce(INDEX i,const FLOAT3D & vPoint,
#line 33 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
CForceStrength & fsGravity,CForceStrength & fsField) 
#line 34 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
{
#line 35 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
if((m_penTarget  != NULL ) && (IsOfClass  (m_penTarget  , "Gravity Marker")))
#line 36 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
{
#line 37 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
m_penTarget  -> GetForce  (i  , vPoint  , fsGravity  , fsField );
#line 38 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
}
#line 39 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
}
  
#line 41 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
CEntity * CGravityRouter::GetForceController(INDEX iForce) 
#line 42 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
{
#line 43 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
return this ;
#line 44 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
}
  
#line 47 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
BOOL CGravityRouter::HandleEvent(const CEntityEvent & ee) 
#line 48 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
{
#line 49 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
if(((EChangeGravity  &) ee ) . ee_slEvent  == EVENTCODE_EChangeGravity )
#line 50 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
{
#line 51 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
m_penTarget  = ((EChangeGravity  &) ee ) . penNewGravity ;
#line 53 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
NotifyGravityChanged  ();
#line 54 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
return TRUE ;
#line 55 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
}
#line 56 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
return FALSE ;
#line 57 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
}
BOOL CGravityRouter::
#line 60 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CGravityRouter_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CGravityRouter::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 62 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
InitAsEditorModel  ();
#line 63 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 64 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 67 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
SetModel  (MODEL_MARKER );
#line 68 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 71 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
if(m_strName  == "Marker"){
#line 72 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
m_strName  = "Gravity Router";
#line 73 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
}
#line 75 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
if(m_penTarget  != NULL  && ! IsOfClass  (m_penTarget  , "Gravity Marker")){
#line 76 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
WarningMessage  ("Entity '%s' is not of Gravity Marker class!" , m_penTarget );
#line 77 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
m_penTarget  = NULL ;
#line 78 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
}
#line 80 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
Return(STATE_CURRENT,EVoid());
#line 80 "C:/MyMod/Sources/EntitiesMP/GravityRouter.es"
return TRUE; ASSERT(FALSE); return TRUE;};