#include "ray.h"

ray::ray(){};

ray::ray(const vec3 &a, const vec3 &b)
{
    A = a;
    B = b;
}
