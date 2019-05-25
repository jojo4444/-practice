#pragma once

#include "constants.hpp"
#include "knight.hpp"

// konstruct

knight::knight() {
    armor_ = 0;
}

knight::knight(int hp, int stunned, int armor) : being(hp, stunned){
    armor_ = armor;
}

knight::knight(const state& stat, int armor) : being(stat){
    armor_ = armor;
}

// setters

void knight::setArmor(int armor) {
    armor_ = armor;
}

// getters

int knight::getArmor() const {
    return armor_;
}
