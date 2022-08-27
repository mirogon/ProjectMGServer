#include <catch2/catch_test_macros.hpp>
#include "src/Vector2.h"
#include "src/FVector2.h"

TEST_CASE("Creation", "[Vector2]") {
	Vector2 v{ 0,1 };
	REQUIRE(v.x == 0);
	REQUIRE(v.y == 1);
}

TEST_CASE("Equal", "[Vector2]") {
	Vector2 v1{ 0,1 };
	Vector2 v2{ 0,1 };
	REQUIRE(v1 == v2);
}

TEST_CASE("FVector2Creation", "[FVector2]") {
	FVector2 v1{ 0.15f, 0.2f };
	REQUIRE(0.15f == v1.x);
	REQUIRE(0.2f == v1.y);
}

TEST_CASE("FVectorEqual", "[FVector2]") {
	FVector2 v1{ 0,1 };
	FVector2 v2{ 0,1 };
	REQUIRE(v1 == v2);
}
