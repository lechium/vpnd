//#import <Foundation/NSXPCConnection.h>
#import <Foundation/Foundation.h>
#import "VPNDaemonProtocol.h"
#import <NetworkExtension/NetworkExtension.h>

/**

 Normally i build this with xcode but it was easier to shoehorn together a theos setup for the open sourcing,
 for some REALLY weird reason it doesnt find any of these NSXPC details in the headers, eventhough they clearly exist
 this is to get it to build without complaining
 
 */

@interface NSXPCInterface : NSObject
+ (NSXPCInterface *)interfaceWithProtocol:(Protocol *)protocol;
@end

@interface NSXPCConnection (priv)
@property (nullable, copy) void (^invalidationHandler)(void);
@property (nullable, copy) void (^interruptionHandler)(void);
- (id)remoteObjectProxy;
- (void)invalidate;
@end

@interface NSXPCListener : NSObject
@property (nullable, weak) id delegate;
- (void)resume;
- (void)suspend;
@end


@interface NSXPCListener (Private)
- (id)initWithMachServiceName:(NSString*)arg1;
@end
@interface NEConfiguration: NSObject
@property (readonly) NSUUID * identifier;
@property (copy) NSString * application;
@property (copy) NSString * name;
@property (copy) NSString * applicationIdentifier;
@property (copy) NSString * applicationName;
-(id)getConfigurationProtocol;
-(void)syncWithSystemKeychain;
- (id)initWithVPNPayload:(id)payload configurationName:(id)name grade:(NSInteger)grade;
@end
//[MCVPNPayloadBase NEVPNPayloadBaseDelegateWithConfigurationDict:payload]
@interface MCVPNPayloadBase : NSObject
+ (id)NEVPNPayloadBaseDelegateWithConfigurationDict:(NSDictionary *)dict;
@end
@interface NEVPNProtocol (science)
-(id)initFromLegacyDictionary:(id)arg1;
@end
static NSString * const kGRDHostnameOverride =      @"APIHostname-Override";
static NSString * const kSGAPI_ServerStatus  =      @"/vpnsrv/api/server-status";
static NSString * const kKeychainStr_EapPassword =  @"eap-password";
static NSString * const kKeychainStr_EapUsername =  @"eap-username";
static NSString * const kMCPayloadExpirationDate =  @"nitotv-PayloadExpiration";
@interface VPNDaemonListener : NSObject <VPNDaemonProtocol> {
}

- (void)initialiseListener;
- (void)monitorVPNConnection;
@end
