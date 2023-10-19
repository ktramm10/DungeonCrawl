#include "RNG.h"
#include <chrono>

RNG::RNG()
{
    eng.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

int RNG::GetNumInRange(int min, int max)
{
    std::uniform_int_distribution<int> uni(min, max);
    return uni(eng);
}
