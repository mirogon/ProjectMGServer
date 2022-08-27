#pragma once

#include "ICharacterMover.h"
#include <vector>
#include "src/Game/Character.h"

class CharacterMover : public ICharacterMover {
private:
	std::vector<CharacterPtr> character;
public:
	CharacterMover(std::vector<CharacterPtr> character) {
		this->character = character;
	}
	void Start() {
	}
};