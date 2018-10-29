//
//  Options.h
//  MorphiiSDK
//
//  Created by Chris K on 7/17/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Options : NSObject
@property (nonatomic, strong) NSString *stage;
@property double initialIntensity;

- (id)init:(NSString *)stage withIntensity:(double)initialIntensity;
- (NSDictionary *)json;

@end
