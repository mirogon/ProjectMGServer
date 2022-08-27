#pragma once

#include "ITcpSocket.h"
#include "IPAddress.h"
#include "SocketAddress.h"
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/ServerSocket.h>

using std::shared_ptr;

class TcpSocket : public ITcpSocket {
private:
	Poco::Net::StreamSocket pocoSocket;
public:

	TcpSocket() = delete;
	TcpSocket(Poco::Net::StreamSocket socket) {
		this->pocoSocket = socket;
	}

	static TcpSocketPtr Accept(std::string address, uint16_t port) {
		Poco::Net::ServerSocket serverSocket = Poco::Net::ServerSocket(port);
		auto pocoSocket = serverSocket.acceptConnection();
		return shared_ptr<TcpSocket>(new TcpSocket(pocoSocket));
	}

	static TcpSocketPtr Connect(std::string address, uint16_t port){
		Poco::Net::SocketAddress pocoSocketAddr = Poco::Net::SocketAddress(address, port);
		Poco::Net::StreamSocket streamSocket = Poco::Net::StreamSocket(pocoSocketAddr);
		return shared_ptr<TcpSocket>(new TcpSocket(streamSocket));
	}

	void Send(void* data, int dataSize) override {
		uint8_t dataSized[1440];
		memcpy(dataSized, data, dataSize);
		pocoSocket.sendBytes(dataSized, 1440);
	}

	std::pair<std::shared_ptr<uint8_t>, int> Receive() override {
		while (pocoSocket.available() < 1440) {};
		uint8_t* buffer = new uint8_t[1440];
		int received = pocoSocket.receiveBytes(buffer, 1440);
		return std::make_pair(std::shared_ptr<uint8_t>(buffer), received);
	}

	SocketAddress RemoteAddress() override {
		IPAddressPtr ipPtr = IPAddressPtr(new IPAddress(pocoSocket.peerAddress().host()));
		return SocketAddress(ipPtr, pocoSocket.peerAddress().port());
	}

	void Close() override {
		pocoSocket.close();
	}

	int Available() override {
		return pocoSocket.available();
	}
};
