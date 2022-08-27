#include "Server.h"
#include "Packets.h"
#include "Net/UdpSocket.h"

int main(int argc, char* argv[]){
    ServerPtr server{ new Server() };

    UdpSocketPtr udpSocket{ new UdpSocket(55580) };
    while (true) {
		auto received = udpSocket->Receive();
        if (received.first.get()[1] == PacketType::CharacterMove) {
			CharacterMovePacket packet{ received.first.get() };
			std::cout << "MoveDir: " << packet.MoveDir().x << "|" << packet.MoveDir().y << std::endl;
        }
        else {
            std::cout << "Received packet with invalid type" << std::endl;
        }
    }

    return 0;
}