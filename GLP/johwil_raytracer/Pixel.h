#pragma once
#include "ColorDbl.h"
#include "Ray.h"
class Pixel
{
private:
	ColorDbl color;
	//Ray& ray = Ray(Vertex(0, 0, 0), Vertex(0, 0, 0), ColorDbl(0, 0, 0));
	std::vector<Ray> rayList;
public:
	
	Pixel(ColorDbl c = ColorDbl(0.0,0.0,0.0));
	void addRay(Ray& r);
};

