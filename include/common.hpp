#pragma once

#include <limits>

static constexpr auto infinity = std::numeric_limits<double>::infinity();
static constexpr double pi = 3.1415926535897932385;

inline auto deg2rad(double degrees) -> double { return degrees * pi / 180.0; }
