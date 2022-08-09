/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

EP_ENUMBEG(CustomShadingType)
  EP_ENUMVALUE(CST_NONE, "None"),
  EP_ENUMVALUE(CST_FULL_CUSTOMIZED, "Full customized"),
  EP_ENUMVALUE(CST_CONSTANT_SHADING, "Constant shading"),
EP_ENUMEND(CustomShadingType);

EP_ENUMBEG(ShadowType)
  EP_ENUMVALUE(ST_NONE, "None"),
  EP_ENUMVALUE(ST_CLUSTER, "Cluster shadows"),
  EP_ENUMVALUE(ST_POLYGONAL, "Polygonal"),
EP_ENUMEND(ShadowType);

#define ENTITYCLASS CModelHolder2

CEntityProperty CModelHolder2_properties[] = {
 CEntityProperty(CEntityProperty::EPT_FILENAME, NULL, (0x000000d2<<8)+1, offsetof(CModelHolder2, m_fnModel), "Model", 'M', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FILENAME, NULL, (0x000000d2<<8)+2, offsetof(CModelHolder2, m_fnTexture), "Texture", 'T', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FILENAME, NULL, (0x000000d2<<8)+22, offsetof(CModelHolder2, m_fnReflection), "Reflection", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FILENAME, NULL, (0x000000d2<<8)+23, offsetof(CModelHolder2, m_fnSpecular), "Specular", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FILENAME, NULL, (0x000000d2<<8)+24, offsetof(CModelHolder2, m_fnBump), "Bump", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+3, offsetof(CModelHolder2, m_fStretchAll), "StretchAll", 'S', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+4, offsetof(CModelHolder2, m_fStretchX), "StretchX", 'X', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+5, offsetof(CModelHolder2, m_fStretchY), "StretchY", 'Y', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+6, offsetof(CModelHolder2, m_fStretchZ), "StretchZ", 'Z', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x000000d2<<8)+7, offsetof(CModelHolder2, m_strName), "Name", 'N', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x000000d2<<8)+12, offsetof(CModelHolder2, m_strDescription), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x000000d2<<8)+8, offsetof(CModelHolder2, m_bColliding), "Colliding", 'L', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ANIMATION, NULL, (0x000000d2<<8)+9, offsetof(CModelHolder2, m_iModelAnimation), "Model animation", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ANIMATION, NULL, (0x000000d2<<8)+10, offsetof(CModelHolder2, m_iTextureAnimation), "Texture animation", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENUM, &ShadowType_enum, (0x000000d2<<8)+11, offsetof(CModelHolder2, m_stClusterShadows), "Shadows", 'W', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x000000d2<<8)+13, offsetof(CModelHolder2, m_bBackground), "Background", 'B', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x000000d2<<8)+21, offsetof(CModelHolder2, m_bTargetable), "Targetable", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ENUM, &CustomShadingType_enum, (0x000000d2<<8)+14, offsetof(CModelHolder2, m_cstCustomShading), "Custom shading", 'H', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ANGLE3D, NULL, (0x000000d2<<8)+15, offsetof(CModelHolder2, m_aShadingDirection), "Light direction", 'D', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x000000d2<<8)+16, offsetof(CModelHolder2, m_colLight), "Light color", 'O', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x000000d2<<8)+17, offsetof(CModelHolder2, m_colAmbient), "Ambient color", 'A', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FILENAME, NULL, (0x000000d2<<8)+18, offsetof(CModelHolder2, m_fnmLightAnimation), "Light animation file", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ANIMATION, NULL, (0x000000d2<<8)+19, offsetof(CModelHolder2, m_iLightAnimation), "Light animation", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ANIMOBJECT, NULL, (0x000000d2<<8)+20, offsetof(CModelHolder2, m_aoLightAnimation), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x000000d2<<8)+25, offsetof(CModelHolder2, m_bAttachments), "Attachments", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x000000d2<<8)+26, offsetof(CModelHolder2, m_bActive), "Active", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+31, offsetof(CModelHolder2, m_fMipAdd), "Mip Add", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+32, offsetof(CModelHolder2, m_fMipMul), "Mip Mul", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+33, offsetof(CModelHolder2, m_fMipFadeDist), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+34, offsetof(CModelHolder2, m_fMipFadeLen), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_RANGE, NULL, (0x000000d2<<8)+35, offsetof(CModelHolder2, m_rMipFadeDistMetric), "Mip Fade Dist (Metric)", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+36, offsetof(CModelHolder2, m_fMipFadeLenMetric), "Mip Fade Len (Metric)", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x000000d2<<8)+50, offsetof(CModelHolder2, m_bRandomStretch), "Apply RND stretch", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+52, offsetof(CModelHolder2, m_fStretchRndX), "Stretch RND X (%)", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+51, offsetof(CModelHolder2, m_fStretchRndY), "Stretch RND Y (%)", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+53, offsetof(CModelHolder2, m_fStretchRndZ), "Stretch RND Z (%)", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+54, offsetof(CModelHolder2, m_fStretchRndAll), "Stretch RND All (%)", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT3D, NULL, (0x000000d2<<8)+55, offsetof(CModelHolder2, m_fStretchRandom), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x000000d2<<8)+60, offsetof(CModelHolder2, m_penDestruction), "Destruction", 'Q', C_BLACK  | 0x20, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT3D, NULL, (0x000000d2<<8)+61, offsetof(CModelHolder2, m_vDamage), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+62, offsetof(CModelHolder2, m_tmLastDamage), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x000000d2<<8)+63, offsetof(CModelHolder2, m_penDestroyTarget), "Destruction Target", 0, C_WHITE  | 0xFF, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x000000d2<<8)+64, offsetof(CModelHolder2, m_penLastDamager), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+65, offsetof(CModelHolder2, m_tmSpraySpawned), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+66, offsetof(CModelHolder2, m_fSprayDamage), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x000000d2<<8)+67, offsetof(CModelHolder2, m_penSpray), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+68, offsetof(CModelHolder2, m_fMaxDamageAmmount), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+70, offsetof(CModelHolder2, m_fClassificationStretch), "Classification stretch", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_COLOR, NULL, (0x000000d2<<8)+80, offsetof(CModelHolder2, m_colBurning), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ENUM, &DamageType_enum, (0x000000d2<<8)+90, offsetof(CModelHolder2, m_dmtLastDamageType), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+91, offsetof(CModelHolder2, m_fChainSawCutDamage), "Chain saw cut dammage", 'C', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x000000d2<<8)+93, offsetof(CModelHolder2, m_iFirstRandomAnimation), "First random animation", 'R', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x000000d2<<8)+100, offsetof(CModelHolder2, m_fMaxTessellationLevel), "Max tessellation level", 0, 0x7F0000FFUL, 0),
};
#define CModelHolder2_propertiesct ARRAYCOUNT(CModelHolder2_properties)

CEntityComponent CModelHolder2_components[] = {
#define CLASS_BLOOD_SPRAY ((0x000000d2<<8)+1)
 CEntityComponent(ECT_CLASS, CLASS_BLOOD_SPRAY, "EFNM" "Classes\\BloodSpray.ecl"),
};
#define CModelHolder2_componentsct ARRAYCOUNT(CModelHolder2_components)

CEventHandlerEntry CModelHolder2_handlers[] = {
 {0x00d20000, -1, CEntity::pEventHandler(&CModelHolder2::
#line 642 "C:/MyMod/Sources/EntitiesMP/ModelHolder2.es"
Die),DEBUGSTRING("CModelHolder2::Die")},
 {1, -1, CEntity::pEventHandler(&CModelHolder2::
#line 707 "C:/MyMod/Sources/EntitiesMP/ModelHolder2.es"
Main),DEBUGSTRING("CModelHolder2::Main")},
 {0x00d20001, -1, CEntity::pEventHandler(&CModelHolder2::H0x00d20001_Main_01), DEBUGSTRING("CModelHolder2::H0x00d20001_Main_01")},
 {0x00d20002, -1, CEntity::pEventHandler(&CModelHolder2::H0x00d20002_Main_02), DEBUGSTRING("CModelHolder2::H0x00d20002_Main_02")},
};
#define CModelHolder2_handlersct ARRAYCOUNT(CModelHolder2_handlers)

CEntity *CModelHolder2_New(void) { return new CModelHolder2; };
void CModelHolder2_OnInitClass(void) {};
void CModelHolder2_OnEndClass(void) {};
void CModelHolder2_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CModelHolder2_OnWorldEnd(CWorld *pwo) {};
void CModelHolder2_OnWorldInit(CWorld *pwo) {};
void CModelHolder2_OnWorldTick(CWorld *pwo) {};
void CModelHolder2_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CModelHolder2, CRationalEntity, "ModelHolder2", "Thumbnails\\ModelHolder.tbn", 0x000000d2);
DECLARE_CTFILENAME(_fnmCModelHolder2_tbn, "Thumbnails\\ModelHolder.tbn");
