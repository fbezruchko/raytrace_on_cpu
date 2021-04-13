#include "camera.h"

camera::camera(int W, int H)
{
    this->W = W;
    this->H = H;
    lowerLeftCorner = vec3(-W / 2.0f, -H / 2.0f, -H / 2.0f);
    horizontal = vec3((float)W, 0.0f, 0.0f);
    vertical = vec3(0.0f, (float)H, 0.0f);
    origin = vec3(0.0f, 0.0f, 0.0f);
}

ray camera::getRay(float u, float v)
{
    return ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}