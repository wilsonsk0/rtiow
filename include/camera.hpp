#pragma once

#include <color.hpp>
#include <hittable.hpp>
#include <ray.hpp>
#include <vec3.hpp>

#include <rtiow_export.hpp>

class RTIOW_EXPORT camera {
public:
  double aspect_ratio = 1.0;
  int image_width = 100;
  int samples_per_pixel = 10;

  RTIOW_EXPORT auto render(hittable const &world) -> void;

private:
  int image_height;
  point3 center;
  point3 pixel00_loc;
  vec3 pixel_delta_u;
  vec3 pixel_delta_v;
  double pixel_samples_scale;

  auto initialize() -> void;
  auto ray_color(ray const &r, hittable const &world) const -> color;
  auto get_ray(int i, int j) const -> ray;
};
