//
//  MorphiiClasses.h
//  MorphiiSDK
//
//  Created by Chris K on 9/6/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ReactionError.h"
@interface MorphiiSDK : NSObject

@end

@interface Coordinates : NSObject

@property double lat;
@property double lng;

- (id)init:(double)lat lng:(double)lng;
@end

//----------------------------------------------------------
//----------------------------------------------------------

@interface MorphiiList : NSObject

@property (nonatomic, retain) NSArray *ids;
@property BOOL showName;

@end

//----------------------------------------------------------
//----------------------------------------------------------

@interface ReactionResult : NSObject

@property (nonatomic, strong) NSString *viewId;
@property (nonatomic, strong) NSString *reactionId;
@property (nonatomic, retain) NSDictionary *reactionRecord;
@property BOOL isSubmitted;

@end

//----------------------------------------------------------
//----------------------------------------------------------

@interface AuthenticationResults : NSObject
@property (nonatomic, strong) ReactionError *error;
@property (nonatomic, strong) NSString *jwt;
@property (nonatomic, strong) NSString *apiKey;
@property (nonatomic, strong) NSString *sessionId;
@property BOOL isAuthenticated;

- (id) init:(BOOL)isAuthenticated jwt:(NSString*)jwt apiKey:(NSString*)apiKey sessionId:(NSString*)sessionId error:(ReactionError *)error;

@end

//----------------------------------------------------------
//----------------------------------------------------------
