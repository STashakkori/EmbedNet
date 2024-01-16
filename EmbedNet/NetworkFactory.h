#ifndef NETWORKFACTORY_H
#define NETWORKFACTORY_H

#include "NetworkConfiguration.h"
#include "UDPConnection.h"
#include "MonotonicTimer.h"
#include <memory>
#include <unordered_map>
#include <string>

class NetworkFactory {
public:
    ~NetworkFactory() {
        connections_.clear();
    }

    std::shared_ptr<NetworkConnection> createConnection(const NetworkConfiguration& config) {
        if (config.getProtocol() == "UDP") {
            // Ensuring a valid timer interval
            int timerInterval = config.getTimerInterval() > 0 ? config.getTimerInterval() : 1000; // Default interval
            auto timer = std::make_shared<MonotonicTimer>(timerInterval);
            auto connection = std::make_shared<UDPConnection>(config, timer);

            std::string key = config.getIPAddress() + ":" + config.getPort();
            connections_[key] = connection;

            return connection;
        }
        return nullptr; // Return nullptr for unsupported protocols
    }

private:
    std::unordered_map<std::string, std::shared_ptr<NetworkConnection>> connections_;
};

#endif // NETWORKFACTORY_HPPx