#ifndef UDPCONNECTION_HPP
#define UDPCONNECTION_HPP

#include "NetworkConnection.h"
#include "NetworkConfiguration.h"
#include "NetworkTimer.h"
#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <string>
#include <memory>

class UDPConnection : public NetworkConnection {
public:
    UDPConnection(const NetworkConfiguration& config, std::shared_ptr<NetworkTimer> timer);
    ~UDPConnection();

    void send(const std::string& message) override;
    std::string receive() override;
    void startSending();
    void stopSending();

private:
    Poco::Net::DatagramSocket socket_;
    Poco::Net::SocketAddress endpoint_;
    std::shared_ptr<NetworkTimer> timer_;
    std::string messageToSend_;
    int sendInterval_;

    void onTimerTick();
};

#endif // UDPCONNECTION_HPP