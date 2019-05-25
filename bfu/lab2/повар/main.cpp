#pragma once

#include <iostream>
#include "restourant.hpp"

int main() {
    //check no spam
    restourant mcDonnalds;

    link f1 = link("russia", "hot", "borsh");
    link f2 = link("germany", "hot", "chips");

    mcDonnalds.addFood(f1);
    mcDonnalds.addFood(f2);

    f1._assessment = 4;
    mcDonnalds.update("jojo", "1", f1);

    mcDonnalds.write();

    f2._assessment = 5;
    mcDonnalds.update("jojo", "1", f2);

    mcDonnalds.write();

    //check spam

    link f_spam("italia", "pizza", "toskana");
    mcDonnalds.addFood(f_spam);

    f_spam._assessment = 1;

    for (int i = 0; i < BAD_USER; ++i) {
        mcDonnalds.update("batikov", "evgen", f_spam);
    }

    mcDonnalds.write();

    return 0;
}
