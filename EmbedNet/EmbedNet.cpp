// $t@$h     QVLx Labs
#include "EmbedNet.h"
#include "FactoryTimer.h"
#include "ContextManager.h"

#include <Poco/DateTime.h>
#include <Poco/DateTimeFormatter.h>
#include <Poco/DateTimeFormat.h>
#include <iostream>
#include "NetworkFactory.h"
#include "NetworkConfiguration.h"
#include <limits>

int main()
{
        NetworkConfiguration config("UDP", "127.0.0.1", "8080", "1024", 1000); // 1000 ms interval
        NetworkFactory factory;
        auto connection = std::dynamic_pointer_cast<UDPConnection>(factory.createConnection(config));

        if (connection) {
            connection->send("Hello, UDP!");
            std::string response = connection->receive();
            std::cout << "Received response: " << response << std::endl;
        }
    return 0;
}
