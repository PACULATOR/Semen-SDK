/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_WatchPlayers_INCLUDED
#define _EntitiesMP_WatchPlayers_INCLUDED 1
extern "C" DECL_DLL CDLLEntityClass CWatchPlayers_DLLClass;
class CWatchPlayers : public CRationalEntity {
public:
virtual const CTString &GetName(void) const { return m_strName; };
virtual BOOL IsTargetable(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  CEntityPointer m_penOwner;
  CEntityPointer m_penFar;
  FLOAT m_fWaitTime;
  RANGE m_fDistance;
  BOOL m_bRangeWatcher;
  enum EventEType m_eetEventClose;
  enum EventEType m_eetEventFar;
  CEntityPointer m_penCurrentWatch;
  BOOL m_bActive;
  CTString m_strName;
   
#line 32 "C:/MyMod/Sources/EntitiesMP/WatchPlayers.es"
BOOL IsAnyPlayerClose(void);
   
#line 66 "C:/MyMod/Sources/EntitiesMP/WatchPlayers.es"
void SendCloseEvent(void);
   
#line 77 "C:/MyMod/Sources/EntitiesMP/WatchPlayers.es"
void SendFarEvent(void);
#define  STATE_CWatchPlayers_Main 1
  BOOL 
#line 93 "C:/MyMod/Sources/EntitiesMP/WatchPlayers.es"
Main(const CEntityEvent &__eeInput);
#define  STATE_CWatchPlayers_Active 0x02be0000
  BOOL 
#line 114 "C:/MyMod/Sources/EntitiesMP/WatchPlayers.es"
Active(const CEntityEvent &__eeInput);
  BOOL H0x02be0001_Active_01(const CEntityEvent &__eeInput);
  BOOL H0x02be0002_Active_02(const CEntityEvent &__eeInput);
#define  STATE_CWatchPlayers_Inactive 0x02be0003
  BOOL 
#line 120 "C:/MyMod/Sources/EntitiesMP/WatchPlayers.es"
Inactive(const CEntityEvent &__eeInput);
  BOOL H0x02be0004_Inactive_01(const CEntityEvent &__eeInput);
  BOOL H0x02be0005_Inactive_02(const CEntityEvent &__eeInput);
#define  STATE_CWatchPlayers_CloseWatch 0x02be0006
  BOOL 
#line 134 "C:/MyMod/Sources/EntitiesMP/WatchPlayers.es"
CloseWatch(const CEntityEvent &__eeInput);
  BOOL H0x02be0007_CloseWatch_01(const CEntityEvent &__eeInput);
  BOOL H0x02be0008_CloseWatch_02(const CEntityEvent &__eeInput);
  BOOL H0x02be0009_CloseWatch_03(const CEntityEvent &__eeInput);
  BOOL H0x02be000a_CloseWatch_04(const CEntityEvent &__eeInput);
#define  STATE_CWatchPlayers_FarWatch 0x02be000b
  BOOL 
#line 151 "C:/MyMod/Sources/EntitiesMP/WatchPlayers.es"
FarWatch(const CEntityEvent &__eeInput);
  BOOL H0x02be000c_FarWatch_01(const CEntityEvent &__eeInput);
  BOOL H0x02be000d_FarWatch_02(const CEntityEvent &__eeInput);
  BOOL H0x02be000e_FarWatch_03(const CEntityEvent &__eeInput);
  BOOL H0x02be000f_FarWatch_04(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_WatchPlayers_INCLUDED
