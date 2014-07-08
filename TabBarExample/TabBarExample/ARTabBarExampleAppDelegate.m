//
//  ARTabBarExampleAppDelegate.m
//  TabBarExample
//
//  Created by Luigi Panzeri on 27/02/2014.
//  Copyright (c) 2014 AdRoll. All rights reserved.
//

#import "ARTabBarExampleAppDelegate.h"
#import <AdRoll/AdRoll.h>
#import <AdRoll/AdRoll+Advanced.h>

@implementation ARTabBarExampleAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
#if DEBUG
    [AdRoll setVerboseLogging:YES];
#endif
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
    id arpixelClass = NSClassFromString(@"ARLogger");
    id singleton = [arpixelClass performSelector:NSSelectorFromString(@"sharedInstance")];
    NSURL *url = [NSURL URLWithString:@"http://localhost:7777/"];
    [singleton performSelector:NSSelectorFromString(@"setServerURL:") withObject:url];
#pragma clang diagnostic pop
    
    [AdRoll initializeWithAdvertisableId:@"my-advertisable-id" pixelId:@"my-pixel-id"];
    
    return YES;
}


// deep linking management
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    
    UITabBarController *tabController = (UITabBarController *)self.window.rootViewController;
    
    [AdRoll setPageViewWithURL:url properties:@{AdRollEventPropertySourceApplication: sourceApplication}];
    
    if([[url host] isEqualToString:@"second"]) {
        tabController.selectedIndex = 1;
    }
    return YES;
}
@end
