#pragma once

#include "constants.hpp"
#include "typeFood.hpp"
#include "typeRating.hpp"
#include "food.hpp"

#include <map>
#include <vector>
#include <iostream>

using std::map;
using std::cout;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;

class restourant {
public:
    ~restourant();
    restourant();

    void deleteUser(string& user);
    void addUser(string& user, string& cook, link& offerFood);

    int update(string user, string cook, link offerFood);

    void addFood(link nameFood);
    void delFood(link nameFood);

    void write();

private:
    map <string, pair<int, vector<pair<string, link> > > > _users;// [user](prefixSize, {(cook, food)});
    map <string, typeRating> _cooks;
    food offer;
};
