#include <iostream>
#include <ostream>

#include <color.hpp>
#include <interval.hpp>

auto write_color(std::ostream &os, const color &pixel_color) -> void {
  auto r = pixel_color.x;
  auto g = pixel_color.y;
  auto b = pixel_color.z;

  static constexpr interval intensity{0.000, 0.999};
  int rbyte = static_cast<int>(256 * intensity.clamp(r));
  int gbyte = static_cast<int>(256 * intensity.clamp(g));
  int bbyte = static_cast<int>(256 * intensity.clamp(b));

  os << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
