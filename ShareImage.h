/*****************优化列表************************
 1、去掉Objc包装c++函数，优化调用效率
 2、autoLocalThresHold函数调整判断值
 3、去掉一些重复的逻辑算法
************************************************/

/*****************算法原理************************
 http://en.wikipedia.org/wiki/Canny_edge_detector
 http://fiji.sc/wiki/index.php/Auto_Local_Threshold
 http://en.wikipedia.org/wiki/Gaussian_blur
 http://en.wikipedia.org/wiki/Image_histogram
 ************************************************/

#import <UIKit/UIImage.h>
#include <vector>
#include "ColorConvert.h"

class ShareImage;
@interface ImageWrapper : NSObject 
{
	ShareImage *image;
	bool ownsImage;
}

@property(assign,nonatomic)ShareImage *image;
@property(assign,nonatomic)bool ownsImage;
+ (ImageWrapper*)imageWithCPPImage:(ShareImage*)theImage;

@end

class ImagePoint 
{
public:
	short x,y;
	inline ImagePoint(short xpos, short ypos) 
    {
		x = xpos;
		y = ypos;
	}
	inline ImagePoint(int xpos, int ypos) 
    {
		x = xpos;
		y = ypos;
	}
	inline ImagePoint(const ImagePoint &other) 
    {
		x = other.x;
		y = other.y;
	}
	inline ImagePoint() 
    {
		x = 0; y = 0;
	}
};

class ShareImage 
{
private:
	uint8_t *m_imageData;
	uint8_t **m_yptrs;
	int m_width;
	int m_height;
	bool m_ownsData;
	ShareImage(ImageWrapper *other, int x1, int y1, int x2, int y2);
	ShareImage(int width, int height);
	ShareImage(uint8_t *imageData, int width, int height, bool ownsData=false);
	ShareImage(UIImage *srcImage, int width, int height, CGInterpolationQuality interpolation, bool imageIsRotatedBy90degrees=false);
	void initYptrs();
public:
	static ImageWrapper *createImage(uint8_t *imageData, int width, int height, bool ownsData=false);
	static ImageWrapper *createImage(UIImage *srcImage, int width, int height, bool imageIsRotatedBy90degrees=false);
	ImageWrapper* autoLocalThreshold();
    ImageWrapper *negative();
    ImageWrapper *removeNoise(int noiseWidth=5,int noiseMarginal=25);
	ImageWrapper *rotate(int angle);
	ImageWrapper *resize(int newX, int newY);
	UIImage *toUIImage();
	~ShareImage() 
    {
		if(m_ownsData)
			free(m_imageData);
		delete m_yptrs;
	}
	inline uint8_t* operator[](const int rowIndex) 
    {
		return m_yptrs[rowIndex];
	}
	inline int getWidth() 
    {
		return m_width;
	}
	inline int getHeight() 
    {
		return m_height;
	}
};

inline bool sortByX1(const ImagePoint &p1, const ImagePoint &p2) 
{
	if(p1.x == p2.x) return p1.y<p2.y;
	return p1.x<p2.x;
}

inline bool sortByY1(const ImagePoint &p1, const ImagePoint &p2) 
{
	if(p1.y == p2.y) return p1.x<p2.x;
	return p1.y<p2.y;
}

