//
//  MorphiiEvent.h
//  MorphiiSDK
//
//  Created by Chris K on 7/18/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MorphiiData.h"

@interface MorphiiEvent : NSObject
@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *displayName;
@property (nonatomic, strong) NSString *partName;
@property (nonatomic, strong) NSArray *parts;
@property double intensity;
@property int weight;

- (id)init:(MorphiiData *)morphii andIntensity:(double)intensity;

@end
