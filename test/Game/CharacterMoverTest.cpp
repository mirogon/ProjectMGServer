#include <catch2/catch_test_macros.hpp>
#include "src/Game/CharacterMover.h"
#include <thread>

TEST_CASE("Creation", "[CharacterMoverTest]") {
	std::vector<CharacterPtr> character = std::vector<CharacterPtr>();
	CharacterMoverPtr characterMover{new CharacterMover()};
	characterMover->SetCharacter(character);
}

TEST_CASE("AfterStart_MovesCorrectly", "[CharacterMoverTest]") {
	std::vector<CharacterPtr> character = std::vector<CharacterPtr>();
	character.push_back(CharacterPtr{ new Character(FVector2{0,0}) });
	character.at(0)->SetMoveDirection(Vector2{ 1, 0 });
	REQUIRE(FVector2{ 0,0 } == character.at(0)->Position());
	CharacterMoverPtr characterMover{new CharacterMover()};
	characterMover->SetCharacter(character);
	characterMover->Start();
	std::this_thread::sleep_for(std::chrono::milliseconds(18));
	REQUIRE_FALSE(FVector2{ 0,0 } == character.at(0)->Position());
}
