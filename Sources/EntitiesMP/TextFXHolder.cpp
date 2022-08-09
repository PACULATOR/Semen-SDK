/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"

#include "StdH.h"
#include "EntitiesMP/WorldSettingsController.h"
#include "EntitiesMP/BackgroundViewer.h"

#include <EntitiesMP/TextFXHolder.h>
#include <EntitiesMP/TextFXHolder_tables.h>
#line 8 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"

static CStaticStackArray<CTString> _astrLines;
static CTFileName _fnLastLoaded;

void CTextFXHolder::SetDefaultProperties(void) {
  m_strName = "Text FX holder";
  m_strDescription = "";
  m_fnmMessage = CTString("");
  m_tmFadeInStart = 1e6;
  m_tmFadeOutStart = 1e6;
  m_tmFadeInLen = 0.5f;
  m_tmFadeOutLen = 0.5f;
  m_tmAutoFadeOut = -1.0f;
  m_bDataError = FALSE ;
  CRationalEntity::SetDefaultProperties();
}
  
#line 39 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
const CTString & CTextFXHolder::GetDescription(void)const {
#line 40 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
((CTString &) m_strDescription ) . PrintF  ("%s" , m_fnmMessage  . FileName  ());
#line 41 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return m_strDescription ;
#line 42 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
   CTextFXHolder::CTextFXHolder(void) 
#line 45 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 46 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
bDataLoaded  = FALSE ;
#line 47 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
  
#line 49 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
BOOL CTextFXHolder::ReloadData(void) 
#line 50 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 51 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
m_bDataError  = FALSE ;
#line 52 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(! Text_On  (m_fnmMessage ))
#line 53 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 54 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
Text_Off  ();
#line 55 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return FALSE ;
#line 56 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 57 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return TRUE ;
#line 58 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
  
#line 60 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
BOOL CTextFXHolder::LoadOneFile(const CTFileName & fnm) 
#line 61 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 62 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(fnm  == ""){return FALSE ;}
#line 63 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
try 
#line 64 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 66 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
CTFileStream  strm ;
#line 67 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
strm  . Open_t  (fnm );
#line 70 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
INDEX ctLines  = 0;
#line 71 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
while(! strm  . AtEOF  ())
#line 72 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 73 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
CTString strLine ;
#line 74 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
strm  . GetLine_t  (strLine );
#line 75 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
ctLines  ++;
#line 76 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 77 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
strm  . SetPos_t  (0);
#line 80 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
CTString * astr  = _astrLines  . Push  (ctLines );
#line 82 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
for(INDEX iLine  = 0;iLine  < ctLines  && ! strm  . AtEOF  ();iLine  ++)
#line 83 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 84 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
strm  . GetLine_t  (astr  [ iLine  ]);
#line 85 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 86 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
strm  . Close  ();
#line 87 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return TRUE ;
#line 88 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 89 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
catch  (char  * strError )
#line 90 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 91 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
CPrintF  ("%s\n" , strError );
#line 92 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return FALSE ;
#line 93 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 94 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
_fnLastLoaded  = fnm ;
#line 95 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
  
#line 98 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
BOOL CTextFXHolder::Text_On(CTFileName fnText) 
#line 99 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 100 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
_astrLines  . PopAll  ();
#line 101 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return LoadOneFile  (fnText );
#line 102 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
  
#line 105 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
void CTextFXHolder::Text_Off(void) 
#line 106 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 107 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
_astrLines  . Clear  ();
#line 108 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
  
#line 111 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
FLOAT CTextFXHolder::TextFX_Render(CTextFXHolder * penThis,CDrawPort * pdp) 
#line 112 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 113 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(m_bDataError ){return 0;}
#line 115 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(! bDataLoaded ){
#line 116 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(! ReloadData  ()){
#line 117 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
m_bDataError  = TRUE ;
#line 118 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return 0;
#line 119 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 120 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
bDataLoaded  = TRUE ;
#line 121 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return 1;
#line 122 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 124 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
FLOAT fNow  = _pTimer  -> CurrentTick  ();
#line 125 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(fNow  < m_tmFadeInStart ){return 0;}
#line 126 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(fNow  > m_tmFadeOutStart  + m_tmFadeOutLen ){return 0;}
#line 128 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
PIX  pixW  = 0;
#line 129 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
PIX  pixH  = 0;
#line 130 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
PIX  pixJ  = 0;
#line 131 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
FLOAT fResolutionScaling ;
#line 132 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
PIX  pixLineHeight ;
#line 133 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
CTString strEmpty ;
#line 135 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
CDrawPort  * pdpCurr  = pdp ;
#line 136 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> Unlock  ();
#line 137 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pdpCurr  -> Lock  ();
#line 139 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pixW  = pdpCurr  -> GetWidth  ();
#line 140 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pixH  = pdpCurr  -> GetHeight  ();
#line 141 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
fResolutionScaling  = (FLOAT) pixH  / 360.0f;
#line 142 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pdpCurr  -> SetFont  (_pfdDisplayFont );
#line 143 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pixLineHeight  = floor  (20 * fResolutionScaling );
#line 145 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
INDEX ctMaxLinesOnScreen  = pixH  / pixLineHeight ;
#line 146 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
INDEX ctLines  = ClampUp  (_astrLines  . Count  () , ctMaxLinesOnScreen );
#line 148 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pixJ  = PIX  (pixH  / 2 - ctLines  / 2.0f * pixLineHeight );
#line 149 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
for(INDEX iLine  = 0;iLine  < ctLines ;iLine  ++)
#line 150 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 151 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
CTString * pstr  = & _astrLines  [ iLine  ];
#line 152 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> SetFont  (_pfdDisplayFont );
#line 153 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> SetTextScaling  (fResolutionScaling );
#line 154 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> SetTextAspect  (1.0f);
#line 155 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
FLOAT fRatio  = 1.0f;
#line 156 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(fNow  > m_tmFadeOutStart )
#line 157 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 158 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
fRatio  = CalculateRatio  (fNow  , m_tmFadeOutStart  , m_tmFadeOutStart  + m_tmFadeOutLen  , 0 , 1);
#line 159 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 160 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(fNow  < m_tmFadeInStart  + m_tmFadeInLen )
#line 161 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 162 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
fRatio  = CalculateRatio  (fNow  , m_tmFadeInStart  , m_tmFadeInStart  + m_tmFadeInLen  , 1 , 0);
#line 163 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 164 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
UBYTE  ubA  = ClampUp  (UBYTE  (fRatio  * 255.0f) , UBYTE  (255));
#line 165 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> PutTextC  (* pstr  , pixW  / 2 , pixJ  , C_WHITE  | ubA );
#line 166 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pixJ  += pixLineHeight ;
#line 167 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 169 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pdpCurr  -> Unlock  ();
#line 170 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pdp  -> Lock  ();
#line 172 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return 1;
#line 173 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
BOOL CTextFXHolder::
#line 178 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
WaitAndFadeOut(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CTextFXHolder_WaitAndFadeOut
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CTextFXHolder::WaitAndFadeOut expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 180 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
SetTimerAfter(m_tmAutoFadeOut );
Jump(STATE_CURRENT, 0x00ef0001, FALSE, EBegin());return TRUE;}BOOL CTextFXHolder::H0x00ef0001_WaitAndFadeOut_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00ef0002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CTextFXHolder::H0x00ef0002_WaitAndFadeOut_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0002
;
#line 181 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
Jump(STATE_CURRENT, STATE_CTextFXHolder_ApplyFadeOut, TRUE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};BOOL CTextFXHolder::
#line 184 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
ApplyFadeOut(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CTextFXHolder_ApplyFadeOut
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CTextFXHolder::ApplyFadeOut expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 186 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
m_tmFadeOutStart  = _pTimer  -> CurrentTick  ();
#line 187 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 188 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(!(pwsc  != NULL )){ Jump(STATE_CURRENT,0x00ef0006, FALSE, EInternal());return TRUE;}
#line 190 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
SetTimerAfter(m_tmFadeOutLen );
Jump(STATE_CURRENT, 0x00ef0004, FALSE, EBegin());return TRUE;}BOOL CTextFXHolder::H0x00ef0004_ApplyFadeOut_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0004
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00ef0005, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CTextFXHolder::H0x00ef0005_ApplyFadeOut_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0005
;
#line 191 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 192 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
ETextFX  etfx ;
#line 193 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
etfx  . bStart  = FALSE ;
#line 194 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
etfx  . penSender  = this ;
#line 195 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pwsc  -> SendEvent  (etfx );Jump(STATE_CURRENT,0x00ef0006, FALSE, EInternal());return TRUE;}BOOL CTextFXHolder::H0x00ef0006_ApplyFadeOut_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0006

#line 197 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
Return(STATE_CURRENT,EReturn  ());
#line 197 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CTextFXHolder::
#line 200 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CTextFXHolder_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CTextFXHolder::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 202 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
InitAsEditorModel  ();
#line 203 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 204 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 207 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
SetModel  (MODEL_MARKER );
#line 208 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 210 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
SetTimerAfter(0.05f);
Jump(STATE_CURRENT, 0x00ef0007, FALSE, EBegin());return TRUE;}BOOL CTextFXHolder::H0x00ef0007_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0007
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00ef0008, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CTextFXHolder::H0x00ef0008_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0008
;
#line 212 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(! Text_On  (m_fnmMessage ))
#line 213 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 214 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
Text_Off  ();
#line 215 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
Return(STATE_CURRENT,EVoid());
#line 215 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return TRUE;
#line 216 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 217 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
m_bDataError  = FALSE ;
#line 219 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00ef0009, FALSE, EBegin());return TRUE;}BOOL CTextFXHolder::H0x00ef0009_Main_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef0009
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):
#line 221 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{const EBegin&e= (EBegin&)__eeInput;

#line 222 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return TRUE;
#line 223 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStart):
#line 225 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{const EStart&eStart= (EStart&)__eeInput;

#line 226 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 227 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(pwsc  != NULL )
#line 228 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 229 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
m_tmFadeInStart  = _pTimer  -> CurrentTick  ();
#line 230 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
ETextFX  etfx ;
#line 231 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
etfx  . bStart  = TRUE ;
#line 232 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
etfx  . penSender  = this ;
#line 233 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
pwsc  -> SendEvent  (etfx );
#line 234 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
if(m_tmAutoFadeOut  != - 1)
#line 235 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{
#line 236 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
Call(STATE_CURRENT, STATE_CTextFXHolder_WaitAndFadeOut, TRUE, EVoid());return TRUE;
#line 237 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 238 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}
#line 239 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return TRUE;
#line 240 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStop):
#line 242 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{const EStop&eStop= (EStop&)__eeInput;

#line 243 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
Call(STATE_CURRENT, STATE_CTextFXHolder_ApplyFadeOut, TRUE, EVoid());return TRUE;
#line 244 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return TRUE;
#line 245 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EReturn):
#line 247 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
{const EReturn&e= (EReturn&)__eeInput;

#line 248 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return TRUE;
#line 249 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 250 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
}return TRUE;}BOOL CTextFXHolder::H0x00ef000a_Main_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00ef000a

#line 251 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
Text_Off  ();
#line 252 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
Return(STATE_CURRENT,EVoid());
#line 252 "C:/MyMod/Sources/EntitiesMP/TextFXHolder.es"
return TRUE; ASSERT(FALSE); return TRUE;};