#include <catch2/catch_test_macros.hpp>
#include "src/Game/Character.h"
#include "src/Game/Player.h"
#include "src/Net/SocketAddress.h"

TEST_CASE("Creation", "[PlayerTest]") {
	std::vector<CharacterPtr> playerCharacter = std::vector<CharacterPtr>();
	SocketAddress addr{ IPAddressPtr{new IPAddress("127.0.0.1")}, 500 };
	PlayerPtr player{ new Player(addr, std::vector<CharacterPtr>{playerCharacter}) };
	REQUIRE(playerCharacter == player->Character());
	REQUIRE(addr.Address() == player->Address().Address());
	REQUIRE(addr.Port() == player->Address().Port());
}
