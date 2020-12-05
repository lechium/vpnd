#import <UIKit/UIInterface.h>

@protocol VPNDaemonProtocol <NSObject>

- (void)applicationDidLaunch;
- (void)applicationDidFinishTask;
- (void)applicationRequestsPreferencesUpdate;
- (void)applicationChangedViewMode:(NSInteger)style; //
- (void)applicationStartVPNConnection:(NSDictionary *)profile;
- (void)applicationStopVPNConnection;
- (void)applicationRequestsVPNStatus;
- (void)applicationRequestExpirationStatus;
- (void)applicationRequestsToggleVPN;

@end
