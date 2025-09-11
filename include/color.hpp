#pragma once

#include <iosfwd>

#include <vec3.hpp>
#include <rtiow_export.hpp>

using color = vec3;

RTIOW_EXPORT auto write_color(std::ostream &os, color const& pixel_color) -> void;
