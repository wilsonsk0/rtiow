#include <iostream>

#include <camera.hpp>
#include <color.hpp>
#include <common.hpp>
#include <hittable.hpp>
#include <interval.hpp>
#include <ray.hpp>
#include <vec3.hpp>

template <class T> auto mix(T const &a, T const &b, double t) -> T {
  return (1 - t) * a + t * b;
}

auto camera::ray_color(ray const &r, hittable const &world) const -> color {
  static constexpr color white{1.0, 1.0, 1.0};
  static constexpr color blue{0.5, 0.7, 1.0};

  hit_record rec;

  if (world.hit(r, interval{0, infinity}, rec))
    return 0.5 * (rec.normal + color{1, 1, 1});

  vec3 unit_direction = unit_vector(r.direction());
  auto a = 0.5 * (unit_direction.y + 1.0);
  return mix(white, blue, a);
}

auto camera::render(hittable const &world) -> void {
  initialize();

  std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines remaining: " << (image_height - j) << ' '
              << std::flush;
    for (int i = 0; i < image_width; i++) {
      color pixel_color{0.0, 0.0, 0.0};
      for (int sample = 0; sample < samples_per_pixel; sample++) {
        ray r = get_ray(i, j);
        pixel_color += ray_color(r, world);
      }
      write_color(std::cout, pixel_samples_scale * pixel_color);
    }
  }
  std::clog << "\rDone.                          \n";
}

auto camera::initialize() -> void {
  image_height = std::max(static_cast<int>(image_width / aspect_ratio), 1);

  auto focal_length = 1.0;
  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (static_cast<double>(image_width) /
                                           static_cast<double>(image_height));

  auto viewport_u = vec3{viewport_width, 0.0, 0.0};
  auto viewport_v = vec3{0.0, -viewport_height, 0.0};

  pixel_delta_u = viewport_u / image_width;
  pixel_delta_v = viewport_v / image_height;

  auto viewport_upper_left =
      center - vec3{0, 0, focal_length} - (viewport_u / 2) - (viewport_v / 2);
  pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

  pixel_samples_scale = 1.0 / samples_per_pixel;
}

static auto sample_square() -> vec3 {
  return {random_double() - 0.5, random_double() - 0.5, 0};
}

auto camera::get_ray(int i, int j) const -> ray {
  auto offset = sample_square();
  auto pixel_sample = pixel00_loc + ((i + offset.x) * pixel_delta_u) +
                      ((j + offset.y) * pixel_delta_v);
  auto ray_origin = center;
  auto ray_direction = pixel_sample - ray_origin;
  return {ray_origin, ray_direction};
}
