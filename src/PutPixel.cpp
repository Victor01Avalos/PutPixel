#include "PutPixel.h"

void frameBuffer::setup()
{
	_img.allocate(1024, 768, ofImageType::OF_IMAGE_COLOR_ALPHA);
	clear(ofColor::black);
}

void frameBuffer::update()
{
}

void frameBuffer::draw()
{
	for (int x = 0; x < 1024; x++) {
		putpixel(x, 768 / 2, ofColor::green);
	}
}

void frameBuffer::putpixel(const int & x, const int & y, const ofColor & color)
{
	_img.setColor(x, y, color);
	_img.update();
	_img.draw(ofPoint(0, 0, 0));
}

void frameBuffer::clear(const ofColor & color)
{
	for (int y = 0; y < 768; y++)
		for (int x = 0; x < 1024; x++)
			FASTputpixel(x, y, color);
	_img.update();
	_img.draw(ofPoint(0, 0, 0));
}

void frameBuffer::FASTputpixel(const int & x, const int & y, const ofColor & color)
{
	_img.setColor(x, y, color);
}
