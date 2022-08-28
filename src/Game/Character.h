#pragma once
#include "ICharacter.h"

class Character : public ICharacter {
private:
	FVector2 position;
	Vector2 moveDir;
	float speed;
public:
	Character(FVector2 pos, float speed) {
		this->position = pos;
		this->speed = speed;
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

	float Speed() override {
		return speed;
	}
};