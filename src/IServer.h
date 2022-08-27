#pragma once
#include <memory>
#include "src/Packets.h"
#include "src/Net/SocketAddress.h"

class IServer {
public:
	virtual void HandleCharacterMovePacket(SocketAddress playerAddr, CharacterMovePacket p) = 0;
	virtual void HandlePlayerRegisterPacket(SocketAddress playerAddr, PlayerRegisterPacket p) = 0;
};

typedef std::shared_ptr<IServer> ServerPtr;