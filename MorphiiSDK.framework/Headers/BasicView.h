//
//  BasicView.h
//  MorphiiSDK
//
//  Created by Chris K on 7/20/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "User.h"
#import "Project.h"
#import "BasicViewConfiguration.h"
#import "MorphiiView.h"
#import "ReactionRequestRecord.h"
@class MorphiiService;

@interface  MorphiiObject : NSObject
@property BOOL selected;
@property int weight;

- (id) init:(BOOL)selected weight:(int)weight;
@end

@interface  CommentObject : NSObject
@property BOOL required;
@property int length;
@property (nonatomic, strong) NSString *value;

- (id) init:(BOOL)required length:(int)length value:(NSString*)value;
@end

@interface  BasicViewObject : NSObject
@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) MorphiiObject *morphii;
@property (nonatomic, strong) CommentObject *comment;

- (id) init:(NSString*)id morphii:(MorphiiObject*)morphii comment:(CommentObject*)comment;
@end

@protocol BasicViewDelegate <NSObject>
@required
- (void) commentChange:(NSString *)type commentRequiredValid:(BOOL)commentRequiredValid view:(BasicViewObject *)view;
@end


@interface BasicView : UIView
@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSString *viewId;
@property (nonatomic, strong) NSString *placeholder;
@property (nonatomic, strong) UIView * morphiiLayout;
@property (nonatomic, strong) NSArray * morphiiViews;
@property (nonatomic, strong) NSArray * morphiiChoices;
@property (nonatomic, strong) User *user;
@property (nonatomic, strong) Project *project;
@property (nonatomic, strong) BasicViewConfiguration *configuration;
@property (retain, nonatomic) id <BasicViewDelegate> delegate;
@property (nonatomic, strong) MorphiiView *currentMorphiiView;
@property (nonatomic, strong) MorphiiService * shared;
@property (nonatomic, strong) UITextView *commentTextView;
@property (nonatomic, strong) UISlider *currentSlider;

@property BOOL *production;
@property BOOL morphiiSelected;
@property BOOL isSubmitted;


- (id) init:(CGRect)frame configuration:(BasicViewConfiguration*)configuration delegate:(id<BasicViewDelegate>)delegate;
- (void) resetWithComment:(BOOL)comment;
- (ReactionRequestRecord *) getReactionRequestRecord;

@end
