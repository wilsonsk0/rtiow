#include <cmath>
#include <hittable.hpp>
#include <ray.hpp>

#include <sphere.hpp>
#include <vec3.hpp>

sphere::sphere(point3 const &center, double radius)
    : center(center), radius(std::fmax(0.0, radius)) {}

auto sphere::hit(ray const &r, double ray_tmin, double ray_tmax,
                 hit_record &rec) const -> bool {
  vec3 oc = center - r.origin();
  auto a = r.direction().length_squared();
  auto h = dot(r.direction(), oc);
  auto c = oc.length_squared() - radius * radius;

  auto discriminant = h * h - a * c;
  if (discriminant < 0)
    return false;

  auto sqrtd = std::sqrt(discriminant);

  auto root = (h - sqrtd) / a;
  if (root <= ray_tmin || ray_tmax <= root) {
    root = (h + sqrtd) / a;
    if (root <= ray_tmin || ray_tmax <= root)
      return false;
  }

  rec.t = root;
  rec.p = r.at(root);
  vec3 outward_normal = (rec.p - center) / radius;
  rec.set_face_normal(r, outward_normal);

  return true;
}
