//
//  ServiceError.h
//  MorphiiSDK
//
//  Created by Chris K on 8/7/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ServiceError : NSObject
@property (nonatomic, strong) NSString *code;
@property (nonatomic, strong) NSString *message;

- (id) init:(NSString *)code message:(NSString *)message;
@end
