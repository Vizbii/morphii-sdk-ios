//
//  Utilities.h
//  MorphiiSDK
//
//  Created by Chris K on 8/27/18.
//  Copyright © 2018 Xtern Software, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface Utilities : NSObject


+ (NSString *) iso8601:(NSDate *) date;

+ (UIImage *) croppedImage:(UIImage *)image bounds:(CGRect)bounds;

+ (UIImage *) imageResize:(UIImage *)image size:(CGSize)size;

+ (UIColor *) colorWithHexString: (NSString *) hexString;


+ (double) roundTo:(double)number;
+ (NSString *) roundDoubleToString:(double)number;

@end
