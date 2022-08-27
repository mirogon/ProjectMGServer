#include <catch2/catch_test_macros.hpp>
#include "src/Game/Character.h"
#include "src/Game/Player.h"

TEST_CASE("Creation", "[PlayerTest]") {
	std::vector<CharacterPtr> playerCharacter = std::vector<CharacterPtr>();
	PlayerPtr player{ new Player(std::vector<CharacterPtr>{playerCharacter}) };
	REQUIRE(playerCharacter == player->Character());
}
