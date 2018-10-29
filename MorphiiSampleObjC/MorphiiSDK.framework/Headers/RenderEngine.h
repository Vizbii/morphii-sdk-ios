//
//  RenderEngine.h
//  MorphiiSDK
//
//  Created by Chris K on 8/13/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MorphiiData.h"
#import <GLKit/GLKit.h>


@interface PPoint : NSObject
@property (nonatomic, strong) NSNumber * x;
@property (nonatomic, strong) NSNumber * y;
@end

@interface Curve : NSObject
@property int index;
@property (nonatomic, strong) NSNumber * x1;
@property (nonatomic, strong) NSNumber * y1;
@property (nonatomic, strong) NSNumber * x2;
@property (nonatomic, strong) NSNumber * y2;
@property (nonatomic, strong) NSNumber * x;
@property (nonatomic, strong) NSNumber * y;
@end

@interface Segment : NSObject
@property (nonatomic, strong) NSString * key;
@property (nonatomic, strong) NSObject * color;
@property (nonatomic, strong) NSArray  * curvs;
@property (nonatomic, strong) PPoint  * st;
@end

@interface RangeStruct : NSObject
@property (nonatomic, strong) NSString * key;
@property double lower;
@property double upper;

- (id) init:(NSString*)key lower:(double)lower upper:(double)upper;
@end

@interface RenderResults : NSObject
@property (nonatomic, strong) NSString * partName;
@property (nonatomic, strong) NSArray  * parts;
@property (nonatomic, strong) UIImage  * blurImage;
@property double intensity;

- (id) init:(NSString*)partName parts:(NSArray *)parts intensity:(double)intensity;
- (id) init:(NSString*)partName parts:(NSArray *)parts intensity:(double)intensity blurImage:(UIImage *)blurImage;

@end

@interface RenderEngine : NSObject
@property (nonatomic, strong) NSDictionary * anchorDict;
@property (nonatomic, strong) NSDictionary * deltasDict;
@property (nonatomic, strong) NSDictionary * deltaDict;
@property (nonatomic, strong) CIContext * contextCI;
@property (nonatomic, strong) MorphiiData * morphiiData;
@property (nonatomic, strong) GLKView * viewForImage;
@property (nonatomic, strong) UIView * parentView;

@property double intensity;
@property int version;
@property BOOL isForImage;

- (id) init:(MorphiiData *)morphiiData intensity:(double)intensity;
- (id) init:(MorphiiData *)morphiiData intensity:(double)intensity cicontext:(CIContext*)cicontext morphiiView:(UIView *)parentView viewForImage:(GLKView*)viewForImage;
- (RenderResults *) render:(CGContextRef)context bounds:(CGRect)bounds andScale:(CGPoint)scale;
@end
