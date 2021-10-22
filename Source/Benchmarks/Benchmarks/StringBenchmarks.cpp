#include <benchmark/benchmark.h>
#include <String/String.hpp>

static void BM_StdStringCreation(benchmark::State& state)
{
	for (auto _: state)
	{
		std::string test_string("String");
	}

}

BENCHMARK(BM_StdStringCreation);


static void BM_CustomStringCreation(benchmark::State& state)
{
	for (auto _: state)
	{
		DataStructures::String test_string("String");
	}
}

BENCHMARK(BM_CustomStringCreation);

static void BM_StringCompare(benchmark::State& state)
{
	std::string s1(state.range(0), '-');
	std::string s2(state.range(0), '-');
	for (auto _: state)
	{
		benchmark::DoNotOptimize(s1.compare(s2));
	}
	state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_StringCompare)
->RangeMultiplier(2)->Range(1 << 10, 1 << 18)->Complexity(benchmark::oN);


BENCHMARK_MAIN();