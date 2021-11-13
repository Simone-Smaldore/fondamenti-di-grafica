#pragma once

#include <sstream>

using namespace std;

struct ray {
    point3d o;
    vec3 d;

    ray() {}

    ray(const point3d& _origin, const vec3& _direction) {
        o = _origin;
        d = _direction;
    }

    point3d origin() const { return o; }

    vec3 direction() const { return d; }

    point3d point_at_parameter(float t) const {
        return o + t * d;
    }

    float t_at_point(point3d& p) const { 
        return magnitude(p - o); 
    }
};

inline string toString(const ray& r) {
    stringstream ss;
    ss << "RAY( " << endl << "\tORIGIN = " << toString(r.origin()) << endl << "\tDIRECTION = " << toString(r.direction()) << endl << ")";
    string s = ss.str();
    return s;
}
