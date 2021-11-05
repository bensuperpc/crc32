cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    crc32
    VERSION 0.1.0
    DESCRIPTION "fast crc32"
    HOMEPAGE_URL "https://create.stephan-brumme.com/"
    LANGUAGES CXX
)

docs_early_return()

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    crc32_crc32
    source/crc32.cpp
)
add_library(crc32::crc32 ALIAS crc32_crc32)

include(GenerateExportHeader)
generate_export_header(
    crc32_crc32
    BASE_NAME crc32
    EXPORT_FILE_NAME export/crc32/crc32_export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(crc32_crc32 PUBLIC CRC32_STATIC_DEFINE)
endif()

set_target_properties(
    crc32_crc32 PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME crc32
    OUTPUT_NAME crc32
)

target_include_directories(
    crc32_crc32 ${crc32_warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_include_directories(
    crc32_crc32 SYSTEM
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features(crc32_crc32 PUBLIC cxx_std_17)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----

if(PROJECT_IS_TOP_LEVEL)
  option(BUILD_EXAMPLES "Build examples tree." "${crc32_DEVELOPER_MODE}")
  if(BUILD_EXAMPLES)
    add_subdirectory(example)
  endif()
endif()

# ---- Developer mode ----

if(NOT crc32_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of crc32"
  )
endif()

include(cmake/dev-mode.cmake)
