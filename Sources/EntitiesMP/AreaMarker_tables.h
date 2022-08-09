/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CAreaMarker

CEntityProperty CAreaMarker_properties[] = {
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x000000ca<<8)+1, offsetof(CAreaMarker, m_strName), "Name", 'N', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x000000ca<<8)+2, offsetof(CAreaMarker, m_strDescription), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOATAABBOX3D, NULL, (0x000000ca<<8)+3, offsetof(CAreaMarker, m_boxArea), "Area box", 'B', 0x7F0000FFUL, 0),
};
#define CAreaMarker_propertiesct ARRAYCOUNT(CAreaMarker_properties)

CEntityComponent CAreaMarker_components[] = {
#define MODEL_AREAMARKER ((0x000000ca<<8)+1)
 CEntityComponent(ECT_MODEL, MODEL_AREAMARKER, "EFNM" "Models\\Editor\\Axis.mdl"),
#define TEXTURE_AREAMARKER ((0x000000ca<<8)+2)
 CEntityComponent(ECT_TEXTURE, TEXTURE_AREAMARKER, "EFNM" "Models\\Editor\\Vector.tex"),
};
#define CAreaMarker_componentsct ARRAYCOUNT(CAreaMarker_components)

CEventHandlerEntry CAreaMarker_handlers[] = {
 {1, -1, CEntity::pEventHandler(&CAreaMarker::
#line 29 "C:/MyMod/Sources/EntitiesMP/AreaMarker.es"
Main),DEBUGSTRING("CAreaMarker::Main")},
};
#define CAreaMarker_handlersct ARRAYCOUNT(CAreaMarker_handlers)

CEntity *CAreaMarker_New(void) { return new CAreaMarker; };
void CAreaMarker_OnInitClass(void) {};
void CAreaMarker_OnEndClass(void) {};
void CAreaMarker_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CAreaMarker_OnWorldEnd(CWorld *pwo) {};
void CAreaMarker_OnWorldInit(CWorld *pwo) {};
void CAreaMarker_OnWorldTick(CWorld *pwo) {};
void CAreaMarker_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CAreaMarker, CEntity, "AreaMarker", "Thumbnails\\AreaMarker.tbn", 0x000000ca);
DECLARE_CTFILENAME(_fnmCAreaMarker_tbn, "Thumbnails\\AreaMarker.tbn");
