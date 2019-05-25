#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <vector>
#include <map>
#include <fstream>
#include <type_traits>

#include "myStack.hpp"
#include "threadGuard.hpp"

using std::string;
using std::cout;
using std::cin;
using std::map;
using std::vector;

class myClass {
public:
    myClass(int x = -4) :
        x_(x) {}

    int getX() const {
        return x_;
    }

private:
    int x_;
};

Stack <myClass> kek;

mutex print_m;

void turn(string s) {
    std::ifstream fin(s);
    int n, x;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        string op;
        fin >> op;
        if (op == "push") {
            fin >> x;
            kek.push(myClass(x));
        } else if (op == "pop") {
            kek.pop();
        } else {
            myClass top = kek.top();
            lock_guard<mutex> lock(print_m);
            cout << "thread: " << s[0] << ", top : " << top.getX() << "\n";
        }
    }

    fin.close();
}

int main() {
    string files[] = {"1.txt", "2.txt", "3.txt"};

    thread_guard ths[3];

    std::function<void(string)> f = &turn;
    for (int i = 0; i < 3; ++i) {
        ths[i].start(f, files[i]);
    }
    for (int i = 0; i < 3; ++i) {
        ths[i].stop();
    }

    cout << "\nfin stat:\n";
    while (kek.size()) {
        myClass top = kek.top();
        kek.pop();
        cout << top.getX() << " ";
    }

    return 0;
}
