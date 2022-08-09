/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 2 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"

#include "StdH.h"
#include "EntitiesMP/WorldSettingsController.h"
#include "EntitiesMP/BackgroundViewer.h"

#include <EntitiesMP/CreditsHolder.h>
#include <EntitiesMP/CreditsHolder_tables.h>
#line 8 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"


#define CTA_LEFT 1
#define CTA_RIGHT 2
#define CTA_CENTER 3

class CCreditEntry {
public:
  CTString strTitle;
  CTString strName;
  CTString strQuote;
  INDEX    iAlign;
  INDEX    iX, iY;
  FLOAT    fRelSize;
  FLOAT    fWait;
};
  
static CStaticStackArray<CCreditEntry> _acceEntries;
#define BLANK_TIME 1.0f

void CCreditsHolder::SetDefaultProperties(void) {
  m_strName = "Credits holder";
  m_strDescription = "";
  m_fnmMessage = CTString("");
  m_fMyTimer = 0.0f;
  m_fMyTimerLast = 0.0f;
  m_iTotalEntries = 0;
  m_bEnd = FALSE ;
  m_penEndCreditsTrigger = NULL;
  m_bDataError = FALSE ;
  CRationalEntity::SetDefaultProperties();
}
  
#line 57 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
const CTString & CCreditsHolder::GetDescription(void)const {
#line 58 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
((CTString &) m_strDescription ) . PrintF  ("%s" , m_fnmMessage  . FileName  ());
#line 59 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return m_strDescription ;
#line 60 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
   CCreditsHolder::CCreditsHolder(void) 
#line 63 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 64 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
bDataLoaded  = FALSE ;
#line 65 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
  
#line 67 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
BOOL CCreditsHolder::ReloadData(void) 
#line 68 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 69 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
m_bDataError  = FALSE ;
#line 70 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(! Credits_On  (m_fnmMessage ))
#line 71 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 72 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
Credits_Off  ();
#line 73 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return FALSE ;
#line 74 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 75 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(! LoadFont  ())
#line 76 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 77 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
Credits_Off  ();
#line 78 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return FALSE ;
#line 79 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 80 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return TRUE ;
#line 81 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
  
#line 84 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
BOOL CCreditsHolder::LoadOneFile(const CTFileName & fnm) 
#line 85 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 86 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(fnm  == ""){return FALSE ;}
#line 88 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
try 
#line 89 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 91 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CTFileStream  strm ;
#line 92 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . Open_t  (fnm );
#line 94 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CTString strCheck ;
#line 95 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . GetLine_t  (strCheck );
#line 96 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strCheck  . TrimSpacesRight  ();
#line 97 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(strCheck  != "CREDITS"){return FALSE ;};
#line 99 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
m_iTotalEntries  = 0;
#line 100 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
while(! strm  . AtEOF  ())
#line 101 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 102 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CTString strLine ;
#line 103 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CTString strArgs ;
#line 104 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CTString strTmp ;
#line 105 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CCreditEntry  cceEntry ;
#line 107 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . GetLine_t  (strLine );
#line 108 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . GetLine_t  (strLine );
#line 109 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strLine  . TrimSpacesRight  ();
#line 110 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(strLine  == "END"){
#line 111 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . Close  ();
#line 112 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return TRUE ;
#line 113 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}else if(strLine  != "ENTRY"){
#line 114 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  . PopAll  ();
#line 115 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return FALSE ;
#line 116 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 117 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . GetLine_t  (strArgs );
#line 118 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strArgs  . ScanF  ("%d,%d" , & cceEntry  . iX  , & cceEntry  . iY );
#line 119 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . GetLine_t  (strArgs );
#line 120 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strArgs  . ScanF  ("%f" , & cceEntry  . fRelSize );
#line 121 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . GetLine_t  (strArgs );
#line 122 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strArgs  . TrimSpacesRight  ();
#line 123 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(strArgs  == "CENTER"){cceEntry  . iAlign  = CTA_CENTER ;}
#line 124 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
else if(strArgs  == "RIGHT"){cceEntry  . iAlign  = CTA_RIGHT ;}
#line 125 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
else if(TRUE ){cceEntry  . iAlign  = CTA_LEFT ;}
#line 126 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . GetLine_t  (cceEntry  . strTitle );
#line 127 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . GetLine_t  (cceEntry  . strName );
#line 128 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . GetLine_t  (cceEntry  . strQuote );
#line 129 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . GetLine_t  (strArgs );
#line 130 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strArgs  . ScanF  ("%f" , & cceEntry  . fWait );
#line 131 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  . Push  () = cceEntry ;
#line 132 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
m_iTotalEntries  ++;
#line 133 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 135 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
strm  . Close  ();
#line 136 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return TRUE ;
#line 137 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 138 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
catch  (char  * strError )
#line 139 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 140 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CPrintF  ("%s\n" , strError );
#line 141 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return FALSE ;
#line 142 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 143 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
  
#line 145 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
BOOL CCreditsHolder::LoadFont() 
#line 146 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 147 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
try 
#line 148 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 149 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_fdMedium  . Load_t  (CTFILENAME  ("Fonts\\Display3-normal.fnt"));
#line 150 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 151 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
catch  (char  * strError )
#line 152 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 153 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CPrintF  ("%s\n" , strError );
#line 154 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return FALSE ;
#line 155 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 156 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return TRUE ;
#line 157 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
  
#line 160 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
BOOL CCreditsHolder::Credits_On(CTFileName fnCreditsText) 
#line 161 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 162 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  . PopAll  ();
#line 163 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return LoadOneFile  (fnCreditsText );
#line 164 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
  
#line 167 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
void CCreditsHolder::Credits_Off(void) 
#line 168 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 169 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  . Clear  ();
#line 170 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
  
#line 173 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT CCreditsHolder::Credits_Render(CCreditsHolder * penThis,CDrawPort * pdp) 
#line 174 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 175 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(m_bDataError ){return 0;}
#line 177 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(! bDataLoaded ){
#line 178 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(! ReloadData  ()){
#line 179 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
m_bDataError  = TRUE ;
#line 180 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return 0;
#line 181 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 182 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
bDataLoaded  = TRUE ;
#line 183 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return 1;
#line 184 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 186 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
PIX  pixW  = 0;
#line 187 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
PIX  pixH  = 0;
#line 189 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CTString strEmpty ;
#line 191 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fTime  = Lerp  (m_fMyTimerLast  , m_fMyTimer  , _pTimer  -> GetLerpFactor  ());
#line 192 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CDrawPort  * pdpCurr  = pdp ;
#line 194 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> Unlock  ();
#line 195 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdpCurr  -> Lock  ();
#line 197 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pixW  = pdpCurr  -> GetWidth  ();
#line 198 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pixH  = pdpCurr  -> GetHeight  ();
#line 200 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fResFactor  = pixH  / 480.0f;
#line 202 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdpCurr  -> SetFont  (_pfdDisplayFont );
#line 205 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
BOOL bOver  = FALSE ;
#line 207 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fPassed  = 0.0f;
#line 208 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fStart  = 0.0f;
#line 209 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
INDEX iNextItem  = 0;
#line 211 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
for(INDEX i  = 0;i  < _acceEntries  . Count  ();i  ++){
#line 212 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(_acceEntries  [ i  ] . fWait  != 0.0f){
#line 213 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
fPassed  += _acceEntries  [ i  ] . fWait ;
#line 214 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(fPassed  > fTime ){
#line 215 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
break ;
#line 216 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}else {
#line 217 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
iNextItem  = i  + 1;
#line 218 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
fStart  = fPassed ;
#line 219 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(iNextItem  >= _acceEntries  . Count  ())
#line 220 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 221 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
bOver  = TRUE ;
#line 222 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 223 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 224 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 225 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 227 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(! bOver ){
#line 228 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
while(TRUE ){
#line 229 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
BOOL bLast  = FALSE ;
#line 230 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(_acceEntries  [ iNextItem  ] . fWait  != 0.0f){bLast  = TRUE ;};
#line 231 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fFade  = CalculateRatio  (fTime  , fStart  , fPassed  - BLANK_TIME  , 0.2f , 0.2f);
#line 232 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetFont  (_pfdDisplayFont );
#line 233 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetTextAspect  (1.0f);
#line 235 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fTextSize01  = 1.2f * _acceEntries  [ iNextItem  ] . fRelSize ;
#line 236 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fTextSize02  = 2.0f * _acceEntries  [ iNextItem  ] . fRelSize ;
#line 237 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fTextSize03  = 0.75f * _acceEntries  [ iNextItem  ] . fRelSize ;
#line 238 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fTextHeight  = 15.0f;
#line 239 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fSpacing01  = 1.2f;
#line 240 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fSpacing02  = 1.1f;
#line 242 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(_acceEntries  [ iNextItem  ] . iAlign  == CTA_CENTER ){
#line 243 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fYY  = _acceEntries  [ iNextItem  ] . iY  * fResFactor ;
#line 245 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetTextScaling  (fTextSize01  * fResFactor );
#line 246 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> PutTextC  (_acceEntries  [ iNextItem  ] . strTitle  , 
#line 247 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  [ iNextItem  ] . iX  * fResFactor  , fYY  , 
#line 248 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
C_WHITE  | (INDEX) (fFade  * 255));
#line 249 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
fYY  += fTextSize01  * fResFactor  * fTextHeight  * fSpacing01 ;
#line 251 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetFont  (& _fdMedium );
#line 252 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetTextScaling  (fTextSize02  * fResFactor );
#line 253 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> PutTextC  (_acceEntries  [ iNextItem  ] . strName  , 
#line 254 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  [ iNextItem  ] . iX  * fResFactor  , fYY  , 
#line 255 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
C_WHITE  | (INDEX) (fFade  * 255));
#line 256 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
fYY  += fTextSize02  * fResFactor  * fTextHeight  * fSpacing02 ;
#line 258 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetTextScaling  (fTextSize03  * fResFactor );
#line 259 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> PutTextC  (_acceEntries  [ iNextItem  ] . strQuote  , 
#line 260 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  [ iNextItem  ] . iX  * fResFactor  , fYY  , 
#line 261 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
C_WHITE  | (INDEX) (fFade  * 255));
#line 263 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}else if(_acceEntries  [ iNextItem  ] . iAlign  == CTA_RIGHT ){
#line 264 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fYY  = _acceEntries  [ iNextItem  ] . iY  * fResFactor ;
#line 266 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetTextScaling  (fTextSize01  * fResFactor );
#line 267 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> PutTextR  (_acceEntries  [ iNextItem  ] . strTitle  , 
#line 268 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  [ iNextItem  ] . iX  * fResFactor  , fYY  , 
#line 269 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
C_WHITE  | (INDEX) (fFade  * 255));
#line 270 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
fYY  += fTextSize01  * fResFactor  * fTextHeight  * fSpacing01 ;
#line 272 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetTextScaling  (fTextSize02  * fResFactor );
#line 273 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> PutTextR  (_acceEntries  [ iNextItem  ] . strName  , 
#line 274 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  [ iNextItem  ] . iX  * fResFactor  , fYY  , 
#line 275 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
C_WHITE  | (INDEX) (fFade  * 255));
#line 276 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
fYY  += fTextSize02  * fResFactor  * fTextHeight  * fSpacing02 ;
#line 278 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetTextScaling  (fTextSize03  * fResFactor );
#line 279 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> PutTextR  (_acceEntries  [ iNextItem  ] . strQuote  , 
#line 280 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  [ iNextItem  ] . iX  * fResFactor  , fYY  , 
#line 281 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
C_WHITE  | (INDEX) (fFade  * 255));
#line 283 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}else if(TRUE ){
#line 284 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
FLOAT fYY  = _acceEntries  [ iNextItem  ] . iY  * fResFactor ;
#line 286 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetTextScaling  (fTextSize01  * fResFactor );
#line 287 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> PutText  (_acceEntries  [ iNextItem  ] . strTitle  , 
#line 288 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  [ iNextItem  ] . iX  * fResFactor  , fYY  , 
#line 289 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
C_WHITE  | (INDEX) (fFade  * 255));
#line 290 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
fYY  += fTextSize01  * fResFactor  * fTextHeight  * fSpacing01 ;
#line 292 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetTextScaling  (fTextSize02  * fResFactor );
#line 293 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> PutText  (_acceEntries  [ iNextItem  ] . strName  , 
#line 294 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  [ iNextItem  ] . iX  * fResFactor  , fYY  , 
#line 295 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
C_WHITE  | (INDEX) (fFade  * 255));
#line 296 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
fYY  += fTextSize02  * fResFactor  * fTextHeight  * fSpacing02 ;
#line 298 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> SetTextScaling  (fTextSize03  * fResFactor );
#line 299 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> PutText  (_acceEntries  [ iNextItem  ] . strQuote  , 
#line 300 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
_acceEntries  [ iNextItem  ] . iX  * fResFactor  , fYY  , 
#line 301 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
C_WHITE  | (INDEX) (fFade  * 255));
#line 303 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 305 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
iNextItem  ++;
#line 306 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(iNextItem  >= _acceEntries  . Count  () || bLast ){
#line 307 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
bOver  = TRUE ;
#line 308 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
break ;
#line 309 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 310 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 311 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 313 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdpCurr  -> Unlock  ();
#line 314 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pdp  -> Lock  ();
#line 316 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(bOver ){
#line 317 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return 0;
#line 318 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}else {
#line 319 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return 1;
#line 320 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 321 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
BOOL CCreditsHolder::
#line 325 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
WaitScrollingToEnd(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CCreditsHolder_WaitScrollingToEnd
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CCreditsHolder::WaitScrollingToEnd expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 327 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
Jump(STATE_CURRENT,0x00f00003, FALSE, EInternal());return TRUE;}BOOL CCreditsHolder::H0x00f00003_WaitScrollingToEnd_03(const CEntityEvent &__eeInput)
#line 328 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f00003
if(!(! m_bEnd )){ Jump(STATE_CURRENT,0x00f00004, FALSE, EInternal());return TRUE;}
#line 329 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
SetTimerAfter(_pTimer  -> TickQuantum );
Jump(STATE_CURRENT, 0x00f00001, FALSE, EBegin());return TRUE;}BOOL CCreditsHolder::H0x00f00001_WaitScrollingToEnd_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f00001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00f00002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CCreditsHolder::H0x00f00002_WaitScrollingToEnd_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f00002
;
#line 330 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
m_fMyTimerLast  = m_fMyTimer ;
#line 331 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
m_fMyTimer  += _pTimer  -> TickQuantum  / _pNetwork  -> GetRealTimeFactor  ();Jump(STATE_CURRENT,0x00f00003, FALSE, EInternal());return TRUE;
#line 332 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}BOOL CCreditsHolder::H0x00f00004_WaitScrollingToEnd_04(const CEntityEvent &__eeInput) {
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f00004

#line 333 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
Return(STATE_CURRENT,EStop  ());
#line 333 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CCreditsHolder::
#line 336 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CCreditsHolder_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CCreditsHolder::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 338 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
InitAsEditorModel  ();
#line 339 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 340 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 343 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
SetModel  (MODEL_HOLDER );
#line 344 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
SetModelMainTexture  (TEXTURE_HOLDER );
#line 346 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
SetTimerAfter(0.05f);
Jump(STATE_CURRENT, 0x00f00005, FALSE, EBegin());return TRUE;}BOOL CCreditsHolder::H0x00f00005_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f00005
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00f00006, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CCreditsHolder::H0x00f00006_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f00006
;
#line 348 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(! Credits_On  (m_fnmMessage ))
#line 349 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 350 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CPrintF  ("Error loading credits file '%s'!\n" , m_fnmMessage );
#line 351 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
Credits_Off  ();
#line 352 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
Return(STATE_CURRENT,EVoid());
#line 352 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return TRUE;
#line 353 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 354 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
m_bDataError  = FALSE ;
#line 356 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00f00007, FALSE, EBegin());return TRUE;}BOOL CCreditsHolder::H0x00f00007_Main_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f00007
switch(__eeInput.ee_slEvent){case(EVENTCODE_EStart):
#line 358 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{const EStart&eStart= (EStart&)__eeInput;

#line 359 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 360 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(pwsc  != NULL )
#line 361 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 362 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
m_fMyTimer  = 0;
#line 363 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
m_fMyTimerLast  = 0;
#line 364 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
ECredits  ecr ;
#line 365 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
ecr  . bStart  = TRUE ;
#line 366 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
ecr  . penSender  = this ;
#line 367 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pwsc  -> SendEvent  (ecr );
#line 368 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 369 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
Call(STATE_CURRENT, STATE_CCreditsHolder_WaitScrollingToEnd, TRUE, EVoid());return TRUE;
#line 370 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStop):
#line 372 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{const EStop&eStop= (EStop&)__eeInput;

#line 373 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
CWorldSettingsController  * pwsc  = GetWSC  (this );
#line 374 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(pwsc  != NULL )
#line 375 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
{
#line 376 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
ECredits  ecr ;
#line 377 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
ecr  . bStart  = FALSE ;
#line 378 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
ecr  . penSender  = this ;
#line 379 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
pwsc  -> SendEvent  (ecr );
#line 380 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 381 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
UnsetTimer();Jump(STATE_CURRENT,0x00f00008, FALSE, EInternal());return TRUE;
#line 382 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}ASSERT(FALSE);break;default: return FALSE; break;
#line 383 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}return TRUE;}BOOL CCreditsHolder::H0x00f00008_Main_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00f00008

#line 384 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
Credits_Off  ();
#line 385 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
if(m_penEndCreditsTrigger ){
#line 386 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
SendToTarget  (m_penEndCreditsTrigger  , EET_TRIGGER  , FixupCausedToPlayer  (this  , NULL  , FALSE ));
#line 387 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
}
#line 388 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
Return(STATE_CURRENT,EVoid());
#line 388 "C:/MyMod/Sources/EntitiesMP/CreditsHolder.es"
return TRUE; ASSERT(FALSE); return TRUE;};