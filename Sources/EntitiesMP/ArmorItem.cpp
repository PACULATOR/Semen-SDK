/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"

#include "StdH.h"
#include "Models/Items/ItemHolder/ItemHolder.h"

#include <EntitiesMP/ArmorItem.h>
#include <EntitiesMP/ArmorItem_tables.h>
CEntityEvent *EArmor::MakeCopy(void) { CEntityEvent *peeCopy = new EArmor(*this); return peeCopy;}
EArmor::EArmor() : CEntityEvent(EVENTCODE_EArmor) {;
 ClearToDefault(fArmor);
 ClearToDefault(bOverTopArmor);
};
void CArmorItem::SetDefaultProperties(void) {
  m_EaitType = ARIT_SHARD ;
  m_bOverTopArmor = FALSE ;
  m_iSoundComponent = 0;
  CItem::SetDefaultProperties();
}
  
#line 80 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
void CArmorItem::Precache(void) {
#line 81 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
switch(m_EaitType ){
#line 82 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SHARD : PrecacheSound  (SOUND_SHARD );break ;
#line 83 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SMALL : PrecacheSound  (SOUND_SMALL );break ;
#line 84 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_MEDIUM : PrecacheSound  (SOUND_MEDIUM );break ;
#line 85 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_STRONG : PrecacheSound  (SOUND_STRONG );break ;
#line 86 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SUPER : PrecacheSound  (SOUND_SUPER );break ;
#line 87 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_HELM : PrecacheSound  (SOUND_HELM );break ;
#line 88 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 89 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
  
#line 91 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
BOOL CArmorItem::FillEntityStatistics(EntityStats * pes) 
#line 92 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
{
#line 93 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
pes  -> es_strName  = "Armor";
#line 94 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
pes  -> es_ctCount  = 1;
#line 95 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
pes  -> es_ctAmmount  = m_fValue ;
#line 96 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
pes  -> es_fValue  = m_fValue  * 2;
#line 97 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
pes  -> es_iScore  = 0;
#line 98 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
switch(m_EaitType ){
#line 99 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SHARD : pes  -> es_strName  += " shard";break ;
#line 100 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SMALL : pes  -> es_strName  += " small";break ;
#line 101 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_MEDIUM : pes  -> es_strName  += " medium";break ;
#line 102 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_STRONG : pes  -> es_strName  += " strong";break ;
#line 103 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SUPER : pes  -> es_strName  += " super";break ;
#line 104 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_HELM : pes  -> es_strName  += " helm";break ;
#line 105 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 106 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
return TRUE ;
#line 107 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
  
#line 110 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
void CArmorItem::RenderParticles(void) {
#line 112 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
if(GetRenderType  () != CEntity  :: RT_MODEL  || GetSP  () -> sp_gmGameMode  > CSessionProperties  :: GM_COOPERATIVE  
#line 113 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
|| ! ShowItemParticles  ())
#line 114 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
{
#line 115 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
return ;
#line 116 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 117 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
switch(m_EaitType ){
#line 118 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SHARD : 
#line 119 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Particles_Emanate  (this  , 0.75f * 0.75 , 0.75f * 0.75 , PT_STAR04  , 8 , 7.0f);
#line 120 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
break ;
#line 121 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SMALL : 
#line 122 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Particles_Emanate  (this  , 1.0f * 0.75 , 1.0f * 0.75 , PT_STAR04  , 32 , 7.0f);
#line 123 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
break ;
#line 124 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_MEDIUM : 
#line 125 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Particles_Emanate  (this  , 1.5f * 0.75 , 1.5f * 0.75 , PT_STAR04  , 64 , 7.0f);
#line 126 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
break ;
#line 127 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_STRONG : 
#line 128 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Particles_Emanate  (this  , 2.0f * 0.75 , 1.25f * 0.75 , PT_STAR04  , 96 , 7.0f);
#line 129 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
break ;
#line 130 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SUPER : 
#line 131 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Particles_Emanate  (this  , 2.5f * 0.75 , 1.5f * 0.75 , PT_STAR04  , 128 , 7.0f);
#line 132 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
break ;
#line 133 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_HELM : 
#line 134 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Particles_Emanate  (this  , 0.875f * 0.75 , 0.875f * 0.75 , PT_STAR04  , 16 , 7.0f);
#line 135 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
break ;
#line 136 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 137 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
  
#line 140 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
void CArmorItem::SetProperties(void) {
#line 141 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
switch(m_EaitType ){
#line 142 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SHARD : 
#line 143 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_SMALL );
#line 144 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fValue  = 1.0f;
#line 145 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_bOverTopArmor  = TRUE ;
#line 146 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 10.0f;
#line 147 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_strDescription  . PrintF  ("Shard - H:%g  T:%g" , m_fValue  , m_fRespawnTime );
#line 149 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddItem  (MODEL_1  , TEXTURE_1  , 0 , TEX_SPEC_MEDIUM  , 0);
#line 150 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.4f , 0) , FLOAT3D (1.0 , 1.0 , 0.3f));
#line 151 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
StretchItem  (FLOAT3D (0.75f * 0.75 , 0.75f * 0.75 , 0.75f * 0.75));
#line 152 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_iSoundComponent  = SOUND_SHARD ;
#line 153 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
break ;
#line 154 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SMALL : 
#line 155 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_MEDIUM );
#line 156 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fValue  = 25.0f;
#line 157 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_bOverTopArmor  = FALSE ;
#line 158 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 10.0f;
#line 159 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_strDescription  . PrintF  ("Small - H:%g  T:%g" , m_fValue  , m_fRespawnTime );
#line 161 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddItem  (MODEL_25  , TEXTURE_25  , TEX_REFL_LIGHTMETAL01  , TEX_SPEC_MEDIUM  , 0);
#line 162 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.6f , 0) , FLOAT3D (2 , 2 , 0.5f));
#line 163 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
StretchItem  (FLOAT3D (2.0f , 2.0f , 2.0f));
#line 164 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_iSoundComponent  = SOUND_SMALL ;
#line 165 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
break ;
#line 166 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_MEDIUM : {
#line 167 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_MEDIUM );
#line 168 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fValue  = 50.0f;
#line 169 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_bOverTopArmor  = FALSE ;
#line 170 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 25.0f;
#line 171 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_strDescription  . PrintF  ("Medium - H:%g  T:%g" , m_fValue  , m_fRespawnTime );
#line 173 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddItem  (MODEL_50  , TEXTURE_50  , TEX_REFL_LIGHTMETAL01  , TEX_SPEC_MEDIUM  , 0);
#line 174 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 1.0f , 0) , FLOAT3D (3 , 3 , 0.5f));
#line 175 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
StretchItem  (FLOAT3D (2.0f , 2.0f , 2.0f));
#line 176 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_iSoundComponent  = SOUND_MEDIUM ;
#line 177 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}break ;
#line 178 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_STRONG : 
#line 179 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_MEDIUM );
#line 180 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fValue  = 100.0f;
#line 181 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_bOverTopArmor  = FALSE ;
#line 182 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 60.0f;
#line 183 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_strDescription  . PrintF  ("Strong - H:%g  T:%g" , m_fValue  , m_fRespawnTime );
#line 185 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddItem  (MODEL_100  , TEXTURE_100  , TEX_REFL_LIGHTMETAL01  , TEX_SPEC_MEDIUM  , 0);
#line 186 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.75f , 0) , FLOAT3D (3.5 , 3.5 , 1.0f));
#line 187 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
StretchItem  (FLOAT3D (2.5f , 2.5f , 2.5f));
#line 188 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_iSoundComponent  = SOUND_STRONG ;
#line 189 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
break ;
#line 190 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SUPER : 
#line 191 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_MEDIUM );
#line 192 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fValue  = 200.0f;
#line 193 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_bOverTopArmor  = TRUE ;
#line 194 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 120.0f;
#line 195 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_strDescription  . PrintF  ("Super - H:%g  T:%g" , m_fValue  , m_fRespawnTime );
#line 198 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddItem  (MODEL_200  , TEXTURE_200  , TEX_REFL_LIGHTMETAL01  , TEX_SPEC_MEDIUM  , 0);
#line 199 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.75f , 0) , FLOAT3D (3 , 3 , 1.0f));
#line 200 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
StretchItem  (FLOAT3D (2.5f , 2.5f , 2.5f));
#line 201 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_iSoundComponent  = SOUND_SUPER ;
#line 202 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
break ;
#line 203 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_HELM : 
#line 204 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_SMALL );
#line 205 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fValue  = 5.0f;
#line 206 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_bOverTopArmor  = FALSE ;
#line 207 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 10.0f;
#line 208 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_strDescription  . PrintF  ("Helm - H:%g  T:%g" , m_fValue  , m_fRespawnTime );
#line 210 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddItem  (MODEL_5  , TEXTURE_5  , 0 , TEX_SPEC_MEDIUM  , 0);
#line 211 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.5f , 0) , FLOAT3D (1.5 , 1.5 , 0.4f));
#line 212 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
StretchItem  (FLOAT3D (0.875f * 0.75 , 0.875f * 0.75 , 0.875f * 0.75));
#line 213 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_iSoundComponent  = SOUND_HELM ;
#line 214 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
break ;
#line 215 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 216 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
  
#line 218 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
void CArmorItem::AdjustDifficulty(void) 
#line 219 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
{
#line 220 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
if(! GetSP  () -> sp_bAllowArmor  && m_penTarget  == NULL ){
#line 221 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Destroy  ();
#line 222 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 223 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
BOOL CArmorItem::
#line 226 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
ItemCollected(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CArmorItem_ItemCollected
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EPass, "CArmorItem::ItemCollected expects 'EPass' as input!");  const EPass &epass = (const EPass &)__eeInput;
#line 227 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
ASSERT  (epass  . penOther  != NULL );
#line 230 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
if(GetSP  () -> sp_bHealthArmorStays  && ! (m_bPickupOnce  || m_bRespawn )){
#line 232 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
BOOL bWasPicked  = MarkPickedBy  (epass  . penOther );
#line 233 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
if(bWasPicked ){
#line 235 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Return(STATE_CURRENT,EVoid());
#line 235 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
return TRUE;
#line 236 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 237 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 240 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
EArmor  eArmor ;
#line 241 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
eArmor  . fArmor  = m_fValue ;
#line 242 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
eArmor  . bOverTopArmor  = m_bOverTopArmor ;
#line 244 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
if(epass  . penOther  -> ReceiveItem  (eArmor )){
#line 246 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
if(_pNetwork  -> IsPlayerLocal  (epass  . penOther ))
#line 247 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
{
#line 248 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
switch(m_EaitType )
#line 249 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
{
#line 250 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SHARD : IFeel_PlayEffect  ("PU_ArmourShard");break ;
#line 251 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SMALL : IFeel_PlayEffect  ("PU_ArmourSmall");break ;
#line 252 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_MEDIUM : IFeel_PlayEffect  ("PU_ArmourMedium");break ;
#line 253 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_STRONG : IFeel_PlayEffect  ("PU_ArmourStrong");break ;
#line 254 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_SUPER : IFeel_PlayEffect  ("PU_ArmourSuper");break ;
#line 255 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
case ARIT_HELM : IFeel_PlayEffect  ("PU_ArmourHelm");break ;
#line 256 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 257 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 260 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_soPick  . Set3DParameters  (50.0f , 1.0f , 1.0f , 1.0f);
#line 261 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
PlaySound  (m_soPick  , m_iSoundComponent  , SOF_3D );
#line 262 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
m_fPickSoundLen  = GetSoundLength  (m_iSoundComponent );
#line 264 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
if(! GetSP  () -> sp_bHealthArmorStays  || (m_bPickupOnce  || m_bRespawn )){
#line 265 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Jump(STATE_CURRENT, STATE_CItem_ItemReceived, FALSE, EVoid());return TRUE;
#line 266 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 267 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
}
#line 268 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Return(STATE_CURRENT,EVoid());
#line 268 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CArmorItem::
#line 271 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CArmorItem_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CArmorItem::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 272 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Initialize  ();
#line 273 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
StartModelAnim  (ITEMHOLDER_ANIM_SMALLOSCILATION  , AOF_LOOPING  | AOF_NORESTART );
#line 274 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
SetProperties  ();
#line 276 "C:/MyMod/Sources/EntitiesMP/ArmorItem.es"
Jump(STATE_CURRENT, STATE_CItem_ItemLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};