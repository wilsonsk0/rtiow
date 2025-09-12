#pragma once

#include <interval.hpp>
#include <ray.hpp>
#include <vec3.hpp>

struct hit_record {
  point3 p;
  vec3 normal;
  double t;
  bool front_face;

  auto set_face_normal(ray const &r, vec3 const &outward_normal) -> void {
    front_face = dot(r.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
  }
};

struct hittable {
  virtual ~hittable() = default;
  virtual auto hit(ray const &, interval, hit_record &) const -> bool = 0;
};
