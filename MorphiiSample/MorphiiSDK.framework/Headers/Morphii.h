//
//  Morphii.h
//  MorphiiSDK
//
//  Created by Chris K on 7/26/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface Morphii : NSObject
@property (retain, nonatomic) NSString * id;
@property (retain, nonatomic) NSString * name;
@property (retain, nonatomic) NSString * staticUrl;
@property (retain, nonatomic) NSString * dataUrl;
@property (retain, nonatomic) NSString * pngString;
@property (retain, nonatomic) NSString * displayName;
@property (retain, nonatomic) NSDictionary * metaData;
@property (retain, nonatomic) UIImage * morphiiPng;
@property double emoodl;
@property int scaleType;
@property int sequence;
@property int weight;

- (id) init:(NSString *)id name:(NSString *)name scaleType:(int)scaleType staticUrl:(NSString *)staticUrl dataUrl:(NSString *)dataUrl displayName:(NSString *)displayName weight:(int)weight sequence:(int)sequence pngString:(NSString *)pngString metaData:(NSDictionary *)metaData;
@end

@interface MorphiiIndex : NSObject
@property (retain, nonatomic) NSString * id;
@property (retain, nonatomic) NSString * name;
@property (retain, nonatomic) NSString * staticUrl;
@property (retain, nonatomic) NSString * dataUrl;
@property (retain, nonatomic) UIImage * morphiiImage;
@property (retain, nonatomic) NSData * morphiiData;
@property int scaleType;

- (id) init:(NSString *)id name:(NSString *)name staticUrl:(NSString *)staticUrl scaleType:(int)scaleType dataUrl:(NSString *)dataUrl;
- (void) setStatImage:(UIImage*)morphiiImage;
- (void) setMorphiiData:(NSData*)morphiiData;

@end
