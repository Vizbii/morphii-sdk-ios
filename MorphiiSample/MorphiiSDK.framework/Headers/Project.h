//
//  Project.h
//  MorphiiSDK
//
//  Created by Chris K on 7/17/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Project : NSObject
@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSString *projectDescription;

- (id)init:(NSString *)id withDescription:(NSString *)description;
- (NSDictionary *)json;
@end
