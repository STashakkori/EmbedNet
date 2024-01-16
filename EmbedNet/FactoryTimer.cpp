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

}
