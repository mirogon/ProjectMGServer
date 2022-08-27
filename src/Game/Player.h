#pragma once
#include "IPlayer.h"
#include <vector>

class Player : public IPlayer {
private:
	std::vector<CharacterPtr> character;
public:
	Player(std::vector<CharacterPtr> character) {
		this->character = character;
	}
	std::vector<CharacterPtr> Character() override {
		return character;
	}
};