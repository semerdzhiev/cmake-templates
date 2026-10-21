#include <myproject/math/calculator.h>

namespace myproject::math {

/// Calculates the factorial of n
int factorial(int n)
{
	int result = 1;

	for (; n > 1; --n)
		result *= n;

	return result;
}

/// Calculates the n-th Fibonacci number
int fibonacci(int n)
{
	int a = 1, b = 0;

	for (; n > 0; --n) {
		a += b;
		b = a - b;
	}

	return b;
}

} // namespace myproject::math
