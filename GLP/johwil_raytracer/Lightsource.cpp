#include "Lightsource.h"

Lightsource::Lightsource()
{    
   
    color = ColorDbl(1.0f, 1.0f, 1.0f);
    material = Material(color, LIGHTSOURCE);
    t1 = Triangle{ p1, p3, p2, material};
    t2 = Triangle{ p4, p2, p3, material};
    lightSource.push_back(t1);
    lightSource.push_back(t2);
 }

