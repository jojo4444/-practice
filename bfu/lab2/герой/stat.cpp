#pragma once

#include "stat.hpp"

stat::stat(string name, int cnt, int limit, change f):
    _name(name), _cnt(cnt), _limit(limit), changeCnt(f) {}

stat::stat(const stat& otherStat) {
    *this = otherStat;
}

stat::~stat() {
    changeCnt = nullptr;
}

string stat::getName() const {
    return _name;
}

int stat::getCnt() const {
    return _cnt;
}

int stat::getLimit() const {
    return _limit;
}

change stat::getChange() const {
    return changeCnt;
}

void stat::setName(string name) {
    _name = name;
}
void stat::setCnt(int cnt) {
    _cnt = cnt;
}

void stat::setLimit(int limit) {
    _limit = limit;
}

void stat::setChange(change f) {
    changeCnt = f;
}

void stat::update() {
    _cnt = changeCnt(_cnt, _limit);
}

stat& stat::operator= (const stat& otherStat) {
    _name = otherStat.getName();
    _cnt = otherStat.getCnt();
    _limit = otherStat.getLimit();
    changeCnt = otherStat.getChange();
    return *this;
}

bool stat::operator< (const stat& otherStat) const {
    return _name < otherStat.getName();
}
