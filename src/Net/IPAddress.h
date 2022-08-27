#pragma once 

#include <string>
#include "Poco/Net/IPAddress.h"
#include "IIPAddress.h"

class IPAddress : public IIPAddress {
private:
	Poco::Net::IPAddress pocoIp;
public:
	IPAddress(std::string ipString) {
		pocoIp = Poco::Net::IPAddress(ipString);
	}
	IPAddress(Poco::Net::IPAddress pocoIp) {
		this->pocoIp = pocoIp;
	}
	std::string ToString() override {
		return pocoIp.toString();
	}

	std::shared_ptr<uint8_t> Bytes() override {
		std::shared_ptr<uint8_t> raw{ new uint8_t[4] };
		memcpy(raw.get(), pocoIp.addr(), 4);
		return raw;
	}
};