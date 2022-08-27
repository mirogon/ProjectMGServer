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
		udpSocket->Close();
		receiveThread.join();
	}

private:

	void ReceivePackets() {
		try {
			while (active){
				SocketAddress addr{ IPAddressPtr{new IPAddress{"0.0.0.0"}}, 0 };
				auto data = udpSocket->ReceiveFrom(addr);
				if (data.first.get()[1] == PacketType::CharacterMove) {
					CharacterMovePacket p{ data.first.get() };
					server->HandleCharacterMovePacket(addr, p);
				}
			}
		}
		catch (...) {
		}
	}

};