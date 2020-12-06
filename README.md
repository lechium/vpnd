# vpnd
VPN daemon utilized by nitoTV to deliver VPN access on tvOS

This is normally built as part of nitoTV in an Xcode project, i didn't feel like re-creating the daemon like that as a part of a new xcode project because that is a pretty massive pain to do. 

Still need to add some companion code on how to interact with the VPN. nicely cleaned up and documented now at least.

Read more about [configuration profiles](https://developer.apple.com/business/documentation/Configuration-Profile-Reference.pdf)

I recommend creating profiles to experiment in [Apple Configurator 2](https://support.apple.com/apple-configurator)

***build and use at your own risk! working with NEVPNManager is a huge & finicky pain if you arent familiar with it.***

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

@end
```
