#include "Pixel.h"


void Pixel::setColor(ColorDbl c)
{
	color = c;
}

Pixel::Pixel(ColorDbl c)
{
	color = c;
	
}

void Pixel::addRay(Ray& r) //
{
	rayList.push_back(r);
}

