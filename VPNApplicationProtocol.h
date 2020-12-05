
@protocol VPNApplicationProtocol <NSObject>

- (void)daemonReportsStatus:(NSInteger)status;
- (void)daemonProfileExpired:(BOOL)expired;
- (void)daemonDidRequestQueuedNotification;

@end
