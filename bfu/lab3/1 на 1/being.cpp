#pragma once

#include "constants.hpp"
#include "being.hpp"

// motion

motion::motion(int block = 0, int hit = -1) {
    block_ = block;
    hit_ = hit;
}

// state

state::state(int hp = 0, int stunned = 0) {
    hp_ = hp;
    stunned_ = stunned;
}

// being

being::being() {
    for (int i = 0; i < 3; ++i) {
        hit_[i] = nullptr;
    }
}

being::being(const state& stat) {
    stat_.stunned_ = stat.stunned_;
    stat_.hp_= stat.hp_;
}

being::being(int hp = 0, int stunned = 0) {
    stat_ = state(hp, stunned);
}

state being::goHit(being& enemy) {
    return hit_[mt_.hit_](enemy);
}

// getters being

state being::getState() const {
    return stat_;
}

int being::getBlock() const {
    return mt_.block_;
}

int being::getHit() const {
    return mt_.hit_;
}

// setters being

void being::setState(int hp, int stunned) {
    stat_ = state(hp, stunned);
}

void being::setState(const state& stat) {
    stat_.stunned_ = stat.stunned_;
    stat_.hp_ = stat.hp_;
}

void being::setMotion(int block, int hit) {
    mt_ = motion(block, hit);
}

void being::setMotion(const motion& mt) {
    mt_.block_ = mt.block_;
    mt_.hit_ = mt.hit_;
}

void being::setHitUp(const funcType& f) {
    hit_[0] = f;
}

void being::setHitMiddle(const funcType& f) {
    hit_[1] = f;
}

void being::setHitDown(const funcType& f) {
    hit_[2] = f;
}
