#pragma once

#include <cmath>
#include <cstddef>
#include <iosfwd>
#include <stdexcept>
#include <type_traits>

#include <rtiow_export.hpp>

class vec3 {
public:
  double x{0.0};
  double y{0.0};
  double z{0.0};

  auto operator[](std::size_t i) -> double & {
    switch (i) {
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    default:
      throw std::out_of_range("index out of range");
    }
  }

  auto operator[](std::size_t i) const -> double {
    return const_cast<vec3 *>(this)->operator[](i);
  }

  auto operator-() const -> vec3 { return vec3{-x, -y, -z}; }

  auto operator+=(double t) -> vec3 & {
    x += t;
    y += t;
    z += t;
    return *this;
  }

  auto operator+=(vec3 const &other) -> vec3 & {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
  }

  auto operator*=(double t) -> vec3 & {
    x *= t;
    y *= t;
    z *= t;
    return *this;
  }

  auto operator/=(double t) -> vec3 & { return (*this) *= (1.0 / t); }

  auto operator-=(double t) -> vec3 & { return (*this) += (-t); }

  auto operator+(vec3 const &other) const -> vec3 {
    return vec3{x + other.x, y + other.y, z + other.z};
  }

  auto operator+(double t) const -> vec3 { return vec3{x + t, y + t, z + t}; }

  auto operator-(vec3 const &other) const -> vec3 {
    return vec3{x - other.x, y - other.y, z - other.z};
  }

  auto operator*(vec3 const &other) const -> vec3 {
    return vec3{x * other.x, y * other.y, z * other.z};
  }

  auto operator*(double t) const -> vec3 { return vec3{x * t, y * t, z * t}; }

  auto operator/(double t) const -> vec3 { return vec3{x / t, y / t, z / t}; }

  auto length_squared() const -> double { return x * x + y * y + z * z; }

  auto length() const -> double { return std::sqrt(length_squared()); }
};

using point3 = vec3;

RTIOW_EXPORT auto operator<<(std::ostream &, const vec3 &) -> std::ostream &;

inline auto operator*(double t, vec3 const &v) -> vec3 { return v * t; }

inline auto dot(vec3 const &u, vec3 const &v) -> double {
  return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline auto cross(vec3 const &u, vec3 const &v) -> vec3 {
  return vec3{u.x * v.y - u.y * v.x, u.z * v.x - u.x * v.z,
              u.y * v.z - u.z * v.y};
}

inline auto unit_vector(const vec3 &v) { return v / v.length(); }
