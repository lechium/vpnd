/*
* This header is generated by classdump-dyld 1.0
* on Saturday, September 26, 2020 at 1:36:40 AM Mountain Standard Time
* Operating System: Version 14.0 (Build 18J386)
* Image Source: /System/Library/Frameworks/CoreServices.framework/CoreServices
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <Foundation/NSProxy.h>
#import <libobjc.A.dylib/NSSecureCoding.h>

@class LSBundleRecord;

@interface _LSCoreTypesRecordProxy : NSProxy <NSSecureCoding> {

	LSBundleRecord* _realRecord;

}

@property (nonatomic,readonly) LSBundleRecord * _realRecord;              //@synthesize realRecord=_realRecord - In the implementation block
+(id)description;
+(BOOL)supportsSecureCoding;
+(id)classFallbacksForKeyedArchiver;
+(Class)classForKeyedUnarchiver;
-(BOOL)isKindOfClass:(Class)arg1 ;
-(BOOL)isEqual:(id)arg1 ;
-(unsigned long long)hash;
-(id)debugDescription;
-(BOOL)isMemberOfClass:(Class)arg1 ;
-(BOOL)conformsToProtocol:(id)arg1 ;
-(id)description;
-(id)methodSignatureForSelector:(SEL)arg1 ;
-(void)forwardInvocation:(id)arg1 ;
-(id)forwardingTargetForSelector:(SEL)arg1 ;
-(id)init;
-(id)SDKVersion;
-(Class)classForCoder;
-(void)encodeWithCoder:(id)arg1 ;
-(id)initWithCoder:(id)arg1 ;
-(id)URL;
-(id)bundleIdentifier;
-(id)localizedName;
-(id)replacementObjectForCoder:(id)arg1 ;
-(id)awakeAfterUsingCoder:(id)arg1 ;
-(id)executableURL;
-(Class)classForKeyedArchiver;
-(id)replacementObjectForKeyedArchiver:(id)arg1 ;
-(id)entitlements;
-(id)dataContainerURL;
-(id)UIBackgroundModes;
-(unsigned)platform;
-(id)localizedShortName;
-(id)applicationIdentifier;
-(void)detach;
-(id)intentDefinitionURLs;
-(id)supportedIntents;
-(id)supportedIntentMediaCategories;
-(id)intentsRestrictedWhileProtectedDataUnavailable;
-(id)intentsRestrictedWhileLocked;
-(BOOL)isProfileValidated;
-(id)machOUUIDs;
-(id)managedPersonas;
-(char)developerType;
-(BOOL)isUPPValidated;
-(BOOL)isFreeProfileValidated;
-(id)serviceRecords;
-(LSBundleRecord *)_realRecord;
-(id)localizedNameWithPreferredLocalizations:(id)arg1 ;
-(id)localizedShortNameWithPreferredLocalizations:(id)arg1 ;
-(id)localizedUsageDescriptionForFeature:(unsigned long long)arg1 ;
-(id)localizedUsageDescriptionForFeature:(unsigned long long)arg1 preferredLocalizations:(id)arg2 ;
-(id)accentColorName;
-(id)WKBackgroundModes;
-(BOOL)supportsNowPlaying;
-(id)_loadRealRecord;
-(id)signerOrganization;
@end
