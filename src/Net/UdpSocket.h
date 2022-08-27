#pragma once
#include <utility>
#include "IUdpSocket.h"
#include "Poco/Net/DatagramSocket.h"

class UdpSocket : public IUdpSocket {
private:
	Poco::Net::DatagramSocket pocoSocket;
public:
	UdpSocket(uint16_t port){
		pocoSocket = Poco::Net::DatagramSocket(Poco::Net::SocketAddress(Poco::Net::IPAddress("0.0.0.0"), port));
	}

	void Send(void* data, int dataSize, SocketAddress dest) {
		pocoSocket.sendTo(data, dataSize, Poco::Net::SocketAddress(Poco::Net::IPAddress(dest.Address()->ToString()), dest.Port()));
	}

	std::pair<std::shared_ptr<uint8_t>, int> Receive() override {
		uint8_t* buffer = new uint8_t[1500];
		int received = pocoSocket.receiveBytes(buffer, 1500);
		std::shared_ptr<uint8_t> data{buffer};
		return std::make_pair(data, received);
	}

	std::pair<std::shared_ptr<uint8_t>, int> ReceiveFrom(SocketAddress& from) override {
		uint8_t* buffer = new uint8_t[1500];
		Poco::Net::SocketAddress addr;
		int received = pocoSocket.receiveFrom(buffer, 1500, addr);
		from = SocketAddress{ IPAddressPtr(new IPAddress(addr.host().toString())), addr.port() };
		std::shared_ptr<uint8_t> data{buffer};
		return std::make_pair(data, received);
	}

	SocketAddress LocalAddress() override {
		return SocketAddress(IPAddressPtr{ new IPAddress(pocoSocket.address().host()) }, pocoSocket.address().port());
	}

	void Close() override {
		pocoSocket.close();
	}
};