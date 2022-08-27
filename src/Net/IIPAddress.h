#pragma once
#include "Poco/Net/IPAddress.h"

class IIPAddress {
public:
	virtual std::string ToString() = 0;
	virtual std::shared_ptr<uint8_t> Bytes() = 0;
};

typedef std::shared_ptr<IIPAddress> IPAddressPtr;