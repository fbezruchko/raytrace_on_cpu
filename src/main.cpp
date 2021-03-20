#include <iostream>
#include <vector>

using namespace std;

int main() {
    int W = 720;
    int H = 480;

    cout << "P3\n" << W << " " << H << "\n255\n";
    vector < vector <int> > pixels(W*H);
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            int w = W*y;
            pixels[w + x].resize(3);
            pixels[w + x][0] = int(255 * float(x) / float(W));
            pixels[w + x][1] = int(255 * float(y) / float(H));
            pixels[w + x][2] = int(255 * 0.8);
        }
    }

    for (int y = H-1; y >= 0; y--) {
        for (int x = 0; x < W; x++) {
            int w = W*y;
            cout << pixels[w + x][0] << " " << pixels[w + x][1] << " " << pixels[w + x][2] << "\n";
        }
    }

}