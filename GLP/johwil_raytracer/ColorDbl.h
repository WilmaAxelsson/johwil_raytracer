#pragma once
#include "Vertex.h"

class ColorDbl
{

public:
	ColorDbl(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	float red, green, blue;
	ColorDbl operator+=(ColorDbl rhs) {
		return ColorDbl(red += rhs.red, green += rhs.green, blue += rhs.blue);
	}
	ColorDbl operator/(float y) {
		return ColorDbl(red / y, green / y, blue / y);
	}
};

