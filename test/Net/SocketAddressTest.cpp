#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <thread>

#include "src/Net/IPAddress.h"
#include "src/Net/SocketAddress.h"

using std::shared_ptr;

TEST_CASE("ToString_WithGivenIp_Correct", "[SocketAddress]") {
	auto ip = shared_ptr<IPAddress>(new IPAddress("127.0.0.1"));
	auto socketAddr = shared_ptr<SocketAddress>(new SocketAddress(ip, 55560));
	REQUIRE("127.0.0.1:55560" == socketAddr->ToString());
}

TEST_CASE("AddressAndPort_EqualsGiven", "[SocketAddress]") {
	auto ip = shared_ptr<IPAddress>(new IPAddress("255.255.255.0"));
	auto socketAddr = shared_ptr<SocketAddress>(new SocketAddress(ip, 55560));
	REQUIRE(ip == socketAddr->Address());
	REQUIRE(55560 == socketAddr->Port());
}
