#include "catch2/catch_all.hpp"
#include <myproject/math/calculator.h>

using myproject::math::factorial;

TEST_CASE("factorial of 0 is 1", "[factorial]")
{
	REQUIRE(factorial(0) == 1);
}

TEST_CASE("factorial of -5 is 1", "[factorial]")
{
	REQUIRE(factorial(-5) == 1);
}

TEST_CASE("factorial of 6 is 120", "[factorial]")
{
	REQUIRE(factorial(5) == 120);
}
