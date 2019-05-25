#pragma once

#include "typeRating.hpp"

typeRating::typeRating(string name, double rating, int all) {
    _name = name;
    _rating = rating;
    _all = all;
}

string typeRating::getName() const {
    return _name;
}

double typeRating::getRating() const {
    return _rating;
}

int typeRating::getAll() const {
    return _all;
}

void typeRating::setName(string name) {
    _name = name;
}

void typeRating::addRating(int assessment) {
    _rating = (_rating * _all + assessment) / (double)(_all + 1);
    ++_all;
}
int typeRating::delRating(int assessment) {
    if (_all == 0) {
        return ERROR_DEL_RATING;
    }
    if (_all == 1) {
        _rating = 0;
        _all = 0;
        return EMPTY_RATING;
    }
    _rating = (_rating * _all - assessment) / (double)(_all - 1);
    --_all;
    return DELETED_RATING;
}

void typeRating::write() const {
    cout << fixed << _name << " (rate = " << _rating << ")\n";
}

bool typeRating::operator< (const typeRating& other) const {
    return _name < other.getName();
}
