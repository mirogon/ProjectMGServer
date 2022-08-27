#pragma once
#include <memory>
#include "src/Vector2.h"

enum PacketType {
	CharacterMove = 1
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