#pragma once

#include "threadGuard.hpp"

thread_guard::thread_guard() {
    //
}

thread_guard::~thread_guard() {
    if (t.joinable()) {
        t.join();
    }
}

void thread_guard::start(std::function<void(std::string)>& f, std::string s) {
    t = std::thread(f, s);
}

void thread_guard::stop() {
    if (t.joinable()) {
        t.join();
    }
}
