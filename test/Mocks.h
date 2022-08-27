#include "gmock/gmock.h"
#include "src/IServer.h"
#include "src/Packets.h"

class ServerMock : public IServer {
public:
	MOCK_METHOD(void, HandleCharacterMovePacket, (SocketAddress, CharacterMovePacket), (override));
};