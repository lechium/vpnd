//
//     Generated by classdumpios 1.0.1 (64 bit) (iOS port by DreamDevLost)(Debug version compiled Sep 26 2020 00:23:19).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <TVSettingKit/TSKViewController.h>

@class PBSDisplayMode, UIViewController;

@interface TVSettingsResolutionViewController : TSKViewController
{
    PBSDisplayMode *_lastDisplayMode;	// 8 = 0x8
    UIViewController *_recoveryController;	// 16 = 0x10
}

- (void).cxx_destruct;	// IMP=0x0000000100012ea8
@property(nonatomic) __weak UIViewController *recoveryController; // @synthesize recoveryController=_recoveryController;
@property(retain, nonatomic) PBSDisplayMode *lastDisplayMode; // @synthesize lastDisplayMode=_lastDisplayMode;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;	// IMP=0x0000000100012d98
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;	// IMP=0x0000000100012cb0
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;	// IMP=0x0000000100012ad4
- (void)_selectedItem:(id)arg1;	// IMP=0x0000000100012a84
- (CDUnknownBlockType)resolutionItemConfigurationBlock;	// IMP=0x0000000100012768
- (id)resolutionGroupsForCommonModes:(_Bool)arg1;	// IMP=0x0000000100012310
- (void)changeModeTo:(id)arg1;	// IMP=0x000000010001201c
- (void)viewDidLoad;	// IMP=0x0000000100011f68
- (void)dealloc;	// IMP=0x0000000100011e88
- (id)initWithStyle:(long long)arg1;	// IMP=0x0000000100011d68

@end

