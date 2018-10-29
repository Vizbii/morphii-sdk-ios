//
//  Comment.h
//  MorphiiSDK
//
//  Created by Chris K on 7/17/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Comment : NSObject
@property BOOL show;
@property BOOL required;
@property int maxLength;
@property (nonatomic, strong) NSString *hintText;
@property (nonatomic, strong) NSString *label;

- (id)init:(BOOL)show isRequired:(BOOL)required withMaxLength:(int)maxLength label:(NSString *) label andHintText:(NSString *) hintText;
- (NSDictionary *) json;
@end
