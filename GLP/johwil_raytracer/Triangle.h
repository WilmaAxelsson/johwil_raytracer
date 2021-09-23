#pragma once

#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"
#include "Ray.h"
class Triangle
{
private:
	Vertex vex1, vex2, vex3; // Skapa vertices med inte default constructors?
	ColorDbl color;
	Direction normDirection;

public:
	Triangle(Vertex v1, Vertex v2, Vertex v3, ColorDbl c, Direction d);
	void rayIntersection(Ray ray);
};

