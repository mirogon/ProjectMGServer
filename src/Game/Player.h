#pragma once
#include "IPlayer.h"
#include <vector>

class Player : public IPlayer {
private:
	CharacterPtr character;
	SocketAddress addr;
public:
	Player(SocketAddress addr, CharacterPtr character):
		addr{addr}
	{
		this->character = character;
	}
	CharacterPtr Character() override {
		return character;
	}
	SocketAddress Address() {
		return addr;
	}
};