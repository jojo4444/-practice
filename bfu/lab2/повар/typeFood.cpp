#pragma once

#include "typeFood.hpp"

typeFood::typeFood() {
    _rating = 0;
    _all = 0;
}

typeFood::~typeFood() {
    _foods.clear();
}

double typeFood::getRating() const {
    return _rating;
}

int typeFood::getAll() const {
    return _all;
}

void typeFood::changeRating(string food, int assessment, int lvl) {
    auto foodIn = *(_foods.find(typeRating(food)));

    _foods.erase(foodIn);

    double r_down = foodIn.getRating();
    if (lvl == 1) {
        foodIn.addRating(assessment);
    } else {
        foodIn.delRating(assessment);
    }
    double r_up = foodIn.getRating();

    if (fabs(foodIn.getRating()) > EPS) {
        _foods.insert(foodIn);
    }

    if (_all + lvl == 0) {
        _rating = 0;
    } else {
        _rating = (_rating * _all - r_down + r_up) / (double)(_all + lvl);
    }
    _all += lvl;
}

void typeFood::clearRating(typeRating& food) {
    _foods.erase(food);
    if (_all == 1) {
        _rating = 0;
        _all = 0;
        return;
    }
    _rating = (_rating * _all - food.getRating()) / (double)(_all - 1);
    --_all;
}

int typeFood::addFood(string newFood) {
    if (_foods.find(newFood) != _foods.end()) {
        return IN_FOODS;
    }
    _foods.insert(typeRating(newFood));
    return ADDED_FOOD;
}

int typeFood::delFood(string lastFood) {
    if (_foods.find(typeRating(lastFood)) == _foods.end()) {
        return EMPTY_FOOD;
    }
    typeRating f = *(_foods.find(typeRating(lastFood)));
    clearRating(f);
    _foods.erase(f);
    return DELETED_FOOD;
}

void typeFood::write() const {
    cout << fixed << "(rate = " << _rating << ")\n";
    for (const typeRating& f : _foods) {
        f.write();
    }
    cout << "\n";
}
