//
//  MorphiiIntensityChangeEvent.h
//  MorphiiSDK
//
//  Created by Chris K on 7/18/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import "MorphiiEvent.h"

@interface MorphiiIntensityChangeEvent : MorphiiEvent
@property double begin;
@property double end;
@property (nonatomic, strong) NSString *partBegin;
@property (nonatomic, strong) NSString *partEnd;

- (id)init:(MorphiiData *)morphii intensity:(double)intensity begin:(double)begin end:(double)end;
- (id)init:(MorphiiData *)morphii intensity:(double)intensity begin:(double)begin end:(double)end partBegin:(NSString *)partBegin partEnd:(NSString *)partEnd;
@end
