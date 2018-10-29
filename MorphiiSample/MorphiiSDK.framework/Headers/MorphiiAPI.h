//
//  MorphiiAPI.h
//  MorphiiSDK
//
//  Created by Chris K on 8/27/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Morphii.h"
#import "Constants.h"
#import "MorphiiConfiguration.h"
#import "BasicViewConfiguration.h"
#import "AFHTTPSessionManager.h"


@interface MorphiiAPI : NSObject
@property (strong, nonatomic) NSArray<Morphii *> * allMorphiis;
@property (nonatomic) NSString *username;
@property (nonatomic) NSString *password;
@property (nonatomic) NSString *accountId;
@property (nonatomic) NSString *clientKey;
@property (nonatomic) NSString *apiKey;
@property (nonatomic) NSString *jwt;

+ (MorphiiAPI*) sharedInstance;

- (NSArray *) getMorphiiIDs;
- (NSDictionary*)getAuthenticateBodyData;
- (NSDictionary*)getReactionBodyData;
- (void) fetchMorphiis:(MorphiiConfiguration *)config ids:(NSArray*)ids completion:(void (^)(NSArray *morphiisArray))completion;
- (void) fetchAllMorphiis:(BasicViewConfiguration *)config completion:(void (^)(NSArray *morphiisArray))completion;
@end
