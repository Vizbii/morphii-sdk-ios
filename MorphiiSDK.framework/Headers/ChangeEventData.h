//
//  ChangeEventData.h
//  MorphiiSDK
//
//  Created by Chris K on 8/2/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface Panning : NSObject
@property BOOL directionChange;
@property double value;
@property int direction;

- (id)init:(BOOL)directionChange value:(double)value direction:(int)direction;
@end

@interface ChangeEventData : NSObject
@property double intensity;
@property double previousIntensity;
@property (strong, nonatomic) Panning * panning;


- (id)init:(double)intensity previousIntensity:(double)previousIntensity;
- (void)updatePanning:(BOOL)directionChange value:(double)value direction:(int)direction;
@end


