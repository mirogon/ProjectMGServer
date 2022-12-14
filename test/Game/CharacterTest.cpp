#include <catch2/catch_test_macros.hpp>
#include "src/Game/Character.h"
#include "src/FVector2.h"
#include "src/Vector2.h"

TEST_CASE("Creation", "[Character]") {
	FVector2 pos{ 0,0 };
	float speed = 5;
	CharacterPtr character{ new Character(pos, speed) };
	REQUIRE(pos == character->Position());
	REQUIRE(5 == character->Speed());
}

TEST_CASE("MoveCharacter", "[Character]") {
	FVector2 pos{ 0,0 };
	CharacterPtr character{ new Character(pos, 5) };
	character->Move(FVector2{10, 5});
	REQUIRE(FVector2{ 10, 5 } == character->Position());
}

TEST_CASE("MoveDirection", "[Character]") {
	FVector2 pos{ 0,0 };
	CharacterPtr character{ new Character(pos, 5) };
	REQUIRE(Vector2{ 0,0 } == character->MoveDirection());
	character->SetMoveDirection(Vector2{ 1,0 });
	REQUIRE(Vector2{ 1,0 } == character->MoveDirection());
}
