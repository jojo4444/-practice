#pragma once

#include "constants.hpp"
#include "fairy.hpp"

// konstruct

fairy::fairy() {
    poison_ = 0;
}

fairy::fairy(int hp, int stunned, int poison) : being(hp, stunned){
    poison_ = poison;
}

fairy::fairy(const state& stat, int poison) : being(stat){
    poison_ = poison;
}

// setters

void fairy::setPoison(int poison) {
    poison_ = poison;
}

// getters

int fairy::getPoison() const {
    return poison_;
}
