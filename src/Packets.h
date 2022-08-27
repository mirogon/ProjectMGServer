#pragma once
#include <memory>
#include "src/Vector2.h"
#include "src/FVector2.h"

enum PacketType {
	PlayerRegister = 1,
	CharacterMove = 2,
	CharacterPosition = 3
};

struct PlayerRegisterPacket {
	PlayerRegisterPacket() {}
	PlayerRegisterPacket(uint8_t* raw){}

	std::pair<std::shared_ptr<uint8_t>, int> PacketFormat() {
		std::shared_ptr<uint8_t> data{ new uint8_t[4] };
		data.get()[0] = 0;
		data.get()[1] = PacketType::PlayerRegister;
		return std::make_pair(data, 2);
	}
};

struct CharacterMovePacket {
private:
	Vector2 moveDir;
public:
	CharacterMovePacket(Vector2 moveDir) {
		this->moveDir = moveDir;
	}
	CharacterMovePacket(uint8_t* raw) {
		moveDir.x = raw[2];
		moveDir.y = raw[3];
	}

	Vector2 MoveDir() {
		return moveDir;
	}

	std::pair<std::shared_ptr<uint8_t>, int> PacketFormat() {
		std::shared_ptr<uint8_t> data{ new uint8_t[4] };
		data.get()[0] = 0;
		data.get()[1] = PacketType::CharacterMove;
		data.get()[2] = moveDir.x;
		data.get()[3] = moveDir.y;
		return std::make_pair(data, 4);
	}
	
};

struct CharacterPositionPacket {
private: 
	FVector2 pos;
public:
	CharacterPositionPacket(const FVector2& pos) {
		this->pos = pos;
	}
	CharacterPositionPacket(uint8_t* raw) {
		memcpy(&pos.x, raw + 2, 4);
		memcpy(&pos.y, raw + 6, 4);
	}

	std::pair<std::shared_ptr<uint8_t>, int> PacketFormat() {
		std::shared_ptr<uint8_t> data{ new uint8_t[10] };
		data.get()[0] = 0;
		data.get()[1] = PacketType::CharacterPosition;
		memcpy(((uint8_t*)data.get()) + 2, &pos.x, 4);
		memcpy(((uint8_t*)data.get()) + 6, &pos.y, 4);
		return std::make_pair(data, 10);
	}
	FVector2 Position() {
		return pos;
	}
};