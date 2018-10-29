//
//  ReactionMorphiiResultRecord.h
//  MorphiiSDK
//
//  Created by Chris K on 7/17/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ReactionMorphiiResultRecord : NSObject
@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *displayName;
@property (nonatomic, strong) NSString *partName;
@property (nonatomic, strong) NSDictionary *urls;
@property (nonatomic, strong) NSArray *parts;
@property double intensity;
@property int weight;


- (id)init:(NSString *)id withName:(NSString *)name displayName:(NSString *)displayName intensity:(double)intensity  andweight:(int)weight;
@end
