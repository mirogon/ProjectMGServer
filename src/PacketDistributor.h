#pragma once
#include "src/Server.h"

class PacketDistributor {
private:
	ServerPtr server;
public:
	PacketDistributor(ServerPtr server) {
		this->server = server;
	}
};