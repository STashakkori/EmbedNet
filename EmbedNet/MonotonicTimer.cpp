#include "MonotonicTimer.h"

void MonotonicTimer::run() {
    while (!stop_) {
        if (callback_) {
            callback_();
        }
        Poco::Thread::sleep(interval_);
    }
}

void MonotonicTimer::start(std::function<void()> callback) {
    callback_ = callback;
    if (!thread_.isRunning()) {
        stop_ = false;
        thread_.start(*this);
    }
}

void MonotonicTimer::stop() {
    stop_ = true;
    thread_.join();
}