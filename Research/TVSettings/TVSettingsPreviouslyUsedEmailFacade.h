//
//     Generated by classdumpios 1.0.1 (64 bit) (iOS port by DreamDevLost)(Debug version compiled Sep 26 2020 00:23:19).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray;

@interface TVSettingsPreviouslyUsedEmailFacade : NSObject
{
    NSArray *_previouslyUsedEmails;	// 8 = 0x8
}

+ (id)sharedInstance;	// IMP=0x00000001000b2e28
- (void).cxx_destruct;	// IMP=0x00000001000b3200
@property(copy, nonatomic) NSArray *previouslyUsedEmails; // @synthesize previouslyUsedEmails=_previouslyUsedEmails;
- (void)clearAllEntriesWithCompletion:(CDUnknownBlockType)arg1;	// IMP=0x00000001000b3128
- (void)deleteEntry:(id)arg1 completion:(CDUnknownBlockType)arg2;	// IMP=0x00000001000b3010
- (void)update;	// IMP=0x00000001000b2f88
- (id)init;	// IMP=0x00000001000b2ec8

@end
