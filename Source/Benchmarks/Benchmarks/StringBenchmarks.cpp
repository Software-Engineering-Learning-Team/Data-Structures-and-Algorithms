#include <benchmark/benchmark.h>
#include <String/String.hpp>

static void BM_StdStringCreation(benchmark::State& state)
{
	for (auto _: state)
	{
		std::string test_string("String for benchmark");
	}

}

BENCHMARK(BM_StdStringCreation);

static void BM_CustomStringCreation(benchmark::State& state)
{
	for (auto _: state)
	{
		DataStructures::String test_string("String for benchmark");
	}
}

BENCHMARK(BM_CustomStringCreation);

BENCHMARK_MAIN();