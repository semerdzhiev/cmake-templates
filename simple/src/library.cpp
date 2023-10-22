#include "library.h"

unsigned int factorial(unsigned int n)
{
	unsigned int result = 1;

	for (; n > 1; --n)
		result *= n;

	return result;
}