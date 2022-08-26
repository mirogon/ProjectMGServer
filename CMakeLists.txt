cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(Game LANGUAGES CXX)

add_executable(GameServer "src/main.cpp")

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

#find_package(Poco REQUIRED COMPONENTS Foundation Net Util)
add_executable(GameServerTest "test/test.cpp")

target_link_libraries(GameServerTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(GameServerTest PRIVATE GTest::gtest GTest::gmock)
#target_link_libraries(GameServerTest PRIVATE Poco::Foundation Poco::Net Poco::Util)