#include <cmath>
#include <hittable.hpp>
#include <interval.hpp>
#include <ray.hpp>

#include <sphere.hpp>
#include <vec3.hpp>

sphere::sphere(point3 const &center, double radius)
    : center(center), radius(std::fmax(0.0, radius)) {}

auto sphere::hit(ray const &r, interval ray_t, hit_record &rec) const -> bool {
  vec3 oc = center - r.origin();
  auto a = r.direction().length_squared();
  auto h = dot(r.direction(), oc);
  auto c = oc.length_squared() - radius * radius;

  auto discriminant = h * h - a * c;
  if (discriminant < 0)
    return false;

  auto sqrtd = std::sqrt(discriminant);

  auto root = (h - sqrtd) / a;
  if (root <= ray_t.min || ray_t.max <= root) {
    root = (h + sqrtd) / a;
    if (root <= ray_t.min || ray_t.max <= root)
      return false;
  }

  rec.t = root;
  rec.p = r.at(root);
  vec3 outward_normal = (rec.p - center) / radius;
  rec.set_face_normal(r, outward_normal);

  return true;
}
