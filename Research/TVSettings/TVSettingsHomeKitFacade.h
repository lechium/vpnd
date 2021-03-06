//
//     Generated by classdumpios 1.0.1 (64 bit) (iOS port by DreamDevLost)(Debug version compiled Sep 26 2020 00:23:19).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "TVSettingsTCCFacade.h"

#import "HMHomeDelegatePrivate-Protocol.h"
#import "HMHomeManagerDelegate-Protocol.h"

@class HMHomeManager, NSArray, NSString, TVCSHomeManager;

@interface TVSettingsHomeKitFacade : TVSettingsTCCFacade <HMHomeManagerDelegate, HMHomeDelegatePrivate>
{
    _Bool _needsUpdate;	// 8 = 0x8
    NSArray *_residentDevices;	// 16 = 0x10
    NSArray *_doorbellServices;	// 24 = 0x18
    HMHomeManager *_homeManager;	// 32 = 0x20
    TVCSHomeManager *_settingsHomeManager;	// 40 = 0x28
}

+ (id)sharedInstance;	// IMP=0x00000001000af5e4
- (void).cxx_destruct;	// IMP=0x00000001000affac
@property(nonatomic) _Bool needsUpdate; // @synthesize needsUpdate=_needsUpdate;
@property(readonly, nonatomic) TVCSHomeManager *settingsHomeManager; // @synthesize settingsHomeManager=_settingsHomeManager;
@property(readonly, nonatomic) HMHomeManager *homeManager; // @synthesize homeManager=_homeManager;
@property(copy, nonatomic) NSArray *doorbellServices; // @synthesize doorbellServices=_doorbellServices;
@property(copy, nonatomic) NSArray *residentDevices; // @synthesize residentDevices=_residentDevices;
- (void)_updateDoorbellServices;	// IMP=0x00000001000afce0
- (void)_updateResidentDevices;	// IMP=0x00000001000afa0c
- (void)_setNeedsResidentDeviceUpdate;	// IMP=0x00000001000af908
- (void)home:(id)arg1 didRemoveResidentDevice:(id)arg2;	// IMP=0x00000001000af8fc
- (void)home:(id)arg1 didAddResidentDevice:(id)arg2;	// IMP=0x00000001000af8f0
- (void)homeManagerDidUpdatePrimaryHome:(id)arg1;	// IMP=0x00000001000af8e4
- (void)homeManager:(id)arg1 didRemoveHome:(id)arg2;	// IMP=0x00000001000af8d8
- (void)homeManager:(id)arg1 didAddHome:(id)arg2;	// IMP=0x00000001000af89c
- (void)homeManagerDidUpdateHomes:(id)arg1;	// IMP=0x00000001000af890
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;	// IMP=0x00000001000af7f8
- (id)initWithServiceName:(id)arg1;	// IMP=0x00000001000af69c

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

