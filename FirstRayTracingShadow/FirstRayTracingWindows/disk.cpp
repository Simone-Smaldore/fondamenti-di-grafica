#include "disk.h"

bool disk::hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) {
    float den = dot(ray.direction(), normal);
    if (den == 0) {
        return false;
    }
    float t = dot(p0 - ray.origin(), normal) / den;
    rec.t = t;
    rec.p = ray.point_at_parameter(rec.t);
    rec.normal = normal;
    rec.m = mat;
    if (t < t_min || t > t_max) {
        return false;
    }
    if (magnitude(rec.p - p0) < rayDistance) {
        return true;
    }
    return false;
}


string disk::toString() {
    stringstream ss;
    ss << "DISK CENTER = (" << ::toString(this->p0) << ")" << endl
        << "DISK NORMAL = " << ::toString(this->normal) << endl
        << "DISK RAY = " << this->rayDistance << endl
        << "COLOR -> " << ::toString(this->color) << endl << ")";
    string s = ss.str();
    return s;
}
