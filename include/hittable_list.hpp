#pragma once

#include <hittable.hpp>
#include <rtiow_export.hpp>

#include <memory>
#include <vector>

class RTIOW_EXPORT hittable_list : public hittable {
public:
  hittable_list() = default;
  ~hittable_list() override = default;

  auto clear() -> void { objects.clear(); }
  auto add(std::shared_ptr<hittable> object) -> void {
    objects.push_back(object);
  }

  RTIOW_EXPORT auto hit(ray const &r, double ray_tmin, double ray_tmax,
                        hit_record &rec) const -> bool override;

private:
  std::vector<std::shared_ptr<hittable>> objects;
};
