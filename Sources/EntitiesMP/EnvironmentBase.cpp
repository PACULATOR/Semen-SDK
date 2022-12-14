/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"

#include "StdH.h"

#include <EntitiesMP/EnvironmentBase.h>
#include <EntitiesMP/EnvironmentBase_tables.h>
void CEnvironmentBase::SetDefaultProperties(void) {
  m_strName = "Base Environment";
  m_strDescription = "";
  m_fDistance = 100.0f;
  m_fStretch = 1.0f;
  m_penTarget = NULL;
  m_penWatcher = NULL;
  m_fWatcherFrequency = 2.0f;
  m_vDesiredPosition = FLOAT3D(0 , 0 , 0);
  m_fMoveSpeed = 2.0f;
  m_fRotateSpeed = 60.0f;
  m_fMoveFrequency = 0.5f;
  m_bUseWatcher = FALSE ;
  m_bFlying = FALSE ;
  m_fWaitTime = 0.0f;
  m_fnMdl = CTFILENAME("Models\\Editor\\Axis.mdl");
  m_fnTex = CTString("");
  m_iAnim = 0;
  m_fnAtt1Mdl = CTString("");
  m_fnAtt1Tex = CTString("");
  m_iAtt1Position = 0;
  m_iAtt1Anim = 0;
  m_fnAtt2Mdl = CTString("");
  m_fnAtt2Tex = CTString("");
  m_iAtt2Position = 1;
  m_iAtt2Anim = 0;
  m_fnAtt3Mdl = CTString("");
  m_fnAtt3Tex = CTString("");
  m_iAtt3Position = 1;
  m_iAtt3Anim = 0;
  CMovableEntity::SetDefaultProperties();
}
  
#line 56 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
BOOL CEnvironmentBase::MovesByTargetedRoute(CTString & strTargetProperty)const {
#line 57 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
strTargetProperty  = "Target";
#line 58 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return TRUE ;
#line 59 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 61 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
BOOL CEnvironmentBase::DropsMarker(CTFileName & fnmMarkerClass,CTString & strTargetProperty)const {
#line 62 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
fnmMarkerClass  = CTFILENAME  ("Classes\\EnvironmentMarker.ecl");
#line 63 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
strTargetProperty  = "Target";
#line 64 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return TRUE ;
#line 65 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 66 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
const CTString & CEnvironmentBase::GetDescription(void)const {
#line 67 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
((CTString &) m_strDescription ) . PrintF  ("-><none>");
#line 68 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(m_penTarget  != NULL ){
#line 69 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
((CTString &) m_strDescription ) . PrintF  ("->%s" , m_penTarget  -> GetName  ());
#line 70 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 71 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return m_strDescription ;
#line 72 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 74 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CAnimData * CEnvironmentBase::GetAnimData(SLONG slPropertyOffset) {
#line 75 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(slPropertyOffset  == offsetof  (CEnvironmentBase  , m_iAnim )){
#line 76 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return GetModelObject  () -> GetData  ();
#line 78 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}else if(slPropertyOffset  == offsetof  (CEnvironmentBase  , m_iAtt1Anim )){
#line 79 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CAttachmentModelObject  * pamo  = GetModelObject  () -> GetAttachmentModel  (m_iAtt1Position );
#line 80 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(pamo  != NULL ){return pamo  -> amo_moModelObject  . GetData  ();}
#line 81 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return CEntity  :: GetAnimData  (slPropertyOffset );
#line 83 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}else if(slPropertyOffset  == offsetof  (CEnvironmentBase  , m_iAtt2Anim )){
#line 84 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CAttachmentModelObject  * pamo  = GetModelObject  () -> GetAttachmentModel  (m_iAtt2Position );
#line 85 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(pamo  != NULL ){return pamo  -> amo_moModelObject  . GetData  ();}
#line 86 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return CEntity  :: GetAnimData  (slPropertyOffset );
#line 88 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}else if(slPropertyOffset  == offsetof  (CEnvironmentBase  , m_iAtt3Anim )){
#line 89 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CAttachmentModelObject  * pamo  = GetModelObject  () -> GetAttachmentModel  (m_iAtt3Position );
#line 90 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(pamo  != NULL ){return pamo  -> amo_moModelObject  . GetData  ();}
#line 91 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return CEntity  :: GetAnimData  (slPropertyOffset );
#line 93 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}else {
#line 94 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return CEntity  :: GetAnimData  (slPropertyOffset );
#line 95 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 96 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 104 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
BOOL CEnvironmentBase::NextMarker(void) {
#line 105 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(m_penTarget  == NULL ){
#line 106 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return FALSE ;
#line 107 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 110 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(m_penTarget  != NULL  && ! IsOfClass  (m_penTarget  , "Environment Marker")){
#line 111 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
WarningMessage  ("Target '%s' is not of Environment Marker class!" , m_penTarget  -> GetName  ());
#line 112 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_penTarget  = NULL ;
#line 113 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return FALSE ;
#line 114 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 117 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CMarker  * penTarget  = (CMarker  *) (CEntity  *) m_penTarget ;
#line 118 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CMarker  * penNextTarget  = (CMarker  *) (CEntity  *) penTarget  -> m_penTarget ;
#line 121 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(penNextTarget  == NULL ){
#line 122 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return FALSE ;
#line 123 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 126 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_penTarget  = penNextTarget ;
#line 128 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return TRUE ;
#line 129 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 132 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
void CEnvironmentBase::CalcRotation(ANGLE aWantedHeadingRelative,ANGLE3D & aRotation) {
#line 134 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
aWantedHeadingRelative  = NormalizeAngle  (aWantedHeadingRelative );
#line 137 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(aWantedHeadingRelative  < - m_fRotateSpeed  * m_fMoveFrequency ){
#line 139 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
aRotation  (1) = - m_fRotateSpeed ;
#line 141 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}else if(aWantedHeadingRelative  > m_fRotateSpeed  * m_fMoveFrequency ){
#line 143 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
aRotation  (1) = + m_fRotateSpeed ;
#line 145 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}else {
#line 146 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
aRotation  (1) = aWantedHeadingRelative  / m_fMoveFrequency ;
#line 147 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 148 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 151 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
void CEnvironmentBase::StopMoving(void) {
#line 152 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetDesiredRotation  (ANGLE3D (0 , 0 , 0));
#line 153 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetDesiredTranslation  (FLOAT3D (0.0f , 0.0f , 0.0f));
#line 154 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 157 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
void CEnvironmentBase::MoveToPosition(void) {
#line 158 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
FLOAT3D vDesiredAngle ;
#line 161 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
vDesiredAngle  = (m_vDesiredPosition  - GetPlacement  () . pl_PositionVector ) . Normalize  ();
#line 163 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
ANGLE3D aRotation  (0 , 0 , 0);
#line 164 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CalcRotation  (GetRelativeHeading  (vDesiredAngle ) , aRotation );
#line 167 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
FLOAT3D vTranslation  (0.0f , 0.0f , 0.0f);
#line 168 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
vTranslation  (3) = - m_fMoveSpeed ;
#line 171 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(m_bFlying ){
#line 172 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
vTranslation  (2) = Sgn  (vDesiredAngle  (2)) * m_fMoveSpeed  / 10;
#line 173 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 176 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetDesiredRotation  (aRotation );
#line 177 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetDesiredTranslation  (vTranslation );
#line 178 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 181 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
void CEnvironmentBase::CalcDestination() {
#line 183 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
FLOAT fR  = FRnd  () * ((CEnvironmentMarker  &) * m_penTarget ) . m_fMarkerRange ;
#line 184 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
FLOAT fA  = FRnd  () * 360.0f;
#line 185 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_vDesiredPosition  = m_penTarget  -> GetPlacement  () . pl_PositionVector  + 
#line 186 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
FLOAT3D (CosFast  (fA ) * fR  , 0 , SinFast  (fA ) * fR );
#line 187 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 190 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
void CEnvironmentBase::MarkerParameters() {
#line 191 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(m_penTarget  != NULL ){
#line 192 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CEnvironmentMarker  & em  = (CEnvironmentMarker  &) * m_penTarget ;
#line 193 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(em  . m_fMoveSpeed  > 0.0f){
#line 194 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_fMoveSpeed  = em  . m_fMoveSpeed ;
#line 195 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 196 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(em  . m_fRotateSpeed  > 0.0f){
#line 197 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_fRotateSpeed  = em  . m_fRotateSpeed ;
#line 198 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 199 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 200 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 207 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
void CEnvironmentBase::Initialize(void) {
#line 209 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
InitAsModel  ();
#line 210 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetPhysicsFlags  (EPF_MODEL_WALKING  & ~ (EPF_ORIENTEDBYGRAVITY  | EPF_TRANSLATEDBYGRAVITY ));
#line 211 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetCollisionFlags  (ECF_MODEL );
#line 214 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
GetModelObject  () -> mo_Stretch  = FLOAT3D (m_fStretch  , m_fStretch  , m_fStretch );
#line 217 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetModel  (m_fnMdl );
#line 218 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
GetModelObject  () -> PlayAnim  (m_iAnim  , AOF_LOOPING );
#line 219 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(m_fnTex  != CTString ("")){
#line 220 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
GetModelObject  () -> mo_toTexture  . SetData_t  (m_fnTex );
#line 221 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 223 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
GetModelObject  () -> RemoveAllAttachmentModels  ();
#line 225 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
AddAttachment  (m_iAtt1Position  , m_fnAtt1Mdl  , m_fnAtt1Tex );
#line 226 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CAttachmentModelObject  * pamo  = GetModelObject  () -> GetAttachmentModel  (m_iAtt1Position );
#line 227 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(pamo  != NULL ){
#line 228 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
pamo  -> amo_moModelObject  . StartAnim  (m_iAtt1Anim );
#line 229 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 231 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if((m_iAtt2Position  != m_iAtt1Position ) && (m_fnAtt1Mdl  != m_fnAtt2Mdl )){
#line 232 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
AddAttachment  (m_iAtt2Position  , m_fnAtt2Mdl  , m_fnAtt2Tex );
#line 233 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CAttachmentModelObject  * pamo  = GetModelObject  () -> GetAttachmentModel  (m_iAtt2Position );
#line 234 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(pamo  != NULL ){
#line 235 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
pamo  -> amo_moModelObject  . StartAnim  (m_iAtt2Anim );
#line 236 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 237 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 239 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if((m_iAtt3Position  != m_iAtt1Position ) && (m_fnAtt1Mdl  != m_fnAtt3Mdl ) && 
#line 240 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
(m_iAtt3Position  != m_iAtt2Position ) && (m_fnAtt2Mdl  != m_fnAtt3Mdl )){
#line 241 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
AddAttachment  (m_iAtt3Position  , m_fnAtt3Mdl  , m_fnAtt3Tex );
#line 242 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CAttachmentModelObject  * pamo  = GetModelObject  () -> GetAttachmentModel  (m_iAtt3Position );
#line 243 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(pamo  != NULL ){
#line 244 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
pamo  -> amo_moModelObject  . StartAnim  (m_iAtt3Anim );
#line 245 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 246 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 249 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(m_penTarget  != NULL  && ! IsOfClass  (m_penTarget  , "Environment Marker")){
#line 250 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
WarningMessage  ("Target '%s' is not of Environment Marker class!" , m_penTarget  -> GetName  ());
#line 251 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_penTarget  = NULL ;
#line 252 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 253 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 259 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
void CEnvironmentBase::InitializeWatcher(FLOAT fWaitTime) {
#line 261 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_penWatcher  = CreateEntity  (GetPlacement  () , CLASS_WATCHPLAYERS );
#line 262 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_penWatcher  -> Initialize  (EVoid  ());
#line 265 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CWatchPlayers  & pw  = (CWatchPlayers  &) * m_penWatcher ;
#line 266 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
pw  . m_penOwner  = this ;
#line 267 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
pw  . m_fWaitTime  = 2.0f;
#line 268 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
pw  . m_fDistance  = m_fDistance ;
#line 269 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
pw  . m_bRangeWatcher  = FALSE ;
#line 270 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
pw  . m_eetEventClose  = EET_ENVIRONMENTSTART ;
#line 271 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
pw  . m_eetEventFar  = EET_ENVIRONMENTSTOP ;
#line 272 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 280 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
void CEnvironmentBase::PlayDefaultAnim(void) {
#line 281 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
GetModelObject  () -> PlayAnim  (m_iAnim  , AOF_LOOPING  | AOF_NORESTART );
#line 282 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 285 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
void CEnvironmentBase::PlayMarkerAnimation(void) {
#line 286 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(m_penTarget  != NULL ){
#line 287 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
GetModelObject  () -> PlayAnim  (((CEnvironmentMarker  &) * m_penTarget ) . m_iAnim  , AOF_LOOPING  | AOF_NORESTART );
#line 288 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 289 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 292 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
void CEnvironmentBase::ChangeDefaultAnim(void) {
#line 293 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(m_penTarget  != NULL  && ((CEnvironmentMarker  &) * m_penTarget ) . m_bChangeDefaultAnim ){
#line 294 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_iAnim  = ((CEnvironmentMarker  &) * m_penTarget ) . m_iAnim ;
#line 295 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 296 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
  
#line 299 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
void CEnvironmentBase::WaitOnMarker(void) {
#line 300 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(m_penTarget  != NULL ){
#line 301 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CEnvironmentMarker  & em  = (CEnvironmentMarker  &) * m_penTarget ;
#line 302 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_fWaitTime  = em  . m_fWaitTime ;
#line 303 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_fWaitTime  += FRnd  () * em  . m_fRandomTime ;
#line 305 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(em  . m_bFixedAnimLength ){
#line 306 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_fWaitTime  = floor  (m_fWaitTime  + 0.5f);
#line 307 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 308 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 309 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
BOOL CEnvironmentBase::
#line 318 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
MoveToMarker(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnvironmentBase_MoveToMarker
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnvironmentBase::MoveToMarker expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 320 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(!(NextMarker  ())){ Jump(STATE_CURRENT,0x03840005, FALSE, EInternal());return TRUE;}
#line 322 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
CalcDestination  ();
#line 324 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
Jump(STATE_CURRENT,0x03840003, FALSE, EInternal());return TRUE;}BOOL CEnvironmentBase::H0x03840003_MoveToMarker_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840003
if(!((m_vDesiredPosition  - GetPlacement  () . pl_PositionVector ) . Length  () > 5.0f)){ Jump(STATE_CURRENT,0x03840004, FALSE, EInternal());return TRUE;}
#line 325 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetTimerAfter(m_fMoveFrequency );
Jump(STATE_CURRENT, 0x03840001, FALSE, EBegin());return TRUE;}BOOL CEnvironmentBase::H0x03840001_MoveToMarker_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840001
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 327 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
MoveToPosition  ();
#line 328 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return TRUE;
#line 329 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}ASSERT(FALSE);break;case(EVENTCODE_ETimer):{const ETimer&e= (ETimer&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x03840002, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 331 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}return TRUE;}BOOL CEnvironmentBase::H0x03840002_MoveToMarker_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840002
Jump(STATE_CURRENT,0x03840003, FALSE, EInternal());return TRUE;
#line 332 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}BOOL CEnvironmentBase::H0x03840004_MoveToMarker_04(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840004
Jump(STATE_CURRENT,0x03840005, FALSE, EInternal());return TRUE;}BOOL CEnvironmentBase::H0x03840005_MoveToMarker_05(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840005

#line 335 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
StopMoving  ();
#line 336 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
Return(STATE_CURRENT,EEnd  ());
#line 336 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CEnvironmentBase::
#line 345 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
Activate(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnvironmentBase_Activate
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnvironmentBase::Activate expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 346 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x03840007, FALSE, EBegin());return TRUE;}BOOL CEnvironmentBase::H0x03840007_Activate_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840007
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;
Call(STATE_CURRENT, STATE_CEnvironmentBase_DoAction, TRUE, EVoid());return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EEnvironmentStop):{const EEnvironmentStop&e= (EEnvironmentStop&)__eeInput;
Jump(STATE_CURRENT, STATE_CEnvironmentBase_Stop, TRUE, EVoid());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 349 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}return TRUE;}BOOL CEnvironmentBase::H0x03840008_Activate_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840008
 ASSERT(FALSE); return TRUE;};BOOL CEnvironmentBase::
#line 353 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
Stop(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnvironmentBase_Stop
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnvironmentBase::Stop expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 354 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
StopMoving  ();
#line 355 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x0384000a, FALSE, EBegin());return TRUE;}BOOL CEnvironmentBase::H0x0384000a_Stop_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0384000a
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;
return TRUE;}ASSERT(FALSE);break;case(EVENTCODE_EEnvironmentStart):{const EEnvironmentStart&e= (EEnvironmentStart&)__eeInput;
Jump(STATE_CURRENT, STATE_CEnvironmentBase_Activate, TRUE, EVoid());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 358 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}return TRUE;}BOOL CEnvironmentBase::H0x0384000b_Stop_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0384000b
 ASSERT(FALSE); return TRUE;};BOOL CEnvironmentBase::
#line 362 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
DoAction(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnvironmentBase_DoAction
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnvironmentBase::DoAction expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 363 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
Jump(STATE_CURRENT,0x03840015, FALSE, EInternal());return TRUE;}BOOL CEnvironmentBase::H0x03840015_DoAction_09(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840015
if(!(TRUE )){ Jump(STATE_CURRENT,0x03840016, FALSE, EInternal());return TRUE;}
#line 364 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
WaitOnMarker  ();
#line 365 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(!(m_fWaitTime  > 0.0f)){ Jump(STATE_CURRENT,0x0384000f, FALSE, EInternal());return TRUE;}
#line 366 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
PlayMarkerAnimation  ();
#line 367 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetTimerAfter(m_fWaitTime );
Jump(STATE_CURRENT, 0x0384000d, FALSE, EBegin());return TRUE;}BOOL CEnvironmentBase::H0x0384000d_DoAction_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0384000d
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0384000e, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CEnvironmentBase::H0x0384000e_DoAction_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0384000e
;Jump(STATE_CURRENT,0x0384000f, FALSE, EInternal());return TRUE;}BOOL CEnvironmentBase::H0x0384000f_DoAction_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0384000f

#line 369 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
ChangeDefaultAnim  ();
#line 371 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
MarkerParameters  ();
#line 372 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
PlayDefaultAnim  ();
#line 373 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
STATE_CEnvironmentBase_MoveToMarker, TRUE;
Jump(STATE_CURRENT, 0x03840010, FALSE, EBegin());return TRUE;}BOOL CEnvironmentBase::H0x03840010_DoAction_04(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840010
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CEnvironmentBase_MoveToMarker, TRUE, EVoid());return TRUE;case EVENTCODE_EEnd: Jump(STATE_CURRENT,0x03840011, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CEnvironmentBase::H0x03840011_DoAction_05(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840011
const EEnd&__e= (EEnd&)__eeInput;
;
#line 376 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(!(m_penTarget  == NULL  || ((CEnvironmentMarker  &) * m_penTarget ) . m_penTarget  == NULL )){ Jump(STATE_CURRENT,0x03840014, FALSE, EInternal());return TRUE;}
#line 377 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x03840012, FALSE, EBegin());return TRUE;}BOOL CEnvironmentBase::H0x03840012_DoAction_06(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840012
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x03840013, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CEnvironmentBase::H0x03840013_DoAction_07(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840013
;Jump(STATE_CURRENT,0x03840014, FALSE, EInternal());return TRUE;}BOOL CEnvironmentBase::H0x03840014_DoAction_08(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840014
Jump(STATE_CURRENT,0x03840015, FALSE, EInternal());return TRUE;
#line 379 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}BOOL CEnvironmentBase::H0x03840016_DoAction_10(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840016
 ASSERT(FALSE); return TRUE;};BOOL CEnvironmentBase::
#line 388 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
MainLoop(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnvironmentBase_MainLoop
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnvironmentBase::MainLoop expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 389 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
STATE_CEnvironmentBase_Stop, TRUE;
Jump(STATE_CURRENT, 0x03840018, FALSE, EBegin());return TRUE;}BOOL CEnvironmentBase::H0x03840018_MainLoop_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840018
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CEnvironmentBase_Stop, TRUE, EVoid());return TRUE;case EVENTCODE_EEnd: Jump(STATE_CURRENT,0x03840019, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CEnvironmentBase::H0x03840019_MainLoop_02(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x03840019
const EEnd&__e= (EEnd&)__eeInput;
;
#line 392 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_penWatcher  -> SendEvent  (EEnd  ());
#line 395 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
Destroy  ();
#line 397 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
Return(STATE_CURRENT,EVoid());
#line 397 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CEnvironmentBase::
#line 400 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CEnvironmentBase_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CEnvironmentBase::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 402 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
Initialize  ();
#line 405 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
SetTimerAfter(FRnd  () * 2.0f + 1.0f);
Jump(STATE_CURRENT, 0x0384001a, FALSE, EBegin());return TRUE;}BOOL CEnvironmentBase::H0x0384001a_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0384001a
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0384001b, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CEnvironmentBase::H0x0384001b_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0384001b
;
#line 408 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
if(m_bUseWatcher ){
#line 409 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
InitializeWatcher  (m_fWatcherFrequency );
#line 410 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
}
#line 412 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
m_strDescription  = "Environment base";
#line 414 "C:/MyMod/Sources/EntitiesMP/EnvironmentBase.es"
Jump(STATE_CURRENT, STATE_CEnvironmentBase_MainLoop, TRUE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};