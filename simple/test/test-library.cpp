#include "catch2/catch_all.hpp"
#include "library.h"

#include <array>

#include <chrono>

TEST_CASE("fibonacci(N) throws when N < 0", "[fibonacci]")
{
	REQUIRE_THROWS_AS(fibonacci(-1), std::invalid_argument);
}

TEST_CASE("fibonacci(N) returns correct values", "[fibonacci]")
{
	const int size = 10;
	int expected[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

	for(int i = 0; i < size; ++i)
		REQUIRE(fibonacci(i) == expected[i]);
}

TEST_CASE("fibonacci(N) works for numbers up to 10'000", "[fibonacci]")
{
	REQUIRE_NOTHROW(fibonacci(10'000)); // must not fail
}

TEST_CASE("fibonacci(N) finishes under 2s in the worst case", "[fibonacci]")
{
	auto start = std::chrono::steady_clock::now();
	fibonacci(10'000);
	auto end = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
	REQUIRE(duration <= 2);
}

TEST_CASE("factorial(N) throws when N < 0", "[factorial]")
{
	REQUIRE_THROWS_AS(factorial(-1), std::invalid_argument);
}

TEST_CASE("factorial(N) returns correct values", "[factorial]")
{
	const int size = 11;
	int expected[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

	for(int i = 0; i < size; ++i)
		REQUIRE(factorial(i) == expected[i]);
}

