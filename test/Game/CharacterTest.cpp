#include <catch2/catch_test_macros.hpp>
#include "src/Game/Character.h"
#include "src/FVector2.h"

TEST_CASE("Creation", "[Character]") {
	FVector2 pos{ 0,0 };
	CharacterPtr character{ new Character(pos) };
	REQUIRE(pos == character->Position());
}

TEST_CASE("MoveCharacter", "[Character]") {
	FVector2 pos{ 0,0 };
	CharacterPtr character{ new Character(pos) };
	character->Move(FVector2{10, 5});
	REQUIRE(FVector2{ 10, 5 } == character->Position());
}
