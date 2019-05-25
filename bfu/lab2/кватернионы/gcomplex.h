#pragma once

#include <complex>
#include "vector3.h"

class gcomplex {
public:
    gcomplex();
    gcomplex(ld w, ld x, ld y, ld z);
    gcomplex(ld w, const vector3& u);
    gcomplex(const vector3& u, ld w);
    gcomplex(std::complex<ld> z1, std::complex<ld> z2);

    ld getW() const;
    ld getX() const;
    ld getY() const;
    ld getZ() const;
    vector3 getVec() const;

    void setW(ld w);
    void setX(ld x);
    void setY(ld y);
    void setZ(ld z);
    void setVec(vector3 u);

    gcomplex& operator= (const gcomplex& u);
    gcomplex operator+ (const gcomplex& u);
    gcomplex operator* (const gcomplex& u);
    gcomplex operator* (ld k);

    friend std::ostream& operator<< (std::ostream& out, const gcomplex& u) {
        char sgnX = (u.getX() > 0)?'+':'-';
        char sgnY = (u.getY() > 0)?'+':'-';
        char sgnZ = (u.getZ() > 0)?'+':'-';
        out << std::fixed << "(" << u.getW() << sgnX << fabs(u.getX()) << "i" << sgnY << fabs(u.getY()) << "j" << sgnZ << fabs(u.getZ()) << "k)";
        return out;
    }
    friend std::istream& operator>> (std::istream& in, gcomplex& u) {
        ld w;
        in >> w;
        u.setW(w);
        vector3 v;
        in >> v;
        u.setVec(v);
        return in;
    }
private:
    ld w_;
    vector3 v_;
};

gcomplex conjugate(const gcomplex u);// сопряженное
ld lenght(const gcomplex u);
gcomplex invert(const gcomplex u);//u^-1 = conj(q)/|q|^2
