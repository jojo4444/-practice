#pragma once

#include <iostream>
#include "constants.hpp"

using std::string;

typedef int (*change)(int cnt, int lim);

class stat {
public:
    stat(string name = "default_name_stat", int cnt = DEF_CNT, int limit = DEF_LIMIT, change f = nullptr);
    stat(const stat& otherStat);
    ~stat();

    string getName() const;
    int getCnt() const;
    int getLimit() const;
    change getChange() const;

    void setName(string name);
    void setCnt(int cnt);
    void setLimit(int limit);
    void setChange(change f);

    void update();

    stat& operator= (const stat& otherStat);
    bool operator< (const stat& otherStat) const;
private:
    string _name;
    int _cnt, _limit;
    change changeCnt;
};
