/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"

#include "StdH.h"
#include "Models/Items/ItemHolder/ItemHolder.h"

#include <EntitiesMP/AmmoPack.h>
#include <EntitiesMP/AmmoPack_tables.h>
CEntityEvent *EAmmoPackItem::MakeCopy(void) { CEntityEvent *peeCopy = new EAmmoPackItem(*this); return peeCopy;}
EAmmoPackItem::EAmmoPackItem() : CEntityEvent(EVENTCODE_EAmmoPackItem) {;
 ClearToDefault(iShells);
 ClearToDefault(iBullets);
 ClearToDefault(iRockets);
 ClearToDefault(iGrenades);
 ClearToDefault(iNapalm);
 ClearToDefault(iElectricity);
 ClearToDefault(iIronBalls);
 ClearToDefault(iSniperBullets);
};
void CAmmoPack::SetDefaultProperties(void) {
  m_aptPackType = APT_CUSTOM ;
  m_iShells = MAX_SHELLS ;
  m_iBullets = MAX_BULLETS ;
  m_iRockets = MAX_ROCKETS ;
  m_iGrenades = MAX_GRENADES ;
  m_iNapalm = MAX_NAPALM ;
  m_iElectricity = MAX_ELECTRICITY ;
  m_iIronBalls = MAX_IRONBALLS ;
  m_iSniperBullets = MAX_SNIPERBULLETS ;
  CItem::SetDefaultProperties();
}
  
#line 64 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
void CAmmoPack::Precache(void) {
#line 65 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
PrecacheSound  (SOUND_PICK );
#line 66 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
  
#line 69 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
void CAmmoPack::RenderParticles(void) 
#line 70 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
{
#line 72 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(GetRenderType  () != CEntity  :: RT_MODEL  || GetSP  () -> sp_gmGameMode  > CSessionProperties  :: GM_COOPERATIVE  
#line 73 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
|| ! ShowItemParticles  ())
#line 74 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
{
#line 75 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
return ;
#line 76 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
#line 78 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
Particles_Spiral  (this  , 3.0f * 0.5 , 2.5f * 0.5 , PT_STAR04  , 10);
#line 79 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
  
#line 82 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
BOOL CAmmoPack::FillEntityStatistics(EntityStats * pes) 
#line 83 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
{
#line 84 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
pes  -> es_ctCount  = 1;
#line 85 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
pes  -> es_ctAmmount  = 1;
#line 91 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
pes  -> es_strName  . PrintF  ("Back pack: %d Shells, %d Bullets, %d Rockets, %d Grenades, %d Napalm, %d Electricity, %d Iron balls, %d Sniper bullets" , 
#line 92 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iShells  , m_iBullets  , m_iRockets  , m_iGrenades  , m_iNapalm  , m_iElectricity  , m_iIronBalls  , m_iSniperBullets );
#line 95 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
pes  -> es_fValue  = 
#line 96 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iShells  * AV_SHELLS  + 
#line 97 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iBullets  * AV_BULLETS  + 
#line 98 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iRockets  * AV_ROCKETS  + 
#line 99 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iGrenades  * AV_GRENADES  + 
#line 100 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iNapalm  * AV_NAPALM  + 
#line 101 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iElectricity  * AV_ELECTRICITY  + 
#line 102 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iIronBalls  * AV_IRONBALLS  + 
#line 103 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iSniperBullets  * AV_SNIPERBULLETS 
#line 104 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
;
#line 106 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
pes  -> es_iScore  = 0;
#line 107 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
return TRUE ;
#line 108 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
  
#line 111 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
void CAmmoPack::SetProperties(void) 
#line 112 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
{
#line 113 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
switch(m_aptPackType )
#line 114 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
{
#line 115 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
case APT_SERIOUS : 
#line 116 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_strDescription  = "Serious:";
#line 118 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
AddItem  (MODEL_SERIOUSPACK  , TEXTURE_SERIOUSPACK  , 0 , 0 , 0);
#line 119 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.75f , 0) , FLOAT3D (2 , 2 , 1.3f));
#line 120 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
StretchItem  (FLOAT3D (0.5f , 0.5f , 0.5f));
#line 121 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
break ;
#line 122 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
case APT_CUSTOM : 
#line 123 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_strDescription  = "Custom:";
#line 125 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
AddItem  (MODEL_BACKPACK  , TEXTURE_BACKPACK  , 0 , 0 , 0);
#line 126 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.75f , 0) , FLOAT3D (2 , 2 , 1.3f));
#line 127 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
StretchItem  (FLOAT3D (0.5f , 0.5f , 0.5f));
#line 128 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
break ;
#line 129 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
default  : ASSERTALWAYS  ("Uknown ammo");
#line 130 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
#line 132 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_fValue  = 1.0f;
#line 133 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 30.0f;
#line 134 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(m_iShells  != 0){m_strDescription  . PrintF  ("%s: Shells (%d)" , m_strDescription  , m_iShells );}
#line 135 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(m_iBullets  != 0){m_strDescription  . PrintF  ("%s: Bullets (%d)" , m_strDescription  , m_iBullets );}
#line 136 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(m_iRockets  != 0){m_strDescription  . PrintF  ("%s: Rockets (%d)" , m_strDescription  , m_iRockets );}
#line 137 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(m_iGrenades  != 0){m_strDescription  . PrintF  ("%s: Grenades (%d)" , m_strDescription  , m_iGrenades );}
#line 138 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(m_iNapalm  != 0){m_strDescription  . PrintF  ("%s: Napalm (%d)" , m_strDescription  , m_iNapalm );}
#line 139 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(m_iElectricity  != 0){m_strDescription  . PrintF  ("%s: Electricity (%d)" , m_strDescription  , m_iElectricity );}
#line 140 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(m_iIronBalls  != 0){m_strDescription  . PrintF  ("%s: Iron balls (%d)" , m_strDescription  , m_iIronBalls );}
#line 142 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(m_iSniperBullets  != 0){m_strDescription  . PrintF  ("%s: Sniper bullets (%d)" , m_strDescription  , m_iSniperBullets );}
#line 143 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
  
#line 145 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
void CAmmoPack::AdjustDifficulty(void) 
#line 146 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
{
#line 149 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(GetSP  () -> sp_bInfiniteAmmo  && m_penTarget  == NULL ){
#line 150 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
Destroy  ();
#line 151 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
#line 152 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
BOOL CAmmoPack::
#line 155 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
ItemCollected(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CAmmoPack_ItemCollected
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EPass, "CAmmoPack::ItemCollected expects 'EPass' as input!");  const EPass &epass = (const EPass &)__eeInput;
#line 157 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
ASSERT  (epass  . penOther  != NULL );
#line 160 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(GetSP  () -> sp_bAmmoStays  && ! (m_bPickupOnce  || m_bRespawn )){
#line 162 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
BOOL bWasPicked  = MarkPickedBy  (epass  . penOther );
#line 163 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(bWasPicked ){
#line 165 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
Return(STATE_CURRENT,EVoid());
#line 165 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
return TRUE;
#line 166 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
#line 167 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
#line 170 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
EAmmoPackItem  eAmmo ;
#line 171 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
eAmmo  . iShells  = m_iShells ;
#line 172 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
eAmmo  . iBullets  = m_iBullets ;
#line 173 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
eAmmo  . iRockets  = m_iRockets ;
#line 174 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
eAmmo  . iGrenades  = m_iGrenades ;
#line 175 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
eAmmo  . iNapalm  = m_iNapalm ;
#line 176 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
eAmmo  . iElectricity  = m_iElectricity ;
#line 177 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
eAmmo  . iIronBalls  = m_iIronBalls ;
#line 179 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
eAmmo  . iSniperBullets  = m_iSniperBullets ;
#line 181 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(epass  . penOther  -> ReceiveItem  (eAmmo )){
#line 183 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_soPick  . Set3DParameters  (50.0f , 1.0f , 1.0f , 1.0f);
#line 184 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
PlaySound  (m_soPick  , SOUND_PICK  , SOF_3D );
#line 185 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_fPickSoundLen  = GetSoundLength  (SOUND_PICK );
#line 186 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
if(! GetSP  () -> sp_bAmmoStays  || (m_bPickupOnce  || m_bRespawn )){
#line 187 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
Jump(STATE_CURRENT, STATE_CItem_ItemReceived, FALSE, EVoid());return TRUE;
#line 188 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
#line 189 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
}
#line 190 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
Return(STATE_CURRENT,EVoid());
#line 190 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CAmmoPack::
#line 193 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CAmmoPack_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CAmmoPack::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 194 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iShells  = Clamp  (m_iShells  , INDEX (0) , MAX_SHELLS );
#line 195 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iBullets  = Clamp  (m_iBullets  , INDEX (0) , MAX_BULLETS );
#line 196 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iRockets  = Clamp  (m_iRockets  , INDEX (0) , MAX_ROCKETS );
#line 197 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iGrenades  = Clamp  (m_iGrenades  , INDEX (0) , MAX_GRENADES );
#line 198 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iNapalm  = Clamp  (m_iNapalm  , INDEX (0) , MAX_NAPALM );
#line 199 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iElectricity  = Clamp  (m_iElectricity  , INDEX (0) , MAX_ELECTRICITY );
#line 200 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iIronBalls  = Clamp  (m_iIronBalls  , INDEX (0) , MAX_IRONBALLS );
#line 202 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
m_iSniperBullets  = Clamp  (m_iSniperBullets  , INDEX (0) , MAX_SNIPERBULLETS );
#line 204 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
Initialize  ();
#line 205 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
StartModelAnim  (ITEMHOLDER_ANIM_MEDIUMOSCILATION  , AOF_LOOPING  | AOF_NORESTART );
#line 206 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_MEDIUM );
#line 207 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
SetProperties  ();
#line 209 "C:/MyMod/Sources/EntitiesMP/AmmoPack.es"
Jump(STATE_CURRENT, STATE_CItem_ItemLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};