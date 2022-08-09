/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"

#include "StdH.h"

#include <EntitiesMP/EnemyMarker.h>
#include <EntitiesMP/EnemyMarker_tables.h>
void CEnemyMarker::SetDefaultProperties(void) {
  m_fWaitTime = 0.0f;
  m_fMarkerRange = 0.0f;
  m_fPatrolAreaInner = 0.0f;
  m_fPatrolAreaOuter = 0.0f;
  m_fPatrolTime = 0.0f;
  m_betRunToMarker = BET_IGNORE ;
  m_betFly = BET_IGNORE ;
  m_betBlind = BET_IGNORE ;
  m_betDeaf = BET_IGNORE ;
  m_bStartTactics = FALSE ;
  CMarker::SetDefaultProperties();
}
  
#line 32 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
BOOL CEnemyMarker::MovesByTargetedRoute(CTString & strTargetProperty)const {
#line 33 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
strTargetProperty  = "Target";
#line 34 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
return TRUE ;
#line 35 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
}
  
#line 38 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
BOOL CEnemyMarker::DropsMarker(CTFileName & fnmMarkerClass,CTString & strTargetProperty)const {
#line 39 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
fnmMarkerClass  = CTFILENAME  ("Classes\\EnemyMarker.ecl");
#line 40 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
strTargetProperty  = "Target";
#line 41 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
return TRUE ;
#line 42 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
}
  
#line 44 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
BOOL CEnemyMarker::IsTargetValid(SLONG slPropertyOffset,CEntity * penTarget) 
#line 45 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
{
#line 46 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
if(slPropertyOffset  == offsetof  (CMarker  , m_penTarget ))
#line 47 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
{
#line 48 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
if(IsOfClass  (penTarget  , "Enemy Marker")){return TRUE ;}
#line 49 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
else {return FALSE ;}
#line 50 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
}
#line 51 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
return CEntity  :: IsTargetValid  (slPropertyOffset  , penTarget );
#line 52 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
}
BOOL CEnemyMarker::
#line 55 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnemyMarker_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnemyMarker::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 56 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
InitAsEditorModel  ();
#line 57 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 58 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 60 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
if(m_strName  == "Marker"){
#line 61 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
m_strName  = "Enemy Marker";
#line 62 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
}
#line 65 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
SetModel  (MODEL_MARKER );
#line 66 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 67 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
Return(STATE_CURRENT,EVoid());
#line 67 "C:/MyMod/Sources/EntitiesMP/EnemyMarker.es"
return TRUE; ASSERT(FALSE); return TRUE;};