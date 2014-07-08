//
//  ARTabBarExampleFirstViewController.m
//  TabBarExample
//
//  Created by Luigi Panzeri on 27/02/2014.
//  Copyright (c) 2014 AdRoll. All rights reserved.
//

#import "ARTabBarExampleFirstViewController.h"
#import <AdRoll/AdRoll.h>
#import <AdRoll/AdRoll+Advanced.h>


@implementation ARTabBarExampleFirstViewController
- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    [AdRoll setPageViewWithURL:[NSURL URLWithString:@"/first/"]];
}
@end
