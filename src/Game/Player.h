#pragma once
#include "IPlayer.h"
#include <vector>

class Player : public IPlayer {
private:
	std::vector<CharacterPtr> character;
	SocketAddress addr;
public:
	Player(SocketAddress addr, std::vector<CharacterPtr> character):
		addr{addr}
	{
		this->character = character;
	}
	std::vector<CharacterPtr> Character() override {
		return character;
	}
	void AddCharacter(CharacterPtr newChar) override {
		character.push_back(newChar);
	}
	SocketAddress Address() {
		return addr;
	}
};