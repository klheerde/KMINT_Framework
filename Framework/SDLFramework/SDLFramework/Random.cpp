#include "Random.h"
#include <ctime>

unsigned int Random::_differential = 0;
unsigned int MAX = UINT_MAX - 1;

int Random::GetRandom(int max, int min)
{
	//NOTE: seed the time for random number, add extra number for diff after each call.s
	srand(time(NULL) + _differential++);

	//NOTE: reset if larger than max.
	if (_differential >= MAX)
		_differential = 0;

	//NOTE: get random edge index.
	return rand() % (max - min) + min;
}
