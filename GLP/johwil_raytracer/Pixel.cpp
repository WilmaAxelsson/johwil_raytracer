#include "Pixel.h"


Pixel::Pixel(ColorDbl c)
{
	color = c;
	
}

void Pixel::addRay(Ray& r)
{
	rayList.push_back(r);
}

