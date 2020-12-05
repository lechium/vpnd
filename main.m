//
//  main.m
//  vpnd
//
//  Created by Kevin Bradley on 11/5/20.
//  Copyright © 2020 nito. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPNDaemonListener.h"
#import <Foundation/NSXPCConnection.h>



int main(int argc, const char *argv[])
{
    NSLog(@"*** [vpnd] :: Loading up daemon.");
    #if !TARGET_IPHONE_SIMULATOR
    // initialize our daemon
    
    VPNDaemonListener *daemon = [[VPNDaemonListener alloc] init];
    [daemon initialiseListener];
    [daemon monitorVPNConnection];
    // Bypass compiler prohibited errors
    Class NSXPCListenerClass = NSClassFromString(@"NSXPCListener");
    
    NSXPCListener *listener = [[NSXPCListenerClass alloc] initWithMachServiceName:@"com.nito.vpnd"];
    listener.delegate = daemon;
    [listener resume];
    
    // Run the run loop forever.
    [[NSRunLoop currentRunLoop] run];
#endif
    return EXIT_SUCCESS;
}
