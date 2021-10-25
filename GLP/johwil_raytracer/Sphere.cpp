
#include "Sphere.h"
#include <glm\geometric.hpp>

Sphere::Sphere(Vertex spPos, double r, ColorDbl c)
{
	position = spPos; // spherens mittpunkt
	radius = r;
	color = c;
}

bool Sphere::rayIntersection(Ray& r)
{
    // till att börja med att se om ray skär i sphere (alltså kommer ray hamna innanför spheresn volume)
	
   // (ray direction - sphere mittpunkt ) < radius
	// https://viclw17.github.io/2018/07/16/raytracing-ray-sphere-intersection/
    //glm::vec3 rayDir = glm::vec3{r.direction.x, r.direction.y,r.direction.z}
    
    Vertex oc = r.getStartingP() - position;
    glm::vec3 glm_oc = glm::vec3{oc.x, oc.y, oc.z};
    float a = glm::dot(r.glmDirection, r.glmDirection);
    float b = 2.0 * dot(glm_oc, r.glmDirection);
    float c = dot(glm_oc, glm_oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) return false;
    
    /*
    If discriminant<0, the line of the ray does not intersect the sphere (missed);
    If discriminant=0, the line of the ray just touches the sphere in one point (tangent);
    If discriminant>0, the line of the ray touches the sphere in two points (intersected).
    */ 
        return true;
}
