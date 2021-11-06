// //////////////////////////////////////////////////////////
// crc32_test.cpp
// Copyright (c) 2011-2021 Stephan Brumme. All rights reserved.
// Google test contributed by Bensuperpc
// see http://create.stephan-brumme.com/disclaimer.html
//

#include <string>

#include "crc32/crc32.hpp"

#include "gtest/gtest.h"

TEST(crc32, basic1)
{
  const std::string str = "";
  const auto result = 0x0;

  EXPECT_EQ(result, crc32::crc32_bitwise(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_halfbyte(str.data(), str.size(), 0));

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless2(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_4
  EXPECT_EQ(result, crc32::crc32_4bytes(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_8
  EXPECT_EQ(result, crc32::crc32_8bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_4x8bytes(str.data(), str.size(), 0));

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_16
  EXPECT_EQ(result, crc32::crc32_16bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_16bytes_prefetch(str.data(), str.size(), 0));
#endif

  EXPECT_EQ(result, crc32::crc32_fast(str.data(), str.size(), 0));
}

TEST(crc32, basic2)
{
  const std::string str = "Linux";
  const auto result = 0x53D0684B;

  EXPECT_EQ(result, crc32::crc32_bitwise(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_halfbyte(str.data(), str.size(), 0));

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless2(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_4
  EXPECT_EQ(result, crc32::crc32_4bytes(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_8
  EXPECT_EQ(result, crc32::crc32_8bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_4x8bytes(str.data(), str.size(), 0));

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_16
  EXPECT_EQ(result, crc32::crc32_16bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_16bytes_prefetch(str.data(), str.size(), 0));
#endif

  EXPECT_EQ(result, crc32::crc32_fast(str.data(), str.size(), 0));
}

TEST(crc32, basic3)
{
  const std::string str = "CRC32";
  const auto result = 0xF6151584;

  EXPECT_EQ(result, crc32::crc32_bitwise(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_halfbyte(str.data(), str.size(), 0));

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless2(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_4
  EXPECT_EQ(result, crc32::crc32_4bytes(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_8
  EXPECT_EQ(result, crc32::crc32_8bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_4x8bytes(str.data(), str.size(), 0));

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_16
  EXPECT_EQ(result, crc32::crc32_16bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_16bytes_prefetch(str.data(), str.size(), 0));
#endif

  EXPECT_EQ(result, crc32::crc32_fast(str.data(), str.size(), 0));
}

TEST(crc32, basic4)
{
  const std::string str = "0123456789";
  const auto result = 0xA684C7C6;

  EXPECT_EQ(result, crc32::crc32_bitwise(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_halfbyte(str.data(), str.size(), 0));

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless2(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_4
  EXPECT_EQ(result, crc32::crc32_4bytes(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_8
  EXPECT_EQ(result, crc32::crc32_8bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_4x8bytes(str.data(), str.size(), 0));

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_16
  EXPECT_EQ(result, crc32::crc32_16bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_16bytes_prefetch(str.data(), str.size(), 0));
#endif

  EXPECT_EQ(result, crc32::crc32_fast(str.data(), str.size(), 0));
}

TEST(crc32, basic5)
{
  const std::string str = "LGBTQIA+";
  const auto result = 0x5C9BD8DC;

  EXPECT_EQ(result, crc32::crc32_bitwise(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_halfbyte(str.data(), str.size(), 0));

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless2(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_4
  EXPECT_EQ(result, crc32::crc32_4bytes(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_8
  EXPECT_EQ(result, crc32::crc32_8bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_4x8bytes(str.data(), str.size(), 0));

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_16
  EXPECT_EQ(result, crc32::crc32_16bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_16bytes_prefetch(str.data(), str.size(), 0));
#endif

  EXPECT_EQ(result, crc32::crc32_fast(str.data(), str.size(), 0));
}

TEST(crc32, basic6)
{
  const std::string str = "Intergouvernementalisations";
  const auto result = 0x5DD186B5;

  // EXPECT_NE(0x0, crc32::crc32_1byte(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_bitwise(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_halfbyte(str.data(), str.size(), 0));

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE
  EXPECT_EQ(result, crc32::crc32_1byte(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_1byte_tableless2(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_4
  EXPECT_EQ(result, crc32::crc32_4bytes(str.data(), str.size(), 0));
#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_8
  EXPECT_EQ(result, crc32::crc32_8bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_4x8bytes(str.data(), str.size(), 0));

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_16
  EXPECT_EQ(result, crc32::crc32_16bytes(str.data(), str.size(), 0));
  EXPECT_EQ(result, crc32::crc32_16bytes_prefetch(str.data(), str.size(), 0));
#endif

  EXPECT_EQ(result, crc32::crc32_fast(str.data(), str.size(), 0));
}
