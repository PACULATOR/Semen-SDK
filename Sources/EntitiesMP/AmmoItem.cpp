/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"

#include "StdH.h"
#include "Models/Items/ItemHolder/ItemHolder.h"
#include "Models/Items/Ammo/Shells/Shells.h"
#include "Models/Items/Ammo/Bullets/Bullets.h"
#include "Models/Items/Ammo/Rockets/Rockets.h"
#include "Models/Weapons/RocketLauncher/Projectile/Rocket.h"
#include "Models/Items/Ammo/Grenades/Grenades.h"
#include "Models/Items/Ammo/Electricity/Electricity.h"
#include "Models/Items/Ammo/Cannonball/Cannonball.h"
#include "Models/Items/Ammo/Cannonball/CannonballQuad.h"
#include "ModelsMP/Items/Ammo/SniperBullets/SniperBullets.h"

#include <EntitiesMP/AmmoItem.h>
#include <EntitiesMP/AmmoItem_tables.h>
CEntityEvent *EAmmoItem::MakeCopy(void) { CEntityEvent *peeCopy = new EAmmoItem(*this); return peeCopy;}
EAmmoItem::EAmmoItem() : CEntityEvent(EVENTCODE_EAmmoItem) {;
 ClearToDefault(EaitType);
 ClearToDefault(iQuantity);
};
void CAmmoItem::SetDefaultProperties(void) {
  m_EaitType = AIT_SHELLS ;
  CItem::SetDefaultProperties();
}
  
#line 120 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
void CAmmoItem::Precache(void) {
#line 121 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
PrecacheSound  (SOUND_PICK );
#line 122 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
  
#line 125 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
void CAmmoItem::RenderParticles(void) {
#line 127 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
if(GetRenderType  () != CEntity  :: RT_MODEL  || GetSP  () -> sp_gmGameMode  > CSessionProperties  :: GM_COOPERATIVE  
#line 128 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
|| ! ShowItemParticles  ())
#line 129 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
{
#line 130 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
return ;
#line 131 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 132 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
switch(m_EaitType ){
#line 133 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_SHELLS : 
#line 134 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Particles_Spiral  (this  , 1.0f * 0.75 , 1.0f * 0.75 , PT_STAR04  , 4);
#line 135 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 136 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_BULLETS : 
#line 137 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Particles_Spiral  (this  , 1.5f * 0.75 , 1.0f * 0.75 , PT_STAR04  , 6);
#line 138 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 139 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_ROCKETS : 
#line 140 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Particles_Spiral  (this  , 1.5f * 0.75 , 1.25f * 0.75 , PT_STAR04  , 6);
#line 141 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 142 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_GRENADES : 
#line 143 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Particles_Spiral  (this  , 2.0f * 0.75 , 1.25f * 0.75 , PT_STAR04  , 6);
#line 144 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 145 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_ELECTRICITY : 
#line 146 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Particles_Spiral  (this  , 1.5f * 0.75 , 1.125f * 0.75 , PT_STAR04  , 6);
#line 147 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 148 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_NUKEBALL : 
#line 149 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Particles_Spiral  (this  , 1.25f * 0.75 , 1.0f * 0.75 , PT_STAR04  , 4);
#line 150 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 151 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_IRONBALLS : 
#line 152 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Particles_Spiral  (this  , 2.0f * 0.75 , 1.25f * 0.75 , PT_STAR04  , 8);
#line 153 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 154 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_BACKPACK : 
#line 155 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Particles_Spiral  (this  , 3.0f * 0.5 , 2.5f * 0.5 , PT_STAR04  , 10);
#line 156 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 157 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_SERIOUSPACK : 
#line 158 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Particles_Spiral  (this  , 3.0f * 0.5 , 2.5f * 0.5 , PT_STAR04  , 10);
#line 159 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 160 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_NAPALM : 
#line 161 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Particles_Spiral  (this  , 3.0f * 0.5 , 2.5f * 0.5 , PT_STAR04  , 10);
#line 162 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 163 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_SNIPERBULLETS : 
#line 164 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Particles_Spiral  (this  , 1.5f * 0.75 , 1.25f * 0.75 , PT_STAR04  , 6);
#line 165 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 166 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 167 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
  
#line 170 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
BOOL CAmmoItem::FillEntityStatistics(EntityStats * pes) 
#line 171 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
{
#line 172 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_ctCount  = 1;
#line 173 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_ctAmmount  = m_fValue ;
#line 174 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
switch(m_EaitType ){
#line 175 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_SHELLS : 
#line 176 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_strName  = "Shells";
#line 177 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_fValue  = m_fValue  * AV_SHELLS ;
#line 178 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 179 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_BULLETS : 
#line 180 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_strName  = "Bullets";
#line 181 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_fValue  = m_fValue  * AV_BULLETS ;
#line 182 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 183 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_ROCKETS : 
#line 184 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_strName  = "Rockets";
#line 185 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_fValue  = m_fValue  * AV_ROCKETS ;
#line 186 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 187 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_GRENADES : 
#line 188 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_strName  = "Grenades";
#line 189 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_fValue  = m_fValue  * AV_GRENADES ;
#line 190 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 191 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_ELECTRICITY : 
#line 192 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_strName  = "Electricity";
#line 193 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_fValue  = m_fValue  * AV_ELECTRICITY ;
#line 194 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 201 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_IRONBALLS : 
#line 202 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_strName  = "Ironballs";
#line 203 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_fValue  = m_fValue  * AV_IRONBALLS ;
#line 204 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 205 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_SERIOUSPACK : 
#line 206 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_strName  = "SeriousPack";
#line 207 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_fValue  = m_fValue  * 100000;
#line 208 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 209 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_BACKPACK : 
#line 210 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_strName  = "BackPack";
#line 211 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_fValue  = m_fValue  * 100000;
#line 212 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 213 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_NAPALM : 
#line 214 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_strName  = "Napalm";
#line 215 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_fValue  = m_fValue  * AV_NAPALM ;
#line 216 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 217 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_SNIPERBULLETS : 
#line 218 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_strName  = "Sniper bullets";
#line 219 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_fValue  = m_fValue  * AV_SNIPERBULLETS ;
#line 220 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 221 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 222 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
pes  -> es_iScore  = 0;
#line 223 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
return TRUE ;
#line 224 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
  
#line 228 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
void CAmmoItem::SetProperties(void) 
#line 229 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
{
#line 230 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
switch(m_EaitType ){
#line 231 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_SHELLS : 
#line 232 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fValue  = 10.0f;
#line 233 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 30.0f;
#line 234 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_strDescription  . PrintF  ("Shells: %d" , (int ) m_fValue );
#line 236 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItem  (MODEL_SHELLS  , TEXTURE_SHELLS  , 0 , 0 , 0);
#line 237 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.25f , 0) , FLOAT3D (1.5 , 1.5 , 0.75f));
#line 238 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
StretchItem  (FLOAT3D (0.75f , 0.75f , 0.75f));
#line 239 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 240 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_BULLETS : 
#line 241 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fValue  = 50.0f;
#line 242 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 30.0f;
#line 243 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_strDescription  . PrintF  ("Bullets: %d" , (int ) m_fValue );
#line 245 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItem  (MODEL_BULLETS  , TEXTURE_BULLETS  , 0 , 0 , 0);
#line 246 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.6f , 0) , FLOAT3D (3 , 3 , 1.0f));
#line 247 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
StretchItem  (FLOAT3D (0.75f , 0.75f , 0.75f));
#line 248 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 249 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_ROCKETS : 
#line 250 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fValue  = 5.0f;
#line 251 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 30.0f;
#line 252 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_strDescription  . PrintF  ("Rockets: %d" , (int ) m_fValue );
#line 254 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItem  (MODEL_ROCKETS  , TEXTURE_ROCKET  , 0 , 0 , 0);
#line 255 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItemAttachment  (ROCKETS_ATTACHMENT_ROCKET1  , MODEL_RC_ROCKET  , TEXTURE_ROCKET  , 0 , 0 , 0);
#line 256 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItemAttachment  (ROCKETS_ATTACHMENT_ROCKET2  , MODEL_RC_ROCKET  , TEXTURE_ROCKET  , 0 , 0 , 0);
#line 257 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItemAttachment  (ROCKETS_ATTACHMENT_ROCKET3  , MODEL_RC_ROCKET  , TEXTURE_ROCKET  , 0 , 0 , 0);
#line 258 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItemAttachment  (ROCKETS_ATTACHMENT_ROCKET4  , MODEL_RC_ROCKET  , TEXTURE_ROCKET  , 0 , 0 , 0);
#line 259 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItemAttachment  (ROCKETS_ATTACHMENT_ROCKET5  , MODEL_RC_ROCKET  , TEXTURE_ROCKET  , 0 , 0 , 0);
#line 260 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
SetItemAttachmentAnim  (ROCKETS_ATTACHMENT_ROCKET1  , ROCKET_ANIM_FORAMMO );
#line 261 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
SetItemAttachmentAnim  (ROCKETS_ATTACHMENT_ROCKET2  , ROCKET_ANIM_FORAMMO );
#line 262 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
SetItemAttachmentAnim  (ROCKETS_ATTACHMENT_ROCKET3  , ROCKET_ANIM_FORAMMO );
#line 263 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
SetItemAttachmentAnim  (ROCKETS_ATTACHMENT_ROCKET4  , ROCKET_ANIM_FORAMMO );
#line 264 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
SetItemAttachmentAnim  (ROCKETS_ATTACHMENT_ROCKET5  , ROCKET_ANIM_FORAMMO );
#line 265 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.6f , 0) , FLOAT3D (2 , 2 , 0.75f));
#line 266 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
StretchItem  (FLOAT3D (0.75f , 0.75f , 0.75f));
#line 267 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 268 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_GRENADES : 
#line 269 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fValue  = 5.0f;
#line 270 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 30.0f;
#line 271 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_strDescription  . PrintF  ("Grenades: %d" , (int ) m_fValue );
#line 273 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItem  (MODEL_GRENADES  , TEXTURE_GRENADES  , 0 , 0 , 0);
#line 274 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.6f , 0) , FLOAT3D (4 , 4 , 1.0f));
#line 275 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
StretchItem  (FLOAT3D (0.75f , 0.75f , 0.75f));
#line 276 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 277 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_ELECTRICITY : 
#line 278 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fValue  = 50.0f;
#line 279 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 30.0f;
#line 280 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_strDescription  . PrintF  ("Electricity: %d" , (int ) m_fValue );
#line 282 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItem  (MODEL_ELECTRICITY  , TEXTURE_ELECTRICITY  , TEXTURE_EL_EFFECT  , TEXTURE_EL_EFFECT  , 0);
#line 283 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItemAttachment  (ELECTRICITY_ATTACHMENT_EFFECT1  , MODEL_EL_EFFECT  , TEXTURE_EL_EFFECT  , 0 , 0 , 0);
#line 284 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItemAttachment  (ELECTRICITY_ATTACHMENT_EFFECT2  , MODEL_EL_EFFECT  , TEXTURE_EL_EFFECT  , 0 , 0 , 0);
#line 285 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItemAttachment  (ELECTRICITY_ATTACHMENT_EFFECT3  , MODEL_EL_EFFECT2  , TEXTURE_EL_EFFECT  , 0 , 0 , 0);
#line 286 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.6f , 0) , FLOAT3D (3 , 3 , 0.8f));
#line 287 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
StretchItem  (FLOAT3D (0.75f , 0.75f , 0.75f));
#line 288 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 300 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_IRONBALLS : 
#line 301 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fValue  = 4.0f;
#line 302 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 30.0f;
#line 303 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_strDescription  . PrintF  ("Iron balls: %d" , (int ) m_fValue );
#line 305 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItem  (MODEL_CANNONBALLS  , TEXTURE_IRONBALL  , TEX_REFL_DARKMETAL  , TEX_SPEC_WEAK  , 0);
#line 306 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.75f , 0) , FLOAT3D (5 , 5 , 1.3f));
#line 307 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
StretchItem  (FLOAT3D (0.75f , 0.75f , 0.75f));
#line 308 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 309 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_NAPALM : 
#line 310 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fValue  = 100.0f;
#line 311 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 30.0f;
#line 312 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_strDescription  . PrintF  ("Napalm: %d" , (int ) m_fValue );
#line 314 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItem  (MODEL_FL_RESERVOIR  , TEXTURE_FL_FUELRESERVOIR  , TEX_REFL_LIGHTMETAL01  , TEX_SPEC_MEDIUM  , 0);
#line 315 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.75f , 0) , FLOAT3D (3 , 3 , 1.0f));
#line 316 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
StretchItem  (FLOAT3D (1.25f , 1.25f , 1.25f));
#line 317 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 318 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_SERIOUSPACK : 
#line 319 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fValue  = 1.0f;
#line 320 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 30.0f;
#line 321 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_strDescription  . PrintF  ("SeriousPack: %d" , (int ) m_fValue );
#line 323 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItem  (MODEL_SERIOUSPACK  , TEXTURE_SERIOUSPACK  , 0 , 0 , 0);
#line 324 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.75f , 0) , FLOAT3D (2 , 2 , 1.3f));
#line 325 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
StretchItem  (FLOAT3D (0.5f , 0.5f , 0.5f));
#line 326 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 327 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_BACKPACK : 
#line 328 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fValue  = 1.0f;
#line 329 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 30.0f;
#line 330 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_strDescription  . PrintF  ("BackPack: %d" , (int ) m_fValue );
#line 332 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItem  (MODEL_BACKPACK  , TEXTURE_BACKPACK  , 0 , 0 , 0);
#line 333 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.75f , 0) , FLOAT3D (2 , 2 , 1.3f));
#line 334 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
StretchItem  (FLOAT3D (0.5f , 0.5f , 0.5f));
#line 335 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 336 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
case AIT_SNIPERBULLETS : 
#line 337 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fValue  = 5.0f;
#line 338 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fRespawnTime  = (m_fCustomRespawnTime  > 0) ? m_fCustomRespawnTime  : 30.0f;
#line 339 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_strDescription  . PrintF  ("Sniper bullets: %d" , (int ) m_fValue );
#line 341 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddItem  (MODEL_SNIPER_BULLETS  , TEXTURE_SNIPER_BULLETS  , TEX_REFL_LIGHTMETAL01  , TEX_SPEC_MEDIUM  , 0);
#line 342 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
AddFlare  (MODEL_FLARE  , TEXTURE_FLARE  , FLOAT3D (0 , 0.75f , 0) , FLOAT3D (3 , 3 , 1.0f));
#line 343 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
StretchItem  (FLOAT3D (1.25f , 1.25f , 1.25f));
#line 344 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
break ;
#line 345 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
default  : ASSERTALWAYS  ("Uknown ammo");
#line 346 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 347 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
  
#line 349 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
void CAmmoItem::AdjustDifficulty(void) 
#line 350 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
{
#line 351 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fValue  = ceil  (m_fValue  * GetSP  () -> sp_fAmmoQuantity );
#line 353 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
if(GetSP  () -> sp_bInfiniteAmmo  && m_penTarget  == NULL ){
#line 354 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Destroy  ();
#line 355 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 356 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
BOOL CAmmoItem::
#line 359 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
ItemCollected(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CAmmoItem_ItemCollected
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EPass, "CAmmoItem::ItemCollected expects 'EPass' as input!");  const EPass &epass = (const EPass &)__eeInput;
#line 360 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
ASSERT  (epass  . penOther  != NULL );
#line 363 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
if(GetSP  () -> sp_bAmmoStays  && ! (m_bPickupOnce  || m_bRespawn )){
#line 365 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
BOOL bWasPicked  = MarkPickedBy  (epass  . penOther );
#line 366 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
if(bWasPicked ){
#line 368 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Return(STATE_CURRENT,EVoid());
#line 368 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
return TRUE;
#line 369 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 370 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 373 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
EAmmoItem  eAmmo ;
#line 374 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
eAmmo  . EaitType  = m_EaitType ;
#line 375 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
eAmmo  . iQuantity  = (INDEX) m_fValue ;
#line 377 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
if(epass  . penOther  -> ReceiveItem  (eAmmo )){
#line 379 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_soPick  . Set3DParameters  (50.0f , 1.0f , 1.0f , 1.0f);
#line 380 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
if(_pNetwork  -> IsPlayerLocal  (epass  . penOther )){IFeel_PlayEffect  ("PU_Ammo");}
#line 381 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
if((m_EaitType  == AIT_SERIOUSPACK ) || (m_EaitType  == AIT_BACKPACK ))
#line 382 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
{
#line 383 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
PlaySound  (m_soPick  , SOUND_DEFAULT  , SOF_3D );
#line 384 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
CPrintF  ("^cFF0000^f5Warning!!! Replace old serious pack with new, BackPack entity!^r\n");
#line 385 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 386 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
else 
#line 387 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
{
#line 388 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
PlaySound  (m_soPick  , SOUND_PICK  , SOF_3D );
#line 389 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 390 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_fPickSoundLen  = GetSoundLength  (SOUND_PICK );
#line 391 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
if(! GetSP  () -> sp_bAmmoStays  || (m_bPickupOnce  || m_bRespawn )){
#line 392 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Jump(STATE_CURRENT, STATE_CItem_ItemReceived, FALSE, EVoid());return TRUE;
#line 393 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 394 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 395 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Return(STATE_CURRENT,EVoid());
#line 395 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CAmmoItem::
#line 398 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CAmmoItem_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CAmmoItem::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 399 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
if(m_EaitType  == AIT_NUKEBALL ){
#line 400 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
m_EaitType  = AIT_SHELLS ;
#line 401 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
}
#line 402 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Initialize  ();
#line 403 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
StartModelAnim  (ITEMHOLDER_ANIM_MEDIUMOSCILATION  , AOF_LOOPING  | AOF_NORESTART );
#line 404 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
ForceCollisionBoxIndexChange  (ITEMHOLDER_COLLISION_BOX_MEDIUM );
#line 405 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
SetProperties  ();
#line 407 "C:/MyMod/Sources/EntitiesMP/AmmoItem.es"
Jump(STATE_CURRENT, STATE_CItem_ItemLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};