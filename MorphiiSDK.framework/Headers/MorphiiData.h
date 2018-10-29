//
//  MorphiiData.h
//  MorphiiSDK
//
//  Created by Chris K on 7/17/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MorphiiData : NSObject
@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *partName;
@property (nonatomic, strong) NSDictionary *metadata;
@property (nonatomic, strong) NSString *displayName;
@property (nonatomic, strong) NSArray *parts;
@property int scaleType;
@property int weight;

- (id)init:(NSString *)id name:(NSString *)name scaleType:(int)scaleType data:(NSDictionary *)metadata  displayName:(NSString *)displayName weight:(int)weight;
- (id)init:(NSString *)id name:(NSString *)name scaleType:(int)scaleType data:(NSDictionary *)metadata  displayName:(NSString *)displayName partName:(NSString *)partName parts:(NSArray *)parts weight:(int)weight;
@end
