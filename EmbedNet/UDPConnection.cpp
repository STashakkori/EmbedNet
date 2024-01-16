#include "UDPConnection.h"
#include <Poco/Net/NetException.h>
#include <iostream>

UDPConnection::UDPConnection(const NetworkConfiguration& config, std::shared_ptr<NetworkTimer> timer)
    : timer_(std::move(timer)), sendInterval_(config.getTimerInterval()) {
    try {
        int port = std::stoi(config.getPort());
        endpoint_ = Poco::Net::SocketAddress(config.getIPAddress(), port);
        socket_ = Poco::Net::DatagramSocket(); // Create the socket without binding
        socket_.bind(endpoint_);               // Bind the socket to the endpoint
        socket_.setBlocking(false);
    }
    catch (const Poco::Net::NetException& exc) {
        std::cerr << "Network exception: " << exc.displayText() << std::endl;
        throw;
    }
    catch (const std::exception& exc) {
        std::cerr << "Exception: " << exc.what() << std::endl;
        throw;
    }
}

UDPConnection::~UDPConnection() {
    stopSending();
    socket_.close();
}

void UDPConnection::send(const std::string& message) {
    messageToSend_ = message;
    startSending();
}

std::string UDPConnection::receive() {
    char buffer[1024];
    Poco::Net::SocketAddress sender;
    int n = socket_.receiveFrom(buffer, sizeof(buffer), sender);
    return std::string(buffer, n);
}

void UDPConnection::startSending() {
    if (sendInterval_ > 0) {
        timer_->start([this]() { onTimerTick(); });
    }
    else if (sendInterval_ == 0) {
        onTimerTick();
    }
    // If sendInterval_ is MAX_INT, do nothing, effectively continuous sending
}

void UDPConnection::stopSending() {
    if (timer_) {
        timer_->stop();
    }
}

void UDPConnection::onTimerTick() {
    if (!messageToSend_.empty()) {
        socket_.sendTo(messageToSend_.data(), messageToSend_.size(), endpoint_);
    }
}
