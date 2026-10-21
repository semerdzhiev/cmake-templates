#include "catch2/catch_all.hpp"
#include <myproject/math/calculator.h>

using myproject::math::fibonacci;

TEST_CASE("fibonacci(0) is 0")
{
	REQUIRE(fibonacci(0) == 0);
}

TEST_CASE("fibonacci(1) is 1")
{
	REQUIRE(fibonacci(1) == 1);
}

TEST_CASE("fibonacci(2) is 1")
{
	REQUIRE(fibonacci(2) == 1);
}

TEST_CASE("fibonacci(3) is 2")
{
	REQUIRE(fibonacci(3) == 2);
}

TEST_CASE("fibonacci(8) is 21")
{
	REQUIRE(fibonacci(8) == 21);
}
