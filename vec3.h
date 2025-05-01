#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3
{
public:
    double e[3]; // initialize an array with length 3 doubles

    vec3() : e{0, 0, 0} {}                                   // default constructor for a 3d vector
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {} // constructor with parameters
    double x() const { return e[0]; }                        // getters for x y, z
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); } // operator overloading to negate
    double operator[](int i) const { return e[i]; }              // overloading to return a copy of e[i]
    double &operator[](int i) { return e[i]; }                   // overloading for a reference to modify e[i]

    vec3 &operator+=(const vec3 &v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    } // operator overloading for vector addition (creates reference to vec3, and adds it, returning the object)

    vec3 &operator*=(double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    } // scalar multiplication

    vec3 &operator/=(double t)
    {
        return *this *= 1 / t;
    } // operator overloading for division

    double length() const
    {
        return std::sqrt(length_squared());
    }

    double length_squared() const
    {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
};

using point3 = vec3;

//vector utility functions

#endif