//
//  ARTabBarExampleSecondViewController.m
//  TabBarExample
//
//  Created by Luigi Panzeri on 27/02/2014.
//  Copyright (c) 2014 AdRoll. All rights reserved.
//

#import "ARTabBarExampleSecondViewController.h"
#import <AdRoll/AdRoll.h>
#import <AdRoll/AdRoll+Advanced.h>

@interface ARTabBarExampleSecondViewController ()
- (IBAction)doSomethingCool:(id)sender;
@end

@implementation ARTabBarExampleSecondViewController
- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    [AdRoll setPageViewWithURL:[NSURL URLWithString:@"/second/"]];
}

- (IBAction)doSomethingCool:(id)sender {
    [AdRoll logEvent:@"user-pressed-convert"];
}
@end
