#pragma once

#include "constants.hpp"
#include "restourant.hpp"

restourant::restourant() {
    //
}

restourant::~restourant() {
    _users.clear();
    _cooks.clear();
}

void restourant::deleteUser(string& user) {
    for (auto buy : _users[user].second) {
        offer.change(buy.second, -1);
        _cooks[buy.first].delRating(buy.second._assessment);
    }
    _users.erase(user);
}

void restourant::addUser(string& user, string& cook, link& offerFood){
    pair<int, vector<pair<string, link> > >& usr = _users[user];
    usr.second.push_back(make_pair(cook, offerFood));

    offer.change(offerFood, 1);
    _cooks[cook].addRating(offerFood._assessment);
    _cooks[cook].setName(cook);

    if (usr.second.size() == 1) {
        usr.first = 1;
    } else {
        if (usr.first == GOOD_USER) {
            return;
        }

        int lastAssessment = usr.second[usr.second.size() - 2].second._assessment;
        if (lastAssessment == offerFood._assessment) {
            usr.first++;
        } else {
            usr.first = GOOD_USER;
        }
    }
}

int restourant::update(string user, string cook, link offerFood) {
    addUser(user, cook, offerFood);
    if (_users[user].first == BAD_USER) {
        deleteUser(user);
        return SPAM;
    }
    return NO_SPAM;
}

void restourant::addFood(link nameFood) {
    offer.addFood(nameFood);
}
void restourant::delFood(link nameFood) {
    offer.delFood(nameFood);
}

void restourant::write() {
    cout << "foods:\n";
    offer.write();
    cout << "\ncooks:\n";
    for (auto& cook : _cooks) {
        cook.second.write();
    }
    cout << "------\n";
}
