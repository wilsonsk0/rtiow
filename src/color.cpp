#include <iostream>
#include <ostream>

#include <color.hpp>

auto write_color(std::ostream &os, const color &pixel_color) -> void {
  auto r = pixel_color.x;
  auto g = pixel_color.y;
  auto b = pixel_color.z;

  int rbyte = static_cast<int>(255.999 * r);
  int gbyte = static_cast<int>(255.999 * g);
  int bbyte = static_cast<int>(255.999 * b);

  os << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
