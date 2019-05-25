#pragma once

#include "being.hpp"
#include "constants.hpp"

class fairy : public being {
public:
    fairy();
    fairy(int hp, int stunned, int poison);
    fairy(const state& stat, int poison);

    void setPoison(int poison);

    int getPoison() const;

private:
    int poison_;
};
