#ifndef NETWORKCONFIGURATION_HPP
#define NETWORKCONFIGURATION_HPP

#include <string>
#include <limits>

class NetworkConfiguration {
public:
    NetworkConfiguration(const std::string& protocol, const std::string& ipAddress, const std::string& port, const std::string& bufferSize, int timerInterval = std::numeric_limits<int>::max())
        : protocol_(protocol), ipAddress_(ipAddress), port_(port), bufferSize_(bufferSize), timerInterval_(timerInterval) {}

    std::string getProtocol() const { return protocol_; }
    std::string getIPAddress() const { return ipAddress_; }
    std::string getPort() const { return port_; }
    std::string getBufferSize() const { return bufferSize_; }
    int getTimerInterval() const { return timerInterval_; }

private:
    std::string protocol_;
    std::string ipAddress_;
    std::string port_;
    std::string bufferSize_;
    int timerInterval_;
};

#endif // NETWORKCONFIGURATION_HPP