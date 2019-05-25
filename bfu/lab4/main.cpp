#include <iostream>
#include <vector>
#include <functional>
#include <thread>

#include "threadGuard.hpp";

using std::cin;
using std::cout;
using std::vector;

int n, a;
std::vector <int> arr[2];

void read() {
    cin >> n;
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> a;
            arr[j].push_back(a);
        }
    }
}

int ans[4];
// мало потоков у меня :(

void scalar(int id, int l, int r) {
    int res = 0;
    for (int i = l; i <= r; ++i) {
        res += arr[0][i] * arr[1][i];
    }
    ans[id] = res;
}

int main() {
    read();

    int cntTreads = std::thread::hardware_concurrency();

    thread_guard ths[cntTreads];

    /*
        Checked:
            if cntTreads < 2 (mb 0)
            | no problems
    */

    std::function<void(int, int, int)> f = &scalar;

    int block = (cntTreads == 0 ? n : (n + cntTreads - 1) / cntTreads);
    for (int i = 1; i < cntTreads; ++i) {
        int l = block * i;
        int r = std::min(n - 1, l + block - 1);
        ths[i].start(f, i, l, r);
    }

    scalar(0, 0, block - 1);

    int finAns = ans[0];
    for (int i = 1; i < cntTreads; ++i) {
        ths[i].stop();
        finAns += ans[i];
    }

    cout << finAns;

    return 0;
}
