#include <catch2/catch_test_macros.hpp>
#include "src/Server.h"

TEST_CASE("Creation", "[Server]") {
	ServerPtr server{ new Server() };
}