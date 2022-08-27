cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(Game LANGUAGES CXX)

add_executable(ProjectMGServer 
	"src/main.cpp"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(Catch2 3 REQUIRED)
#find_package(protobuf)
#find_package(GameNetworkingSockets CONFIG REQUIRED)

find_package(Poco REQUIRED COMPONENTS Foundation Net Util)
add_executable(ProjectMGServerTest 
	"test/test.cpp"
	"test/ServerTest.cpp"
	"test/Net/IPAddressTest.cpp"
	"test/Net/SocketAddressTest.cpp"
	"test/Net/TcpSocketTest.cpp"
)

#target_link_libraries(ProjectMGServer PUBLIC GameNetworkingSockets::shared)
target_link_libraries(ProjectMGServerTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(ProjectMGServerTest PRIVATE GTest::gtest GTest::gmock)
target_link_libraries(ProjectMGServerTest PRIVATE Poco::Foundation Poco::Net Poco::Util)
target_link_libraries(ProjectMGServer PRIVATE Poco::Foundation Poco::Net Poco::Util)

include_directories(.)