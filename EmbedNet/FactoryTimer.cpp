#include "FactoryTimer.h"
#include <iostream>

FactoryTimer::FactoryTimer(int workTime, int holdingTime)
    : workTime_(workTime), holdingTime_(holdingTime) {}

void FactoryTimer::start() {
    workHoldingTimer_.start(Poco::TimerCallback<FactoryTimer>(*this, &FactoryTimer::onTimer));
}

void FactoryTimer::stop() {
    workHoldingTimer_.stop();
}

void FactoryTimer::onTimer(Poco::Timer& timer) {
    // This is where you implement the work to be done
    std::cout << "Doing work..." << std::endl;

    // Simulate work by sleeping for workTime milliseconds
    Poco::Thread::sleep(workTime_);

    // This is where you implement the holding/waiting phase
    std::cout << "Holding..." << std::endl;

    // Simulate holding by sleeping for holdingTime milliseconds
    Poco::Thread::sleep(holdingTime_);
}
