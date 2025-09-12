#pragma once

#include <hittable.hpp>
#include <ray.hpp>
#include <rtiow_export.hpp>
#include <vec3.hpp>

class RTIOW_EXPORT sphere : public hittable {
public:
  ~sphere() override = default;

  RTIOW_EXPORT sphere(point3 const &center, double radius);
  RTIOW_EXPORT auto hit(ray const &r, double ray_tmin, double ray_tmax,
                        hit_record &rec) const -> bool override;

private:
  point3 center;
  double radius;
};
