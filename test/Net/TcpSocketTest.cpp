#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <thread>

#include "src/Net/TcpSocket.h"
#include "Poco/Net/IPAddress.h"

TEST_CASE("Connecting_Works", "TcpSocket") {
	TcpSocketPtr socket;
	std::thread t = std::thread([&]() {
		socket = TcpSocket::Accept("127.0.0.1", 55560);
	});
	auto connectingSocket = TcpSocket::Connect("127.0.0.1", 55560);
	t.join();
	REQUIRE("127.0.0.1:55560" == connectingSocket->RemoteAddress().ToString());
	REQUIRE(0 == socket->Available());
}

TEST_CASE("SendAndReceive_WithNewReceiveRefactor_Works", "[TcpSocket]") {
	TcpSocketPtr socket;
	std::thread t = std::thread([&]() {
		socket = TcpSocket::Accept("127.0.0.1", 55561);
	});
	auto connectingSocket = TcpSocket::Connect("127.0.0.1", 55561);
	t.join();

	uint8_t data[128];
	for (int i = 0; i < 128; ++i) {
		data[i] = i;
	}
	connectingSocket->Send(&data, 128);

	std::pair<std::shared_ptr<uint8_t>, int> dataReceived = socket->Receive();

	REQUIRE(1440 == dataReceived.second);
	for (int i = 0; i < 128; ++i) {
		REQUIRE((uint8_t)i == dataReceived.first.get()[i]);
	}
}
