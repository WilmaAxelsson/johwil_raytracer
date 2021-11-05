#pragma once


#include <vector>
#include "Vertex.h"
#include "ColorDbl.h"
#include "Direction.h"
#include "Material.h"
#include "materialTypes.h"

class Ray
{
public:
	Vertex startingPoint;
	Vertex endingPoint;
	Direction direction; // Ray needs direction
	std::vector<Vertex> vertexList;
	ColorDbl color;
	Material material;
	glm::vec3 glmDirection;


	Direction objectNormal;

	Vertex getStartingP() { return startingPoint; }
	Vertex getEndingP() { return endingPoint; }
	Vertex getDirection() { return direction; }

	Direction getObjectNormal() { return objectNormal; }
	void setObjectNormal(Direction objN) { 
		objectNormal = objN; 
		objectNormal.glmDirection = glm::vec3(objN.x, objN.y, objN.z); }

	ColorDbl getColor() { return color; }
	void setColor(ColorDbl newColor) { color = newColor; }

	Material getMaterial() { return material; }
	void setMaterial(Material newMaterial) { material = newMaterial; color = newMaterial.getColor(); }

	void setEndingP(Vertex e) { endingPoint = e; }
	//Ray(Vertex sP, Vertex eP, ColorDbl c);
	Ray(Vertex sP = Vertex(0.0f,0.0f,0.0f), Direction dir = Direction(0.0f,0.0f,0.0f), Material m = Material((0.0f,0.0f,0.0f), 0));
};

