#pragma once
#include "ICharacter.h"

class Character : public ICharacter {
private:
	FVector2 position;
	Vector2 moveDir;
public:
	Character(FVector2 pos) {
		this->position = pos;
		moveDir = Vector2{ 0,0 };
	}
	FVector2 Position() override {
		return position;
	}
	Vector2 MoveDirection() {
		return moveDir;
	}
	void SetMoveDirection(Vector2 newMoveDir) {
		moveDir = newMoveDir;
	}
	void Move(FVector2 movement) override {
		position += movement;
	}
};