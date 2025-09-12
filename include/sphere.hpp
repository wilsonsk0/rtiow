#pragma once

#include <hittable.hpp>
#include <interval.hpp>
#include <ray.hpp>
#include <rtiow_export.hpp>
#include <vec3.hpp>

class RTIOW_EXPORT sphere : public hittable {
public:
  ~sphere() override = default;

  RTIOW_EXPORT sphere(point3 const &center, double radius);
  RTIOW_EXPORT auto hit(ray const &r, interval rat_t, hit_record &rec) const
      -> bool override;

private:
  point3 center;
  double radius;
};
