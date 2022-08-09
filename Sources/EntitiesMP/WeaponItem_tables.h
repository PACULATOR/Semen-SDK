/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

EP_ENUMBEG(WeaponItemType)
  EP_ENUMVALUE(WIT_COLT, "Colt"),
  EP_ENUMVALUE(WIT_SINGLESHOTGUN, "Single shotgun"),
  EP_ENUMVALUE(WIT_DOUBLESHOTGUN, "Double shotgun"),
  EP_ENUMVALUE(WIT_TOMMYGUN, "Tommygun"),
  EP_ENUMVALUE(WIT_MINIGUN, "Minigun"),
  EP_ENUMVALUE(WIT_ROCKETLAUNCHER, "Rocket launcher"),
  EP_ENUMVALUE(WIT_GRENADELAUNCHER, "Grenade launcher"),
  EP_ENUMVALUE(WIT_SNIPER, "Sniper"),
  EP_ENUMVALUE(WIT_FLAMER, "Flamer"),
  EP_ENUMVALUE(WIT_LASER, "Laser"),
  EP_ENUMVALUE(WIT_CHAINSAW, "Chainsaw"),
  EP_ENUMVALUE(WIT_CANNON, "Cannon"),
  EP_ENUMVALUE(WIT_GHOSTBUSTER, "obsolete"),
EP_ENUMEND(WeaponItemType);

#define ENTITYCLASS CWeaponItem

CEntityProperty CWeaponItem_properties[] = {
 CEntityProperty(CEntityProperty::EPT_ENUM, &WeaponItemType_enum, (0x00000322<<8)+1, offsetof(CWeaponItem, m_EwitType), "Type", 'Y', 0x7F0000FFUL, 0),
};
#define CWeaponItem_propertiesct ARRAYCOUNT(CWeaponItem_properties)

CEntityComponent CWeaponItem_components[] = {
#define CLASS_BASE ((0x00000322<<8)+0)
 CEntityComponent(ECT_CLASS, CLASS_BASE, "EFNM" "Classes\\Item.ecl"),
#define MODEL_COLT ((0x00000322<<8)+30)
 CEntityComponent(ECT_MODEL, MODEL_COLT, "EFNM" "Models\\Weapons\\Colt\\ColtItem.mdl"),
#define MODEL_COLTCOCK ((0x00000322<<8)+31)
 CEntityComponent(ECT_MODEL, MODEL_COLTCOCK, "EFNM" "Models\\Weapons\\Colt\\ColtCock.mdl"),
#define MODEL_COLTMAIN ((0x00000322<<8)+32)
 CEntityComponent(ECT_MODEL, MODEL_COLTMAIN, "EFNM" "Models\\Weapons\\Colt\\ColtMain.mdl"),
#define MODEL_COLTBULLETS ((0x00000322<<8)+33)
 CEntityComponent(ECT_MODEL, MODEL_COLTBULLETS, "EFNM" "Models\\Weapons\\Colt\\ColtBullets.mdl"),
#define TEXTURE_COLTMAIN ((0x00000322<<8)+34)
 CEntityComponent(ECT_TEXTURE, TEXTURE_COLTMAIN, "EFNM" "Models\\Weapons\\Colt\\ColtMain.tex"),
#define TEXTURE_COLTCOCK ((0x00000322<<8)+35)
 CEntityComponent(ECT_TEXTURE, TEXTURE_COLTCOCK, "EFNM" "Models\\Weapons\\Colt\\ColtCock.tex"),
#define TEXTURE_COLTBULLETS ((0x00000322<<8)+36)
 CEntityComponent(ECT_TEXTURE, TEXTURE_COLTBULLETS, "EFNM" "Models\\Weapons\\Colt\\ColtBullets.tex"),
#define MODEL_SINGLESHOTGUN ((0x00000322<<8)+40)
 CEntityComponent(ECT_MODEL, MODEL_SINGLESHOTGUN, "EFNM" "Models\\Weapons\\SingleShotgun\\SingleShotgunItem.mdl"),
#define MODEL_SS_SLIDER ((0x00000322<<8)+41)
 CEntityComponent(ECT_MODEL, MODEL_SS_SLIDER, "EFNM" "Models\\Weapons\\SingleShotgun\\Slider.mdl"),
#define MODEL_SS_HANDLE ((0x00000322<<8)+42)
 CEntityComponent(ECT_MODEL, MODEL_SS_HANDLE, "EFNM" "Models\\Weapons\\SingleShotgun\\Handle.mdl"),
#define MODEL_SS_BARRELS ((0x00000322<<8)+43)
 CEntityComponent(ECT_MODEL, MODEL_SS_BARRELS, "EFNM" "Models\\Weapons\\SingleShotgun\\Barrels.mdl"),
#define TEXTURE_SS_HANDLE ((0x00000322<<8)+44)
 CEntityComponent(ECT_TEXTURE, TEXTURE_SS_HANDLE, "EFNM" "Models\\Weapons\\SingleShotgun\\Handle.tex"),
#define TEXTURE_SS_BARRELS ((0x00000322<<8)+45)
 CEntityComponent(ECT_TEXTURE, TEXTURE_SS_BARRELS, "EFNM" "Models\\Weapons\\SingleShotgun\\Barrels.tex"),
#define MODEL_DOUBLESHOTGUN ((0x00000322<<8)+50)
 CEntityComponent(ECT_MODEL, MODEL_DOUBLESHOTGUN, "EFNM" "Models\\Weapons\\DoubleShotgun\\DoubleShotgunItem.mdl"),
#define MODEL_DS_HANDLE ((0x00000322<<8)+51)
 CEntityComponent(ECT_MODEL, MODEL_DS_HANDLE, "EFNM" "Models\\Weapons\\DoubleShotgun\\Dshotgunhandle.mdl"),
#define MODEL_DS_BARRELS ((0x00000322<<8)+52)
 CEntityComponent(ECT_MODEL, MODEL_DS_BARRELS, "EFNM" "Models\\Weapons\\DoubleShotgun\\Dshotgunbarrels.mdl"),
#define MODEL_DS_SWITCH ((0x00000322<<8)+54)
 CEntityComponent(ECT_MODEL, MODEL_DS_SWITCH, "EFNM" "Models\\Weapons\\DoubleShotgun\\Switch.mdl"),
#define TEXTURE_DS_HANDLE ((0x00000322<<8)+56)
 CEntityComponent(ECT_TEXTURE, TEXTURE_DS_HANDLE, "EFNM" "Models\\Weapons\\DoubleShotgun\\Handle.tex"),
#define TEXTURE_DS_BARRELS ((0x00000322<<8)+57)
 CEntityComponent(ECT_TEXTURE, TEXTURE_DS_BARRELS, "EFNM" "Models\\Weapons\\DoubleShotgun\\Barrels.tex"),
#define TEXTURE_DS_SWITCH ((0x00000322<<8)+58)
 CEntityComponent(ECT_TEXTURE, TEXTURE_DS_SWITCH, "EFNM" "Models\\Weapons\\DoubleShotgun\\Switch.tex"),
#define MODEL_TOMMYGUN ((0x00000322<<8)+70)
 CEntityComponent(ECT_MODEL, MODEL_TOMMYGUN, "EFNM" "Models\\Weapons\\TommyGun\\TommyGunItem.mdl"),
#define MODEL_TG_BODY ((0x00000322<<8)+71)
 CEntityComponent(ECT_MODEL, MODEL_TG_BODY, "EFNM" "Models\\Weapons\\TommyGun\\Body.mdl"),
#define MODEL_TG_SLIDER ((0x00000322<<8)+72)
 CEntityComponent(ECT_MODEL, MODEL_TG_SLIDER, "EFNM" "Models\\Weapons\\TommyGun\\Slider.mdl"),
#define TEXTURE_TG_BODY ((0x00000322<<8)+73)
 CEntityComponent(ECT_TEXTURE, TEXTURE_TG_BODY, "EFNM" "Models\\Weapons\\TommyGun\\Body.tex"),
#define MODEL_MINIGUN ((0x00000322<<8)+80)
 CEntityComponent(ECT_MODEL, MODEL_MINIGUN, "EFNM" "Models\\Weapons\\MiniGun\\MiniGunItem.mdl"),
#define MODEL_MG_BARRELS ((0x00000322<<8)+81)
 CEntityComponent(ECT_MODEL, MODEL_MG_BARRELS, "EFNM" "Models\\Weapons\\MiniGun\\Barrels.mdl"),
#define MODEL_MG_BODY ((0x00000322<<8)+82)
 CEntityComponent(ECT_MODEL, MODEL_MG_BODY, "EFNM" "Models\\Weapons\\MiniGun\\Body.mdl"),
#define MODEL_MG_ENGINE ((0x00000322<<8)+83)
 CEntityComponent(ECT_MODEL, MODEL_MG_ENGINE, "EFNM" "Models\\Weapons\\MiniGun\\Engine.mdl"),
#define TEXTURE_MG_BODY ((0x00000322<<8)+84)
 CEntityComponent(ECT_TEXTURE, TEXTURE_MG_BODY, "EFNM" "Models\\Weapons\\MiniGun\\Body.tex"),
#define TEXTURE_MG_BARRELS ((0x00000322<<8)+99)
 CEntityComponent(ECT_TEXTURE, TEXTURE_MG_BARRELS, "EFNM" "Models\\Weapons\\MiniGun\\Barrels.tex"),
#define MODEL_ROCKETLAUNCHER ((0x00000322<<8)+90)
 CEntityComponent(ECT_MODEL, MODEL_ROCKETLAUNCHER, "EFNM" "Models\\Weapons\\RocketLauncher\\RocketLauncherItem.mdl"),
#define MODEL_RL_BODY ((0x00000322<<8)+91)
 CEntityComponent(ECT_MODEL, MODEL_RL_BODY, "EFNM" "Models\\Weapons\\RocketLauncher\\Body.mdl"),
#define TEXTURE_RL_BODY ((0x00000322<<8)+92)
 CEntityComponent(ECT_TEXTURE, TEXTURE_RL_BODY, "EFNM" "Models\\Weapons\\RocketLauncher\\Body.tex"),
#define MODEL_RL_ROTATINGPART ((0x00000322<<8)+93)
 CEntityComponent(ECT_MODEL, MODEL_RL_ROTATINGPART, "EFNM" "Models\\Weapons\\RocketLauncher\\RotatingPart.mdl"),
#define TEXTURE_RL_ROTATINGPART ((0x00000322<<8)+94)
 CEntityComponent(ECT_TEXTURE, TEXTURE_RL_ROTATINGPART, "EFNM" "Models\\Weapons\\RocketLauncher\\RotatingPart.tex"),
#define MODEL_RL_ROCKET ((0x00000322<<8)+95)
 CEntityComponent(ECT_MODEL, MODEL_RL_ROCKET, "EFNM" "Models\\Weapons\\RocketLauncher\\Projectile\\Rocket.mdl"),
#define TEXTURE_RL_ROCKET ((0x00000322<<8)+96)
 CEntityComponent(ECT_TEXTURE, TEXTURE_RL_ROCKET, "EFNM" "Models\\Weapons\\RocketLauncher\\Projectile\\Rocket.tex"),
#define MODEL_GRENADELAUNCHER ((0x00000322<<8)+100)
 CEntityComponent(ECT_MODEL, MODEL_GRENADELAUNCHER, "EFNM" "Models\\Weapons\\GrenadeLauncher\\GrenadeLauncherItem.mdl"),
#define MODEL_GL_BODY ((0x00000322<<8)+101)
 CEntityComponent(ECT_MODEL, MODEL_GL_BODY, "EFNM" "Models\\Weapons\\GrenadeLauncher\\Body.mdl"),
#define MODEL_GL_MOVINGPART ((0x00000322<<8)+102)
 CEntityComponent(ECT_MODEL, MODEL_GL_MOVINGPART, "EFNM" "Models\\Weapons\\GrenadeLauncher\\MovingPipe.mdl"),
#define MODEL_GL_GRENADE ((0x00000322<<8)+103)
 CEntityComponent(ECT_MODEL, MODEL_GL_GRENADE, "EFNM" "Models\\Weapons\\GrenadeLauncher\\GrenadeBack.mdl"),
#define TEXTURE_GL_BODY ((0x00000322<<8)+104)
 CEntityComponent(ECT_TEXTURE, TEXTURE_GL_BODY, "EFNM" "Models\\Weapons\\GrenadeLauncher\\Body.tex"),
#define TEXTURE_GL_MOVINGPART ((0x00000322<<8)+105)
 CEntityComponent(ECT_TEXTURE, TEXTURE_GL_MOVINGPART, "EFNM" "Models\\Weapons\\GrenadeLauncher\\MovingPipe.tex"),
#define MODEL_SNIPER ((0x00000322<<8)+110)
 CEntityComponent(ECT_MODEL, MODEL_SNIPER, "EFNM" "ModelsMP\\Weapons\\Sniper\\Sniper.mdl"),
#define MODEL_SNIPER_BODY ((0x00000322<<8)+111)
 CEntityComponent(ECT_MODEL, MODEL_SNIPER_BODY, "EFNM" "ModelsMP\\Weapons\\Sniper\\Body.mdl"),
#define TEXTURE_SNIPER_BODY ((0x00000322<<8)+112)
 CEntityComponent(ECT_TEXTURE, TEXTURE_SNIPER_BODY, "EFNM" "ModelsMP\\Weapons\\Sniper\\Body.tex"),
#define MODEL_FLAMER ((0x00000322<<8)+130)
 CEntityComponent(ECT_MODEL, MODEL_FLAMER, "EFNM" "ModelsMP\\Weapons\\Flamer\\FlamerItem.mdl"),
#define MODEL_FL_BODY ((0x00000322<<8)+131)
 CEntityComponent(ECT_MODEL, MODEL_FL_BODY, "EFNM" "ModelsMP\\Weapons\\Flamer\\Body.mdl"),
#define MODEL_FL_RESERVOIR ((0x00000322<<8)+132)
 CEntityComponent(ECT_MODEL, MODEL_FL_RESERVOIR, "EFNM" "ModelsMP\\Weapons\\Flamer\\FuelReservoir.mdl"),
#define MODEL_FL_FLAME ((0x00000322<<8)+133)
 CEntityComponent(ECT_MODEL, MODEL_FL_FLAME, "EFNM" "ModelsMP\\Weapons\\Flamer\\Flame.mdl"),
#define TEXTURE_FL_BODY ((0x00000322<<8)+134)
 CEntityComponent(ECT_TEXTURE, TEXTURE_FL_BODY, "EFNM" "ModelsMP\\Weapons\\Flamer\\Body.tex"),
#define TEXTURE_FL_FLAME ((0x00000322<<8)+135)
 CEntityComponent(ECT_TEXTURE, TEXTURE_FL_FLAME, "EFNM" "ModelsMP\\Effects\\Flame\\Flame.tex"),
#define TEXTURE_FL_FUELRESERVOIR ((0x00000322<<8)+136)
 CEntityComponent(ECT_TEXTURE, TEXTURE_FL_FUELRESERVOIR, "EFNM" "ModelsMP\\Weapons\\Flamer\\FuelReservoir.tex"),
#define MODEL_LASER ((0x00000322<<8)+140)
 CEntityComponent(ECT_MODEL, MODEL_LASER, "EFNM" "Models\\Weapons\\Laser\\LaserItem.mdl"),
#define MODEL_LS_BODY ((0x00000322<<8)+141)
 CEntityComponent(ECT_MODEL, MODEL_LS_BODY, "EFNM" "Models\\Weapons\\Laser\\Body.mdl"),
#define MODEL_LS_BARREL ((0x00000322<<8)+142)
 CEntityComponent(ECT_MODEL, MODEL_LS_BARREL, "EFNM" "Models\\Weapons\\Laser\\Barrel.mdl"),
#define TEXTURE_LS_BODY ((0x00000322<<8)+143)
 CEntityComponent(ECT_TEXTURE, TEXTURE_LS_BODY, "EFNM" "Models\\Weapons\\Laser\\Body.tex"),
#define TEXTURE_LS_BARREL ((0x00000322<<8)+144)
 CEntityComponent(ECT_TEXTURE, TEXTURE_LS_BARREL, "EFNM" "Models\\Weapons\\Laser\\Barrel.tex"),
#define MODEL_CHAINSAW ((0x00000322<<8)+150)
 CEntityComponent(ECT_MODEL, MODEL_CHAINSAW, "EFNM" "ModelsMP\\Weapons\\Chainsaw\\ChainsawItem.mdl"),
#define MODEL_CS_BODY ((0x00000322<<8)+151)
 CEntityComponent(ECT_MODEL, MODEL_CS_BODY, "EFNM" "ModelsMP\\Weapons\\Chainsaw\\Body.mdl"),
#define MODEL_CS_BLADE ((0x00000322<<8)+152)
 CEntityComponent(ECT_MODEL, MODEL_CS_BLADE, "EFNM" "ModelsMP\\Weapons\\Chainsaw\\Blade.mdl"),
#define MODEL_CS_TEETH ((0x00000322<<8)+153)
 CEntityComponent(ECT_MODEL, MODEL_CS_TEETH, "EFNM" "ModelsMP\\Weapons\\Chainsaw\\Teeth.mdl"),
#define TEXTURE_CS_BODY ((0x00000322<<8)+154)
 CEntityComponent(ECT_TEXTURE, TEXTURE_CS_BODY, "EFNM" "ModelsMP\\Weapons\\Chainsaw\\Body.tex"),
#define TEXTURE_CS_BLADE ((0x00000322<<8)+155)
 CEntityComponent(ECT_TEXTURE, TEXTURE_CS_BLADE, "EFNM" "ModelsMP\\Weapons\\Chainsaw\\Blade.tex"),
#define TEXTURE_CS_TEETH ((0x00000322<<8)+156)
 CEntityComponent(ECT_TEXTURE, TEXTURE_CS_TEETH, "EFNM" "ModelsMP\\Weapons\\Chainsaw\\Teeth.tex"),
#define MODEL_CANNON ((0x00000322<<8)+170)
 CEntityComponent(ECT_MODEL, MODEL_CANNON, "EFNM" "Models\\Weapons\\Cannon\\Cannon.mdl"),
#define MODEL_CN_BODY ((0x00000322<<8)+171)
 CEntityComponent(ECT_MODEL, MODEL_CN_BODY, "EFNM" "Models\\Weapons\\Cannon\\Body.mdl"),
#define TEXTURE_CANNON ((0x00000322<<8)+173)
 CEntityComponent(ECT_TEXTURE, TEXTURE_CANNON, "EFNM" "Models\\Weapons\\Cannon\\Body.tex"),
#define TEXTURE_FLARE ((0x00000322<<8)+190)
 CEntityComponent(ECT_TEXTURE, TEXTURE_FLARE, "EFNM" "Models\\Items\\Flares\\Flare.tex"),
#define MODEL_FLARE ((0x00000322<<8)+191)
 CEntityComponent(ECT_MODEL, MODEL_FLARE, "EFNM" "Models\\Items\\Flares\\Flare.mdl"),
#define TEX_REFL_BWRIPLES01 ((0x00000322<<8)+200)
 CEntityComponent(ECT_TEXTURE, TEX_REFL_BWRIPLES01, "EFNM" "Models\\ReflectionTextures\\BWRiples01.tex"),
#define TEX_REFL_BWRIPLES02 ((0x00000322<<8)+201)
 CEntityComponent(ECT_TEXTURE, TEX_REFL_BWRIPLES02, "EFNM" "Models\\ReflectionTextures\\BWRiples02.tex"),
#define TEX_REFL_LIGHTMETAL01 ((0x00000322<<8)+202)
 CEntityComponent(ECT_TEXTURE, TEX_REFL_LIGHTMETAL01, "EFNM" "Models\\ReflectionTextures\\LightMetal01.tex"),
#define TEX_REFL_LIGHTBLUEMETAL01 ((0x00000322<<8)+203)
 CEntityComponent(ECT_TEXTURE, TEX_REFL_LIGHTBLUEMETAL01, "EFNM" "Models\\ReflectionTextures\\LightBlueMetal01.tex"),
#define TEX_REFL_DARKMETAL ((0x00000322<<8)+204)
 CEntityComponent(ECT_TEXTURE, TEX_REFL_DARKMETAL, "EFNM" "Models\\ReflectionTextures\\DarkMetal.tex"),
#define TEX_REFL_PURPLE01 ((0x00000322<<8)+205)
 CEntityComponent(ECT_TEXTURE, TEX_REFL_PURPLE01, "EFNM" "Models\\ReflectionTextures\\Purple01.tex"),
#define TEX_SPEC_WEAK ((0x00000322<<8)+210)
 CEntityComponent(ECT_TEXTURE, TEX_SPEC_WEAK, "EFNM" "Models\\SpecularTextures\\Weak.tex"),
#define TEX_SPEC_MEDIUM ((0x00000322<<8)+211)
 CEntityComponent(ECT_TEXTURE, TEX_SPEC_MEDIUM, "EFNM" "Models\\SpecularTextures\\Medium.tex"),
#define TEX_SPEC_STRONG ((0x00000322<<8)+212)
 CEntityComponent(ECT_TEXTURE, TEX_SPEC_STRONG, "EFNM" "Models\\SpecularTextures\\Strong.tex"),
#define SOUND_PICK ((0x00000322<<8)+213)
 CEntityComponent(ECT_SOUND, SOUND_PICK, "EFNM" "Sounds\\Items\\Weapon.wav"),
};
#define CWeaponItem_componentsct ARRAYCOUNT(CWeaponItem_components)

CEventHandlerEntry CWeaponItem_handlers[] = {
 {0x03220001, STATE_CItem_ItemCollected, CEntity::pEventHandler(&CWeaponItem::
#line 387 "C:/MyMod/Sources/EntitiesMP/WeaponItem.es"
ItemCollected),DEBUGSTRING("CWeaponItem::ItemCollected")},
 {1, -1, CEntity::pEventHandler(&CWeaponItem::
#line 419 "C:/MyMod/Sources/EntitiesMP/WeaponItem.es"
Main),DEBUGSTRING("CWeaponItem::Main")},
 {0x03220002, -1, CEntity::pEventHandler(&CWeaponItem::H0x03220002_Main_01), DEBUGSTRING("CWeaponItem::H0x03220002_Main_01")},
 {0x03220003, -1, CEntity::pEventHandler(&CWeaponItem::H0x03220003_Main_02), DEBUGSTRING("CWeaponItem::H0x03220003_Main_02")},
 {0x03220004, -1, CEntity::pEventHandler(&CWeaponItem::H0x03220004_Main_03), DEBUGSTRING("CWeaponItem::H0x03220004_Main_03")},
 {0x03220005, -1, CEntity::pEventHandler(&CWeaponItem::H0x03220005_Main_04), DEBUGSTRING("CWeaponItem::H0x03220005_Main_04")},
 {0x03220006, -1, CEntity::pEventHandler(&CWeaponItem::H0x03220006_Main_05), DEBUGSTRING("CWeaponItem::H0x03220006_Main_05")},
};
#define CWeaponItem_handlersct ARRAYCOUNT(CWeaponItem_handlers)

CEntity *CWeaponItem_New(void) { return new CWeaponItem; };
void CWeaponItem_OnInitClass(void) {};
void CWeaponItem_OnEndClass(void) {};
void CWeaponItem_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CWeaponItem_OnWorldEnd(CWorld *pwo) {};
void CWeaponItem_OnWorldInit(CWorld *pwo) {};
void CWeaponItem_OnWorldTick(CWorld *pwo) {};
void CWeaponItem_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CWeaponItem, CItem, "Weapon Item", "Thumbnails\\WeaponItem.tbn", 0x00000322);
DECLARE_CTFILENAME(_fnmCWeaponItem_tbn, "Thumbnails\\WeaponItem.tbn");
