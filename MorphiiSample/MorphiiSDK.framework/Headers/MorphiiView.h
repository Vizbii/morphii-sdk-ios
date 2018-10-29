//
//  MorphiiView.h
//  MorphiiSDK
//
//  Created by Chris K on 7/25/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BasicViewConfiguration.h"
#import "MorphiiData.h"
#import "UsageService.h"
#import "ChangeEventData.h"
#import "RenderEngine.h"


@interface MorphiiView : UIView
@property CGSize project;
@property CGSize morphiiSize;

@property double intensity;
@property double adjustedIntensity;

@property (nonatomic, strong) MorphiiData * morphiiData;
@property (nonatomic, strong) RenderEngine * renderEngine;
@property (nonatomic, strong) ChangeEventData * changeEventData;
@property (nonatomic, strong) UsageService * usage;
@property (nonatomic, strong) BasicViewConfiguration * configuration;
@property (nonatomic, strong) NSString *previousPart;
@property (nonatomic, strong) NSString *partNewest;
@property (nonatomic, strong) UIImage  * blurImage;
@property BOOL shouldBlur;

- (void) setUpMorphii:(Target *)target viewId:(NSString*)viewId morphiiData:(MorphiiData*)morphiiData size:(CGSize)size intensity:(double)intensity configuration:(BasicViewConfiguration*)configuration;
- (void) setUpMorphii:(CGSize)size morphiiData:(MorphiiData*)morphiiData intensity:(double)intensity;
- (void) trackSlider:(UIEvent*)event;
- (UIImage *) getMorphiiImage:(CGSize)size;

@end
