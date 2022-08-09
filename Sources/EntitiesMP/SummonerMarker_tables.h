/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CSummonerMarker

CEntityProperty CSummonerMarker_properties[] = {
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x0000015e<<8)+1, offsetof(CSummonerMarker, m_strName), "Name", 'N', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x0000015e<<8)+2, offsetof(CSummonerMarker, m_strDescription), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_RANGE, NULL, (0x0000015e<<8)+3, offsetof(CSummonerMarker, m_fMarkerRange), "Marker Range", 'M', 0x7F0000FFUL, 0),
};
#define CSummonerMarker_propertiesct ARRAYCOUNT(CSummonerMarker_properties)

CEntityComponent CSummonerMarker_components[] = {
#define MODEL_SUMMONERMARKER ((0x0000015e<<8)+1)
 CEntityComponent(ECT_MODEL, MODEL_SUMMONERMARKER, "EFNM" "Models\\Editor\\EnemyMarker.mdl"),
#define TEXTURE_SUMMONERMARKER ((0x0000015e<<8)+2)
 CEntityComponent(ECT_TEXTURE, TEXTURE_SUMMONERMARKER, "EFNM" "Models\\Editor\\BoundingBox.tex"),
};
#define CSummonerMarker_componentsct ARRAYCOUNT(CSummonerMarker_components)

CEventHandlerEntry CSummonerMarker_handlers[] = {
 {1, -1, CEntity::pEventHandler(&CSummonerMarker::
#line 48 "C:/MyMod/Sources/EntitiesMP/SummonerMarker.es"
Main),DEBUGSTRING("CSummonerMarker::Main")},
};
#define CSummonerMarker_handlersct ARRAYCOUNT(CSummonerMarker_handlers)

CEntity *CSummonerMarker_New(void) { return new CSummonerMarker; };
void CSummonerMarker_OnInitClass(void) {};
void CSummonerMarker_OnEndClass(void) {};
void CSummonerMarker_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CSummonerMarker_OnWorldEnd(CWorld *pwo) {};
void CSummonerMarker_OnWorldInit(CWorld *pwo) {};
void CSummonerMarker_OnWorldTick(CWorld *pwo) {};
void CSummonerMarker_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CSummonerMarker, CMarker, "SummonerMarker", "Thumbnails\\EnemyMarker.tbn", 0x0000015e);
DECLARE_CTFILENAME(_fnmCSummonerMarker_tbn, "Thumbnails\\EnemyMarker.tbn");
