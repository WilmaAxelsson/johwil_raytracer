#include "Pixel.h"


Pixel::Pixel(Vertex p, ColorDbl c)
{
	position = p;
	color = c;
	pixelVec = glm::vec3(p.x, p.y, p.z);

}

void Pixel::setColor(ColorDbl c)
{
	color = c;
}

Vertex Pixel::getPos()
{
	return position;	
}

void Pixel::setpos(Vertex p) {
	position = p;
}

void Pixel::addRay(Ray& r) //
{
	rayList.push_back(r);
}

