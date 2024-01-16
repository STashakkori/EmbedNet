#pragma once

#include <string>

class ContextManager {
public:
    ContextManager(const std::string& context);
    void createContext();
    void destroyContext();
    std::string getContext() const;

private:
    std::string context_;
};
