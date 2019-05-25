#pragma once

#include "vector3.h"

vector3::vector3() {
    x_ = y_ = z_ = 0;
}

vector3::vector3(ld x = 0, ld y = 0, ld z = 0) {
    x_ = x;
    y_ = y;
    z_ = z;
}

vector3& vector3::operator= (const vector3& u) {
    x_ = u.getX();
    y_ = u.getY();
    z_ = u.getZ();
    return *this;
}

void vector3::setX(ld x) {
    x_ = x;
}

void vector3::setY(ld y) {
    y_ = y;
}

void vector3::setZ(ld z) {
    z_ = z;
}

ld vector3::getX() const {
    return x_;
}

ld vector3::getY() const {
    return y_;
}

ld vector3::getZ() const {
    return z_;
}

vector3 vector3::operator+ (const vector3& u) const {
    vector3 res = vector3(0, 0, 0);
    res.setX(u.getX() + x_);
    res.setY(u.getY() + y_);
    res.setZ(u.getZ() + z_);
    return res;
}

vector3 vector3::operator* (ld k) const {//vec * k
    vector3 res = vector3(0, 0, 0);
    res.setX(x_ * k);
    res.setY(y_ * k);
    res.setZ(z_ * k);
    return res;
}

ld vector3::operator() (const vector3& u) const {// scalar a . b
    return u.getX() * x_ + u.getY() * y_ + u.getZ() * z_;
}

vector3 vector3::operator[] (const vector3 u) const {//cross a[b] = [a, b]
    //без &, ибо так удобнее для кватернионов в умножении ("лишних" 16 байт при ~&, с учётом дальнейшей арифметики - не принципиально)
    vector3 res = vector3(0, 0, 0);
    res.setX(y_ * u.getZ() - z_ * u.getY());
    res.setY((-1)*(x_ * u.getZ() - z_ * u.getX()));
    res.setZ(x_ * u.getY() - y_ * u.getX());
    return res;
}

ld scalar(const vector3& u, const vector3& v) {
    return u.getX() * v.getX() + u.getY() * v.getY() + u.getZ() * v.getZ();
}

vector3 cross(const vector3& v, const vector3& u) {
    return v(u);
}

ld triple(const vector3& u, const vector3& v, const vector3& w) {
    return scalar(u, cross(v, w));
}

vector3 sum(vector3 u, vector3 v) {
    return u + v;
}

ld sqr(ld x) {
    return x * x;
}

ld lenght(vector3 u) {
    return sqrt(sqr(u.getX()) + sqr(u.getY()) + sqr(u.getZ()));
}
