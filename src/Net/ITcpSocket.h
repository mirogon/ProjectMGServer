#pragma once
#include <memory>
#include <utility>
#include "SocketAddress.h"

class ITcpSocket {
public:
	virtual int Available() = 0;
	virtual SocketAddress RemoteAddress() = 0;
	virtual void Send(void* data, int dataSize) = 0;
	virtual std::pair<std::shared_ptr<uint8_t>, int> Receive() = 0;
	virtual void Close() = 0;
};

typedef std::shared_ptr<ITcpSocket> TcpSocketPtr;