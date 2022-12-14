/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"

#include "StdH.h"

#include <EntitiesMP/WorldLink.h>
#include <EntitiesMP/WorldLink_tables.h>
void CWorldLink::SetDefaultProperties(void) {
  m_strGroup = "";
  m_strWorld = "";
  m_bStoreWorld = FALSE ;
  m_EwltType = WLT_RELATIVE ;
  CMarker::SetDefaultProperties();
}
  
#line 34 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
BOOL CWorldLink::HandleEvent(const CEntityEvent & ee) {
#line 35 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
if(ee  . ee_slEvent  == EVENTCODE_ETrigger ){
#line 36 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
ETrigger  & eTrigger  = (ETrigger  &) ee ;
#line 37 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
_SwcWorldChange  . strGroup  = m_strGroup ;
#line 38 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
_SwcWorldChange  . plLink  = GetPlacement  ();
#line 39 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
_SwcWorldChange  . iType  = (INDEX) m_EwltType ;
#line 40 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
_pNetwork  -> ChangeLevel  (m_strWorld  , m_bStoreWorld  , 0);
#line 41 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
return TRUE ;
#line 42 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
}
#line 43 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
return FALSE ;
#line 44 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
}
BOOL CWorldLink::
#line 50 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CWorldLink_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CWorldLink::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 51 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
InitAsEditorModel  ();
#line 52 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 53 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 56 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
SetModel  (MODEL_WORLDLINK );
#line 57 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
SetModelMainTexture  (TEXTURE_WORLDLINK );
#line 60 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
m_strName  . PrintF  ("World link - %s" , m_strGroup );
#line 62 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
Return(STATE_CURRENT,EVoid());
#line 62 "C:/MyMod/Sources/EntitiesMP/WorldLink.es"
return TRUE; ASSERT(FALSE); return TRUE;};