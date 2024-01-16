#pragma once

#include "Poco/Timer.h"
#include "Poco/Thread.h"

class FactoryTimer {
public:
    FactoryTimer(int workTime, int holdingTime);
    void start();
    void stop();

private:
    void onTimer(Poco::Timer& timer);

private:
    Poco::Timer workHoldingTimer_;
    int workTime_;
    int holdingTime_;
};