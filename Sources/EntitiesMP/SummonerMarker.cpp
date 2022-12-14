/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"

#include "StdH.h"

#include <EntitiesMP/SummonerMarker.h>
#include <EntitiesMP/SummonerMarker_tables.h>
void CSummonerMarker::SetDefaultProperties(void) {
  m_strName = "SummonerMarker";
  m_strDescription = "SummonerMarker";
  m_fMarkerRange = 0.0f;
  CMarker::SetDefaultProperties();
}
  
#line 25 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
BOOL CSummonerMarker::MovesByTargetedRoute(CTString & strTargetProperty)const {
#line 26 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
strTargetProperty  = "Target";
#line 27 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
return TRUE ;
#line 28 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
}
  
#line 31 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
BOOL CSummonerMarker::DropsMarker(CTFileName & fnmMarkerClass,CTString & strTargetProperty)const {
#line 32 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
fnmMarkerClass  = CTFILENAME  ("Classes\\SummonerMarker.ecl");
#line 33 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
strTargetProperty  = "Target";
#line 34 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
return TRUE ;
#line 35 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
}
  
#line 37 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
BOOL CSummonerMarker::IsTargetValid(SLONG slPropertyOffset,CEntity * penTarget) 
#line 38 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
{
#line 39 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
if(slPropertyOffset  == offsetof  (CSummonerMarker  , m_penTarget ))
#line 40 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
{
#line 41 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
if(IsOfClass  (penTarget  , "SummonerMarker")){return TRUE ;}
#line 42 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
else {return FALSE ;}
#line 43 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
}
#line 44 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
return CEntity  :: IsTargetValid  (slPropertyOffset  , penTarget );
#line 45 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
}
BOOL CSummonerMarker::
#line 48 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CSummonerMarker_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CSummonerMarker::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 50 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
InitAsEditorModel  ();
#line 51 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 52 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 55 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
SetModel  (MODEL_SUMMONERMARKER );
#line 56 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
SetModelMainTexture  (TEXTURE_SUMMONERMARKER );
#line 58 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
Return(STATE_CURRENT,EVoid());
#line 58 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
return TRUE; ASSERT(FALSE); return TRUE;};