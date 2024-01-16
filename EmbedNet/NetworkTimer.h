#ifndef NETWORKTIMER_H
#define NETWORKTIMER_H

#include <functional>

class NetworkTimer {
public:
    virtual ~NetworkTimer() = default;
    virtual void start(std::function<void()> callback) = 0;
    virtual void stop() = 0;
};

#endif // NETWORKTIMER_H