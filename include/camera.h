#ifndef CAMERAH
#define CAMERAH

#include "ray.h"

class camera
{
public:
    camera(int, int);
    ray getRay(float, float);

    int W;
    int H;
    vec3 origin;
    vec3 lowerLeftCorner;
    vec3 horizontal;
    vec3 vertical;
};
#endif