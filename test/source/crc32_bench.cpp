// //////////////////////////////////////////////////////////
// crc32_bench.cpp
// Copyright (c) 2011-2021 Stephan Brumme. All rights reserved.
// Google benchmark contributed by Bensuperpc
// see http://create.stephan-brumme.com/disclaimer.html
//

#include <cstdint>
#include <memory>

#include "crc32/crc32.hpp"

#include <benchmark/benchmark.h>

static std::unique_ptr<char[]> generate(const std::uint64_t length);

static std::unique_ptr<char[]> generate(const std::uint64_t length)
{
  uint32_t randomNumber = 0x27121978;
  // initialize
  std::unique_ptr<char[]> data(new char[length]);
  for (std::uint64_t i = 0; i < length; i++) {
    data[i] = char(randomNumber & 0xFF);
    // simple LCG, see
    // http://en.wikipedia.org/wiki/Linear_congruential_generator
    randomNumber = 1664525 * randomNumber + 1013904223;
  }
  return data;
}

static void crc32_fast_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_fast(str.get(), size, 0);

    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));

  // state.SetLabel("OK");
}
BENCHMARK(crc32_fast_bench)
    ->Name("crc32_fast")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

static void crc32_bitwise_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_bitwise(str.get(), size, 0);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
BENCHMARK(crc32_bitwise_bench)
    ->Name("crc32_bitwise")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

static void crc32_bitwise_branch_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_bitwise_branch(str.get(), size, 0);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
BENCHMARK(crc32_bitwise_branch_bench)
    ->Name("crc32_bitwise_branch")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

static void crc32_halfbyte_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_halfbyte(str.get(), size, 0);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
BENCHMARK(crc32_halfbyte_bench)
    ->Name("crc32_halfbyte")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE

static void crc32_1byte_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_1byte(str.get(), size, 0);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
BENCHMARK(crc32_1byte_bench)
    ->Name("crc32_1byte")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

static void crc32_1byte_tableless_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_1byte_tableless(str.get(), size, 0);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
BENCHMARK(crc32_1byte_tableless_bench)
    ->Name("crc32_1byte_tableless")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

static void crc32_1byte_tableless2_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_1byte_tableless2(str.get(), size, 0);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
BENCHMARK(crc32_1byte_tableless2_bench)
    ->Name("crc32_1byte_tableless2")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_4

static void crc32_4bytes_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_4bytes(str.get(), size, 0);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
BENCHMARK(crc32_4bytes_bench)
    ->Name("crc32_4bytes")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_8

static void crc32_8bytes_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_8bytes(str.get(), size, 0);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
BENCHMARK(crc32_8bytes_bench)
    ->Name("crc32_8bytes")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

static void crc32_4x8bytes_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_4x8bytes(str.get(), size, 0);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
BENCHMARK(crc32_4x8bytes_bench)
    ->Name("crc32_4x8bytes")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_16

static void crc32_16bytes_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_16bytes(str.get(), size, 0);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
BENCHMARK(crc32_16bytes_bench)
    ->Name("crc32_16bytes")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

static void crc32_16bytes_prefetch_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  auto str = generate(size);

  for (auto _ : state) {
    benchmark::DoNotOptimize(str);
    crc32::crc32_16bytes_prefetch(str.get(), size, 0, 512);
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
BENCHMARK(crc32_16bytes_prefetch_bench)
    ->Name("crc32_16bytes_prefetch")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000);

#endif

// Run the benchmark if not link with benchmark::benchmark_main
// BENCHMARK_MAIN();
