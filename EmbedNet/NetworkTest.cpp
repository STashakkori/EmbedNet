#include <gtest/gtest.h>
#include <memory>
#include "NetworkFactory.h"
#include "NetworkConfiguration.h"
#include "UDPConnection.h"
#include "MonotonicTimer.h"

TEST(NetworkFactoryTest, FactoryConstructionTest) {
	NetworkFactory netFactory;
	ASSERT_NE(nullptr, &netFactory);
}

TEST(NetworkConfigurationTest, ConfigurationConstructionTest) {
	std::string ip = "127.0.0.1";
	std::string port = "8007";
	NetworkConfiguration netConfig("UDP", ip, port, "4096");
	ASSERT_NE(nullptr, &netConfig);
}

TEST(NetworkConfigurationTest, ConfigurationFieldsTest) {
	std::string ip = "127.0.0.1";
	std::string port = "8007";
	std::string bufferSize = "4096";

	NetworkConfiguration netConfig("UDP", ip, port, bufferSize);

	// Check the fields individually
	EXPECT_EQ("UDP", netConfig.getProtocol());
	EXPECT_EQ(ip, netConfig.getIPAddress());
	EXPECT_EQ(port, netConfig.getPort());
	EXPECT_EQ(bufferSize, netConfig.getBufferSize());
}

TEST(NetworkConnectionTest, CreateCloseConnectionTest) {
	NetworkFactory netFactory;
	std::string ip = "127.0.0.1";
	std::string port = "8008";
	NetworkConfiguration netConfig("UDP", ip, port, "4096");

	auto connection = netFactory.createConnection(netConfig);
	ASSERT_NE(nullptr, connection);
}