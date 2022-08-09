/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

EP_ENUMBEG(SkaCustomShadingType)
  EP_ENUMVALUE(SCST_NONE, "Automatic shading"),
  EP_ENUMVALUE(SCST_CONSTANT_SHADING, "Constant shading"),
  EP_ENUMVALUE(SCST_FULL_CUSTOMIZED, "Customized shading"),
EP_ENUMEND(SkaCustomShadingType);

EP_ENUMBEG(SkaShadowType)
  EP_ENUMVALUE(SST_NONE, "None"),
  EP_ENUMVALUE(SST_CLUSTER, "Cluster shadows"),
  EP_ENUMVALUE(SST_POLYGONAL, "Polygonal"),
EP_ENUMEND(SkaShadowType);

#define ENTITYCLASS CModelHolder3

CEntityProperty CModelHolder3_properties[] = {
 CEntityProperty(CEntityProperty::EPT_FILENAME, NULL, (0x000000f2<<8)+1, offsetof(CModelHolder3, m_fnModel), "Model file (.smc)", 'M', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000f2<<8)+3, offsetof(CModelHolder3, m_fStretchAll), "StretchAll", 'S', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ANGLE3D, NULL, (0x000000f2<<8)+4, offsetof(CModelHolder3, m_vStretchXYZ), "StretchXYZ", 'X', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x000000f2<<8)+7, offsetof(CModelHolder3, m_strName), "Name", 'N', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x000000f2<<8)+12, offsetof(CModelHolder3, m_strDescription), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x000000f2<<8)+8, offsetof(CModelHolder3, m_bColliding), "Collision", 'L', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENUM, &SkaShadowType_enum, (0x000000f2<<8)+11, offsetof(CModelHolder3, m_stClusterShadows), "Shadows", 'W', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x000000f2<<8)+13, offsetof(CModelHolder3, m_bBackground), "Background", 'B', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x000000f2<<8)+21, offsetof(CModelHolder3, m_bTargetable), "Targetable", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENUM, &SkaCustomShadingType_enum, (0x000000f2<<8)+14, offsetof(CModelHolder3, m_cstCustomShading), "Shading mode", 'H', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ANGLE3D, NULL, (0x000000f2<<8)+15, offsetof(CModelHolder3, m_aShadingDirection), "Shade. Light direction", 'D', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x000000f2<<8)+16, offsetof(CModelHolder3, m_colLight), "Shade. Light color", 'O', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x000000f2<<8)+17, offsetof(CModelHolder3, m_colAmbient), "Shade. Ambient color", 'A', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x000000f2<<8)+26, offsetof(CModelHolder3, m_bActive), "Active", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000f2<<8)+70, offsetof(CModelHolder3, m_fClassificationStretch), "Classification stretch", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000f2<<8)+100, offsetof(CModelHolder3, m_fMaxTessellationLevel), "Max tessellation level", 0, 0x7F0000FFUL, 0),
};
#define CModelHolder3_propertiesct ARRAYCOUNT(CModelHolder3_properties)

CEntityComponent CModelHolder3_components[] = {
  CEntityComponent()
};
#define CModelHolder3_componentsct 0


CEventHandlerEntry CModelHolder3_handlers[] = {
 {0x00f20000, -1, CEntity::pEventHandler(&CModelHolder3::
#line 603 "C:/MyMod/Sources/EntitiesMP/ModelHolder3.es"
Die),DEBUGSTRING("CModelHolder3::Die")},
 {1, -1, CEntity::pEventHandler(&CModelHolder3::
#line 660 "C:/MyMod/Sources/EntitiesMP/ModelHolder3.es"
Main),DEBUGSTRING("CModelHolder3::Main")},
 {0x00f20001, -1, CEntity::pEventHandler(&CModelHolder3::H0x00f20001_Main_01), DEBUGSTRING("CModelHolder3::H0x00f20001_Main_01")},
 {0x00f20002, -1, CEntity::pEventHandler(&CModelHolder3::H0x00f20002_Main_02), DEBUGSTRING("CModelHolder3::H0x00f20002_Main_02")},
};
#define CModelHolder3_handlersct ARRAYCOUNT(CModelHolder3_handlers)

CEntity *CModelHolder3_New(void) { return new CModelHolder3; };
void CModelHolder3_OnInitClass(void) {};
void CModelHolder3_OnEndClass(void) {};
void CModelHolder3_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CModelHolder3_OnWorldEnd(CWorld *pwo) {};
void CModelHolder3_OnWorldInit(CWorld *pwo) {};
void CModelHolder3_OnWorldTick(CWorld *pwo) {};
void CModelHolder3_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CModelHolder3, CRationalEntity, "ModelHolder3", "Thumbnails\\ModelHolder3.tbn", 0x000000f2);
DECLARE_CTFILENAME(_fnmCModelHolder3_tbn, "Thumbnails\\ModelHolder3.tbn");
