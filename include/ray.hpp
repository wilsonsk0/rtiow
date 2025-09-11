#pragma once

#include <vec3.hpp>

class ray {
public:
  ray() = default;
  ray(point3 const &origin, vec3 const &direction)
      : orig(origin), dir(direction) {}

  auto origin() const -> point3 const & { return orig; }
  auto direction() const -> vec3 const & { return dir; }

  auto at(double t) const -> vec3 { return orig + (t * dir); }

private:
  point3 orig;
  vec3 dir;
};
