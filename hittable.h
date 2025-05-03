#ifndef HITTABLE_H
#define HITTABLE_H

class hit_record
{
public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    void set_face_normal(const ray &r, const vec3 &outward_normal)
    {
        // sets the hit record normal vector
        // outward normal is assumed to have unit length

        front_face = dot(r.direction(), outward_normal) < 0;    // check if it's front faced(ray hitting outside)
        normal = front_face ? outward_normal : -outward_normal; /// if it's hitting outside, fine; if not, invert the direction
    }
};

class hittable
{
public:
    // virtual -> function can be overridden in a derived class,
    // and when called, it should have the most specific version to run
    // ~ -> destructor (automatically called when an object is out of scope or deleted)

    virtual ~hittable() = default; // declare a deconstructor and use compilers automatic behaviour
    virtual bool hit(const ray &r, interval ray_t, hit_record &rec) const = 0;
};

#endif