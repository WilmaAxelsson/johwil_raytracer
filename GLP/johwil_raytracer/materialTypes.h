#pragma once

// Different materials, we differ them using ints
const int LIGHTSOURCE = 0;
const int LAMBERTIAN = 1;
const int PERFECT_REFL = 2;

//Different ray types
enum RayType{ SHADOW, PRIMARY, SECONDARY, REFLECTION};
 //PRIMARY is the first ray to be sent out, directly from the camera/the eye
// SECONDARY is remaining rays sent out 

