#ifndef HITABLEH
#define HITABLEH

#include "ray.h"

struct tHitRecord
{
    float t;
    vec3 p;
    vec3 normal;
};

class hitable
{
public:
    virtual bool hit(const ray &r, float t_min, float t_max, tHitRecord &rec) const = 0;
};

#endif