#pragma once
#include <memory>
#include "src/FVector2.h"
#include "src/Vector2.h"

class ICharacter {
public:
	virtual FVector2 Position() = 0;
	virtual Vector2 MoveDirection() = 0;
	virtual void SetMoveDirection(Vector2 newMoveDir) = 0;
	virtual void Move(FVector2 movement) = 0;
};

typedef std::shared_ptr<ICharacter> CharacterPtr;