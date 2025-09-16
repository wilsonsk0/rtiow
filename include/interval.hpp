#pragma once

#include <common.hpp>
#include <rtiow_export.hpp>

struct RTIOW_EXPORT interval {
  double min{-infinity};
  double max{infinity};

  auto size() const -> double { return max - min; }

  auto contains(double x) const -> bool { return min <= x && x <= max; }

  auto surrounds(double x) const -> bool { return min < x && x < max; }

  auto clamp(double x) const -> double {
    if (x < min)
      return min;
    if (x > max)
      return max;
    return x;
  }

  static const interval empty, universe;
};
