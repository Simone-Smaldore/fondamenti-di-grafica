#include "triangle.h"

bool triangle::hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) {
    vec3 normal = cross(p1-p2, p2-p3);
    float den = dot(ray.direction(), normal);
    if(den == 0) {
        return false;
    }
    float t = dot(p1 - ray.origin(), normal) / den;
    rec.t = t;
    rec.p = ray.point_at_parameter(rec.t);
    rec.normal = normal;
    if(t < t_min || t > t_max) {
        return false;
    }

    vec3 side1 = p2 - p1;
    vec3 side2 = p3 - p2;
    vec3 side3 = p1 - p3;
    vec3 diagonal1 = cross(side1, rec.p - p1);
    vec3 diagonal2 = cross(side2, rec.p - p2);
    vec3 diagonal3 = cross(side3, rec.p - p3);
    if(dot(normal, diagonal1) > 0 && dot(normal, diagonal2) > 0 && dot(normal, diagonal3) > 0) {
        return true;
    }
    if(dot(normal, diagonal1) < 0 && dot(normal, diagonal2) < 0 && dot(normal, diagonal3) < 0) {
        return true;
    }
    return false;
}


string triangle::toString() {
    stringstream ss;
    ss << "P1  = (" << ::toString(this->p1) << ")" << endl
       << "P2  = (" << ::toString(this->p2) << ")" << endl
       << "P3  = (" << ::toString(this->p2) << ")" << endl
       << "COLOR -> " << ::toString(this->color) << endl << ")";
    string s = ss.str();
    return s;
}