//
//  MorphiiService.h
//  MorphiiSDK
//
//  Created by Chris K on 7/19/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Project.h"
#import "Constants.h"
#import "BasicViewConfiguration.h"
#import "MorphiiSelectionView.h"
#import "ViewAddEvent.h"
#import "Morphii.h"
#import "MorphiiAPI.h"
#import "MorphiiClasses.h"
#import "ReactionRequestRecord.h"
#import "ReactionService.h"
#import "BasicView.h"
@protocol MorphiiServiceDelegate

@optional
- (void) morphiiSelectionViewAdded:(MorphiiSelectionView *)morphiiSelectionView;
- (void) morphiiBasicViewAdded:(BasicView *)basicView;
- (void) morphiiConfigurationDidFinish:(NSObject *)morphiis;
- (void) morphiiArrayReceived:(NSArray *)morphiis;

@end


@interface MorphiiService : NSObject
{
    id <MorphiiServiceDelegate> serviceDelegate;
}

@property (retain) id <MorphiiServiceDelegate> serviceDelegate;
@property (nonatomic, strong) User *user;
@property (nonatomic, strong) Project *project;
@property BOOL production;
@property (nonatomic, strong) MorphiiService *shared;
@property (nonatomic, strong) NSMutableArray *basicViews;

+ (MorphiiService*) sharedInstance;
- (BOOL) isProduction;
- (void) setAPIKey:(NSString *)apiKey accountId:(NSString *)accountId;
- (void) setAPIKey:(NSString *)apiKey accountId:(NSString *)accountId withSubAccountID:(NSString *)subaccountId andSubAccountName:(NSString *)subaccountName;
- (MorphiiSelectionView *) addSelectionViewWithIntensity:(double)initialIntensity config:(MorphiiConfiguration*)config delegate:(id<MorphiiSelectionViewDelegate>)delegate;
- (void) addSelectionViewWithResponse:(double)initialIntensity config:(MorphiiConfiguration*)config delegate:(id<MorphiiSelectionViewDelegate>)delegate;
- (void) submit:(void (^)(NSArray<ReactionResultRecord*> *results))completion;
- (void) remove:(BasicView *)basicView;
- (BasicView *) addWithContainerView:(UIView*)containerView config:(BasicViewConfiguration*)config delegate:(id<BasicViewDelegate>)delegate;
- (void) addBasicViewWithResponse:(UIView*)containerView config:(BasicViewConfiguration*)config delegate:(id<BasicViewDelegate>)delegate;
- (void) resetWithComment:(BOOL)comment;
- (void) getMorphiisAsArray:(MorphiiConfiguration *)config withSize:(double)size intensity:(double)intensity;

@end
