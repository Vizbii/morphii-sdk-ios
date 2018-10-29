//
//  ReactionRequestRecord.h
//  MorphiiSDK
//
//  Created by Chris K on 8/13/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Target.h"
#import "Project.h"
#import "Options.h"
#import "User.h"
#import "ReactionMorphiiRequestRecord.h"
#import "AccountService.h"
#import "IntegrationLibrary.h"
#import "BasicViewConfiguration.h"

@interface ReactionRequestRecord : NSObject

@property (nonatomic, strong) ReactionMorphiiRequestRecord * morphii;
@property (nonatomic, strong) Target * target;
@property (nonatomic, strong) Project * project;
@property (nonatomic, strong) Options * options;
@property (nonatomic, strong) User * user;
@property (nonatomic, strong) BasicViewConfiguration * configuration;
@property (nonatomic, strong) NSString * commentText;
@property (nonatomic, strong) NSString * viewId;
@property (nonatomic, strong) NSString * hintText;

- (id)init:(ReactionMorphiiRequestRecord *)morphii target:(Target*)target project:(Project*)project options:(Options*)options viewId:(NSString *)viewId user:(User *)user commentText:(NSString *)commentText hintText:(NSString *)hintText configuration:(BasicViewConfiguration *)configuration;
- (NSDictionary *)json;
@end
