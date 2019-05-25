#pragma once

#include "being.hpp"
#include "constants.hpp"

class knight : public being {
public:
    knight();
    knight(int hp, int stunned, int armor);
    knight(const state& stat, int armor);

    void setArmor(int armor);

    int getArmor() const;

private:
    int armor_;
};
