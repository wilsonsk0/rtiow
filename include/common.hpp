#pragma once

#include <limits>
#include <random>

static constexpr auto infinity = std::numeric_limits<double>::infinity();
static constexpr double pi = 3.1415926535897932385;

inline auto deg2rad(double degrees) -> double { return degrees * pi / 180.0; }

inline auto random_double() -> double {
  static std::uniform_real_distribution<double> dist(0.0, 1.0);
  static std::mt19937 gen;
  return dist(gen);
}

inline auto random_double(double min, double max) -> double {
  return min + (max - min) * random_double();
}
