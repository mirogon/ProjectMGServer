#pragma once
#include <memory>

class IServer {
public:
	virtual void EMPTY_INTERFACE() = 0;
};

typedef std::shared_ptr<IServer> ServerPtr;