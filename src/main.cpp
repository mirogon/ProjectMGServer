#include "Server.h"
#include "Packets.h"
#include "Net/UdpSocket.h"
#include "PacketDistributor.h"
#include "src/Game/Player.h"

int main(int argc, char* argv[]){
    std::vector<PlayerPtr> player = std::vector<PlayerPtr>();
    CharacterMoverPtr charMover{ new CharacterMover() };
    UdpSocketPtr udpSocket{ new UdpSocket(55580) };
    ServerPtr server{ new Server(udpSocket, player, charMover) };
    PacketDistributor packetDistributor{ udpSocket, server };
    while(true){}
    return 0;
}