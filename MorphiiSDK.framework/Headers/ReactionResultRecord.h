//
//  ReactionResultRecord.h
//  MorphiiSDK
//
//  Created by Chris K on 8/13/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ReactionCommentRecord.h"
#import "ReactionMorphiiResultRecord.h"
#import "ReactionError.h"
@interface ReactionResultRecord : NSObject

@property BOOL isSubmitted;
@property (nonatomic, strong) ReactionCommentRecord * comment;
@property (nonatomic, strong) ReactionMorphiiResultRecord * morphii;
@property (nonatomic, strong) ReactionError * error;
@property (nonatomic, strong) NSString * reactionId;
@property (nonatomic, strong) NSString * viewId;
@property (nonatomic, strong) NSString * targetId;
@property (nonatomic, strong) NSString * serverTimestamp;

- (id)init:(NSDictionary *)record;
@end
