#include <iostream>

#include <color.hpp>
#include <vec3.hpp>
#include <ray.hpp>

static constexpr int IMAGE_WIDTH = 256;
static constexpr int IMAGE_HEIGHT = 256;

int main() {
    std::cout << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";

    for (int j = 0; j < IMAGE_HEIGHT; j++) {
        std::clog << "\rScanlines remaining: " << (IMAGE_HEIGHT - j) << ' ' << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; i++) {
            auto r = static_cast<double>(i) / static_cast<double>(IMAGE_WIDTH - 1);
            auto g = static_cast<double>(j) / static_cast<double>(IMAGE_HEIGHT - 1);
            auto b = 0.0;

            auto pixel_color = color{r, g, b};
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.                          \n";
}
