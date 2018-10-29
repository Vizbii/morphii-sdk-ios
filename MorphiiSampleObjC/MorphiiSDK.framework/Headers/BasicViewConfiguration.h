//
//  BasicViewConfiguration.h
//  MorphiiSDK
//
//  Created by Chris K on 7/23/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MorphiiConfiguration.h"
#import "ApplicationInformation.h"
#import "Target.h"
#import "Project.h"
#import "Comment.h"
#import "Options.h"
#import "User.h"

@interface BasicViewConfiguration : NSObject
@property (nonatomic, retain) MorphiiConfiguration *morphiiConfig;
@property (nonatomic, retain) Target *target;
@property (nonatomic, retain) Project *project;
@property (nonatomic, retain) Comment *comment;
@property (nonatomic, retain) Options *options;
@property (nonatomic, retain) User *user;
@property (nonatomic, retain) ApplicationInformation *application;

@property BOOL showSlider; //Added July 31st, 2018
@property BOOL showSliderVertical; //Added July 31st, 2018

- (id) initWithMorphiiConfig:(MorphiiConfiguration*)morphiiConfig target:(Target*)target project:(Project*)project comment:(Comment*)comment options:(Options*)options user:(User*)user;
- (NSDictionary*) json;
@end
