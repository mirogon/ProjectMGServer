#include <catch2/catch_test_macros.hpp>
#include "src/Server.h"
#include "src/Packets.h"
#include "src/Game/CharacterMover.h"
#include "src/Game/Player.h"

TEST_CASE("Creation", "[Server]") {
	std::vector<PlayerPtr> player = std::vector<PlayerPtr>();
	CharacterMoverPtr mover{ new CharacterMover() };
	ServerPtr server{ new Server(player, mover) };
}

TEST_CASE("HandleCharacterMovePacket", "[Server]") {
	std::vector<PlayerPtr> player = std::vector<PlayerPtr>();
	CharacterMoverPtr mover{ new CharacterMover() };
	ServerPtr server{ new Server(player, mover) };
	CharacterMovePacket p{ Vector2{0,1} };
	SocketAddress addr{ IPAddressPtr{new IPAddress{"0.0.0.0"}}, 0 };
	server->HandleCharacterMovePacket(addr, p);
}

TEST_CASE("HandlePlayerRegisterPacket", "[Server]") {
	std::vector<PlayerPtr> player = std::vector<PlayerPtr>();
	CharacterMoverPtr mover{ new CharacterMover() };
	ServerPtr server{ new Server(player, mover) };
	PlayerRegisterPacket p{};
	SocketAddress addr{ IPAddressPtr{new IPAddress{"0.0.0.0"}}, 0 };
	server->HandlePlayerRegisterPacket(addr, p);
}

