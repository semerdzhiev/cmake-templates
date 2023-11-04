#include "catch2/catch_all.hpp"
#include "library.h"

#include <chrono>

TEST_CASE("fibonacci(N) throws when N < 0")
{
	REQUIRE_THROWS_AS(fibonacci(-1), std::invalid_argument);
}

TEST_CASE("fibonacci(N) returns correct values")
{
	const int size = 10;
	int expected[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

	for(int i = 0; i < size; ++i)
		REQUIRE(fibonacci(i) == expected[i]);
}

TEST_CASE("fibonacci(N) works for numbers up to 10'000")
{
	REQUIRE_NOTHROW(fibonacci(10'000)); // must not fail
}

TEST_CASE("fibonacci(N) finishes under 2s in the worst case")
{
	auto start = std::chrono::steady_clock::now();
	fibonacci(10'000);
	auto end = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
	REQUIRE(duration <= 2);
}