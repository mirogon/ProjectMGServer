#pragma once
#include "Character.h"
#include "src/Net/SocketAddress.h"

class IPlayer {
public:
	virtual CharacterPtr Character() = 0;
	virtual SocketAddress Address() = 0;
};

typedef std::shared_ptr<IPlayer> PlayerPtr;