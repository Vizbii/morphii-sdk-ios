//
//  ReactionMorphiiRequestRecord.h
//  MorphiiSDK
//
//  Created by Chris K on 7/17/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MorphiiData.h"
#import "MorphiiConfiguration.h"

@interface ReactionMorphiiRequestRecord : NSObject
@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *partName;
@property (nonatomic, strong) NSString *displayName;
@property (nonatomic, strong) NSArray  *parts;
@property (nonatomic, strong) NSArray  *choices;
@property double intensity;
@property int weight;

- (id)init:(MorphiiData *)morphii withIntensity:(double)intensity;
- (NSDictionary *)json;
- (NSDictionary *)jsonWithMorphiiChoices:(MorphiiConfiguration *)config;
@end
