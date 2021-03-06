//
//     Generated by classdumpios 1.0.1 (64 bit) (iOS port by DreamDevLost)(Debug version compiled Sep 26 2020 13:48:20).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import "LSApplicationWorkspaceObserverProtocol-Protocol.h"

@class CoreTelephonyClient, LSApplicationWorkspace, MCBackgroundActivityManager, NSString;
@protocol OS_dispatch_group, OS_dispatch_queue;

@interface MCProfileServiceServer : NSObject <LSApplicationWorkspaceObserverProtocol>
{
    _Bool _memberQueueNeedToRecomputeNagMetadata;	// 8 = 0x8
    _Bool _memberQueueHasMigrated;	// 9 = 0x9
    _Bool _memberQueueHasActivationRecordChangesPending;	// 10 = 0xa
    struct os_unfair_lock_s _checkInLock;	// 12 = 0xc
    int _mobileKeybagLockStateChangeNotificationToken;	// 16 = 0x10
    NSObject<OS_dispatch_queue> *_workerQueue;	// 24 = 0x18
    NSObject<OS_dispatch_group> *_workerGroup;	// 32 = 0x20
    MCBackgroundActivityManager *_workerQueueBackgroundActivityManager;	// 40 = 0x28
    unsigned long long _workerQueueLastCarrierProfileCheckTime;	// 48 = 0x30
    NSObject<OS_dispatch_queue> *_memberQueue;	// 56 = 0x38
    double _memberQueueIdleTimeInterval;	// 64 = 0x40
    NSObject<OS_dispatch_queue> *_clientRestrictionQueue;	// 72 = 0x48
    NSObject<OS_dispatch_queue> *_mailAccountsQueue;	// 80 = 0x50
    id _powerAssertionAssertedNotificationToken;	// 88 = 0x58
    id _powerAssertionDeassertedNotificationToken;	// 96 = 0x60
    LSApplicationWorkspace *_appWorkspace;	// 104 = 0x68
    CoreTelephonyClient *_coreTelephonyClient;	// 112 = 0x70
}

+ (id)_descriptionForServiceSubscriptionContext:(id)arg1;	// IMP=0x000000010000ba4c
+ (id)sharedServer;	// IMP=0x0000000100002904
- (void).cxx_destruct;	// IMP=0x00000001000112f8
@property(retain, nonatomic) CoreTelephonyClient *coreTelephonyClient; // @synthesize coreTelephonyClient=_coreTelephonyClient;
@property(retain, nonatomic) LSApplicationWorkspace *appWorkspace; // @synthesize appWorkspace=_appWorkspace;
@property(nonatomic) int mobileKeybagLockStateChangeNotificationToken; // @synthesize mobileKeybagLockStateChangeNotificationToken=_mobileKeybagLockStateChangeNotificationToken;
@property(retain, nonatomic) id powerAssertionDeassertedNotificationToken; // @synthesize powerAssertionDeassertedNotificationToken=_powerAssertionDeassertedNotificationToken;
@property(retain, nonatomic) id powerAssertionAssertedNotificationToken; // @synthesize powerAssertionAssertedNotificationToken=_powerAssertionAssertedNotificationToken;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *mailAccountsQueue; // @synthesize mailAccountsQueue=_mailAccountsQueue;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *clientRestrictionQueue; // @synthesize clientRestrictionQueue=_clientRestrictionQueue;
@property(nonatomic) _Bool memberQueueHasActivationRecordChangesPending; // @synthesize memberQueueHasActivationRecordChangesPending=_memberQueueHasActivationRecordChangesPending;
@property(nonatomic) _Bool memberQueueHasMigrated; // @synthesize memberQueueHasMigrated=_memberQueueHasMigrated;
@property(nonatomic) _Bool memberQueueNeedToRecomputeNagMetadata; // @synthesize memberQueueNeedToRecomputeNagMetadata=_memberQueueNeedToRecomputeNagMetadata;
@property(nonatomic) double memberQueueIdleTimeInterval; // @synthesize memberQueueIdleTimeInterval=_memberQueueIdleTimeInterval;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *memberQueue; // @synthesize memberQueue=_memberQueue;
@property(nonatomic) unsigned long long workerQueueLastCarrierProfileCheckTime; // @synthesize workerQueueLastCarrierProfileCheckTime=_workerQueueLastCarrierProfileCheckTime;
@property(retain, nonatomic) MCBackgroundActivityManager *workerQueueBackgroundActivityManager; // @synthesize workerQueueBackgroundActivityManager=_workerQueueBackgroundActivityManager;
@property(retain, nonatomic) NSObject<OS_dispatch_group> *workerGroup; // @synthesize workerGroup=_workerGroup;
@property(retain, nonatomic) NSObject<OS_dispatch_queue> *workerQueue; // @synthesize workerQueue=_workerQueue;
@property(nonatomic) struct os_unfair_lock_s checkInLock; // @synthesize checkInLock=_checkInLock;
- (void)debugRescheduleBackgroundActivity:(long long)arg1 startDate:(id)arg2 gracePeriod:(id)arg3 repeatingInterval:(id)arg4 completion:(CDUnknownBlockType)arg5;	// IMP=0x0000000100010fbc
- (void)managingOrganizationInformationWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x0000000100010a58
- (void)validateAppBundleIDs:(id)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x0000000100010918
- (void)setUserBookmarks:(id)arg1 senderPID:(int)arg2 sender:(id)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100010768
- (id)bookmarkDictsFromBookmarks:(id)arg1;	// IMP=0x00000001000105bc
- (id)bookmarksFromBookmarkDicts:(id)arg1;	// IMP=0x0000000100010408
- (void)setURLsFromUserBookmarkDictsAsSettings:(id)arg1 sender:(id)arg2;	// IMP=0x0000000100010100
- (void)storeActivationRecord:(id)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x000000010000fc88
- (void)createActivationLockBypassCodeWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010000fb70
- (void)cloudConfigurationStoreDetails:(id)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x000000010000fa00
- (_Bool)storeCloudConfigurationDetails:(id)arg1 outError:(id *)arg2;	// IMP=0x000000010000f97c
- (void)cloudConfigurationMachineInfoDataWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010000f830
- (void)fetchConfigurationWithCompletionBlock:(CDUnknownBlockType)arg1;	// IMP=0x000000010000f810
- (void)rereadManagedAppAttributesWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010000f688
- (void)resetAllSettingsToDefaultsIsUserInitiated:(_Bool)arg1 sender:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x000000010000f4a0
- (void)markStoredProfileForPurposeAsInstalled:(int)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x000000010000f324
- (void)profileDataStoredForPurpose:(int)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x000000010000f228
- (void)storeProfileData:(id)arg1 configurationSource:(int)arg2 purpose:(int)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x000000010000efbc
- (void)removeExpiredProfilesWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010000eeac
- (void)updateMISTrust;	// IMP=0x000000010000edf4
- (void)workerQueueUpdateMISTrust;	// IMP=0x000000010000edac
- (void)revalidateManagedApps;	// IMP=0x000000010000ecf4
- (void)workerQueueRevalidateManagedApps;	// IMP=0x000000010000ec78
- (void)removeExpiredProfiles;	// IMP=0x000000010000ebc0
- (void)workerQueueRemoveExpiredProfiles;	// IMP=0x000000010000eb54
- (void)managedAppIDsWithFlags:(int)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x000000010000ea84
- (void)removeProvisioningProfileWithUUID:(id)arg1 managingProfileIdentifier:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x000000010000e704
- (void)installProvisioningProfileData:(id)arg1 managingProfileIdentifier:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x000000010000e290
- (id)_badProvisioningProfileError;	// IMP=0x000000010000e1f8
- (void)storeCertificateData:(id)arg1 forIPCUIdentifier:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x000000010000dfa4
- (void)applicationsDidInstall:(id)arg1;	// IMP=0x000000010000dc54
- (void)workerQueueNotifyUserLoggedIn;	// IMP=0x000000010000dbfc
- (void)notifyUserLoggedIn;	// IMP=0x000000010000db44
- (void)_markPostUserLoginWorkCompleted;	// IMP=0x000000010000da30
- (_Bool)_hasCompletedPostLoginWork;	// IMP=0x000000010000d9f8
- (void)notifyProvisioningProfilesChanged;	// IMP=0x000000010000d7d8
- (void)notifyGracePeriodChanged;	// IMP=0x000000010000d698
- (void)notifyFirstUnlock;	// IMP=0x000000010000d5e0
- (void)notifyDeviceUnlockedWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010000d470
- (void)notifyDeviceUnlockedAndPasscodeRequiredWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010000d300
- (void)workerQueueNotifyDeviceUnlockedAndPasscodeRequired;	// IMP=0x000000010000d2cc
- (void)workerQueueNotifyDeviceUnlocked;	// IMP=0x000000010000d2c0
- (void)workerQueueReadBiometricState;	// IMP=0x000000010000d1d0
- (void)_workerQueueCheckCarrierProfileOnUnlockSometimes;	// IMP=0x000000010000ce24
- (void)_workerQueueForceCheckOfCarrierProfileOnNextUnlock;	// IMP=0x000000010000cd80
- (void)checkCarrierProfileAndForceReinstallation:(_Bool)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x000000010000c3c8
- (void)_workerQueueCheckCarrierProfileAtPath:(id)arg1 forceReinstallation:(_Bool)arg2;	// IMP=0x000000010000bb0c
- (void)_workerQueueRemoveAllCarrierProfiles;	// IMP=0x000000010000b844
- (void)_workerQueueSignIntoFaceTimeWithUsername:(id)arg1;	// IMP=0x000000010000b840
- (void)signIntoFaceTimeWithUsername:(id)arg1;	// IMP=0x000000010000b834
- (void)openSettingsAppForProfileInstallation:(id)arg1 bundleID:(id)arg2;	// IMP=0x000000010000b6bc
- (id)URLForInstallingProfileInSettingsApp:(id)arg1 returningToBundleID:(id)arg2;	// IMP=0x000000010000b618
- (void)_handleSettingsJumpWithProfileData:(id)arg1 targetDeviceType:(unsigned long long)arg2 bundleID:(id)arg3;	// IMP=0x000000010000b548
- (void)openSensitiveURL:(id)arg1 unlock:(_Bool)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x000000010000b224
- (void)removeValueSetting:(id)arg1 sender:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x000000010000b054
- (void)removeBoolSetting:(id)arg1 sender:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x000000010000ae84
- (void)setParametersForSettingsByType:(id)arg1 configurationUUID:(id)arg2 toSystem:(_Bool)arg3 user:(_Bool)arg4 passcode:(id)arg5 credentialSet:(id)arg6 senderPID:(int)arg7 sender:(id)arg8 completion:(CDUnknownBlockType)arg9;	// IMP=0x000000010000ab00
- (void)recomputeProfileRestrictionsWithCompletionBlock:(CDUnknownBlockType)arg1;	// IMP=0x000000010000aa90
- (void)migrateCleanupMigratorWithContext:(int)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x000000010000a8dc
- (void)migrateWithContext:(int)arg1 passcodeWasSetInBackup:(_Bool)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x000000010000a768
- (void)managedWiFiNetworkNamesWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010000a6cc
- (void)managedSystemConfigurationServiceIDsWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010000a630
- (void)resetPasscodeMetadataWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010000a4cc
- (void)isPasscodeCompliantWithNamedPolicy:(id)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x000000010000a2f8
- (void)clearPasscodeWithEscrowKeybagData:(id)arg1 secret:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x000000010000a0e4
- (void)createMDMUnlockTokenIfNeededWithPasscode:(id)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x0000000100009ecc
- (void)changePasscode:(id)arg1 oldPasscode:(id)arg2 senderBundleID:(id)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100009b30
- (void)recomputePerClientUserComplianceWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x00000001000099d0
- (void)recomputeUserComplianceWarningWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010000988c
- (void)notifyHaveSeenComplianceMessageWithLastLockDate:(id)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x0000000100009690
- (void)notifyStartComplianceTimer:(id)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x00000001000093fc
- (void)setAllowedURLStrings:(id)arg1 senderPID:(int)arg2 sender:(id)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100009288
- (void)setSpellCheckAllowed:(_Bool)arg1 senderPID:(int)arg2 sender:(id)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100009128
- (void)setKeyboardShortcutsAllowed:(_Bool)arg1 senderPID:(int)arg2 sender:(id)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100008fc8
- (void)setContinuousPathKeyboardAllowed:(_Bool)arg1 senderPID:(int)arg2 sender:(id)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100008e68
- (void)setPredictiveKeyboardAllowed:(_Bool)arg1 senderPID:(int)arg2 sender:(id)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100008d08
- (void)setSmartPunctuationAllowed:(_Bool)arg1 senderPID:(int)arg2 sender:(id)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100008ba8
- (void)setAutoCorrectionAllowed:(_Bool)arg1 senderPID:(int)arg2 sender:(id)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100008a48
- (void)loadMailAccountsWithAuditToken:(CDStruct_6ad76789)arg1 filteringEnabled:(_Bool)arg2 sourceAccountManagement:(int)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100008534
- (void)allowedKeyboardBundleIDsAfterApplyingFilterToBundleIDs:(id)arg1 messageSendingAppBundleID:(id)arg2 hostAppBundleID:(id)arg3 accountIsManaged:(_Bool)arg4 completion:(CDUnknownBlockType)arg5;	// IMP=0x0000000100007ecc
- (void)allowedImportFromAppBundleIDs:(id)arg1 importingAppBundleID:(id)arg2 importingIsManaged:(_Bool)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100007988
- (void)allowedOpenInAppBundleIDs:(id)arg1 originatingAppBundleID:(id)arg2 originatingIsManaged:(_Bool)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x000000010000740c
- (void)defaultAppBundleIDForCommunicationServiceType:(id)arg1 forAccountWithIdentifier:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x0000000100007330
- (void)mayShareToAirDropForOriginatingAppBundleID:(id)arg1 originatingAccountIsManaged:(_Bool)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x00000001000072d0
- (void)mayShareToMessagesForOriginatingAppBundleID:(id)arg1 originatingAccountIsManaged:(_Bool)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x0000000100007270
- (_Bool)shouldApplyFilterForBundleID:(id)arg1 sourceAccountManagement:(int)arg2 outAllowManagedAccounts:(_Bool *)arg3 outAllowUnmanagedAccounts:(_Bool *)arg4;	// IMP=0x00000001000070f8
- (void)mayShareToWhitelistedSourceUnmanagedTargetAppWithServiceName:(id)arg1 originatingAppBundleID:(id)arg2 originatingAccountIsManaged:(_Bool)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100006e74
- (_Bool)mayOpenFromManagedToUnmanaged;	// IMP=0x0000000100006e10
- (_Bool)mayOpenFromUnmanagedToManaged;	// IMP=0x0000000100006dac
- (_Bool)isOpenInRestrictionInEffect;	// IMP=0x0000000100006d64
- (void)waitForMigrationIncludingPostRestoreMigration:(_Bool)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x00000001000068e0
- (void)setUserInfo:(id)arg1 forClientUUID:(id)arg2 sender:(id)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x00000001000067e0
- (void)removeOrphanedClientRestrictionsWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x000000010000667c
- (void)applyRestrictionDictionary:(id)arg1 appsAndOptions:(id)arg2 clientType:(id)arg3 clientUUID:(id)arg4 sender:(id)arg5 localizedClientDescription:(id)arg6 localizedWarningMessage:(id)arg7 completion:(CDUnknownBlockType)arg8;	// IMP=0x000000010000645c
- (void)removeUninstalledProfileWithIdentifier:(id)arg1 installationType:(long long)arg2 targetDeviceType:(unsigned long long)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x00000001000061a0
- (void)removeProfileWithIdentifier:(id)arg1 installationType:(long long)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x0000000100005f24
- (void)updateProfileIdentifier:(id)arg1 interactionClient:(id)arg2 completion:(CDUnknownBlockType)arg3;	// IMP=0x0000000100005cb4
- (void)installProfileData:(id)arg1 interactionClient:(id)arg2 options:(id)arg3 completion:(CDUnknownBlockType)arg4;	// IMP=0x0000000100005860
- (id)_handleProvisioningProfileData:(id)arg1 jumpToSettings:(_Bool)arg2 bundleID:(id)arg3;	// IMP=0x0000000100005600
- (void)queueProfileDataForInstallation:(id)arg1 originalFileName:(id)arg2 originatingBundleID:(id)arg3 transitionToUI:(_Bool)arg4 completion:(CDUnknownBlockType)arg5;	// IMP=0x0000000100004f48
- (void)popProvisioningProfileFromHeadOfInstallationQueueWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x0000000100004dc0
- (void)peekProfileDataFromPurgatoryForDeviceType:(unsigned long long)arg1 withCompletion:(CDUnknownBlockType)arg2;	// IMP=0x0000000100004c28
- (void)popProfileDataFromHeadOfInstallationQueueWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x0000000100004a74
- (void)checkInWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x0000000100004960
- (void)_sendEffectiveSettingsChangedNotification;	// IMP=0x00000001000048c8
- (void)_sendRestrictionChangedNotification;	// IMP=0x0000000100004844
- (void)workerQueueCheckForAutoInstallProfiles;	// IMP=0x00000001000041b0
- (void)workerQueueRecomputeNagMessage;	// IMP=0x00000001000040f4
- (void)workerQueueDidRecomputeNagMessageWithResult:(_Bool)arg1;	// IMP=0x0000000100003f28
- (void)_workerQueuePrepareForService;	// IMP=0x0000000100003770
- (void)reapplyAppEnforcedRestrictionsWithAssertion:(id)arg1;	// IMP=0x0000000100003388
- (void)localeChanged;	// IMP=0x0000000100003330
- (void)notifyBatterySaverModeChanged;	// IMP=0x0000000100003090
- (void)start;	// IMP=0x0000000100002ae8
- (id)init;	// IMP=0x0000000100002970

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

