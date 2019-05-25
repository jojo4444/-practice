#pragma once

#include "constants.hpp"
#include "fairy.hpp"
#include "knight.hpp"

/*
in next time:

    #include "ogre.hpp"
    #include "vampire.hpp"
*/

template <class warrior1, class warrior2>
class war {
public:
    war(const warrior1& A, const warrior2& B);

    bool next() const;
    int win() const;
    void goWar();

private:
    warrior1 A_;
    warrior2 B_;
};



// release code



// KONSTRUCT

template <class warrior1, class warrior2>
war<warrior1, warrior2>::war(const warrior1& A, const warrior2& B) {
    A_ = A;
    B_ = B;
}

// methods

template <class warrior1, class warrior2>
bool war<warrior1, warrior2>::next() const {
    return A_.getState().hp_ > 0 && B_.getState().hp_ > 0;
}

template <class warrior1, class warrior2>
int war<warrior1, warrior2>::win() const {
    int hpA = A_.getState().hp_;
    int hpB = B_.getState().hp_;
    if (next()) {
        return NOT_FINISH;
    }
    if (hpA <= 0 && hpB <= 0) {
        return ALL_DEATH;
    } else if (hpA > 0) {
        return FIRST;
    } else {
        return SECOND;
    }
}

template <class warrior1, class warrior2>
void war<warrior1, warrior2>::goWar() {
    warrior1 lastA = A_;
    warrior2 lastB = B_;

    state statNewA = B_.goHit(lastA);
    state statNewB = A_.goHit(lastB);

    /*
        funcType стандартизирован так, что может менять класс, это сделано для следующего:
            - нанесём урон, а если наша способность ещё с нами что-то делает, то сделаем это сейчас
            - предполагается, что мы меняем особенные черты персонажа (armor, poison, ...)
    */

    A_.setStat(statNewA);
    B_.setStat(statNewB);
}
