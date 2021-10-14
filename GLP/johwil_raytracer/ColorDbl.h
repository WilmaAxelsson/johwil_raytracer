#pragma once
#include "Vertex.h"

class ColorDbl
{

public:
	ColorDbl(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	float red, blue, green;
	ColorDbl operator+=(ColorDbl rhs) {
		return ColorDbl(red += rhs.red, blue - rhs.blue, green - rhs.green);
	}
};

