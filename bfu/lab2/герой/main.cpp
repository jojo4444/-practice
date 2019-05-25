#include <iostream>
#include "hero.hpp"

using std::min;
using std::cout;

hero jojo;
abil game("game");

int flowsUpd(int cnt, int lim) {
    return min(lim, 1 + cnt);
}

int androidUpd(int cnt, int lim) {
    return min(lim, 4 + cnt);
}

void check() {
    if (jojo.addAbil(game) == ADDED_ABIL) {
        cout << "nice add\n";
    } else {
        cout << "bad add\n";
    }
}

int main() {
    stat j4("flow", 4, 10, flowsUpd);
    stat j44("java", 2, 100, androidUpd);
    jojo.addStat(j4);
    jojo.addStat(j44);

    stat java("java", 30, 100);
    stat flow("flow", 2, 10);

    game.addStat(java);
    game.addStat(flow);

    check();

    for (int i = 0; i < 8; ++i) {
        jojo.updateStat("java");
    }

    check();

    jojo.write();

    return 0;
}
