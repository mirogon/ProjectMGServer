#include <catch2/catch_test_macros.hpp>
#include "src/Server.h"
#include "src/Packets.h"

TEST_CASE("Creation", "[Server]") {
	ServerPtr server{ new Server() };
}

TEST_CASE("HandleCharacterMovePacket", "[Server]") {
	ServerPtr server{ new Server() };
	CharacterMovePacket p{ Vector2{0,1} };
	server->HandleCharacterMovePacket(p);
}
