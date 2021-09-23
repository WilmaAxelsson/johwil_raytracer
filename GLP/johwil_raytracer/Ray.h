#pragma once


#include <vector>
#include "Vertex.h"
#include "ColorDbl.h"

class Ray
{
public:
	Vertex startingPoint;
	Vertex endingPoint;
	//Triangle& triangle;
	std::vector<Vertex> vertexList;
	ColorDbl color;

	Ray(Vertex sP = Vertex(0, 0, 0), Vertex eP = Vertex(0, 0, 0), ColorDbl c = ColorDbl(0, 0, 0));
};

