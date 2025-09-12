#include <common.hpp>
#include <interval.hpp>

const interval interval::empty{+infinity, -infinity};
const interval interval::universe{-infinity, +infinity};
