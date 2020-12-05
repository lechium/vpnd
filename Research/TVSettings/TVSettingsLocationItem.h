//
//     Generated by classdumpios 1.0.1 (64 bit) (iOS port by DreamDevLost)(Debug version compiled Sep 26 2020 00:23:19).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray, NSDictionary, NSString, TVImageProxy;

@interface TVSettingsLocationItem : NSObject
{
    NSString *_title;	// 8 = 0x8
    NSString *_explanatoryText;	// 16 = 0x10
    TVImageProxy *_image;	// 24 = 0x18
    unsigned long long _type;	// 32 = 0x20
    unsigned long long _accessType;	// 40 = 0x28
    NSArray *_allowedAccessTypes;	// 48 = 0x30
    NSString *_identifier;	// 56 = 0x38
    NSDictionary *_info;	// 64 = 0x40
}

+ (id)_imageForInfo:(id)arg1;	// IMP=0x000000010007fcf0
+ (id)_allowedAccessTypesForInfo:(id)arg1;	// IMP=0x000000010007fc14
+ (unsigned long long)_accessTypeForInfo:(id)arg1;	// IMP=0x000000010007fbd4
+ (unsigned long long)_itemTypeForInfo:(id)arg1;	// IMP=0x000000010007fb8c
+ (id)_explanatoryTextForInfo:(id)arg1;	// IMP=0x000000010007fa28
+ (id)_titleForIdentifier:(id)arg1 info:(id)arg2;	// IMP=0x000000010007f79c
- (void).cxx_destruct;	// IMP=0x000000010007fd74
@property(copy, nonatomic) NSDictionary *info; // @synthesize info=_info;
@property(readonly, nonatomic) NSString *identifier; // @synthesize identifier=_identifier;
@property(retain, nonatomic) NSArray *allowedAccessTypes; // @synthesize allowedAccessTypes=_allowedAccessTypes;
@property(nonatomic) unsigned long long accessType; // @synthesize accessType=_accessType;
@property(nonatomic) unsigned long long type; // @synthesize type=_type;
@property(retain, nonatomic) TVImageProxy *image; // @synthesize image=_image;
@property(copy, nonatomic) NSString *explanatoryText; // @synthesize explanatoryText=_explanatoryText;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
- (id)initWithInfo:(id)arg1 identifier:(id)arg2;	// IMP=0x000000010007f304
- (id)init;	// IMP=0x000000010007f2f0

@end
