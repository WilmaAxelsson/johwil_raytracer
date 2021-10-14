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

	Vertex getStartingP() { return startingPoint; }
	Vertex getEndingP() { return endingPoint; }
	ColorDbl getColor() { return color; }
	void setColor(ColorDbl newColor) { color = newColor; }

	Ray(Vertex sP = Vertex(0, 0, 0), Vertex eP = Vertex(0, 0, 0), ColorDbl c = ColorDbl(0, 0, 0));
};

