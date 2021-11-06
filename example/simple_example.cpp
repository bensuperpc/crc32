// //////////////////////////////////////////////////////////
// simple_example.cpp
// Copyright (c) 2021-2021 Stephan Brumme. All rights reserved.
// Simple example contributed by Bensuperpc
// see http://create.stephan-brumme.com/disclaimer.html
//

#include <iostream>
#include <string>

#include "crc32/crc32.hpp"

auto main(int argc, char* argv[]) -> int
{
  const std::string str = "Linux";
  const auto result = crc32::crc32_halfbyte(str.data(), str.size(), 0);

  std::cout << "CRC32 of: " << str << " = 0x" << std::hex << result
            << std::endl;

  return 0;
}
