#include <iostream>
#include <vector>
#include "vec3.h"
#include "ray.h"
#include "camera.h"
#include "sphere.h"
#include "hitableList.h"
#include <limits>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBIW_WINDOWS_UTF8
#include <stb_image_write.h>

vec3 color(const ray &r, hitable *world, int depth)
{
    // tHitRecord rec;
    // if (world->hit(r, 0.0f, std::numeric_limits<float>::max(), rec))
    // {
    //     return 0.5f * vec3(rec.normal.x() + 1.0f, rec.normal.y() + 1.0f, rec.normal.z() + 1.0f);
    // }
    // else
    // {
    //     vec3 unitDirection = unitVector(r.getDirection());
    //     float t = 0.5f * (unitDirection.y() + 1.0f);
    //     return (1.0f - t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
    // }

    tHitRecord rec;

    if (depth <= 0) return vec3(0.0f, 0.0f, 0.0f);

    if (world->hit(r, 0.0001f, std::numeric_limits<float>::max(), rec)) 
    {
        vec3 target = rec.p + rec.normal + unitVector(vec3::randomInUnitSphere());
        return 0.5 * color(ray(rec.p, target - rec.p), world, depth-1);
    }

    vec3 unitDirection = unitVector(r.getDirection());
    float t = 0.5f * (unitDirection.y() + 1.0f);
    return (1.0f-t) * vec3(1.0f, 1.0f, 1.0f) + t * vec3(0.5f, 0.7f, 1.0f);
}

std::vector<uint8_t>* Render(camera* cam, hitable *world)
{
    int W = cam->W;
    int H = cam->H;
    std::vector<uint8_t> *pixels = new std::vector<uint8_t>;
    pixels->resize(W * H * 3);
    int max_depth = 50;

    for (int p = 0; p < W * H; p++)
    {
        float v = float(H - (p / W)) / float(H);
        float u = float(p % W) / float(W);
        vec3 col = color(cam->getRay(u, v), world, max_depth);

        (*pixels)[p*3] = uint8_t(255 * sqrt(col.r()));
        (*pixels)[p*3 + 1] = uint8_t(255 * sqrt(col.g()));
        (*pixels)[p*3 + 2] = uint8_t(255 * sqrt(col.b()));
    }

    return pixels;
}

void Render(camera* cam, hitable *world, const char *fileName)
{
    int W = cam->W;
    int H = cam->H;
    int max_depth = 50;

    std::vector<uint8_t> pixels(W * H * 3);
    for (int p = 0; p < W * H; p++)
    {
        float v = float(H - (p / W)) / float(H);
        float u = float(p % W) / float(W);
        vec3 col = color(cam->getRay(u, v), world, max_depth);
        pixels[p*3] = uint8_t(255 * sqrt(col.r()));
        pixels[p*3 + 1] = uint8_t(255 * sqrt(col.g()));
        pixels[p*3 + 2] = uint8_t(255 * sqrt(col.b()));
    }

    stbi_write_png(fileName, W, H, 3, pixels.data(), W * 3);
}

int main()
{
    int W = 1920;
    int H = 1080;

    hitable *list[2];
    list[0] = new sphere(vec3(0, 0, -1), 0.5);
    list[1] = new sphere(vec3(0, -100.5, -1), 100);
    hitable *world = new hitableList(list, 2);

    camera cam(W, H);

    Render(&cam, world, "image_stb.png");
}