/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

EP_ENUMBEG(GruntType)
  EP_ENUMVALUE(GT_SOLDIER, "Grunt soldier"),
  EP_ENUMVALUE(GT_COMMANDER, "Grunt commander"),
EP_ENUMEND(GruntType);

#define ENTITYCLASS CGrunt

CEntityProperty CGrunt_properties[] = {
 CEntityProperty(CEntityProperty::EPT_ENUM, &GruntType_enum, (0x00000157<<8)+1, offsetof(CGrunt, m_gtType), "Type", 'Y', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_SOUNDOBJECT, NULL, (0x00000157<<8)+10, offsetof(CGrunt, m_soFire1), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_SOUNDOBJECT, NULL, (0x00000157<<8)+11, offsetof(CGrunt, m_soFire2), "", 0, 0, 0),
};
#define CGrunt_propertiesct ARRAYCOUNT(CGrunt_properties)

CEntityComponent CGrunt_components[] = {
#define CLASS_BASE ((0x00000157<<8)+1)
 CEntityComponent(ECT_CLASS, CLASS_BASE, "EFNM" "Classes\\EnemyBase.ecl"),
#define CLASS_PROJECTILE ((0x00000157<<8)+3)
 CEntityComponent(ECT_CLASS, CLASS_PROJECTILE, "EFNM" "Classes\\Projectile.ecl"),
#define MODEL_GRUNT ((0x00000157<<8)+10)
 CEntityComponent(ECT_MODEL, MODEL_GRUNT, "EFNM" "ModelsMP\\Enemies\\Grunt\\Grunt.mdl"),
#define MODEL_GUN_COMMANDER ((0x00000157<<8)+11)
 CEntityComponent(ECT_MODEL, MODEL_GUN_COMMANDER, "EFNM" "ModelsMP\\Enemies\\Grunt\\Gun_Commander.mdl"),
#define MODEL_GUN_SOLDIER ((0x00000157<<8)+12)
 CEntityComponent(ECT_MODEL, MODEL_GUN_SOLDIER, "EFNM" "ModelsMP\\Enemies\\Grunt\\Gun.mdl"),
#define TEXTURE_SOLDIER ((0x00000157<<8)+20)
 CEntityComponent(ECT_TEXTURE, TEXTURE_SOLDIER, "EFNM" "ModelsMP\\Enemies\\Grunt\\Soldier.tex"),
#define TEXTURE_COMMANDER ((0x00000157<<8)+21)
 CEntityComponent(ECT_TEXTURE, TEXTURE_COMMANDER, "EFNM" "ModelsMP\\Enemies\\Grunt\\Commander.tex"),
#define TEXTURE_GUN_COMMANDER ((0x00000157<<8)+22)
 CEntityComponent(ECT_TEXTURE, TEXTURE_GUN_COMMANDER, "EFNM" "ModelsMP\\Enemies\\Grunt\\Gun_Commander.tex"),
#define TEXTURE_GUN_SOLDIER ((0x00000157<<8)+23)
 CEntityComponent(ECT_TEXTURE, TEXTURE_GUN_SOLDIER, "EFNM" "ModelsMP\\Enemies\\Grunt\\Gun.tex"),
#define SOUND_IDLE ((0x00000157<<8)+50)
 CEntityComponent(ECT_SOUND, SOUND_IDLE, "EFNM" "ModelsMP\\Enemies\\Grunt\\Sounds\\Idle.wav"),
#define SOUND_SIGHT ((0x00000157<<8)+52)
 CEntityComponent(ECT_SOUND, SOUND_SIGHT, "EFNM" "ModelsMP\\Enemies\\Grunt\\Sounds\\Sight.wav"),
#define SOUND_WOUND ((0x00000157<<8)+53)
 CEntityComponent(ECT_SOUND, SOUND_WOUND, "EFNM" "ModelsMP\\Enemies\\Grunt\\Sounds\\Wound.wav"),
#define SOUND_FIRE ((0x00000157<<8)+57)
 CEntityComponent(ECT_SOUND, SOUND_FIRE, "EFNM" "ModelsMP\\Enemies\\Grunt\\Sounds\\Fire.wav"),
#define SOUND_DEATH ((0x00000157<<8)+58)
 CEntityComponent(ECT_SOUND, SOUND_DEATH, "EFNM" "ModelsMP\\Enemies\\Grunt\\Sounds\\Death.wav"),
};
#define CGrunt_componentsct ARRAYCOUNT(CGrunt_components)

CEventHandlerEntry CGrunt_handlers[] = {
 {0x01570000, STATE_CEnemyBase_Fire, CEntity::pEventHandler(&CGrunt::
#line 212 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
Fire),DEBUGSTRING("CGrunt::Fire")},
 {0x01570001, -1, CEntity::pEventHandler(&CGrunt::H0x01570001_Fire_01), DEBUGSTRING("CGrunt::H0x01570001_Fire_01")},
 {0x01570002, -1, CEntity::pEventHandler(&CGrunt::H0x01570002_Fire_02), DEBUGSTRING("CGrunt::H0x01570002_Fire_02")},
 {0x01570003, -1, CEntity::pEventHandler(&CGrunt::H0x01570003_Fire_03), DEBUGSTRING("CGrunt::H0x01570003_Fire_03")},
 {0x01570004, -1, CEntity::pEventHandler(&CGrunt::H0x01570004_Fire_04), DEBUGSTRING("CGrunt::H0x01570004_Fire_04")},
 {0x01570005, -1, CEntity::pEventHandler(&CGrunt::H0x01570005_Fire_05), DEBUGSTRING("CGrunt::H0x01570005_Fire_05")},
 {0x01570006, -1, CEntity::pEventHandler(&CGrunt::H0x01570006_Fire_06), DEBUGSTRING("CGrunt::H0x01570006_Fire_06")},
 {0x01570007, -1, CEntity::pEventHandler(&CGrunt::H0x01570007_Fire_07), DEBUGSTRING("CGrunt::H0x01570007_Fire_07")},
 {0x01570008, -1, CEntity::pEventHandler(&CGrunt::H0x01570008_Fire_08), DEBUGSTRING("CGrunt::H0x01570008_Fire_08")},
 {0x01570009, -1, CEntity::pEventHandler(&CGrunt::
#line 227 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
SoldierAttack),DEBUGSTRING("CGrunt::SoldierAttack")},
 {0x0157000a, -1, CEntity::pEventHandler(&CGrunt::H0x0157000a_SoldierAttack_01), DEBUGSTRING("CGrunt::H0x0157000a_SoldierAttack_01")},
 {0x0157000b, -1, CEntity::pEventHandler(&CGrunt::H0x0157000b_SoldierAttack_02), DEBUGSTRING("CGrunt::H0x0157000b_SoldierAttack_02")},
 {0x0157000c, -1, CEntity::pEventHandler(&CGrunt::H0x0157000c_SoldierAttack_03), DEBUGSTRING("CGrunt::H0x0157000c_SoldierAttack_03")},
 {0x0157000d, -1, CEntity::pEventHandler(&CGrunt::H0x0157000d_SoldierAttack_04), DEBUGSTRING("CGrunt::H0x0157000d_SoldierAttack_04")},
 {0x0157000e, -1, CEntity::pEventHandler(&CGrunt::H0x0157000e_SoldierAttack_05), DEBUGSTRING("CGrunt::H0x0157000e_SoldierAttack_05")},
 {0x0157000f, -1, CEntity::pEventHandler(&CGrunt::H0x0157000f_SoldierAttack_06), DEBUGSTRING("CGrunt::H0x0157000f_SoldierAttack_06")},
 {0x01570010, -1, CEntity::pEventHandler(&CGrunt::
#line 246 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
CommanderAttack),DEBUGSTRING("CGrunt::CommanderAttack")},
 {0x01570011, -1, CEntity::pEventHandler(&CGrunt::H0x01570011_CommanderAttack_01), DEBUGSTRING("CGrunt::H0x01570011_CommanderAttack_01")},
 {0x01570012, -1, CEntity::pEventHandler(&CGrunt::H0x01570012_CommanderAttack_02), DEBUGSTRING("CGrunt::H0x01570012_CommanderAttack_02")},
 {0x01570013, -1, CEntity::pEventHandler(&CGrunt::H0x01570013_CommanderAttack_03), DEBUGSTRING("CGrunt::H0x01570013_CommanderAttack_03")},
 {0x01570014, -1, CEntity::pEventHandler(&CGrunt::H0x01570014_CommanderAttack_04), DEBUGSTRING("CGrunt::H0x01570014_CommanderAttack_04")},
 {0x01570015, -1, CEntity::pEventHandler(&CGrunt::H0x01570015_CommanderAttack_05), DEBUGSTRING("CGrunt::H0x01570015_CommanderAttack_05")},
 {0x01570016, -1, CEntity::pEventHandler(&CGrunt::H0x01570016_CommanderAttack_06), DEBUGSTRING("CGrunt::H0x01570016_CommanderAttack_06")},
 {0x01570017, -1, CEntity::pEventHandler(&CGrunt::H0x01570017_CommanderAttack_07), DEBUGSTRING("CGrunt::H0x01570017_CommanderAttack_07")},
 {0x01570018, -1, CEntity::pEventHandler(&CGrunt::H0x01570018_CommanderAttack_08), DEBUGSTRING("CGrunt::H0x01570018_CommanderAttack_08")},
 {0x01570019, -1, CEntity::pEventHandler(&CGrunt::H0x01570019_CommanderAttack_09), DEBUGSTRING("CGrunt::H0x01570019_CommanderAttack_09")},
 {0x0157001a, -1, CEntity::pEventHandler(&CGrunt::H0x0157001a_CommanderAttack_10), DEBUGSTRING("CGrunt::H0x0157001a_CommanderAttack_10")},
 {0x0157001b, -1, CEntity::pEventHandler(&CGrunt::H0x0157001b_CommanderAttack_11), DEBUGSTRING("CGrunt::H0x0157001b_CommanderAttack_11")},
 {0x0157001c, -1, CEntity::pEventHandler(&CGrunt::H0x0157001c_CommanderAttack_12), DEBUGSTRING("CGrunt::H0x0157001c_CommanderAttack_12")},
 {1, -1, CEntity::pEventHandler(&CGrunt::
#line 289 "C:/MyMod/Sources/EntitiesMP/Grunt.es"
Main),DEBUGSTRING("CGrunt::Main")},
};
#define CGrunt_handlersct ARRAYCOUNT(CGrunt_handlers)

CEntity *CGrunt_New(void) { return new CGrunt; };
void CGrunt_OnInitClass(void) {};
void CGrunt_OnEndClass(void) {};
void CGrunt_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CGrunt_OnWorldEnd(CWorld *pwo) {};
void CGrunt_OnWorldInit(CWorld *pwo) {};
void CGrunt_OnWorldTick(CWorld *pwo) {};
void CGrunt_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CGrunt, CEnemyBase, "Grunt", "Thumbnails\\Grunt.tbn", 0x00000157);
DECLARE_CTFILENAME(_fnmCGrunt_tbn, "Thumbnails\\Grunt.tbn");
