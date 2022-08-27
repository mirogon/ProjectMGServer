#include <catch2/catch_test_macros.hpp>
#include "src/PacketDistributor.h"
#include "src/Server.h"
#include "src/Net/UdpSocket.h"

TEST_CASE("Creation", "[PacketDistributor]") {
	ServerPtr server{ new Server() };
	UdpSocketPtr udpSocket{ new UdpSocket(0) };
	PacketDistributor distributor{udpSocket, server};
}
