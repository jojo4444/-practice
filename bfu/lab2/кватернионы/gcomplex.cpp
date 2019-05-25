#pragma once

#include "gcomplex.h"

gcomplex::gcomplex() {
    w_ = 0;
}

gcomplex::gcomplex(ld w = 0, ld x = 0, ld y = 0, ld z = 0) {
    w_ = w;
    v_.setX(x);
    v_.setY(y);
    v_.setZ(z);
}

gcomplex::gcomplex(ld w, const vector3& u) {
    w_ = w;
    v_ = u;
}

gcomplex::gcomplex(const vector3& u, ld w) {
    w_ = w;
    v_ = u;
}

gcomplex::gcomplex(std::complex<ld> z1, std::complex<ld> z2) {
    w_ = z1.real();
    v_.setX(z1.imag());
    v_.setY(z2.real());
    v_.setZ(z2.imag());
}

ld gcomplex::getW() const {
    return w_;
}

ld gcomplex::getX() const {
    return v_.getX();
}

ld gcomplex::getY() const {
    return v_.getY();
}

ld gcomplex::getZ() const {
    return v_.getZ();
}

vector3 gcomplex::getVec() const {
    return v_;
}

void gcomplex::setW(ld w) {
    w_ = w;
}

void gcomplex::setX(ld x) {
    v_.setX(x);
}

void gcomplex::setY(ld y) {
    v_.setY(y);
}

void gcomplex::setZ(ld z) {
    v_.setZ(z);
}

void gcomplex::setVec(vector3 u) {
    v_ = u;
}

gcomplex& gcomplex::operator= (const gcomplex& u) {
    w_ = u.getW();
    v_ = u.getVec();
    return *this;
}

gcomplex gcomplex::operator+ (const gcomplex& u) {
    gcomplex res = gcomplex(0, 0, 0, 0);
    res.setW(u.getW() + w_);
    res.v_ = u.getVec() + v_;
    return res;
}

gcomplex gcomplex::operator* (const gcomplex& u) {
    gcomplex res = gcomplex(0, 0, 0, 0);
    res.setW((w_ * u.getW()) - scalar(v_, u.getVec()));
    res.setVec(sum(u.getVec() * w_, sum(v_ * u.getW(), v_[u.getVec()])));
    return res;
}

gcomplex gcomplex::operator* (ld k) {
    gcomplex res = gcomplex(0, 0, 0, 0);
    res.setW(w_ * k);
    res.setVec(v_ * k);
    return res;
}

gcomplex conjugate(const gcomplex u){// сопряженное
    gcomplex res = gcomplex(0, 0, 0, 0);
    res.setW(u.getW());
    res.setVec(u.getVec() * (-1));
    return res;
}

ld lenght(const gcomplex u) {
    return sqrt(sqr(u.getW()) + sqr(lenght(u.getVec())));
}

gcomplex invert(const gcomplex u) {
    return conjugate(u) * ((ld)1./pow(lenght(u), 2));
}
