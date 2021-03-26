#include <iostream>
#include <vector>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBIW_WINDOWS_UTF8
#include <stb_image_write.h>

int main() {
    int W = 1366;
    int H = 768;

    std::vector <uint8_t> pixels(W*H*3);
    for (int y = 0; y < H; y++) {
        int h = W*y;
        for (int x = 0; x < W; x++) {
            int p = (h+x)*3;
            pixels[p] = uint8_t(255 * float(x) / float(W));
            pixels[p + 1] = uint8_t(255 * float(y) / float(H));
            pixels[p + 2] = uint8_t(255 * 0.8);
        }
    }

    stbi_write_png("image_stb.png", W, H, 3, pixels.data(), W*3);
}