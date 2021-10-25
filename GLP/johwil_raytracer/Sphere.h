#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include "Ray.h"
class Sphere
{
private:
	Vertex position = Vertex{ 0.0f, 0.0f, 0.0f };
	double radius = 0.0f;
	ColorDbl color = ColorDbl{ 0.0f, 0.0f, 0.0f };

public:
	Sphere(Vertex spPos = Vertex{ 0.0f, 0.0f, 0.0f }, double r = 0.0, ColorDbl c = ColorDbl{ 0.0f, 0.0f, 0.0f });
    bool rayIntersection(Ray& r);



};

