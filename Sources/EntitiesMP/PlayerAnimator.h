/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_PlayerAnimator_INCLUDED
#define _EntitiesMP_PlayerAnimator_INCLUDED 1
#include <EntitiesMP/Player.h>
#include <EntitiesMP/PlayerWeapons.h>
#define EVENTCODE_EAnimatorInit 0x01960000
class DECL_DLL EAnimatorInit : public CEntityEvent {
public:
EAnimatorInit();
CEntityEvent *MakeCopy(void);
CEntityPointer penPlayer;
};
DECL_DLL inline void ClearToDefault(EAnimatorInit &e) { e = EAnimatorInit(); } ;
extern "C" DECL_DLL CDLLEntityClass CPlayerAnimator_DLLClass;
class DECL_DLL  CPlayerAnimator : public CRationalEntity {
public:
virtual CEntity *GetPredictionPair(void) { return m_penPrediction; };
virtual void SetPredictionPair(CEntity *penPair) { m_penPrediction = penPair; };
   virtual void SetDefaultProperties(void);
  CEntityPointer m_penPlayer;
  BOOL m_bReference;
  FLOAT m_fLastActionTime;
  INDEX m_iContent;
  BOOL m_bWaitJumpAnim;
  BOOL m_bCrouch;
  BOOL m_iCrouchDownWait;
  BOOL m_iRiseUpWait;
  BOOL m_bChangeWeapon;
  BOOL m_bSwim;
  INDEX m_iFlare;
  INDEX m_iSecondFlare;
  BOOL m_bAttacking;
  FLOAT m_tmAttackingDue;
  FLOAT m_tmFlareAdded;
  BOOL m_bDisableAnimating;
  FLOAT3D m_vLastPlayerPosition;
  FLOAT m_fEyesYLastOffset;
  FLOAT m_fEyesYOffset;
  FLOAT m_fEyesYSpeed;
  FLOAT m_fWeaponYLastOffset;
  FLOAT m_fWeaponYOffset;
  FLOAT m_fWeaponYSpeed;
  BOOL m_bMoving;
  FLOAT m_fMoveLastBanking;
  FLOAT m_fMoveBanking;
  BOOL m_iMovingSide;
  BOOL m_bSidestepBankingLeft;
  BOOL m_bSidestepBankingRight;
  FLOAT m_fSidestepLastBanking;
  FLOAT m_fSidestepBanking;
  INDEX m_iWeaponLast;
  FLOAT m_fBodyAnimTime;
  CEntityPointer m_penPrediction;
CModelObject * pmoModel;
   
#line 438 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void Read_t(CTStream * istr);
   
#line 443 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void Precache(void);
   
#line 449 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
CPlayer * GetPlayer(void);
   
#line 453 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
CModelObject * GetBody(void);
   
#line 461 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
CModelObject * GetBodyRen(void);
   
#line 471 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void SetComponents(CModelObject * mo,ULONG ulIDModel,ULONG ulIDTexture,
#line 472 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
ULONG ulIDReflectionTexture,ULONG ulIDSpecularTexture,ULONG ulIDBumpTexture);
   
#line 499 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void AddAttachmentModel(CModelObject * mo,INDEX iAttachment,ULONG ulIDModel,ULONG ulIDTexture,
#line 500 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
ULONG ulIDReflectionTexture,ULONG ulIDSpecularTexture,ULONG ulIDBumpTexture);
   
#line 506 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void AddWeaponAttachment(INDEX iAttachment,ULONG ulIDModel,ULONG ulIDTexture,
#line 507 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
ULONG ulIDReflectionTexture,ULONG ulIDSpecularTexture,ULONG ulIDBumpTexture);
   
#line 513 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void SetAttachment(INDEX iAttachment);
   
#line 518 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void SyncWeapon(void);
   
#line 553 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void SetWeapon(void);
   
#line 759 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void SetItem(CModelObject * pmo);
   
#line 776 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void SetBodyAnimation(INDEX iAnimation,ULONG ulFlags);
   
#line 792 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void Initialize(void);
   
#line 834 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void StoreLast(void);
   
#line 845 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void AnimateBanking(void);
   
#line 902 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void AnimateSoftEyes(void);
   
#line 965 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void ChangeView(CPlacement3D & pl);
   
#line 1010 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void BodyAndHeadOrientation(CPlacement3D & plView);
   
#line 1033 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void AnimatePlayer(void);
   
#line 1187 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void Crouch(void);
   
#line 1199 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void Rise(void);
   
#line 1211 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void Fall(void);
   
#line 1222 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void Swim(void);
   
#line 1233 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void Stand(void);
   
#line 1244 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void FireAnimation(INDEX iAnim,ULONG ulFlags);
   
#line 1272 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void FireAnimationOff(void);
   
#line 1282 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void BodyAnimationTemplate(INDEX iNone,INDEX iColt,INDEX iShotgun,INDEX iMinigun,ULONG ulFlags);
   
#line 1307 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void BodyWalkAnimation();
   
#line 1314 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void BodyStillAnimation();
   
#line 1321 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void BodyPushAnimation();
   
#line 1330 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void RemoveWeapon(void);
   
#line 1397 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void BodyPullAnimation();
   
#line 1418 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void BodyPullItemAnimation();
   
#line 1432 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void BodyPickItemAnimation();
   
#line 1446 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void BodyRemoveItem();
   
#line 1458 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void OnPreRender(void);
   
#line 1476 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void ShowFlare(INDEX iAttachWeapon,INDEX iAttachObject,INDEX iAttachFlare);
   
#line 1488 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void HideFlare(INDEX iAttachWeapon,INDEX iAttachObject,INDEX iAttachFlare);
   
#line 1499 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
void ControlFlareAttachment(void);
#define  STATE_CPlayerAnimator_ReminderAction 0x01960001
  BOOL 
#line 1578 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
ReminderAction(const CEntityEvent &__eeInput);
#define  STATE_CPlayerAnimator_Main 1
  BOOL 
#line 1590 "C:/MyMod/Sources/EntitiesMP/PlayerAnimator.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x01960002_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x01960003_Main_02(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_PlayerAnimator_INCLUDED
