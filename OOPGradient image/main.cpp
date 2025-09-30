#include <bits/stdc++.h>
using namespace std;

const int maxn = 1024;

struct Pixel {
    uint8_t R, G, B;
};

struct imageRGB {
    Pixel image[maxn][maxn];
};

int main() {
    ofstream outFile("Raboti.ppm");
    int image_width = maxn;
    int image_height = maxn;

    imageRGB img;

    // Center of the image
    double cx = image_width / 2.0;
    double cy = image_height / 2.0;

    // Max distance (corner from center)
    double max_dist = sqrt(cx*cx + cy*cy);

    // Fill the struct with pixel data
    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            double dx = i - cx;
            double dy = j - cy;
            double dist = sqrt(dx*dx + dy*dy);

            double t = dist / max_dist; // normalized [0,1]

            Pixel p;
            p.R = 0;
            p.G = static_cast<uint8_t>(255.0 * t);
            p.B = 0;

            img.image[j][i] = p;
        }
    }

    // Output PPM (P3 format, text-based)
    outFile << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            Pixel &p = img.image[j][i];
            outFile << int(p.R) << " " << int(p.G) << " " << int(p.B) << "\n";
        }
    }
    outFile.close();
    return 0;
}
