//
//  Target.h
//  MorphiiSDK
//
//  Created by Chris K on 7/17/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Target : NSObject
@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSDictionary *metadata;

- (id)initWithID:(NSString *)id withType:(NSString *)type andData:(NSDictionary *)metadata;
- (NSDictionary *)json;
@end
