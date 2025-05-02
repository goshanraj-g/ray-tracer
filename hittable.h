#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record
{
public:
    point3 p;
    vec3 normal;
    double t;
};

class hittable
{
public:
    // virtual -> function can be overridden in a derived class,
    // and when called, it should have the most specific version to run
    // ~ -> destructor (automatically called when an object is out of scope or deleted)

    virtual ~hittable() = default; // declare a deconstructor and use compilers automatic behaviour
    virtual bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const = 0;
};

#endif