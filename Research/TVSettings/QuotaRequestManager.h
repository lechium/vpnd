//
//     Generated by classdumpios 1.0.1 (64 bit) (iOS port by DreamDevLost)(Debug version compiled Sep 26 2020 00:23:19).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMutableDictionary, NSOperationQueue, QuotaInfoResponse;
@protocol OS_dispatch_queue;

@interface QuotaRequestManager : NSObject
{
    NSOperationQueue *_requestQueue;	// 8 = 0x8
    NSObject<OS_dispatch_queue> *_quota_info_queue;	// 16 = 0x10
    QuotaInfoResponse *_quotaInfo;	// 24 = 0x18
    NSMutableDictionary *_appDetailsCache;	// 32 = 0x20
}

+ (id)noAccountError;	// IMP=0x0000000100067af8
+ (id)sharedManager;	// IMP=0x0000000100067a8c
- (void).cxx_destruct;	// IMP=0x0000000100068a48
- (void)getAppDetailsForBundleIDs:(id)arg1 handler:(CDUnknownBlockType)arg2;	// IMP=0x000000010006882c
- (id)appDetailsForBundleIDs:(id)arg1 error:(id *)arg2;	// IMP=0x00000001000683b8
- (void)clearCachedAppDetails;	// IMP=0x0000000100068358
- (void)getQuotaInfoForHandler:(CDUnknownBlockType)arg1;	// IMP=0x00000001000681ac
- (id)quotaInfoError:(id *)arg1;	// IMP=0x0000000100067eb4
- (id)_sendSynchronousAARequest:(id)arg1;	// IMP=0x0000000100067cec
- (void)noteQuotaInfoChanged;	// IMP=0x0000000100067c8c
- (void)clearCachedQuotaInfo;	// IMP=0x0000000100067c24
- (id)init;	// IMP=0x0000000100067b84

@end

