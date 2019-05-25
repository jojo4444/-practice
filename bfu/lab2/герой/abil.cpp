#pragma once

#include "abil.hpp"

abil::abil(string name) {
    _name = name;
    _job = nullptr;
}

abil::abil(string name, set <stat>& stats, funcAbil f):
    _name(name), _stats(stats), _job(f) {}

abil::~abil() {
    _stats.clear();
    _job = nullptr;
}

string abil::getName() const {
    return _name;
}

set <stat> abil::getStats() const {
    return _stats;
}

funcAbil abil::getJob() const {
    return _job;
}

void abil::setName(string name) {
    _name = name;
}

void abil::setStats(set <stat>& stats) {
    _stats = stats;
}

void abil::setJob(funcAbil job) {
    _job = job;
}

int abil::addStat(stat& newStat) {
    if (_stats.find(newStat) != _stats.end()) {
        return IN_STATS;
    }
    _stats.insert(newStat);
    return ADDED_STAT;
}

void abil::delStat(stat& lastStat) {
    _stats.erase(lastStat);
}

abil& abil::operator= (const abil& otherAbil) {
    _name = otherAbil.getName();
    _stats = otherAbil.getStats();
    _job = otherAbil.getJob();
    return *this;
}
