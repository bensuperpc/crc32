// //////////////////////////////////////////////////////////
// simple_example.c
// Copyright (c) 2021-2021 Stephan Brumme. All rights reserved.
// Simple example contributed by Bensuperpc
// see http://create.stephan-brumme.com/disclaimer.html
//

#include <stdint.h>

#include "crc32/crc32.h"

int main()
{
  char str[6] = {"Linux"};

  const uint32_t result = crc32_halfbyte(str, 6, 0);

  printf("0x%04x", result);
  /*
  printf("%zu\n", sz);

  std::cout << "CRC32 of: " << str << " = 0x" << std::hex << result
            << std::endl;
            */

  return 0;
}
