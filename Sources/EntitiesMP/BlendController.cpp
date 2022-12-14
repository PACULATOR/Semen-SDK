/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/BlendController.es"

#include "StdH.h"
#include "EntitiesMP/WorldSettingsController.h"
#include "EntitiesMP/BackgroundViewer.h"

#include <EntitiesMP/BlendController.h>
#include <EntitiesMP/BlendController_tables.h>
void CBlendController::SetDefaultProperties(void) {
  m_bctType = BCT_NONE ;
  CMarker::SetDefaultProperties();
}
  
#line 39 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
BOOL CBlendController::HandleEvent(const CEntityEvent & ee) 
#line 40 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
{
#line 42 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 43 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
if(pwsc  == NULL ){
#line 44 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
return FALSE ;
#line 45 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
}
#line 46 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
FLOAT tmNow  = _pTimer  -> CurrentTick  ();
#line 48 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
if(ee  . ee_slEvent  == EVENTCODE_EActivate )
#line 49 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
{
#line 50 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
switch(m_bctType )
#line 51 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
{
#line 52 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
case BCT_PYRAMID_PLATES : 
#line 53 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmPyramidPlatesStart  = tmNow ;
#line 54 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
break ;
#line 55 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
case BCT_ACTIVATE_PLATE_1 : 
#line 56 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmActivatedPlate1  = tmNow ;
#line 57 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmDeactivatedPlate1  = 1e6;
#line 58 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
break ;
#line 59 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
case BCT_ACTIVATE_PLATE_2 : 
#line 60 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmActivatedPlate2  = tmNow ;
#line 61 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmDeactivatedPlate2  = 1e6;
#line 62 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
break ;
#line 63 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
case BCT_ACTIVATE_PLATE_3 : 
#line 64 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmActivatedPlate3  = tmNow ;
#line 65 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmDeactivatedPlate3  = 1e6;
#line 66 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
break ;
#line 67 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
case BCT_ACTIVATE_PLATE_4 : 
#line 68 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmActivatedPlate4  = tmNow ;
#line 69 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmDeactivatedPlate4  = 1e6;
#line 70 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
break ;
#line 71 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
case BCT_ACTIVATE_PYRAMID_MORPH_ROOM : 
#line 72 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmPyramidMorphRoomActivated  = tmNow ;
#line 73 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
break ;
#line 74 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
}
#line 75 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
}
#line 76 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
else if(ee  . ee_slEvent  == EVENTCODE_EDeactivate )
#line 77 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
{
#line 78 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
switch(m_bctType )
#line 79 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
{
#line 80 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
case BCT_ACTIVATE_PLATE_1 : 
#line 81 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmDeactivatedPlate1  = tmNow ;
#line 82 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
break ;
#line 83 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
case BCT_ACTIVATE_PLATE_2 : 
#line 84 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmDeactivatedPlate2  = tmNow ;
#line 85 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
break ;
#line 86 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
case BCT_ACTIVATE_PLATE_3 : 
#line 87 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmDeactivatedPlate3  = tmNow ;
#line 88 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
break ;
#line 89 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
case BCT_ACTIVATE_PLATE_4 : 
#line 90 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
pwsc  -> m_tmDeactivatedPlate4  = tmNow ;
#line 91 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
break ;
#line 92 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
}
#line 93 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
}
#line 94 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
return FALSE ;
#line 95 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
}
BOOL CBlendController::
#line 99 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBlendController_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBlendController::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 102 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
InitAsEditorModel  ();
#line 103 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 104 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 107 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
SetModel  (MODEL_CONTROLLER );
#line 108 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
SetModelMainTexture  (TEXTURE_CONTROLLER );
#line 110 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
Return(STATE_CURRENT,EVoid());
#line 110 "C:/MyMod/Sources/EntitiesMP/BlendController.es"
return TRUE; ASSERT(FALSE); return TRUE;};