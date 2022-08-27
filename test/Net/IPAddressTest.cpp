#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <thread>

#include "src/Net/IPAddress.h"

using std::shared_ptr;
using std::string;

TEST_CASE("ToString_EqualsGiven", "IPAddress") {
	string ipString = "127.0.0.1";
	auto ip = shared_ptr<IPAddress>(new IPAddress(ipString));
	REQUIRE(ipString == ip->ToString());
}
TEST_CASE("Bytes_EqualIp", "IPAddress") {
	IPAddressPtr ip{ new IPAddress("192.168.0.100") };
	uint8_t expected[4];
	expected[0] = 192;
	expected[1] = 168;
	expected[2] = 0;
	expected[3] = 100;

	for (int i = 0; i < 4; ++i) {
		REQUIRE(expected[i] == ip->Bytes().get()[i]);
	}
}
