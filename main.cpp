#include <cmath>
#include <iostream>

#include <color.hpp>
#include <hittable.hpp>
#include <ostream>
#include <ray.hpp>
#include <sphere.hpp>
#include <vec3.hpp>

auto ray_color(ray const &r) -> color {
  static constexpr color red{1.0, 0.0, 0.0};
  static constexpr color white{1.0, 1.0, 1.0};
  static constexpr color blue{0.5, 0.7, 1.0};
  static const sphere s(point3{0, 0, -1}, 0.5);

  hit_record rec;
  if (s.hit(r, -INFINITY, INFINITY, rec)) {
      return 0.5 * (rec.normal + 1.0);
  }

  vec3 unit_direction = unit_vector(r.direction());
  auto a = 0.5 * (unit_direction.y + 1.0);
  return (1.0 - a) * white + (a * blue);
}

int main() {
  // Image
  auto aspect_ratio = 16.0 / 9.0;
  int image_width = 400;
  int image_height = std::max(static_cast<int>(image_width / aspect_ratio), 1);

  // Camera
  auto focal_length = 1.0;
  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (static_cast<double>(image_width) /
                                           static_cast<double>(image_height));
  auto camera_center = point3{0.0, 0.0, 0.0};

  auto viewport_u = vec3{viewport_width, 0.0, 0.0};
  auto viewport_v = vec3{0.0, -viewport_height, 0.0};

  auto pixel_delta_u = viewport_u / image_width;
  auto pixel_delta_v = viewport_v / image_height;

  auto viewport_upper_left = camera_center - vec3{0, 0, focal_length} -
                             (viewport_u / 2) - (viewport_v / 2);
  auto pixel00_loc =
      viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

  std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines remaining: " << (image_height - j) << ' '
              << std::flush;
    for (int i = 0; i < image_width; i++) {
      auto pixel_center =
          pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
      auto ray_direction = pixel_center - camera_center;
      ray r(camera_center, ray_direction);

      auto pixel_color = ray_color(r);
      write_color(std::cout, pixel_color);
    }
  }
  std::clog << "\rDone.                          \n";
}
