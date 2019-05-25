#pragma once

#include "constants.hpp"
#include "typeFood.hpp"
#include "typeRating.hpp"

#include <set>
#include <map>

using std::map;
using std::set;
using std::string;
using std::cout;

struct link {
    string _kitchen, _type, _nameFood;
    int _assessment;

    link(string kitchen, string type, string nameFood, int assessment = 0);
};

class food {
public:
    ~food();
    food();

    void addFood(link offerFood);
    void delFood(link offerFood);
    void change(link offerFood, int lvl);

    void write() const;
private:
    map <string, typeFood> _kitchen, _type;
    typeFood _foods;
};
