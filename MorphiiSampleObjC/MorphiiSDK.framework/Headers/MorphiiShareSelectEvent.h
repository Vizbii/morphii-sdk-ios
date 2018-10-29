//
//  MorphiiShareSelectEvent.h
//  MorphiiSDK
//
//  Created by Chris K on 8/7/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import "MorphiiEvent.h"

@interface MorphiiShareSelectEvent : MorphiiEvent
@property (nonatomic, strong) NSString *text;

- (id)init:(MorphiiData *)morphii intensity:(double)intensity text:(NSString *)text;
@end
