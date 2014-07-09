//
//  ColorConvert.h
//  ShareImage
//
//  Created by hxp on 12-7-9.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef ShareImage_ColorConvert_h
#define ShareImage_ColorConvert_h

static void fromYCbCrToRGB(unsigned char Y,
                           unsigned char Cb,
                           unsigned char Cr,
                           unsigned char &R,
                           unsigned char &G,
                           unsigned char &B);

static void fromRGBToYCbCr(unsigned char R,  
                           unsigned char G,  
                           unsigned char B,  
                           unsigned char &Y,  
                           unsigned char &Cb,  
                           unsigned char &Cr); 

static void fromYCbCrToHSI(unsigned char Y,  
                           unsigned char Cb,  
                           unsigned char Cr,  
                           unsigned char &H,  
                           unsigned char &S,  
                           unsigned char &I); 

static void fromHSIToYCbCr(unsigned char H,  
                           unsigned char S,  
                           unsigned char I,  
                           unsigned char &Y,  
                           unsigned char &Cb,  
                           unsigned char &Cr);

static void fromYCbCrToTSL(unsigned char Y,  
                           unsigned char Cb,  
                           unsigned char Cr,  
                           unsigned char &T,  
                           unsigned char &S,  
                           unsigned char &L);

static void fromTSLToYCbCr(unsigned char T,  
                           unsigned char S,  
                           unsigned char L,  
                           unsigned char &Y,  
                           unsigned char &Cb,  
                           unsigned char &Cr);

static void fromTSLToRGB(unsigned char t,  
                         unsigned char s,  
                         unsigned char l,  
                         unsigned char& r,  
                         unsigned char& g,  
                         unsigned char& b);

#endif
