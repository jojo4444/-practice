#pragma once

#include <string>

using std::string;

const string DEF_NAME_TYPE_R = "RUSSIA-jojo";
const string DEF_NAME_TYPE_F = "Pringles-jojo";

const int IN_FOODS = 1;
const int ADDED_FOOD = 2;
const int EMPTY_FOOD = 3;
const int DELETED_FOOD = 4;
const int DELETED_RATING = 5;
const int ERROR_DEL_RATING = 6;
const int EMPTY_RATING = 7;

const int BAD_USER = 8; // max count for equals rate, my english is finish (c)

const int DELETE_USER_RATING = 9;
const int ADD_USER_RATING = 10;

const int SPAM = 11;
const int NO_SPAM = 12;

const int GOOD_USER = -1;

const double EPS = 1e-9;
