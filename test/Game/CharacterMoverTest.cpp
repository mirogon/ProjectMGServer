#include <catch2/catch_test_macros.hpp>
#include "src/Game/CharacterMover.h"

TEST_CASE("Creation", "[CharacterMoverTest]") {
	std::vector<CharacterPtr> character = std::vector<CharacterPtr>();
	CharacterMoverPtr characterMover{new CharacterMover(character)};
}

