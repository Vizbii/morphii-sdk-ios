//
//  ReactionError.h
//  MorphiiSDK
//
//  Created by Chris K on 7/17/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ReactionError : NSObject
@property (nonatomic, strong) NSString *code;
@property (nonatomic, strong) NSString *message;

- (id)init:(NSString *)code andMessage:(NSString *)message;
@end
