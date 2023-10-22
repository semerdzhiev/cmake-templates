#include "catch2/catch_all.hpp"
#include "mathlib/mathlib.h"


TEST_CASE("factorial of 0 is 1")
{
	REQUIRE(factorial(0) == 1);
}

TEST_CASE("factorial of -5 is 1")
{
	REQUIRE(factorial(-5) == 1);
}

TEST_CASE("factorial of 6 is 120")
{
	REQUIRE(factorial(5) == 120);
}