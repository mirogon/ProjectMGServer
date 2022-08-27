#pragma once
#include "Character.h"

class IPlayer {
public:
	virtual std::vector<CharacterPtr> Character() = 0;
};

typedef std::shared_ptr<IPlayer> PlayerPtr;