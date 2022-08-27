#include <catch2/catch_test_macros.hpp>
#include "src/Packets.h"
#include "src/Vector2.h"

TEST_CASE("CharacterMove_Creation", "[Packets]") {
	CharacterMovePacket packet{ Vector2{0,1} };
	REQUIRE(Vector2{0,1} == packet.MoveDir());
}

TEST_CASE("CharacterMove_FromRaw_Correct", "[Packets]") {
	uint8_t raw[4];
	raw[0] = 0;
	raw[1] = PacketType::CharacterMove;
	raw[2] = 0;
	raw[3] = 1;

	CharacterMovePacket packet{ raw };

	REQUIRE(Vector2{0,1} == packet.MoveDir());
}

TEST_CASE("CharacterMove_PacketFormat_Correct", "[Packets]") {
	uint8_t raw[4];
	raw[0] = 0;
	raw[1] = PacketType::CharacterMove;
	raw[2] = 0;
	raw[3] = 1;

	CharacterMovePacket packet{ raw };

	auto actual = packet.PacketFormat();

	for (int i = 0; i < 3; ++i) {
		REQUIRE(raw[i] == actual.first.get()[i]);
	}
}
