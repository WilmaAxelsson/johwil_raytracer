#pragma once


#include <vector>
#include "ColorDbl.h"
#include "definitions.h"
#include "Material.h"
#include "materialTypes.h"

class Ray
{
private: 
	  Vertex startingPoint;
	   Vertex endingPoint;
	   Direction direction;
	   std::vector<Vertex> vertexList;
	   ColorDbl color;
	   Material material;
	   Direction objectNormal;
	   RayType rayType;
public:
	

	Ray();
	~Ray();
	Vertex getStartingP() { return startingPoint; }
	Vertex getEndingP() { return endingPoint; }
	Vertex getDirection() { return direction; }

	Direction getObjectNormal() { return objectNormal; }
	void setObjectNormal(Direction objN) { 
		objectNormal = objN;  }

	ColorDbl getColor() { return color; }
	void setColor(ColorDbl newColor) { color = newColor; }

	Material getMaterial() { return material; }
	void setMaterial(Material newMaterial) { material = newMaterial; color = newMaterial.getColor(); }

	RayType getRayType() { return rayType; }

	void setEndingP(Vertex e) { endingPoint = e; }

	Ray(Vertex sP = Vertex(0.0f,0.0f,0.0f), Direction dir = Direction(0.0f,0.0f,0.0f), RayType rt = SECONDARY);
};

