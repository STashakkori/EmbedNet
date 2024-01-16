#ifndef MONOTONICTIMER_H
#define MONOTONICTIMER_H

#include "NetworkTimer.h"
#include <Poco/Runnable.h>
#include <Poco/Thread.h>
#include <functional>

class MonotonicTimer : public NetworkTimer, public Poco::Runnable {
public:
    explicit MonotonicTimer(int interval);

    void run() override;
    void start(std::function<void()> callback) override;
    void stop() override;

private:
    int interval_;
    bool stop_;
    std::function<void()> callback_;
    Poco::Thread thread_;
};

#endif // MONOTONICTIMER_H