#include <string>

#include "crc32/crc32.hpp"

auto main() -> int
{
  exported_class e;

  return std::string("crc32") == e.name() ? 0 : 1;
}
