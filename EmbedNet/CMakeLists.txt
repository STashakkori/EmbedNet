cmake_minimum_required(VERSION 3.12)

project(EmbedNet)

find_package(GTest REQUIRED)
find_package(Poco REQUIRED COMPONENTS Foundation Net)
include(GoogleTest)

add_executable(EmbedNet
"EmbedNet.cpp"
"EmbedNet.h"
"FactoryTimer.cpp"
"FactoryTimer.h"
"MonotonicTimer.cpp"
"MonotonicTimer.h"
"NetworkConfiguration.h"
"NetworkConnection.h"
"NetworkFactory.h"
"UDPConnection.cpp"
"UDPConnection.h")

set_property(TARGET EmbedNet PROPERTY CXX_STANDARD 20)

target_link_libraries(EmbedNet PRIVATE Poco::Foundation Poco::Net)

add_executable(NetworkTest
"NetworkTest.cpp"
"NetworkFactory.h"
"NetworkConfiguration.h"
"UDPConnection.cpp"
"UDPConnection.h"
"MonotonicTimer.cpp"
"MonotonicTimer.h")

target_link_libraries(NetworkTest PRIVATE GTest::GTest GTest::Main Poco::Foundation Poco::Net)

gtest_discover_tests(NetworkTest)