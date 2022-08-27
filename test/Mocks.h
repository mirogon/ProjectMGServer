#include "gmock/gmock.h"
#include "src/IServer.h"
#include "src/Packets.h"
#include <utility>
#include <memory>
#include "src/Net/UdpSocket.h"
#include "src/Net/SocketAddress.h"

class ServerMock : public IServer {
public:
	MOCK_METHOD(void, HandleCharacterMovePacket, (SocketAddress, CharacterMovePacket), (override));
	MOCK_METHOD(void, HandlePlayerRegisterPacket, (SocketAddress, PlayerRegisterPacket), (override));
};

class MockUdpSocket : public IUdpSocket {
public:

	MOCK_METHOD(SocketAddress, LocalAddress, (), (override));
	MOCK_METHOD(void, Send, (void*, int, SocketAddress), (override));
	MOCK_METHOD((std::pair<std::shared_ptr<uint8_t>, int>), Receive, (), (override));
	MOCK_METHOD((std::pair<std::shared_ptr<uint8_t>,int>), ReceiveFrom, (SocketAddress&), (override));
	MOCK_METHOD(void, Close, (), (override));
};