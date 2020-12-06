# vpnd
VPN daemon utilized by nitoTV to deliver VPN access on tvOS

This is normally built as part of nitoTV in an Xcode project, i didn't feel like re-creating the daemon like that as a part of a new xcode project because that is a pretty massive pain to do, so i've included some sample code you can add to an AppDelegate or whatever class you desire in a normal tvOS application, it probably needs to be unsandboxed or uncontainerized, but im not certain on that, will need to experiment if you decide to mess with this.

Read more about [configuration profiles](https://developer.apple.com/business/documentation/Configuration-Profile-Reference.pdf)

I recommend creating profiles to experiment in [Apple Configurator 2](https://support.apple.com/apple-configurator)

***build and use at your own risk! working with NEVPNManager is a huge & finicky pain if you arent familiar with it.***

## App side sample code

```Objective-C


@interface AppDelegate () 
@property (nonatomic, strong) NSXPCConnection *daemonConnection;
@end


//this is just a partial implementation to give a quick App Side example of toggling the VPN until i can update the sample code.

@implementation AppDelegate 

- (void)daemonDidRequestQueuedNotification {
    NSLog(@"*** [nitoTV] :: daemonDidRequestQueuedNotification");
 
    [self _notifyDaemonOfMessageHandled];
}

- (void)_setupDaemonConnection {
/*#if TARGET_OS_SIMULATOR
    return;
#endif*/
    
    if (self.daemonConnection) {
        [self.daemonConnection invalidate];
        self.daemonConnection = nil;
    }
    
    self.daemonConnection = [[NSXPCConnection alloc] initWithMachServiceName:@"com.nito.vpnd"];
    self.daemonConnection.remoteObjectInterface = [NSXPCInterface interfaceWithProtocol:@protocol(VPNDaemonProtocol)];
    
    self.daemonConnection.exportedInterface = [NSXPCInterface interfaceWithProtocol:@protocol(VPNApplicationProtocol)];
    self.daemonConnection.exportedObject = self;
    
    [self.daemonConnection resume];
    
    // Handle connection errors
    __weak AppDelegate *weakSelf = self;
    self.daemonConnection.interruptionHandler = ^{
        NSLog(@"interruption handler called");
        
        [weakSelf.daemonConnection invalidate];
        weakSelf.daemonConnection = nil;
        
        // Re-create connection
        [weakSelf _setupDaemonConnection];
    };
    
    self.daemonConnection.invalidationHandler = ^{
        NSLog(@"invalidation handler called");
        
        [weakSelf.daemonConnection invalidate];
        weakSelf.daemonConnection = nil;
        
        // Notify of failed connection
        [weakSelf _notifyDaemonFailedToConnect];
    };
    
    // Notify daemon that we've now launched
    @try {
        [[self.daemonConnection remoteObjectProxyWithErrorHandler:^(NSError * _Nonnull error) {
            NSLog(@"%@", error);
            
            if (error.code == NSXPCConnectionInvalid) {
                [weakSelf _notifyDaemonFailedToConnect];
            }
        }] applicationDidLaunch];

    } @catch (NSException *e) {
        [self _notifyDaemonFailedToConnect];
        return;
    }
    
    NSLog(@"*** [nitoTV] :: Setup daemon connection: %@", self.daemonConnection);
}

- (void)_notifyDaemonFailedToConnect {
    if (!self.applicationIsActive) {
        self.pendingDaemonConnectionAlert = YES;
        return;
    }
    
    // That's not good...
    UIAlertController *av = [UIAlertController alertControllerWithTitle:@"Error" message:@"Could not connect to VPN daemon.\n\nPlease restart nitoTV." preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *action = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {}];
    [av addAction:action];
    
    [self.window.rootViewController presentViewController:av animated:YES completion:nil];
    
    NSLog(@"*** [nitoTV] :: ERROR :: Failed to setup daemon connection: %@", self.daemonConnection);
}

- (void)toggleVPN {
    @try{
           [[self.daemonConnection remoteObjectProxy] applicationRequestsToggleVPN];
       } @catch (NSException *e) {
           NSLog(@"[nitoTV] failed to applicationRequestsVPNStatus with exception: %@", e);
           // Error previous shown
       }
}

- (void)requestExpirationStatus {
    @try{
           [[self.daemonConnection remoteObjectProxy] applicationRequestExpirationStatus];
       } @catch (NSException *e) {
           NSLog(@"[nitoTV] failed to applicationRequestExpirationStatus with exception: %@", e);
           // Error previous shown
       }
}

- (void)requestVPNStatus {
    @try{
           [[self.daemonConnection remoteObjectProxy] applicationRequestsVPNStatus];
       } @catch (NSException *e) {
           NSLog(@"[nitoTV] failed to applicationRequestsVPNStatus with exception: %@", e);
           // Error previous shown
       }
}

- (void)daemonProfileExpired:(BOOL)expired {
    LOG_SELF;
    if (expired){
        DDLogInfo(@"VPN MC is expired!");
    } else {
        DDLogInfo(@"VPN MC is not expired!");
    }
}

- (void)daemonReportsStatus:(NEVPNStatus)status {
    LOG_SELF;
    DDLogInfo(@"daemon reported status: %lu", status);
    [[packageManagement sharedManager] setCurrentVPNStatus:status];
    [self.tabBarController refreshSettings];
}

- (void)stopVPNService {
    
    @try{
        [[self.daemonConnection remoteObjectProxy] applicationStopVPNConnection];
    } @catch (NSException *e) {
        NSLog(@"[nitoTV] failed to startVPNPayload with exception: %@", e);
        // Error previous shown
    }
}

- (void)setCurrentInterfaceMode:(UIUserInterfaceStyle)style {
    LOG_SELF;
    @try {
        [[self.daemonConnection remoteObjectProxy] applicationChangedViewMode:style];
    } @catch (NSException *exception) {
        NSLog(@"[nitoTV] failed setCurrentInterfaceMode with exception: %@", exception);
    } @finally {
        //
    }
}

- (void)promptToInstallMobileConfig:(NSString *)mcfile {
    
    NSDictionary *dict = [NSDictionary dictionaryWithContentsOfFile:mcfile];
    NSArray *payloads = [dict valueForKey:@"PayloadContent"];
    if (payloads.count > 0){
        NSDictionary *mainPayload = payloads[0];
        NSLog(@"[nitoTV] mainPayload: %@", mainPayload);
        NSString *payloadType = mainPayload[@"PayloadType"];
        NSString *payloadDisplayName = mainPayload[@"PayloadDisplayName"];
        NSString *payloadDescription = mainPayload[@"PayloadDescription"];

        if ([payloadType isEqualToString:@"com.apple.vpn.managed"]){
            
            NSString *title = [NSString stringWithFormat:@"Install '%@'?", payloadDisplayName];
            UIAlertController *ac = [UIAlertController alertControllerWithTitle:title message:payloadDescription preferredStyle:UIAlertControllerStyleAlert];
            UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                
                [self showBulletinWithTitle:@"VPN" message:[NSString stringWithFormat:@"Processing %@...", payloadDisplayName] timeout:3];
                [self startVPNPayload:mainPayload];
            }];
            [ac addAction:okAction];
            [ac addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:nil]];
            dispatch_async(dispatch_get_main_queue(), ^{
                [[self topViewController] presentViewController:ac animated:true completion:nil];
            });
            
        }
    }
   
    
}

//where we send the mobileconfig after receiving it from 
- (void)startVPNPayload:(NSDictionary *)payload {
    @try {
           [[self.daemonConnection remoteObjectProxy] applicationStartVPNConnection:payload];
       } @catch (NSException *e) {
           NSLog(@"[nitoTV] failed to startVPNPayload with exception: %@", e);
           // Error previous shown
       }
}

- (void)_notifyDaemonOfMessageHandled {
    // Let the daemon know to release the background assertion.
    @try {
        [[self.daemonConnection remoteObjectProxy] applicationDidFinishTask];
    } @catch (NSException *e) {
        // Error previous shown
    }
}
@end
```
