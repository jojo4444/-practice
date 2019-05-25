#pragma once

#include <cmath>
#include <iomanip>

typedef long double ld;

class vector3 {
public:
    vector3();
    vector3(ld x, ld y, ld z);

    void setX(ld x);
    void setY(ld y);
    void setZ(ld z);

    ld getX() const;
    ld getY() const;
    ld getZ() const;

    vector3 operator* (ld k) const;
    vector3& operator= (const vector3& u);
    vector3 operator+ (const vector3& u) const;
    vector3 operator[] (const vector3 u) const;
    ld operator() (const vector3& u) const;

    friend std::ostream& operator<< (std::ostream& out, const vector3& u) {
        out << std::fixed << "(" << u.getX() << "," << u.getY() << "," << u.getZ() << ")";
        return out;
    }
    friend std::istream& operator>> (std::istream& in, vector3& u) {
        ld x, y, z;
        in >> x >> y >> z;
        u.setX(x);
        u.setY(y);
        u.setZ(z);
        return in;
    }
private:
    ld x_, y_, z_;
};

ld scalar(const vector3& u, const vector3& v);
vector3 cross(const vector3& u, const vector3& v);
ld triple(const vector3& u, const vector3& v, const vector3& w);
vector3 sum(vector3 u, vector3 v);
ld lenght(vector3 u);
ld sqr(ld x);
