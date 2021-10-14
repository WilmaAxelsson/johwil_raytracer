#pragma once

#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"
#include "Ray.h"
class Triangle
{
private:
	Vertex v0, v1, v2; // Skapa vertices med inte default constructors?
	ColorDbl color;
	Direction normDirection;

public:
	Triangle(Vertex v1, Vertex v2, Vertex v3, ColorDbl c, Direction d);
	ColorDbl getColor() { return color; }
	bool rayIntersection(Ray& ray);
};

