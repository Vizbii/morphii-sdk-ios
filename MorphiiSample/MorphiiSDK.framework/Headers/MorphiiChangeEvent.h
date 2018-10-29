//
//  MorphiiChangeEvent.h
//  MorphiiSDK
//
//  Created by Chris K on 8/7/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import "MorphiiEvent.h"

@interface MorphiiChangeEvent : MorphiiEvent

- (id)init:(MorphiiData *)morphii andIntensity:(double)intensity;

@end
