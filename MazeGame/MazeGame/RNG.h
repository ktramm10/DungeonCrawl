#pragma once
#include <random>

class RNG
{
public:
	RNG();
	int GetNumInRange(int min, int max);
private:
	std::default_random_engine eng;

};