#pragma once

#include <iostream>
#include "war.hpp"

using std::cout;

int main() {
    knight shrek = knight(200, 0, 44);
    fairy fiona = fairy(100, 0, 0);

    war<knight, fairy> battle = war<knight, fairy>(shrek, fiona);

    while(battle.next()) {
        /*
            set hit(up, middle, down) and block for warriors
        */
        battle.goWar();
    }

    int finish = battle.win();

    if (finish == ALL_DEATH) {
        cout << "-good news, all death\n\
                 -oh, shit, you mad?\n\
                 -no, im batman\n";
    } else if (finish == FIRST) {
        cout << "shrek is THANOS (watch meme on google)\n";
    } else {
        cout << "its true?!\nNo way...\n";
    }

    return 0;
}

