/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CStormController

CEntityProperty CStormController_properties[] = {
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+1, offsetof(CStormController, m_penwsc), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x0000025e<<8)+2, offsetof(CStormController, m_strName), "Name", 'N', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025e<<8)+3, offsetof(CStormController, m_fNextLightningDelay), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x0000025e<<8)+4, offsetof(CStormController, m_bStormOn), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025e<<8)+5, offsetof(CStormController, m_fNextLightningStrike), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+10, offsetof(CStormController, m_penLightning00), "Lightning 1", 'T', C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+11, offsetof(CStormController, m_penLightning01), "Lightning 2", 'Y', C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+12, offsetof(CStormController, m_penLightning02), "Lightning 3", 'U', C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+13, offsetof(CStormController, m_penLightning03), "Lightning 4", 'I', C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+14, offsetof(CStormController, m_penLightning04), "Lightning 5", 'O', C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+15, offsetof(CStormController, m_penLightning05), "Lightning 6", 'P', C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+16, offsetof(CStormController, m_penLightning06), "Lightning 7", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+17, offsetof(CStormController, m_penLightning07), "Lightning 8", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+18, offsetof(CStormController, m_penLightning08), "Lightning 9", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+19, offsetof(CStormController, m_penLightning09), "Lightning 10", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+20, offsetof(CStormController, m_penLightning10), "Lightning 11", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+21, offsetof(CStormController, m_penLightning11), "Lightning 12", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+22, offsetof(CStormController, m_penLightning12), "Lightning 13", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+23, offsetof(CStormController, m_penLightning13), "Lightning 14", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+24, offsetof(CStormController, m_penLightning14), "Lightning 15", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+25, offsetof(CStormController, m_penLightning15), "Lightning 16", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+26, offsetof(CStormController, m_penLightning16), "Lightning 17", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+27, offsetof(CStormController, m_penLightning17), "Lightning 18", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+28, offsetof(CStormController, m_penLightning18), "Lightning 19", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x0000025e<<8)+29, offsetof(CStormController, m_penLightning19), "Lightning 20", 0, C_MAGENTA  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025e<<8)+40, offsetof(CStormController, m_tmStormAppearTime), "Storm appear time", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025e<<8)+41, offsetof(CStormController, m_tmStormDisappearTime), "Storm disappear time", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025e<<8)+42, offsetof(CStormController, m_fFirstLightningDelay), "First lightning delay", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025e<<8)+43, offsetof(CStormController, m_fMaxLightningPeriod), "Max lightning period", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025e<<8)+44, offsetof(CStormController, m_fMinLightningPeriod), "Min lightning period", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x0000025e<<8)+45, offsetof(CStormController, m_fMaxStormPowerTime), "Max storm power time", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x0000025e<<8)+50, offsetof(CStormController, m_colBlendStart), "Color blend start", 'B', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x0000025e<<8)+51, offsetof(CStormController, m_colBlendStop), "Color blend stop", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x0000025e<<8)+52, offsetof(CStormController, m_colShadeStart), "Color shade start", 'S', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x0000025e<<8)+53, offsetof(CStormController, m_colShadeStop), "Color shade stop", 0, 0x7F0000FFUL, 0),
};
#define CStormController_propertiesct ARRAYCOUNT(CStormController_properties)

CEntityComponent CStormController_components[] = {
#define MODEL_STORM_CONTROLLER ((0x0000025e<<8)+1)
 CEntityComponent(ECT_MODEL, MODEL_STORM_CONTROLLER, "EFNM" "Models\\Editor\\StormController.mdl"),
#define TEXTURE_STORM_CONTROLLER ((0x0000025e<<8)+2)
 CEntityComponent(ECT_TEXTURE, TEXTURE_STORM_CONTROLLER, "EFNM" "Models\\Editor\\StormController.tex"),
};
#define CStormController_componentsct ARRAYCOUNT(CStormController_components)

CEventHandlerEntry CStormController_handlers[] = {
 {0x025e0000, -1, CEntity::pEventHandler(&CStormController::
#line 95 "C:/MyMod/Sources/EntitiesMP/StormController.es"
Storm),DEBUGSTRING("CStormController::Storm")},
 {0x025e0001, -1, CEntity::pEventHandler(&CStormController::H0x025e0001_Storm_01), DEBUGSTRING("CStormController::H0x025e0001_Storm_01")},
 {0x025e0002, -1, CEntity::pEventHandler(&CStormController::H0x025e0002_Storm_02), DEBUGSTRING("CStormController::H0x025e0002_Storm_02")},
 {0x025e0003, -1, CEntity::pEventHandler(&CStormController::
#line 103 "C:/MyMod/Sources/EntitiesMP/StormController.es"
StormInternal),DEBUGSTRING("CStormController::StormInternal")},
 {0x025e0004, -1, CEntity::pEventHandler(&CStormController::H0x025e0004_StormInternal_01), DEBUGSTRING("CStormController::H0x025e0004_StormInternal_01")},
 {0x025e0005, -1, CEntity::pEventHandler(&CStormController::H0x025e0005_StormInternal_02), DEBUGSTRING("CStormController::H0x025e0005_StormInternal_02")},
 {0x025e0006, -1, CEntity::pEventHandler(&CStormController::H0x025e0006_StormInternal_03), DEBUGSTRING("CStormController::H0x025e0006_StormInternal_03")},
 {0x025e0007, -1, CEntity::pEventHandler(&CStormController::H0x025e0007_StormInternal_04), DEBUGSTRING("CStormController::H0x025e0007_StormInternal_04")},
 {0x025e0008, -1, CEntity::pEventHandler(&CStormController::H0x025e0008_StormInternal_05), DEBUGSTRING("CStormController::H0x025e0008_StormInternal_05")},
 {0x025e0009, -1, CEntity::pEventHandler(&CStormController::H0x025e0009_StormInternal_06), DEBUGSTRING("CStormController::H0x025e0009_StormInternal_06")},
 {0x025e000a, -1, CEntity::pEventHandler(&CStormController::H0x025e000a_StormInternal_07), DEBUGSTRING("CStormController::H0x025e000a_StormInternal_07")},
 {0x025e000b, -1, CEntity::pEventHandler(&CStormController::H0x025e000b_StormInternal_08), DEBUGSTRING("CStormController::H0x025e000b_StormInternal_08")},
 {1, -1, CEntity::pEventHandler(&CStormController::
#line 169 "C:/MyMod/Sources/EntitiesMP/StormController.es"
Main),DEBUGSTRING("CStormController::Main")},
 {0x025e000c, -1, CEntity::pEventHandler(&CStormController::H0x025e000c_Main_01), DEBUGSTRING("CStormController::H0x025e000c_Main_01")},
 {0x025e000d, -1, CEntity::pEventHandler(&CStormController::H0x025e000d_Main_02), DEBUGSTRING("CStormController::H0x025e000d_Main_02")},
 {0x025e000e, -1, CEntity::pEventHandler(&CStormController::H0x025e000e_Main_03), DEBUGSTRING("CStormController::H0x025e000e_Main_03")},
 {0x025e000f, -1, CEntity::pEventHandler(&CStormController::H0x025e000f_Main_04), DEBUGSTRING("CStormController::H0x025e000f_Main_04")},
 {0x025e0010, -1, CEntity::pEventHandler(&CStormController::H0x025e0010_Main_05), DEBUGSTRING("CStormController::H0x025e0010_Main_05")},
 {0x025e0011, -1, CEntity::pEventHandler(&CStormController::H0x025e0011_Main_06), DEBUGSTRING("CStormController::H0x025e0011_Main_06")},
};
#define CStormController_handlersct ARRAYCOUNT(CStormController_handlers)

CEntity *CStormController_New(void) { return new CStormController; };
void CStormController_OnInitClass(void) {};
void CStormController_OnEndClass(void) {};
void CStormController_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CStormController_OnWorldEnd(CWorld *pwo) {};
void CStormController_OnWorldInit(CWorld *pwo) {};
void CStormController_OnWorldTick(CWorld *pwo) {};
void CStormController_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CStormController, CRationalEntity, "Storm controller", "Thumbnails\\StormController.tbn", 0x0000025e);
DECLARE_CTFILENAME(_fnmCStormController_tbn, "Thumbnails\\StormController.tbn");