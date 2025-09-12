#include <hittable.hpp>
#include <ray.hpp>
#include <hittable_list.hpp>

auto hittable_list::hit(ray const &r, double ray_tmin, double ray_tmax,
                        hit_record &rec) const -> bool {
  hit_record temp_rec;
  bool hit_anything = false;
  auto closest_so_far = ray_tmax;

  for (const auto &object : objects) {
    if (object->hit(r, ray_tmin, closest_so_far, temp_rec)) {
      hit_anything = true;
      closest_so_far = temp_rec.t;
      rec = temp_rec;
    }
  }

  return hit_anything;
}
