/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"

#include "StdH.h"
#include "EntitiesMP/MusicHolder.h"

#include <EntitiesMP/PlayerMarker.h>
#include <EntitiesMP/PlayerMarker_tables.h>
#line 9 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"

  extern void CPlayerWeapons_Precache(ULONG ulAvailable);

void CPlayerMarker::SetDefaultProperties(void) {
  m_fHealth = 100.0f;
  m_fShield = 0.0f;
  m_iGiveWeapons = 0x1;
  m_iTakeWeapons = 0x0;
  m_strGroup = "";
  m_bQuickStart = FALSE ;
  m_bStartInComputer = FALSE ;
  m_penMessage = NULL;
  m_fMaxAmmoRatio = 0.0f;
  m_tmLastSpawned = -1000.0f;
  m_iTakeAmmo = 0x0;
  m_bNoRespawnInPlace = FALSE ;
  CMarker::SetDefaultProperties();
}
  
#line 37 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
void CPlayerMarker::Precache(void) {
#line 38 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
if(m_iGiveWeapons  > 1){
#line 39 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
CPlayerWeapons_Precache  (m_iGiveWeapons );
#line 40 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
}
#line 41 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
}
  
#line 42 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
BOOL CPlayerMarker::HandleEvent(const CEntityEvent & ee) {
#line 43 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
if(ee  . ee_slEvent  == EVENTCODE_ETrigger ){
#line 44 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
CEntity  * penMainMusicHolder  = _pNetwork  -> GetEntityWithName  ("MusicHolder" , 0);
#line 45 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
if(penMainMusicHolder  == NULL  || ! IsOfClass  (penMainMusicHolder  , "MusicHolder")){
#line 46 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
return TRUE ;
#line 47 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
}
#line 48 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
CMusicHolder  * pmh  = (CMusicHolder  *) penMainMusicHolder ;
#line 49 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
BOOL bNew  = (pmh  -> m_penRespawnMarker  != this );
#line 50 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
pmh  -> m_penRespawnMarker  = this ;
#line 53 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
CEntity  * penCaused  = ((ETrigger  &) ee ) . penCaused ;
#line 54 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
if(bNew  && 
#line 55 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
(GetSP  () -> sp_bSinglePlayer  && GetSP  () -> sp_gmGameMode  != CSessionProperties  :: GM_FLYOVER ) 
#line 56 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
&& IsOfClass  (penCaused  , "Player")){
#line 58 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
CPlayerSettings  * pps  = (CPlayerSettings  *) (((CPlayerEntity  *) penCaused ) -> en_pcCharacter  . pc_aubAppearance );
#line 59 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
if(pps  -> ps_ulFlags  & PSF_AUTOSAVE ){
#line 61 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
_pShell  -> Execute  ("gam_bQuickSave=1;");
#line 62 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
}
#line 63 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
}
#line 64 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
return TRUE ;
#line 65 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
}
#line 67 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
return FALSE ;
#line 68 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
}
BOOL CPlayerMarker::
#line 71 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CPlayerMarker_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CPlayerMarker::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 73 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
InitAsEditorModel  ();
#line 74 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 75 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 78 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
SetModel  (MODEL_MARKER );
#line 79 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 82 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
if(m_bQuickStart ){
#line 83 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
m_strName  . PrintF  ("Player Quick Start");
#line 84 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
}else {
#line 85 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
m_strName  . PrintF  ("Player Start - %s" , m_strGroup );
#line 86 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
}
#line 88 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
Return(STATE_CURRENT,EVoid());
#line 88 "C:/MyMod/Sources/EntitiesMP/PlayerMarker.es"
return TRUE; ASSERT(FALSE); return TRUE;};