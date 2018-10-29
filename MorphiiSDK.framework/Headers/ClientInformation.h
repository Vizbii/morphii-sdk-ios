//
//  ClientInformation.h
//  MorphiiSDK
//
//  Created by Chris K on 8/20/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ClientInformation : NSObject

@property (strong,nonatomic) NSDictionary * client;

+ (NSDictionary *) client;
@end
