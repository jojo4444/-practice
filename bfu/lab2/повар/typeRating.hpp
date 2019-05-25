#pragma once

#include <iostream>
#include "constants.hpp"

using std::cout;
using std::fixed;
using std::string;

class typeRating {
public:
    typeRating(string name = DEF_NAME_TYPE_R, double rating = 0, int all = 0);

    string getName() const;
    double getRating() const;
    int getAll() const;

    void setName(string name);

    void addRating(int assessment);
    int delRating(int assessment);

    void write() const;

    bool operator< (const typeRating& other) const;
private:
    string _name;
    double _rating;
    int _all;
};

