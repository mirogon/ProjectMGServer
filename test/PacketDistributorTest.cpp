#include <catch2/catch_test_macros.hpp>
#include "src/PacketDistributor.h"
#include "src/Server.h"
#include "src/Net/UdpSocket.h"
#include "gmock/gmock.h"
#include "Mocks.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

TEST_CASE("Creation", "[PacketDistributor]") {
	std::vector<PlayerPtr> player = std::vector<PlayerPtr>();
	CharacterMoverPtr mover{ new CharacterMover() };
	UdpSocketPtr udpSocket{ new UdpSocket(0) };
	ServerPtr server{ new Server(udpSocket,player, mover) };
	PacketDistributor distributor{udpSocket, server};
}

TEST_CASE("DistributePlayerRegister_CallsServerHandlePlayerRegister", "[PacketDistributor]") {
	ServerMock serverMock = ServerMock();
	ServerPtr server{ &serverMock , [](IServer* s) {} };

	EXPECT_CALL(serverMock, HandlePlayerRegisterPacket).Times(1);

	UdpSocketPtr udpSocket{ new UdpSocket(55580) };
	PacketDistributor distributor{ udpSocket, server };

	UdpSocketPtr sendSocket{ new UdpSocket(0) };
	auto p = PlayerRegisterPacket{}.PacketFormat();
	SocketAddress addr{ IPAddressPtr{new IPAddress("127.0.0.1")}, 55580 };
	sendSocket->Send(p.first.get(), p.second, addr);
}

TEST_CASE("DistributeCharacterMove_CallsServerHandleCharacterMove", "[PacketDistributor]") {
	ServerMock serverMock = ServerMock();
	ServerPtr server{ &serverMock , [](IServer* s) {} };

	EXPECT_CALL(serverMock, HandleCharacterMovePacket).Times(1);

	UdpSocketPtr udpSocket{ new UdpSocket(55580) };
	PacketDistributor distributor{ udpSocket, server };

	UdpSocketPtr sendSocket{ new UdpSocket(0) };
	auto p = CharacterMovePacket{ Vector2{0,1} }.PacketFormat();
	SocketAddress addr{ IPAddressPtr{new IPAddress("127.0.0.1")}, 55580 };
	sendSocket->Send(p.first.get(), p.second, addr);

}

