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
            auto timer = std::make_shared<MonotonicTimer>(config.getTimerInterval());
            auto connection = std::make_shared<UDPConnection>(config, timer);

            std::string key = config.getIPAddress() + ":" + config.getPort();
            connections_[key] = connection;

            return connection;
        }
        return nullptr;
    }

private:
    std::unordered_map<std::string, std::shared_ptr<NetworkConnection>> connections_;
};

#endif // NETWORKFACTORY_HPPx