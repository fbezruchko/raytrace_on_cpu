#ifndef RAYH
#define RAYH

#include "vec3.h"

class ray
{
public:
    ray();
    ~ray() {};
    ray(const vec3 &a, const vec3 &b);

    vec3 getOrigin() const { return A; }
    vec3 getDirection() const { return B; }
    
    vec3 pointAtParameter(float t) const { return A + t * B; }

    vec3 A;
    vec3 B;
};

#endif // !RAYH
