#include <catch2/catch_test_macros.hpp>
#include <myproject/math/calculator.h>

using myproject::math::factorial;

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
