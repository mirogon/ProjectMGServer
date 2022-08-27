#include <catch2/catch_test_macros.hpp>
#include "src/Net/UdpSocket.h"
#include "src/Net/SocketAddress.h"

TEST_CASE("Creation", "[UdpSocket]") {
	UdpSocketPtr udpSocket{ new UdpSocket(55580) };
	REQUIRE(55580 == udpSocket->LocalAddress().Port());
}

TEST_CASE("Send_WithInvalidAddr_DoesntThrow", "[UdpSocket]") {
	UdpSocketPtr udpSocket{ new UdpSocket(55580) };
	SocketAddress addr{ IPAddressPtr{new IPAddress("127.0.0.1")}, 55555 };
	udpSocket->Send(new char{'A'}, 1, addr);
	REQUIRE(true);
}

TEST_CASE("Receive_Works", "[UdpSocket]") {
	UdpSocketPtr udpSocket{ new UdpSocket(55580) };

	Poco::Net::DatagramSocket pocoSocket{ Poco::Net::SocketAddress{Poco::Net::IPAddress{"127.0.0.1"}, 0} };
	pocoSocket.sendTo(new char{ 'A' }, 1, Poco::Net::SocketAddress{ Poco::Net::IPAddress{"127.0.0.1"}, 55580 });

	auto data = udpSocket->Receive();

	REQUIRE('A' == data.first.get()[0]);
	REQUIRE('B' != data.first.get()[0]);
}

TEST_CASE("ReceiveFrom", "[UdpSocket]") {
	UdpSocketPtr udpSocket{ new UdpSocket(55580) };

	Poco::Net::DatagramSocket pocoSocket{ Poco::Net::SocketAddress{Poco::Net::IPAddress{"127.0.0.1"}, 0} };
	pocoSocket.sendTo(new char{ 'A' }, 1, Poco::Net::SocketAddress{ Poco::Net::IPAddress{"127.0.0.1"}, 55580 });

	SocketAddress receivedFrom{IPAddressPtr{new IPAddress("0.0.0.0")}, 50};
	auto data = udpSocket->ReceiveFrom(receivedFrom);

	REQUIRE(pocoSocket.address().port() == receivedFrom.Port());
	REQUIRE('A' == data.first.get()[0]);
	REQUIRE('B' != data.first.get()[0]);

}
