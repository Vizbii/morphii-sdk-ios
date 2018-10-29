//
//  AccountService.h
//  MorphiiSDK
//
//  Created by Chris K on 8/24/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ReactionError.h"
#import "MorphiiClasses.h"
@interface SubAccount : NSObject
@property (retain, nonatomic) NSString * id;
@property (retain, nonatomic) NSString * name;

- (NSDictionary *) json;
- (id) initWithId:(NSString *)id name:(NSString *)name;
- (id) init;
@end

@interface AccountService : NSObject

@property BOOL isAuthenticated;
@property (retain, nonatomic) NSString * id;
@property (nonatomic, strong) NSString *jwt;
@property (nonatomic, strong) NSString *apiKey;
@property (nonatomic, strong) NSString *sessionId;
@property (nonatomic, strong) ReactionError *error;
@property (nonatomic, strong) SubAccount *subAcct;
@property (nonatomic, strong) NSString *userName;
@property (nonatomic, strong) NSString *password;

+ (AccountService*) sharedInstance;

- (NSDictionary *) account;
- (void)setAPIKey:(NSString *)apiKey accountId:(NSString *)accountId;
- (void)setAPIKey:(NSString *)apiKey accountId:(NSString *)accountId subAccountID:(NSString *)subAccountID subAccountName:(NSString *)subAccountName;
@end
