//
//     Generated by classdumpios 1.0.1 (64 bit) (iOS port by DreamDevLost)(Debug version compiled Sep 26 2020 13:48:20).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "NEVPNPluginDriver-Protocol.h"

@class NSDictionary;

@protocol NEVPNAuthenticationPluginDriver <NEVPNPluginDriver>
- (void)authenticateWithParameters:(NSDictionary *)arg1 completionHandler:(void (^)(NSDictionary *, int))arg2;
@end
