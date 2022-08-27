#include "TcpSocket.h"
#include "src/Net/TcpSocket.h"
#include "src/Net/IPAddress.h"

class NullTcpSocket : public ITcpSocket {
public:
	SocketAddress RemoteAddress() {
		IPAddressPtr ip = IPAddressPtr(new IPAddress("0.0.0.0"));
		return SocketAddress(ip, 50);
	}
	void Send(void* data, int dataSize)override {
	}
	std::pair<std::shared_ptr<uint8_t>, int> Receive() override {
		return std::pair<std::shared_ptr<uint8_t>, int>();
	}
	int Available() override {
		return 0;
	}
	void Close() override {
	}
};
