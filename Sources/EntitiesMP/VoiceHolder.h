/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_VoiceHolder_INCLUDED
#define _EntitiesMP_VoiceHolder_INCLUDED 1
extern "C" DECL_DLL CDLLEntityClass CVoiceHolder_DLLClass;
class CVoiceHolder : public CRationalEntity {
public:
virtual const CTString &GetName(void) const { return m_strName; };
virtual BOOL IsTargetable(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  CTString m_strName;
  CTString m_strDescription;
  CTFileName m_fnmMessage;
  BOOL m_bActive;
  INDEX m_ctMaxTrigs;
CAutoPrecacheSound m_aps;
   
#line 27 "C:/MyMod/Sources/EntitiesMP/VoiceHolder.es"
void Precache(void);
   
#line 31 "C:/MyMod/Sources/EntitiesMP/VoiceHolder.es"
const CTString & GetDescription(void)const;
#define  STATE_CVoiceHolder_Main 1
  BOOL 
#line 37 "C:/MyMod/Sources/EntitiesMP/VoiceHolder.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x00e70000_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x00e70001_Main_02(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_VoiceHolder_INCLUDED
