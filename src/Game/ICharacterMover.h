#pragma once
#include <memory>
#include "src/Game/Character.h"

class ICharacterMover {
public:
	virtual void Start() = 0;
	virtual void SetCharacter(std::vector<CharacterPtr> character) = 0;
};

typedef std::shared_ptr<ICharacterMover> CharacterMoverPtr;
