#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <TVSystemMenuUI/TVSMButtonViewController.h>
#include "NTVVPNModule.h"
#import "UIView+RecursiveFind.h"
#import "UIImage+Tint.h"

//14+ code
@interface TVSMButtonViewController (science)
@property (assign,nonatomic) BOOL toggledOn API_AVAILABLE(tvos(14.0));
@property (nonatomic,copy) UIColor * symbolTintColor API_AVAILABLE(tvos(14.0));
@end

@interface NSDistributedNotificationCenter : NSNotificationCenter

+ (id)defaultCenter;
- (void)addObserver:(id)arg1 selector:(SEL)arg2 name:(id)arg3 object:(id)arg4;
- (void)postNotificationName:(id)arg1 object:(id)arg2 userInfo:(id)arg3;

@end

@implementation NTVVPNModule

/**

 abusing NSDistributedNotificationCenter because I couldn't get XPC service to work from a widget. we receive these notifications from vpnd after we query for status
 by sending this notification name: @"com.nito.vpnd/request-status"
 
 then vpnd relays back @"com.nito.vpnd/connected" & @"com.nito.vpnd/disconnected" respectively.

 */

- (void)receivedVPNOnNotification:(id)note {
    NSLog(@"[NTVVPNModule] the VPN is on!");
    self.vpnOn = true;
    [self updateContentControllerForMode];
}

- (void)receivedVPNOffNotification:(id)object {
    NSLog(@"[NTVVPNModule] the VPN is off!");
    self.vpnOn = false;
    [self updateContentControllerForMode];
}

- (void)listenForNotifications {
    [[NSDistributedNotificationCenter defaultCenter] addObserver:self selector:@selector(receivedVPNOnNotification:) name:@"com.nito.vpnd/connected" object:nil];
    [[NSDistributedNotificationCenter defaultCenter] addObserver:self selector:@selector(receivedVPNOffNotification:) name:@"com.nito.vpnd/disconnected" object:nil];
}

- (id)init {
    self = [super init];
    if (self){
        _vpnOn = false;
        [self listenForNotifications];
    }
    return self;
}

+(long long)buttonStyle {
    return 1;
}
//easier to track light/dark mode
- (BOOL)darkMode {
    return (self.buttonController.view.traitCollection.userInterfaceStyle == UIUserInterfaceStyleDark);
}

- (void)updateContentControllerForMode {
    UIColor *onTintColor = [UIColor blackColor];
    if (@available(tvOS 14.0, *)) {
        onTintColor = [UIColor blackColor];
    } else {
        if ([self darkMode]){
            onTintColor = [UIColor whiteColor];
        }
    }
    
    self.packageFile = [[self bundle] pathForResource:@"vpn-off" ofType:@"png"];
    if (@available(tvOS 14.0, *)) {
        [self.buttonController setToggledOn:false];
    }
    if (self.vpnOn){
        NSLog(@"[NTVVPNModule] vpn is on!");
        if (@available(tvOS 14.0, *)) {
            NSLog(@"[NTVVPNModule] symbol tint color: %@", [self.buttonController symbolTintColor]);
            [self.buttonController setSymbolTintColor:onTintColor];
            [self.buttonController setToggledOn:true];
        } else { //tvOS 13 this is kinda hacky but it works for now.
            UIView *bv = [self.buttonController buttonView];
            //NSLog(@"[NTVVPNModule] bv: %@", bv);
            //NSString *recurse = [bv performSelector:@selector(recursiveDescription)];
            UIImageView * iv = (UIImageView*)[bv findFirstSubviewWithClass:[UIImageView class]];
            NSLog(@"[NTVVPNModule] imageView: %@", iv);
            //[iv setTintColor:onTintColor];
            UIImage *image = [iv image];
            UIImage *newImage = [image imageWithTintColor:onTintColor];
            [self.buttonController setImage:newImage];
            return;
        }
    } else {
        NSLog(@"[NTVVPNModule] vpn is off!");
    }
    
    NSLog(@"[NTVVPNModule] packageFile: %@", self.packageFile);
    UIImage *theImage = [[UIImage imageWithContentsOfFile:self.packageFile] imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
    [self.buttonController setImage:theImage];
}

-(id)contentViewController {
    
    NSLog(@"[NTVVPNModule] requesting status");
    [[NSDistributedNotificationCenter defaultCenter] postNotificationName:@"com.nito.vpnd/request-status" object:nil userInfo:nil];
    self.buttonController = (TVSMButtonViewController*)[super contentViewController];
    [self.buttonController setStyle:1];
    [self updateContentControllerForMode];
    return self.buttonController;
}

-(void)handleAction {
    
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"nitotv://extra/togglevpn"] options:@{} completionHandler:nil];
}

-(BOOL)dismissAfterAction {
    return TRUE;
}

@end
