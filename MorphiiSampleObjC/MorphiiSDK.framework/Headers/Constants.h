//
//  Constants.h
//  MorphiiSDK
//
//  Created by Chris K on 7/23/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Constants : NSObject
@end

@interface API : Constants
@property (nonatomic, retain) NSString *Authenticate;
@property (nonatomic, retain) NSString *Morphiis;
@property (nonatomic, retain) NSString *Reactions;
@property (nonatomic, retain) NSString *Usage;
@property (nonatomic, retain) NSString *Echo;

+(NSString *) Authenticate;
+(NSString *) Morphiis;
+(NSString *) Reactions;
+(NSString *) Usage;
+(NSString *) Echo;
+ (BOOL) isServiceProduction;
@end
