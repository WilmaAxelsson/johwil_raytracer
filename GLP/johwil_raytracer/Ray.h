#pragma once


#include <vector>
#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"

class Ray
{
public:
	Vertex startingPoint;
	Vertex endingPoint;
	Direction direction; // Ray needs direction
	std::vector<Vertex> vertexList;
	ColorDbl color;
	glm::vec3 glmDirection;

	Vertex getStartingP() { return startingPoint; }
	Vertex getEndingP() { return endingPoint; }
	Vertex getDirection() { return endingPoint - startingPoint; }

	ColorDbl getColor() { return color; }
	void setColor(ColorDbl newColor) { color = newColor; }
	void setEndingP(Vertex e) { endingPoint = e; }
	//Ray(Vertex sP, Vertex eP, ColorDbl c);
	Ray(Vertex sP = Vertex(0.0f,0.0f,0.0f), Direction dir = Direction(0.0f,0.0f,0.0f), ColorDbl c = ColorDbl(0.0f,0.0f,0.0f));
};

