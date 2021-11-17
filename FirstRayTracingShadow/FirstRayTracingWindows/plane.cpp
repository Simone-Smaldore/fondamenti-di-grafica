#include "plane.h"

bool plane::hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) {
    float den = dot(ray.direction(), normal);
    if (den == 0) {
        return false;
    }
    float t = dot(p0 - ray.origin(), normal) / den;
    rec.t = t;
    rec.p = ray.point_at_parameter(rec.t);
    rec.normal = normal;
    if (t < t_min || t > t_max) {
        return false;
    }
    return true;
}

bool plane::hit_shadow(const ray& ray, float t_min, float t_max) {
    float den = dot(ray.direction(), normal);
    if (den == 0) {
        return false;
    }
    float t = dot(p0 - ray.origin(), normal) / den;
    if (t < t_min || t > t_max) {
        return false;
    }
    return true;
}


string plane::toString() {
    stringstream ss;
    ss << "PLANE POINT = (" << ::toString(this->p0) << ")" << endl
        << "PLANE NORMAL = " << ::toString(this->normal) << endl
        << "COLOR -> " << ::toString(this->color) << endl << ")";
    string s = ss.str();
    return s;
}
