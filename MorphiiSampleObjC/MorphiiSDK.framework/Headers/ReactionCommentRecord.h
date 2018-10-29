//
//  ReactionCommentRecord.h
//  MorphiiSDK
//
//  Created by Chris K on 7/17/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ReactionCommentRecord : NSObject
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) NSString *locale;

- (id)init:(NSString *)text withLocale:(NSString *)locale;
@end
