#include <string>

#include "crc32/crc32.hpp"

exported_class::exported_class()
    : m_name("crc32")
{
}

auto exported_class::name() const -> const char*
{
  return m_name.c_str();
}
