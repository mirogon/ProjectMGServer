#pragma once
#include <memory>
#include "SocketAddress.h"

class IUdpSocket {
public:
	virtual SocketAddress LocalAddress() = 0;
	virtual void Send(void* data, int dataSize, SocketAddress dest) = 0;
	virtual std::pair<std::shared_ptr<uint8_t>, int> Receive() = 0;
	virtual void Close() = 0;
};

typedef std::shared_ptr<IUdpSocket> UdpSocketPtr;
