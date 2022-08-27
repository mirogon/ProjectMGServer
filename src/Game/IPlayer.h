#pragma once
#include "Character.h"
#include "src/Net/SocketAddress.h"

class IPlayer {
public:
	virtual std::vector<CharacterPtr> Character() = 0;
	virtual void AddCharacter(CharacterPtr character) = 0;
	virtual SocketAddress Address() = 0;
};

typedef std::shared_ptr<IPlayer> PlayerPtr;