/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"

#include "StdH.h"
#include "ModelsMP/CutSequences/Book/Book.h"
#include "ModelsMP/CutSequences/Book/CoverPages.h"

#include <EntitiesMP/PhotoAlbum.h>
#include <EntitiesMP/PhotoAlbum_tables.h>
void CPhotoAlbum::SetDefaultProperties(void) {
  m_fStretch = 1.0f;
  m_strName = "Photo album";
  m_iCurrentPage = -1;
  m_tmPageWait = 0.5f;
  m_soPage.SetOwner(this);
m_soPage.Stop_internal();
  CMovableModelEntity::SetDefaultProperties();
}
  
#line 40 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
void CPhotoAlbum::Precache(void) {
#line 41 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PrecacheTexture  (TEXTURE_PAGE01 );
#line 42 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PrecacheTexture  (TEXTURE_PAGE02 );
#line 43 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PrecacheTexture  (TEXTURE_PAGE03 );
#line 44 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PrecacheTexture  (TEXTURE_PAGE04 );
#line 45 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PrecacheTexture  (TEXTURE_PAGE_JOKE );
#line 46 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PrecacheTexture  (TEXTURE_PAGE05 );
#line 47 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PrecacheTexture  (TEXTURE_PAGE06 );
#line 48 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PrecacheTexture  (TEXTURE_PAGE07 );
#line 49 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PrecacheTexture  (TEXTURE_BLANK_PAGE );
#line 50 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PrecacheSound  (SOUND_PAGE );
#line 51 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
}
BOOL CPhotoAlbum::
#line 54 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
OpenBook(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CPhotoAlbum_OpenBook
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CPhotoAlbum::OpenBook expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 57 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
GetModelObject  () -> PlayAnim  (BOOK_ANIM_OPENING  , 0);
#line 59 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
CModelObject & mo1  = GetModelObject  () -> GetAttachmentModel  (BOOK_ATTACHMENT_PAGE01 ) -> amo_moModelObject ;
#line 60 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
mo1  . PlayAnim  (COVERPAGES_ANIM_OPENING  , 0);
#line 62 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
CModelObject & mo2  = GetModelObject  () -> GetAttachmentModel  (BOOK_ATTACHMENT_PAGE02 ) -> amo_moModelObject ;
#line 63 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
mo2  . PlayAnim  (COVERPAGES_ANIM_RIGHTOPENING  , 0);
#line 64 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
m_soPage  . Set3DParameters  (1000.0f , 500.0f , 2.0f , 1.0f);
#line 65 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PlaySound  (m_soPage  , SOUND_PAGE  , SOF_3D );
#line 67 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
SetTimerAfter(GetModelObject  () -> GetAnimLength  (BOOK_ANIM_OPENING ));
Jump(STATE_CURRENT, 0x02660001, FALSE, EBegin());return TRUE;}BOOL CPhotoAlbum::H0x02660001_OpenBook_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02660001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x02660002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CPhotoAlbum::H0x02660002_OpenBook_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02660002
;
#line 68 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
SetTimerAfter(0.1f);
Jump(STATE_CURRENT, 0x02660003, FALSE, EBegin());return TRUE;}BOOL CPhotoAlbum::H0x02660003_OpenBook_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02660003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x02660004, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CPhotoAlbum::H0x02660004_OpenBook_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02660004
;
#line 69 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
m_iCurrentPage  = TEXTURE_PAGE01 ;
#line 70 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
Jump(STATE_CURRENT,0x0266000b, FALSE, EInternal());return TRUE;}BOOL CPhotoAlbum::H0x0266000b_OpenBook_11(const CEntityEvent &__eeInput)
#line 71 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
{
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0266000b
if(!(m_iCurrentPage  < TEXTURE_PAGE07 )){ Jump(STATE_CURRENT,0x0266000c, FALSE, EInternal());return TRUE;}
#line 72 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
SetTimerAfter(m_tmPageWait );
Jump(STATE_CURRENT, 0x02660005, FALSE, EBegin());return TRUE;}BOOL CPhotoAlbum::H0x02660005_OpenBook_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02660005
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x02660006, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CPhotoAlbum::H0x02660006_OpenBook_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02660006
;
#line 73 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
AddAttachment  (BOOK_ATTACHMENT_PAGE03  , MODEL_PAGE  , m_iCurrentPage );
#line 74 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
GetModelObject  () -> StretchModel  (FLOAT3D (m_fStretch  , m_fStretch  , m_fStretch ));
#line 75 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
CModelObject & mo3  = GetModelObject  () -> GetAttachmentModel  (BOOK_ATTACHMENT_PAGE03 ) -> amo_moModelObject ;
#line 76 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
mo3  . PlayAnim  (COVERPAGES_ANIM_OPENING  , 0);
#line 77 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
PlaySound  (m_soPage  , SOUND_PAGE  , SOF_3D );
#line 79 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
CModelObject & mo2  = GetModelObject  () -> GetAttachmentModel  (BOOK_ATTACHMENT_PAGE02 ) -> amo_moModelObject ;
#line 80 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
mo2  . SetTextureData  (GetTextureDataForComponent  (m_iCurrentPage  + 1));
#line 81 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
SetTimerAfter(1.0f);
Jump(STATE_CURRENT, 0x02660007, FALSE, EBegin());return TRUE;}BOOL CPhotoAlbum::H0x02660007_OpenBook_07(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02660007
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x02660008, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CPhotoAlbum::H0x02660008_OpenBook_08(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x02660008
;
#line 82 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
CModelObject & mo3  = GetModelObject  () -> GetAttachmentModel  (BOOK_ATTACHMENT_PAGE03 ) -> amo_moModelObject ;
#line 83 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
mo3  . SetTextureData  (GetTextureDataForComponent  (TEXTURE_BLANK_PAGE ));
#line 84 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
SetTimerAfter(mo3  . GetAnimLength  (COVERPAGES_ANIM_OPENING ) - 1.0f);
Jump(STATE_CURRENT, 0x02660009, FALSE, EBegin());return TRUE;}BOOL CPhotoAlbum::H0x02660009_OpenBook_09(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x02660009
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0266000a, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CPhotoAlbum::H0x0266000a_OpenBook_10(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0266000a
;
#line 85 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
RemoveAttachment  (BOOK_ATTACHMENT_PAGE03 );
#line 86 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
m_iCurrentPage  += 1;Jump(STATE_CURRENT,0x0266000b, FALSE, EInternal());return TRUE;
#line 87 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
}BOOL CPhotoAlbum::H0x0266000c_OpenBook_12(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0266000c

#line 89 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
Return(STATE_CURRENT,EReturn  ());
#line 89 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CPhotoAlbum::
#line 95 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CPhotoAlbum_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CPhotoAlbum::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 97 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
InitAsModel  ();
#line 99 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 100 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 103 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
SetModel  (MODEL_ALBUM );
#line 104 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
SetModelMainTexture  (TEXTURE_ALBUM );
#line 105 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
GetModelObject  () -> StartAnim  (BOOK_ANIM_CLOSED );
#line 106 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
AddAttachment  (BOOK_ATTACHMENT_PAGE01  , MODEL_PAGE  , TEXTURE_BLANK_PAGE );
#line 107 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
AddAttachment  (BOOK_ATTACHMENT_PAGE02  , MODEL_PAGE  , TEXTURE_PAGE01 );
#line 108 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
CAttachmentModelObject  * pamo ;
#line 109 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
pamo  = GetModelObject  () -> GetAttachmentModel  (BOOK_ATTACHMENT_PAGE01 );
#line 110 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
CModelObject * pmo ;
#line 111 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
pmo  = & pamo  -> amo_moModelObject ;
#line 112 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
pmo  -> PlayAnim  (COVERPAGES_ANIM_LEFTCLOSED  , 0);
#line 113 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
pamo  = GetModelObject  () -> GetAttachmentModel  (BOOK_ATTACHMENT_PAGE02 );
#line 114 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
pmo  = & pamo  -> amo_moModelObject ;
#line 115 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
pmo  -> PlayAnim  (COVERPAGES_ANIM_RIGHTCLOSED  , 0);
#line 117 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
GetModelObject  () -> StretchModel  (FLOAT3D (m_fStretch  , m_fStretch  , m_fStretch ));
#line 118 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
ModelChangeNotify  ();
#line 120 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x0266000d, FALSE, EBegin());return TRUE;}BOOL CPhotoAlbum::H0x0266000d_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0266000d
switch(__eeInput.ee_slEvent)
#line 121 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
{case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 124 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
return TRUE;
#line 125 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStart):{const EStart&e= (EStart&)__eeInput;

#line 127 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
Call(STATE_CURRENT, STATE_CPhotoAlbum_OpenBook, TRUE, EVoid());return TRUE;
#line 128 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
return TRUE;
#line 129 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
}ASSERT(FALSE);break;case(EVENTCODE_EReturn):{const EReturn&e= (EReturn&)__eeInput;

#line 131 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
return TRUE;
#line 132 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 133 "C:/MyMod/Sources/EntitiesMP/PhotoAlbum.es"
}return TRUE;}BOOL CPhotoAlbum::H0x0266000e_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0266000e
; ASSERT(FALSE); return TRUE;};