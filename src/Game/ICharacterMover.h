#pragma once
#include <memory>

class ICharacterMover {
public:
	virtual void Start() = 0;
};

typedef std::shared_ptr<ICharacterMover> CharacterMoverPtr;
