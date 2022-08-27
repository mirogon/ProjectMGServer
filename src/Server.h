#pragma once
#include "IServer.h"
#include <iostream>

class Server : public IServer {
public:

	void HandleCharacterMovePacket(CharacterMovePacket packet) override {
		std::cout << "MoveDir: " << packet.MoveDir().x << "|" << packet.MoveDir().y << std::endl;
	}
};