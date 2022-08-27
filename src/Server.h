#pragma once
#include "IServer.h"
#include <iostream>
#include "src/Game/Player.h"
#include "src/Game/CharacterMover.h"

class Server : public IServer {
private: 
	std::vector<PlayerPtr> player;
	CharacterMoverPtr characterMover;
public:

	Server(std::vector<PlayerPtr> player, CharacterMoverPtr characterMover){
		this->player = player;
		this->characterMover = characterMover;
		if (player.size() > 0) {
			characterMover->SetCharacter(player.at(0)->Character());
		}
		characterMover->Start();
	}
	void HandleCharacterMovePacket(SocketAddress playerAddr, CharacterMovePacket packet) override {
		std::cout << "MoveDir: " << packet.MoveDir().x << "|" << packet.MoveDir().y << std::endl;
	}
};