//
//  ReactionService.h
//  MorphiiSDK
//
//  Created by Chris K on 8/13/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ReactionRequestRecord.h"
#import "AFHTTPSessionManager.h"
#import "BasicViewConfiguration.h"
#import "ClientInformation.h"
#import "IntegrationLibrary.h"
#import "ApplicationInformation.h"
#import "ReactionResultRecord.h"
@interface ReactionService : NSObject

@property (nonatomic, strong) BasicViewConfiguration *configuration;

- (id)initWithConfigurationDetails:(BasicViewConfiguration*) details;
- (void)sendReaction:(ReactionRequestRecord*) record completion:(void (^)(NSArray<ReactionResultRecord*> *results))completion;
- (void)sendReactions:(NSArray*) records completion:(void (^)(NSArray<ReactionResultRecord*> *results))completion;
- (void)post:(NSDictionary*)jsonObject completion:(void (^)(NSArray<ReactionResultRecord*> *results))completion;
@end
