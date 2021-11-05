#include "Lightsource.h"

Lightsource::Lightsource()
{    
   
    color = ColorDbl(1.0f, 1.0f, 1.0f);
    material = Material(color, LIGHTSOURCE);
    t1 = Triangle{ p1, p2, p3, material};
    t2 = Triangle{ p2, p4, p3, material};
    lightSource.push_back(t1);
    lightSource.push_back(t2);
 }

