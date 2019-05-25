#pragma once

#include "constants.hpp"
#include <functional>

#define funcType function<state(const being& enemy)>


/*
    повышающее преобразование будет использовани в будующем,
    однако оно всегда безопасно, поэтому наследники будут -> being
*/


using std::function;

struct motion {
    int block_;
    int hit_;

    motion(int block, int hit);
};

struct state {
    int hp_;
    int stunned_;

    state(int hp, int stunned);
};

class being {
public:
    being();
    being(int hp, int stunned);
    being(const state& stat);

    state goHit(being& enemy); //returned stat enemy

    state getState() const;
    int getBlock() const;
    int getHit() const;

    void setMotion(int block, int hit);
    void setMotion(const motion& mt);

    void setState(int hp, int stunned);
    void setState(const state& stat);

    void setHitUp(const funcType& f);
    void setHitMiddle(const funcType& f);
    void setHitDown(const funcType& f);

private:
    funcType hit_[3];
    state stat_;
    motion mt_;
};
