#pragma once

#include "definitions.h"
#include "ColorDbl.h"
#include <vector>
#include "Triangle.h"
class Lightsource
{
    // Make a small point light, with two triangles that form a square

public:
    Lightsource();
    std::vector<Triangle> getLight() { return lightSource; }
private:
    std::vector<Triangle> lightSource;
    ColorDbl color;
    Material material;

    //Points for point light  
    Vertex p1{ 6.5f, 0.5f, 4.95f };
    Vertex p2{ 5.5f, 0.5f, 4.95f };
    Vertex p3{ 6.5f, -0.5f, 4.95f };
    Vertex p4{ 5.5f, -0.5f, 4.95f };
    Triangle t1, t2;
    
        
};

