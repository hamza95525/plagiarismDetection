#include "Dummy.h"
#include "BenchIncludes.h"
static void Dummy_Integrate(State& state) {
    Dummy dummy{};
    for (auto _ : state) {
        auto integral = dummy.integrate(0, state.range(0));
        DoNotOptimize(integral);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Dummy_Integrate)->RangeMultiplier(2)->Range(1<<5, 1<<18)->Complexity();
