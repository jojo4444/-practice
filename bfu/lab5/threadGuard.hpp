#pragma once

#include <iostream>
#include <thread>
#include <functional>

class thread_guard {
public:
    ~thread_guard();
    thread_guard();

    void start(std::function<void(std::string)>& f, std::string s);
    void stop();

private:
    std::thread t;
};
