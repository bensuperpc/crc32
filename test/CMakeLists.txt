cmake_minimum_required(VERSION 3.14)

project(crc32Tests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/windows-set-path.cmake)

if(PROJECT_IS_TOP_LEVEL)
  find_package(crc32 REQUIRED)
  enable_testing()
endif()

add_executable(crc32_test source/crc32_test.cpp)
target_link_libraries(crc32_test PRIVATE crc32::crc32)
target_compile_features(crc32_test PRIVATE cxx_std_17)

add_test(NAME crc32_test COMMAND crc32_test)
windows_set_path(crc32_test crc32::crc32)
