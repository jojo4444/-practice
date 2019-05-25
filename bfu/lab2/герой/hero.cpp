#pragma once

#include "hero.hpp"

hero::hero(string name, set <stat>& stats, set <string>& abil) :
    _name(name), _stats(stats), _abil(abil) {}

hero::hero(string name) {
    _name = name;
}

hero::~hero() {
    _stats.clear();
    _abil.clear();
}

int hero::updateStat(string nameStat) {
    auto itStat = _stats.find(stat(nameStat));
    if (itStat == _stats.end()) {
        return NO_STAT_IN_STATS;
    }
    stat res = *itStat;
    _stats.erase(itStat);
    res.update();
    _stats.insert(res);
    return UPDATED_STAT;
}

void hero::write() const {
    cout << "name: " << _name << "\nstats: \n";
    for (const stat& s : _stats) {
        cout << s.getName() << " " << s.getCnt() << "/" << s.getLimit() << "\n";
    }
    cout << "abils:\n";
    for (const string& s : _abil) {
        cout << s << "\n";
    }
    cout << std::endl;
}


int hero::addAbil(const abil& newAbil) {
    if (_abil.find(newAbil.getName()) != _abil.end()) {
        return IN_ABILS;
    }
    set <stat> statsAbil = newAbil.getStats();
    for (const stat& statCheck : statsAbil) {
        auto inStats = _stats.find(statCheck);
        if (inStats == _stats.end()) {
            return NO_STAT_IN_STATS;
        }
        if (inStats->getCnt() < statCheck.getCnt()) {
            return LOW_CNT_IN_STAT;
        }
    }

    _abil.insert(newAbil.getName());
    return ADDED_ABIL;
}

int hero::addStat(const stat& newStat) {
    auto itStat = _stats.find(newStat);
    if (itStat != _stats.end()) {
        return IN_STATS;
    }
    _stats.insert(newStat);
    return ADDED_STAT;
}
