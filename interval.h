#ifndef INTERVAL_H
#define INTERVAL_H

#include "headers.h"

class interval
{
public:
    double min, max;

    interval() : min(+infinity), max(-infinity) {}           // default is empty (initializer list)
    interval(double min, double max) : min(min), max(max) {} // default list is empty (initializer list, where it takes the smallest...)

    double size() const
    {
        return max - min;
    }

    bool contains(double x) const
    {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const
    {
        return min < x && x < max;
    }

    static const interval empty, universe;
    // declare two static const variables in interval class
};

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

#endif