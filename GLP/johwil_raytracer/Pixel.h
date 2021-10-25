#pragma once
#include "ColorDbl.h"
#include "Ray.h"
class Pixel
{
private:
	ColorDbl color{};
	Vertex position{};
	//Ray& ray = Ray(Vertex(0, 0, 0), Vertex(0, 0, 0), ColorDbl(0, 0, 0));
	std::vector<Ray> rayList;

public:
	glm::vec3 pixelVec = glm::vec3(0.0f, 0.0f, 0.0f);
	Pixel(Vertex p = Vertex(0.0f, 0.0f, 0.0f), ColorDbl c = ColorDbl(0.0f, 0.0f ,0.0f));
	void addRay(Ray& r);
	void setColor(ColorDbl c);
	Vertex getPos();
	void setpos(Vertex p);
	ColorDbl getColor() {
		return color;
	};
};

