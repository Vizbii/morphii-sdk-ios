//
//  ViewAddEvent.h
//  MorphiiSDK
//
//  Created by Chris K on 7/26/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ViewAddEvent : NSObject

@property (nonatomic, strong) NSDictionary *options;
@property (nonatomic, strong) NSArray *morphiiChoices;

- (id)init:(NSDictionary *)options choices:(NSArray *)choices;
@end
