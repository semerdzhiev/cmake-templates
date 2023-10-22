/// Calculates the factorial of n
int factorial(int n)
{
	int result = 1;

	for (; n > 1; --n)
		result *= n;

	return result;
}

/// Calculates the n-th fibbonachi number
int fibbonachi(int n)
{
	int a = 1, b = 0;

	for (; n > 0; --n) {
		a += b;
		b = a - b;
	}

	return b;
}