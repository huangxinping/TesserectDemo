//
//  TTShareImageViewController.h
//  TTShareImage
//
//  Created by hxp on 12-7-9.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Tesseract.h"

@interface TTShareImageViewController : UIViewController
{
    Tesseract *tesseract;
}
@property (retain, nonatomic) IBOutlet UIImageView *cameraImage;
- (IBAction)convertImage:(id)sender;

@end
