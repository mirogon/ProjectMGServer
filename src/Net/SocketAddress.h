#pragma once

#include <string>
#include "IPAddress.h"

class SocketAddress {
private:
	IPAddressPtr ip;
	uint16_t port;
public:
	SocketAddress(IPAddressPtr ip, uint16_t port){
		this->ip = ip;
		this->port = port;
	}
	std::string ToString() {
		return ip->ToString() + ":" + std::to_string(port);
	}
	IPAddressPtr Address() {
		return ip;
	}
	uint16_t Port() {
		return port;
	}
};