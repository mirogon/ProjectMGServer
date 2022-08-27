#pragma once
#include "src/Server.h"
#include "src/Packets.h"
#include "src/Net/UdpSocket.h"
#include <thread>

class PacketDistributor {
private:
	UdpSocketPtr udpSocket;
	ServerPtr server;
	std::thread receiveThread;
	bool active;
public:
	PacketDistributor(UdpSocketPtr socket, ServerPtr server) {
		this->udpSocket = socket;
		this->server = server;
		active = true;
		receiveThread = std::thread(&PacketDistributor::ReceivePackets, this);
	}
	~PacketDistributor() {
		active = false;
		receiveThread.join();
	}

private:

	void ReceivePackets() {
		while (active){
			auto data = udpSocket->Receive();
			if (data.first.get()[1] == PacketType::CharacterMove) {
				CharacterMovePacket p{ data.first.get() };
				server->HandleCharacterMovePacket(p);
			}
		}
	}

};