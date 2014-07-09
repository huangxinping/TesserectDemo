//
//  TTShareImageViewController.m
//  TTShareImage
//
//  Created by hxp on 12-7-9.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "TTShareImageViewController.h"
//#import "ShareImage.h"

@interface TTShareImageViewController ()

@end

@implementation TTShareImageViewController
@synthesize cameraImage;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    tesseract = [[Tesseract alloc] initWithDataPath:@"tessdata" language:@"eng"];
//    [tesseract setVariableValue:@"0123456789" forKey:@"tessedit_char_whitelist"];
}

- (void)viewDidUnload
{
    [self setCameraImage:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
        return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
    } else {
        return YES;
    }
}

- (void)scanThread:(UIImage*)image
{
    [tesseract setImage:image];
    [tesseract recognize];
    
    NSString *text = [tesseract recognizedText];
    
    UIAlertView *av = [[UIAlertView alloc] initWithTitle:@"结果" message:text delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil];
    [av show];
    [av release];
    
    self.view.userInteractionEnabled = YES;
}

- (IBAction)convertImage:(id)sender 
{
//    ImageWrapper *greyScale = ShareImage::createImage(cameraImage.image, cameraImage.image.size.width/4, cameraImage.image.size.height/4);
//    ImageWrapper *thredhold = greyScale.image->autoLocalThreshold(); 
//    ImageWrapper *negative = thredhold.image->negative();
////    ImageWrapper *noise = negative.image->removeNoise();
//    cameraImage.image = negative.image->toUIImage();
    
    self.view.userInteractionEnabled = NO;
    [self performSelector:@selector(scanThread:) withObject:cameraImage.image afterDelay:0.10];
}

- (void)dealloc 
{
    [tesseract release];
    [cameraImage release];
    [super dealloc];
}
@end
