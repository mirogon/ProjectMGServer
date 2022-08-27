#include "Server.h"
#include "Packets.h"
#include "Net/UdpSocket.h"
#include "PacketDistributor.h"

int main(int argc, char* argv[]){
    ServerPtr server{ new Server() };
    UdpSocketPtr udpSocket{ new UdpSocket(55580) };
    PacketDistributor packetDistributor{ udpSocket, server };
    while(true){}
    return 0;
}