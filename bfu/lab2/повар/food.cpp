#pragma once

#include "food.hpp"

// link

link::link(string kitchen, string type, string nameFood, int assessment) {
    _kitchen = kitchen;
    _type = type;
    _nameFood = nameFood;
    _assessment = assessment;
}

// food

food::food() {
    //
}

food::~food() {
    _kitchen.clear();
    _type.clear();
}

void food::write() const {
    cout << "kitchen:\n";
    for (auto& kitchen : _kitchen) {
        cout << kitchen.first << ": ";
        kitchen.second.write();
    }
    cout << "\ntype:\n";
    for (auto& type : _type) {
        cout << type.first << ": ";
        type.second.write();
    }
    cout << "\nall food:\n";
    _foods.write();
    cout << "\n";
}

void food::addFood(link offerFood) {
    _kitchen[offerFood._kitchen].addFood(offerFood._nameFood);
    _type[offerFood._type].addFood(offerFood._nameFood);
    _foods.addFood(offerFood._nameFood);
}

void food::delFood(link offerFood) {
    _kitchen[offerFood._kitchen].delFood(offerFood._nameFood);
    _type[offerFood._type].delFood(offerFood._nameFood);
    _foods.delFood(offerFood._nameFood);
}

void food::change(link offerFood, int lvl) {
    _kitchen[offerFood._kitchen].changeRating(offerFood._nameFood, offerFood._assessment, lvl);
    _type[offerFood._type].changeRating(offerFood._nameFood, offerFood._assessment, lvl);
    _foods.changeRating(offerFood._nameFood, offerFood._assessment, lvl);
}
