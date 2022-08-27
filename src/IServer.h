#pragma once
#include <memory>
#include "src/Packets.h"

class IServer {
public:
	virtual void HandleCharacterMovePacket(CharacterMovePacket p) = 0;
};

typedef std::shared_ptr<IServer> ServerPtr;