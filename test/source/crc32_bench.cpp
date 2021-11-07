// //////////////////////////////////////////////////////////
// crc32_bench.cpp
// Copyright (c) 2011-2021 Stephan Brumme. All rights reserved.
// Google benchmark contributed by Bensuperpc
// see http://create.stephan-brumme.com/disclaimer.html
//

#include <cstdint>
#include <random>
#include <string>
#include <vector>

#include "crc32/crc32.hpp"

#include <benchmark/benchmark.h>

static std::string generate(const std::uint64_t length)
{
  std::string possible_characters =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  std::random_device rd;
  std::mt19937 engine(rd());
  std::uniform_int_distribution<> dist(0, possible_characters.size() - 1);
  std::string ret = "";
  for (std::uint64_t i = 0; i < length; i++) {
    ret += possible_characters[dist(engine)];
  }
  return ret;
}

static void crc32_fast(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  const std::string&& str = generate(size);

  for (auto _ : state) {
    crc32::crc32_fast(str.data(), str.size(), 0);
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(str);
  }
  // state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
  // state.SetLabel("OK");
}
// Register the function as a benchmark
BENCHMARK(crc32_fast)->RangeMultiplier(100)->Range(1, 1000000000);

static void crc32_bitwise(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  const std::string&& str = generate(size);

  for (auto _ : state) {
    crc32::crc32_bitwise(str.data(), str.size(), 0);
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(str);
  }
  // state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
// Register the function as a benchmark
BENCHMARK(crc32_bitwise)->RangeMultiplier(100)->Range(1, 1000000000);

static void crc32_halfbyte(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  const std::string&& str = generate(size);

  for (auto _ : state) {
    crc32::crc32_halfbyte(str.data(), str.size(), 0);
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(str);
  }
  // state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
// Register the function as a benchmark
BENCHMARK(crc32_halfbyte)->RangeMultiplier(100)->Range(1, 1000000000);

#ifdef CRC32_USE_LOOKUP_TABLE_BYTE

static void crc32_1byte(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  const std::string&& str = generate(size);

  for (auto _ : state) {
    crc32::crc32_1byte(str.data(), str.size(), 0);
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(str);
  }
  // state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
// Register the function as a benchmark
BENCHMARK(crc32_1byte)->RangeMultiplier(100)->Range(1, 1000000000);

static void crc32_1byte_tableless(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  const std::string&& str = generate(size);

  for (auto _ : state) {
    crc32::crc32_1byte_tableless(str.data(), str.size(), 0);
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(str);
  }
  // state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
// Register the function as a benchmark
BENCHMARK(crc32_1byte_tableless)->RangeMultiplier(100)->Range(1, 1000000000);

static void crc32_1byte_tableless2(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  const std::string&& str = generate(size);

  for (auto _ : state) {
    crc32::crc32_1byte_tableless2(str.data(), str.size(), 0);
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(str);
  }
  // state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
// Register the function as a benchmark
BENCHMARK(crc32_1byte_tableless2)->RangeMultiplier(100)->Range(1, 1000000000);

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_4

static void crc32_4bytes(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  const std::string&& str = generate(size);

  for (auto _ : state) {
    crc32::crc32_4bytes(str.data(), str.size(), 0);
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(str);
  }
  // state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
// Register the function as a benchmark
BENCHMARK(crc32_4bytes)->RangeMultiplier(100)->Range(1, 1000000000);

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_8

static void crc32_8bytes(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  const std::string&& str = generate(size);

  for (auto _ : state) {
    crc32::crc32_8bytes(str.data(), str.size(), 0);
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(str);
  }
  // state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
// Register the function as a benchmark
BENCHMARK(crc32_8bytes)->RangeMultiplier(100)->Range(1, 1000000000);

static void crc32_4x8bytes(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  const std::string&& str = generate(size);

  for (auto _ : state) {
    crc32::crc32_4x8bytes(str.data(), str.size(), 0);
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(str);
  }
  // state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
// Register the function as a benchmark
BENCHMARK(crc32_4x8bytes)->RangeMultiplier(100)->Range(1, 1000000000);

#endif

#ifdef CRC32_USE_LOOKUP_TABLE_SLICING_BY_16

static void crc32_16bytes(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  const std::string&& str = generate(size);

  for (auto _ : state) {
    crc32::crc32_16bytes(str.data(), str.size(), 0);
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(str);
  }
  // state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
// Register the function as a benchmark
BENCHMARK(crc32_16bytes)->RangeMultiplier(100)->Range(1, 1000000000);

static void crc32_16bytes_prefetch(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto size = state.range(0);
  const std::string&& str = generate(size);

  for (auto _ : state) {
    crc32::crc32_16bytes(str.data(), str.size(), 0);
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(str);
  }
  // state.SetItemsProcessed(state.iterations() * state.range(0));
  state.SetBytesProcessed(state.iterations() * state.range(0) * sizeof(char));
}
// Register the function as a benchmark
BENCHMARK(crc32_16bytes_prefetch)->RangeMultiplier(100)->Range(1, 1000000000);

#endif

// Run the benchmark if not link with benchmark::benchmark_main
// BENCHMARK_MAIN();
