#pragma once

#include <set>
#include "constants.hpp"
#include "stat.hpp"

using std::set;
using std::string;

typedef void (*funcAbil)();

class abil {
public:
    abil(string name = "default_name_abil");
    abil(string name, set <stat>& stats, funcAbil f = nullptr);
    ~abil();

    string getName() const;
    set <stat> getStats() const;
    funcAbil getJob() const;

    void setName(string name);
    void setStats(set <stat>& stats);
    void setJob(funcAbil job);

    int addStat(stat& newStat);
    void delStat(stat& lastStat);

    abil& operator= (const abil& otherAbil);

private:
    string _name;
    set <stat> _stats;
    funcAbil _job;
};
