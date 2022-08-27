#pragma once
#include "IServer.h"
#include <iostream>
#include "src/Game/Player.h"
#include "src/Game/CharacterMover.h"
#include "src/Net/UdpSocket.h"
#include <thread>

class Server : public IServer {
private: 
	UdpSocketPtr udpSocket;
	std::vector<PlayerPtr> player;
	CharacterMoverPtr characterMover;
	std::thread thread;
	bool active;
public:

	Server(UdpSocketPtr udpSocket, std::vector<PlayerPtr> player, CharacterMoverPtr characterMover){
		active = true;
		this->udpSocket = udpSocket;
		this->player = player;
		this->characterMover = characterMover;
		if (player.size() > 0) {
			characterMover->SetCharacter(player.at(0)->Character());
		}
		characterMover->Start();
		thread = std::thread(&Server::SendCharacterPositions, this);
	}
	~Server() {
		active = false;
		if (thread.joinable()) {
			thread.join();
		}
	}
	void HandleCharacterMovePacket(SocketAddress playerAddr, CharacterMovePacket packet) override {
		for (int i = 0; i < player.size(); ++i) {
			if (player.at(i)->Address().Address() == playerAddr.Address() && player.at(i)->Address().Port() == playerAddr.Port()) {
				player.at(i)->Character()[0]->SetMoveDirection(packet.MoveDir());
			}
		}
		std::cout << "MoveDir: " << packet.MoveDir().x << "|" << packet.MoveDir().y << std::endl;
	}

	void HandlePlayerRegisterPacket(SocketAddress playerAddr, PlayerRegisterPacket p) override {
		player.push_back(PlayerPtr{new Player(playerAddr, std::vector<CharacterPtr>())});
		player.back()->AddCharacter(CharacterPtr{ new Character(FVector2{0,0}) });
	}
private:
	void SendCharacterPositions() {
		while (active) {
			for (int i = 0; i < player.size(); ++i) {
				PlayerPtr p = player.at(i);
				auto pos = p->Character()[0]->Position();
				CharacterPositionPacket posPacket{ pos };
				udpSocket->Send(posPacket.PacketFormat().first.get(), posPacket.PacketFormat().second, p->Address());
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(15));
		}
	}
};