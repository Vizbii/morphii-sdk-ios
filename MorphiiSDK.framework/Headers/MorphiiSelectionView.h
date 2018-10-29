//
//  MorphiiSelectionView.h
//  MorphiiSDK
//
//  Created by Chris K on 7/25/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MorphiiConfiguration.h"
#import "MorphiiData.h"
#import "Morphii.h"

@protocol MorphiiSelectionViewDelegate <NSObject>
@required
- (void) selectedMorphii:(MorphiiConfiguration *)morphiiConfiguration;
@end



@interface MorphiiContainerView : UIView{
    
}
@property (nonatomic, retain) Morphii *morphii;
@property (nonatomic, retain) MorphiiData *morphiiData;

@end
@interface MorphiiSelectionView : UIView{
    
}
@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;
@property (nonatomic, retain) MorphiiConfiguration *configuration;
@property (nonatomic, retain) id<MorphiiSelectionViewDelegate> delegate;
@property double initialIntensity;
@property CGSize *size;

- (void) setupMorphiis:(MorphiiConfiguration *)configuration initialIntensity:(double)initialIntensity backgroundColor:(UIColor*) backgroundColor delegate:(id<MorphiiSelectionViewDelegate>)delegate;
@end
