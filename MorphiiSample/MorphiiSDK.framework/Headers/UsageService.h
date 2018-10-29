//
//  UsageService.h
//  MorphiiSDK
//
//  Created by Chris K on 8/6/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Target.h"
#import "Timestamp.h"
#import "ApplicationInformation.h"
#import "IntegrationLibrary.h"
#import "ClientInformation.h"
#import "AccountService.h"
#import "ViewAddEvent.h"
#import "MorphiiChangeEvent.h"
#import "MorphiiIntensityChangeEvent.h"
#import "MorphiiShareSelectEvent.h"
#import "Constants.h"
#import "AFHTTPSessionManager.h"
#import "BasicViewConfiguration.h"

@interface UsageService : NSObject
@property (nonatomic, strong) NSString *viewId;
@property (nonatomic, strong) Target *target;
@property (nonatomic, strong) User *user;
@property (nonatomic, strong) Project *project;
@property (nonatomic, strong) ApplicationInformation *application;


//methods
- (id) init:(NSString *)viewId target:(Target *)target;
- (id) init:(NSString *)viewId basicViewConfiguration:(BasicViewConfiguration *)basicConfig;
- (void) sendLoadEvent;
- (void) sendAddEvent:(ViewAddEvent *)data;
- (void) sendChangeEvent:(MorphiiChangeEvent *)data;
- (void) sendChangeIntensityEvent:(MorphiiIntensityChangeEvent *)data;
- (void) sendShareSelectEvent:(MorphiiShareSelectEvent *)data;

@end
