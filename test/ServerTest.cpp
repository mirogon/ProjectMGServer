#include <catch2/catch_test_macros.hpp>
#include "src/Server.h"
#include "src/Packets.h"
#include "src/Game/CharacterMover.h"
#include "src/Game/Player.h"
#include "src/Net/UdpSocket.h"
#include "src/PacketDistributor.h"
#include "test/Mocks.h"

using ::testing::Return;
using ::testing::AtLeast;
using ::testing::_;

TEST_CASE("Creation", "[Server]") {
	std::vector<PlayerPtr> player = std::vector<PlayerPtr>();
	CharacterMoverPtr mover{ new CharacterMover() };
	UdpSocketPtr udpSocket{ new UdpSocket(0) };
	ServerPtr server{ new Server(udpSocket, player, mover) };
}

TEST_CASE("HandleCharacterMovePacket", "[Server]") {
	std::vector<PlayerPtr> player = std::vector<PlayerPtr>();
	CharacterMoverPtr mover{ new CharacterMover() };
	UdpSocketPtr udpSocket{ new UdpSocket(0) };
	ServerPtr server{ new Server(udpSocket, player, mover) };
	CharacterMovePacket p{ Vector2{0,1} };
	SocketAddress addr{ IPAddressPtr{new IPAddress{"0.0.0.0"}}, 0 };
	server->HandleCharacterMovePacket(addr, p);
}

TEST_CASE("HandlePlayerRegisterPacket", "[Server]") {
	std::vector<PlayerPtr> player = std::vector<PlayerPtr>();
	CharacterMoverPtr mover{ new CharacterMover() };
	UdpSocketPtr udpSocket{ new UdpSocket(0) };
	ServerPtr server{ new Server(udpSocket, player, mover) };
	PlayerRegisterPacket p{};
	SocketAddress addr{ IPAddressPtr{new IPAddress{"0.0.0.0"}}, 0 };
	server->HandlePlayerRegisterPacket(addr, p);
}

TEST_CASE("SendsCharacterPositionPackets", "[Server]") {
	std::vector<PlayerPtr> player = std::vector<PlayerPtr>();
	CharacterMoverPtr mover{ new CharacterMover() };
	MockUdpSocket mockUdpSocket;

	EXPECT_CALL(mockUdpSocket, Close);
	EXPECT_CALL(mockUdpSocket, Send).Times(AtLeast(1));

	PlayerRegisterPacket rp{};
	std::pair<std::shared_ptr<uint8_t>, int> pair = std::make_pair(std::shared_ptr<uint8_t>(new uint8_t[2]), 2);
	EXPECT_CALL(mockUdpSocket, ReceiveFrom).WillOnce(Return(rp.PacketFormat()))
		.WillRepeatedly(Return(pair));
	
	UdpSocketPtr udpSocket{ &mockUdpSocket, [](IUdpSocket* u) {} };
	ServerPtr server{ new Server(udpSocket, player, mover) };
	PlayerRegisterPacket p{};
	SocketAddress addr{ IPAddressPtr{new IPAddress{"0.0.0.0"}}, 0 };

	PacketDistributor d{ udpSocket, server };

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
