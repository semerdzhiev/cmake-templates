#include "catch2/catch_all.hpp"
#include "library.h"

TEST_CASE("factorial(0) returns 1")
{
	REQUIRE(factorial(0) == 1);
}

TEST_CASE("factorial(6) returns  produces correct values")
{
	REQUIRE(factorial(6) == 720);
}