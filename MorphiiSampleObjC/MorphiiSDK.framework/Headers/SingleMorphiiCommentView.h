//
//  SingleMorphiiCommentView.h
//  MorphiiSDK
//
//  Created by Chris K on 9/5/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MorphiiView.h"
#import "BasicView.h"

@interface SingleMorphiiCommentView : UIView<UITextViewDelegate>


@property (weak, nonatomic) IBOutlet UISlider *verticalSlider;
@property (weak, nonatomic) IBOutlet UILabel *commentTitleLabel;
@property (weak, nonatomic) IBOutlet UITextView *commentTextView;
@property (weak, nonatomic) IBOutlet UILabel *nameLabel;
@property (weak, nonatomic) IBOutlet MorphiiView *morphiiView;
@property (weak, nonatomic) IBOutlet UISlider *horizontalSlider;

@property (strong,nonatomic) BasicView * basicView;
@property (strong,nonatomic) NSString * placeHolder;
@property (strong,nonatomic) NSString * viewId;
@property BOOL shouldCallDelegate;


@end
