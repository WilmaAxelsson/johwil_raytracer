#pragma once
#include "ColorDbl.h"
#include "Ray.h"
#include "definitions.h"

class Pixel
{
private:
	ColorDbl color{};
	Vertex position{};
	std::vector<Ray> rayList;

public:
	~Pixel();
	Pixel(Vertex p = Vertex(0.0f, 0.0f, 0.0f), ColorDbl c = ColorDbl(0.0f, 0.0f ,0.0f));
	void addRay(Ray& r);
	void setColor(ColorDbl c);
	Vertex getPos() { return position; };
	void setpos(Vertex p);
	ColorDbl getColor() {
		return color;
	};
};

