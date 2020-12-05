#import <TVSystemMenuUI/TVSMModuleContentViewControllerDelegate.h>
#import <TVSystemMenuUI/TVSMModuleContentViewController.h>
#import <TVSystemMenuUI/TVSMActionModule.h>

@interface NTVVPNModule : TVSMActionModule

@property BOOL vpnOn;
@property NSString *packageFile;
@property TVSMButtonViewController *buttonController;
@property UIImage *theImage;

+(long long)buttonStyle;
-(id)contentViewController;
-(void)handleAction;
-(BOOL)dismissAfterAction;
@end


