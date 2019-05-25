#pragma once

#include <iostream>
#include <set>
#include <cmath>
#include "constants.hpp"
#include "typeRating.hpp"

using std::fabs;
using std::set;
using std::cout;
using std::fixed;
using std::string;

class typeFood {
public:
    ~typeFood();
    typeFood();

    double getRating() const;
    int getAll() const;

    void changeRating(string food, int assessment, int lvl);
    void clearRating(typeRating& food);

    int addFood(string newFood);
    int delFood(string lastFood);

    void write() const;

private:
    set<typeRating> _foods;
    double _rating;
    int _all;
};

