#include <string>

#include "crc32/crc32.hpp"

#include "gtest/gtest.h"

TEST(crc32, basic1)
{
  const std::string str = "";
  const auto result = 0x0;
#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
#endif
}

TEST(crc32, basic2)
{
  const std::string str = "Linux";
  const auto result = 0x53D0684B;

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
#endif
}

TEST(crc32, basic3)
{
  const std::string str = "CRC32";
  const auto result = 0xF6151584;

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
#endif
}

TEST(crc32, basic4)
{
  const std::string str = "0123456789";
  const auto result = 0xA684C7C6;

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
#endif
}

TEST(crc32, basic5)
{
  const std::string str = "LGBTQIA+";
  const auto result = 0x5C9BD8DC;

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
#endif
}

TEST(crc32, basic6)
{
  const std::string str = "Intergouvernementalisations";
  const auto result = 0x5DD186B5;

  // EXPECT_NE(0x0, crc32::crc32_1byte(str.data(), str.size(), 0));
#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
#endif
}
