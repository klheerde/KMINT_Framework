#pragma once

#include <memory>

class Random
{
private:
	static unsigned int _differential;

public:
	static int GetRandom(int max, int min = 0);
};

