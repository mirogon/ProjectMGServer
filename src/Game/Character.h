#pragma once
#include "ICharacter.h"

class Character : public ICharacter {
private:
	FVector2 position;
public:
	Character(FVector2 pos) {
		this->position = pos;
	}
	FVector2 Position() override {
		return position;
	}
	void Move(FVector2 movement) override {
		position += movement;
	}
};