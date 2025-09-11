#include <ostream>
#include <vec3.hpp>

auto operator<<(std::ostream &os, vec3 const &v) -> std::ostream & {
  return os << v.x << ' ' << v.y << ' ' << v.z;
}
