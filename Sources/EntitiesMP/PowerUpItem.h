/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_PowerUpItem_INCLUDED
#define _EntitiesMP_PowerUpItem_INCLUDED 1
#include <EntitiesMP/Item.h>
#include <EntitiesMP/Player.h>
extern DECL_DLL CEntityPropertyEnumType PowerUpItemType_enum;
enum PowerUpItemType {
  PUIT_INVISIB = 0,
  PUIT_INVULNER = 1,
  PUIT_DAMAGE = 2,
  PUIT_SPEED = 3,
  PUIT_BOMB = 4,
};
DECL_DLL inline void ClearToDefault(PowerUpItemType &e) { e = (PowerUpItemType)0; } ;
#define EVENTCODE_EPowerUp 0x03280000
class DECL_DLL EPowerUp : public CEntityEvent {
public:
EPowerUp();
CEntityEvent *MakeCopy(void);
enum PowerUpItemType puitType;
};
DECL_DLL inline void ClearToDefault(EPowerUp &e) { e = EPowerUp(); } ;
extern "C" DECL_DLL CDLLEntityClass CPowerUpItem_DLLClass;
class CPowerUpItem : public CItem {
public:
  DECL_DLL virtual void SetDefaultProperties(void);
  enum PowerUpItemType m_puitType;
   
#line 75 "C:/MyMod/Sources/EntitiesMP/PowerUpItem.es"
void Precache(void);
   
#line 88 "C:/MyMod/Sources/EntitiesMP/PowerUpItem.es"
BOOL FillEntityStatistics(EntityStats * pes);
   
#line 107 "C:/MyMod/Sources/EntitiesMP/PowerUpItem.es"
void RenderParticles(void);
   
#line 134 "C:/MyMod/Sources/EntitiesMP/PowerUpItem.es"
void SetProperties(void);
#define  STATE_CPowerUpItem_ItemCollected 0x03280001
  BOOL 
#line 189 "C:/MyMod/Sources/EntitiesMP/PowerUpItem.es"
ItemCollected(const CEntityEvent &__eeInput);
#define  STATE_CPowerUpItem_Main 1
  BOOL 
#line 244 "C:/MyMod/Sources/EntitiesMP/PowerUpItem.es"
Main(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_PowerUpItem_INCLUDED
