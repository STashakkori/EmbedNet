#include "ContextManager.h"

ContextManager::ContextManager(const std::string& context) : context_(context) {}

void ContextManager::createContext() {
    // Implement your context creation logic here
}

void ContextManager::destroyContext() {
    // Implement your context destruction logic here
}

std::string ContextManager::getContext() const {
    return context_;
}
