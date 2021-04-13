#include "vec3.h"
#include <math.h>
#include <cstdlib>

inline float random_float() {
    // Returns a random real in [0,1).
    return (float)rand() / (RAND_MAX + 1.0f);
}

inline float random_float(float min, float max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_float();
}

vec3::vec3() {}
vec3::vec3(float e0, float e1, float e2)
{
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}

float vec3::length() { return (float)sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
float vec3::lengthSqr() { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

void vec3::makeUnitVector()
{
    float k = 1.0f / (float)sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
}

vec3 vec3::random()
{
    return vec3(random_float(), random_float(), random_float());
}

vec3 vec3::random(float min, float max)
{
    return vec3(random_float(min, max), random_float(min, max), random_float(min, max));
}

vec3 vec3::randomInUnitSphere() {
    while (true) {
        auto p = vec3::random(-1,1);
        if (p.lengthSqr() >= 1) continue;
        return p;
    }
}
