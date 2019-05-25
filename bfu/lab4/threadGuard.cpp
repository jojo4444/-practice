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

void thread_guard::stop() {
    if (t.joinable()) {
        t.join();
    }
}

void thread_guard::start(std::function<void(int, int, int)>& f, int id, int l, int r) {
    t = std::thread(f, id, l, r);
}
