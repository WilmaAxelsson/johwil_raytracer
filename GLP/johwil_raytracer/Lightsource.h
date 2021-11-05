#pragma once
#include "Vertex.h"
#include "ColorDbl.h"
#include <vector>
#include "Triangle.h"
class Lightsource
{
    // Gör en liten ljuspunkt, med två triaglar som tillsamans bildar en fyrkant (en liten pointlight)

public:
    Lightsource();
    std::vector<Triangle> getLight() { return lightSource; }
private:
    std::vector<Triangle> lightSource;
    ColorDbl color;
    Material material;

    // punkter till tianglar   
    Vertex p1{ 1.5f, 2.0f, 4.99f };
    Vertex p2{ -1.5f, 2.0f, 4.99f };
    Vertex p3{ 1.5f, -2.0f, 4.99f };
    Vertex p4{ -1.5f, -2.0f, 4.99f };
    Triangle t1, t2;
    
        
};

