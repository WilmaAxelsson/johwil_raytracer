#include "Pixel.h"


Pixel::~Pixel() = default;

Pixel::Pixel(Vertex p, ColorDbl c)
{
	position = p;
	color = c;

}

void Pixel::setColor(ColorDbl c)
{
	color = c;
}


void Pixel::setpos(Vertex p) {
	position = p;
}

void Pixel::addRay(Ray& r) 
{
	rayList.push_back(r);
}

