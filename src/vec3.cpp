#include "vec3.h"
#include <math.h>

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
