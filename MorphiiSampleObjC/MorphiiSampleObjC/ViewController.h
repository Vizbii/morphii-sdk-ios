//
//  ViewController.h
//  MorphiiSampleObjc
//
//  Created by Chris K on 9/25/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MorphiiSDK/MorphiiSDK.h>

@interface ViewController : UIViewController <MorphiiSelectionViewDelegate, MorphiiServiceDelegate, BasicViewDelegate, UICollectionViewDelegate, UICollectionViewDataSource>
@property (nonatomic, strong) NSString *jwt;
@property (nonatomic, strong) NSString *apiKey;
@property (nonatomic, strong) NSString *sessionID;
@property (nonatomic, strong) NSArray *morphiiArray;
@property (nonatomic, strong) BasicViewConfiguration * config;
@property (weak, nonatomic) IBOutlet UIView *selectionView;
@property (weak, nonatomic) IBOutlet UIView *containerView;
@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;
- (IBAction)submitAction:(id)sender;
- (IBAction)resetAction:(id)sender;

@end
