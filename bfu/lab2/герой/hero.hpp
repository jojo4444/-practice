#pragma once

#include "stat.hpp"
#include "abil.hpp"
#include "constants.hpp"

#include <string>
#include <set>

using std::set;
using std::string;
using std::cout;

class hero {
public:
    hero(string name, set <stat>& stats, set <string>& abil);
    hero(string name = DEF_NAME_HERO);

    ~hero();

    int addAbil(const abil& newAbil);
    int addStat(const stat& newStat);

    int updateStat(string nameStat);

    void write() const;
private:
    string _name;
    set <stat> _stats;
    set <string> _abil;
};
