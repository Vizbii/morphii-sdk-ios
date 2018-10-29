//
//  MorphiiConfiguration.h
//  MorphiiSDK
//
//  Created by Chris K on 7/17/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface  MorphiiDetail : NSObject
@property (strong, nonatomic) NSString * id;
@property (strong, nonatomic) NSString * name;
@property (strong, nonatomic) NSString * displayName;
@property int weight;

- (id) init:(NSString *)id name:(NSString *)name weight:(int)weight;
- (id) init:(NSString *)id name:(NSString *)name displayName:(NSString *)displayName weight:(int)weight;
- (NSDictionary *)json;
@end

@interface MorphiiConfiguration : NSObject
@property (strong, nonatomic) NSMutableArray<MorphiiDetail*> * morphiiDetails;
@property BOOL showName;


- (id) init:(BOOL)showName;
- (NSArray *)ids;
- (void) addWithID:(NSString*)id name:(NSString*)name weight:(int)weight;
- (void) addWithID:(NSString*)id name:(NSString*)name displayName:(NSString*)displayName weight:(int)weight;
- (int) weightById:(NSString*)id;
- (NSString *) displayNameById:(NSString*)id;
- (NSDictionary *)json;
- (NSArray *)detailsJSONArray;
@end


