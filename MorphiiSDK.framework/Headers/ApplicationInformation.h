//
//  ApplicationInformation.h
//  MorphiiSDK
//
//  Created by Chris K on 8/20/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ApplicationInformation : NSObject
@property (nonatomic, strong) NSString *appName;
@property (nonatomic, strong) NSString *description;
@property (nonatomic, strong) NSString *version;
@property (nonatomic, strong) NSDictionary *properties;

- (id)initWithName:(NSString *)name description:(NSString *)description version:(NSString *)version andProperties:(NSDictionary *)properties;
- (NSDictionary *) json;

@end
