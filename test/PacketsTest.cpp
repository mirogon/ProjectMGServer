#include <catch2/catch_test_macros.hpp>
#include "src/Packets.h"
#include "src/Vector2.h"
#include "src/FVector2.h"

TEST_CASE("PlayerRegister_Creation", "[Packets]") {
	PlayerRegisterPacket packet{};
}

TEST_CASE("PlayerRegister_FromRaw", "[Packets]") {
	uint8_t raw[2];
	raw[0] = 0;
	raw[1] = PacketType::PlayerRegister;

	PlayerRegisterPacket p{raw};
}

TEST_CASE("PlayerRegister_PacketFormat", "[Packets]") {
	uint8_t raw[2];
	raw[0] = 0;
	raw[1] = PacketType::PlayerRegister;

	PlayerRegisterPacket p{raw};

	auto packetFormat = p.PacketFormat();
	for (int i = 0; i < 2; ++i) {
		REQUIRE(raw[i] == packetFormat.first.get()[i]);
	}
}

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

TEST_CASE("CharacterPosition_Creation", "[Packets]") {
	FVector2 pos{ 0.15, 1 };

	CharacterPositionPacket packet{ pos };

	REQUIRE(pos == packet.Position());
}

TEST_CASE("CharacterPosition_FromRaw", "[Packets]") {
	uint8_t raw[10];
	raw[0] = 0;
	raw[1] = PacketType::CharacterPosition;
	float x = 0.15f;
	memcpy(raw + 2, &x, 4);
	float y = 2.5f;
	memcpy(raw + 6, &y, 4);

	CharacterPositionPacket packet{ raw };

	REQUIRE(FVector2{ 0.15f, 2.5f } == packet.Position());
}

TEST_CASE("CharacterPosition_PacketFormat", "[Packets]") {
	uint8_t raw[10];
	raw[0] = 0;
	raw[1] = PacketType::CharacterPosition;
	float x = 0.15f;
	memcpy(raw + 2, &x, 4);
	float y = 2.5f;
	memcpy(raw + 6, &y, 4);

	CharacterPositionPacket packet{ raw };

	for (int i = 0; i < 10; ++i) {
		REQUIRE(raw[i] == packet.PacketFormat().first.get()[i]);
	}
}
