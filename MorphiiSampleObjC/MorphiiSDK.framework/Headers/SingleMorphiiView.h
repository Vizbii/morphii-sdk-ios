//
//  SingleMorphiiView.h
//  MorphiiSDK
//
//  Created by Chris K on 9/5/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MorphiiView.h"

@interface SingleMorphiiView : UIView

@property (weak, nonatomic) IBOutlet MorphiiView *morphiiView;
@property (weak, nonatomic) IBOutlet UILabel *nameLabel;
@property (weak, nonatomic) IBOutlet UISlider *horizontalSlider;
@property (weak, nonatomic) IBOutlet UISlider *verticalSlider;

@property (strong, nonatomic) NSString *viewId;

@end
