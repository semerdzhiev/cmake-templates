#include "catch2/catch_all.hpp"
#include "mathlib/mathlib.h"


TEST_CASE("fibbonachi(0) is 0")
{
	REQUIRE(fibbonachi(0) == 0);
}

TEST_CASE("fibbonachi(1) is 1")
{
	REQUIRE(fibbonachi(1) == 1);
}

TEST_CASE("fibbonachi(2) is 1")
{
	REQUIRE(fibbonachi(2) == 1);
}

TEST_CASE("fibbonachi(3) is 2")
{
	REQUIRE(fibbonachi(3) == 2);
}

TEST_CASE("fibbonachi(8) is 21")
{
	REQUIRE(fibbonachi(8) == 21);
}