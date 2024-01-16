#ifndef NETWORKCONNECTION_HPP
#define NETWORKCONNECTION_HPP

#include <string>

class NetworkConnection {
public:
    virtual ~NetworkConnection() {}
    virtual void send(const std::string& message) = 0;
    virtual std::string receive() = 0;
};

#endif // NETWORKCONNECTION_HPP