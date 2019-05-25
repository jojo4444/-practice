#pragma once

#include <thread>
#include <functional>

class thread_guard {
public:
    ~thread_guard();
    thread_guard();

    void stop();
    void start(std::function<void(int, int, int)>& f, int id, int l, int r);
private:
    std::thread t;
};
