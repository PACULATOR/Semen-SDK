/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"

#include "StdH.h"

#include <EntitiesMP/Bouncer.h>
#include <EntitiesMP/Bouncer_tables.h>
#line 6 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"


extern DECL_DLL void JumpFromBouncer(CEntity *penToBounce, CEntity *penBouncer)
{
  CEntity *pen = penToBounce;
  CBouncer *pbo = (CBouncer *)penBouncer;
  // if it is a movable model and some time has passed from the last jump
  if ( (pen->GetRenderType()==CEntity::RT_MODEL) &&
       (pen->GetPhysicsFlags()&EPF_MOVABLE) ) {
    CMovableEntity *pmen = (CMovableEntity *)pen;
    if (pmen->en_penReference==NULL) {
      return;
    }
    // give it speed
    FLOAT3D vDir;
    AnglesToDirectionVector(pbo->m_aDirection, vDir);
    pmen->FakeJump(pmen->en_vIntendedTranslation, vDir, pbo->m_fSpeed, 
      -pbo->m_fParallelComponentMultiplier, pbo->m_fNormalComponentMultiplier, pbo->m_fMaxExitSpeed, pbo->m_tmControl);
  }
}


void CBouncer::SetDefaultProperties(void) {
  m_strName = "Bouncer";
  m_strDescription = "";
  m_fSpeed = 20.0f;
  m_aDirection = ANGLE3D(0 , 90 , 0);
  m_tmControl = 5.0f;
  m_bEntrySpeed = TRUE ;
  m_fMaxExitSpeed = 200.0f;
  m_fNormalComponentMultiplier = 1.0f;
  m_fParallelComponentMultiplier = 0.0f;
  CRationalEntity::SetDefaultProperties();
}
BOOL CBouncer::
#line 49 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBouncer_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBouncer::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 51 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"
InitAsBrush  ();
#line 52 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"
SetPhysicsFlags  (EPF_BRUSH_FIXED  | EPF_NOIMPACT );
#line 53 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"
SetCollisionFlags  (ECF_BRUSH );
#line 56 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"
if(! m_bEntrySpeed )
#line 57 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"
{
#line 59 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"
m_fNormalComponentMultiplier  = 0.0f;
#line 60 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"
m_bEntrySpeed  = TRUE ;
#line 61 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"
}
#line 62 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"
Return(STATE_CURRENT,EVoid());
#line 62 "C:/MyMod/Sources/EntitiesMP/Bouncer.es"
return TRUE; ASSERT(FALSE); return TRUE;};