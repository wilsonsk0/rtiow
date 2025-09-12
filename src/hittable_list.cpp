#include <hittable.hpp>
#include <interval.hpp>
#include <ray.hpp>
#include <hittable_list.hpp>

auto hittable_list::hit(ray const &r, interval ray_t,
                        hit_record &rec) const -> bool {
  hit_record temp_rec;
  bool hit_anything = false;
  auto closest_so_far = ray_t.max;

  for (const auto &object : objects) {
    if (object->hit(r, {ray_t.min, closest_so_far}, temp_rec)) {
      hit_anything = true;
      closest_so_far = temp_rec.t;
      rec = temp_rec;
    }
  }

  return hit_anything;
}
