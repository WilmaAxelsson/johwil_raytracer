
#include "Sphere.h"
#include <glm\geometric.hpp>


Sphere::Sphere() = default;

Sphere::~Sphere() = default;


Sphere::Sphere(Vertex spPos, float r, Material m)
{
	position = spPos; // The spheres midpoint
	radius = r;
	material = m;
    color = m.getColor();
}

bool Sphere::rayIntersection(Ray& r)
{
    
    float minimumDistance = 1000;
    Vertex tempIntersection;
    float d1, d2;
   // (Ray direction - sphere midpoint ) < radius
	// https://viclw17.github.io/2018/07/16/raytracing-ray-sphere-intersection/
    
    Vertex oc = r.getStartingP() - position;
    float a = (float)dot(r.getDirection(), r.getDirection());
    float b = 2.0f * (float)dot(oc, r.getDirection());
    float c = (float)dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) return false; //  If discriminant<0, the line of the ray does not intersect the sphere (missed);
    
    //One solution, if discriminant=0 the line of the ray just touches the sphere in one point (tangent);
    else if (discriminant < DBL_EPSILON) {
        d1 = -(b / 2.0f);
        tempIntersection = r.getStartingP() + d1 * r.getDirection();
    }
    //Two solutions, if discriminant>0, the line of the ray touches the sphere in two points (intersected).
    else {
        d1 = -(b / 2.0f) + sqrt(pow((b / 2.0f), 2) - a * c);
        d2 = -(b / 2.0f) - sqrt(pow((b / 2.0f), 2) - a * c);

        if (d2 > 0.0f) {
            tempIntersection = r.getStartingP() + d2 * r.getDirection();
        }
        else if (d1 > 0.0f) {
            tempIntersection = r.getStartingP() + d1 * r.getDirection();
        }
        else return false;
    }

    if (glm::length(tempIntersection - r.getStartingP()) < minimumDistance) {
        minimumDistance = glm::length(tempIntersection - r.getStartingP());
        Direction normal = glm::normalize(tempIntersection - position);
        r.setObjectNormal(normal);
        r.setColor(getColor());
        r.setEndingP(tempIntersection + normal * 0.001f);
        r.setMaterial(getMaterial());
    }

    return true;
}
