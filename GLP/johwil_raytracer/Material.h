#pragma once
#include "ColorDbl.h"
class Material
{
public:
	Material(const ColorDbl c = ColorDbl(0.0f,0.0f,0.0f), const int t = 0);

    bool isType(const int& t) const {
        if  (t==type) return true;
    }

	ColorDbl getColor() { return color; }
	int getType() { return type; }


private:
	ColorDbl color;
	int type;
};

