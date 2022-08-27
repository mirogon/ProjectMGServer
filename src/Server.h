#pragma once
#include "IServer.h"

class Server : public IServer {
public:

	void HandleCharacterMovePacket(CharacterMovePacket p) override {
	}
};