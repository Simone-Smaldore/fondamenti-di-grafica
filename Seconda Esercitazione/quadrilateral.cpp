#include "quadrilateral.h"

bool quadrilateral::hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) {
    vec3 normal = cross(side1, side2);
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
    float magnitudeSide1 = magnitude(side1);
    float magnitudeSide2 = magnitude(side2);
    vec3 diagonal = rec.p - p0;
    float projectionOnSide1 = abs(dot(side1, diagonal) / magnitude(side1));
    float projectionOnSide2 = abs(dot(side2, diagonal) / magnitude(side2));
    if (projectionOnSide1 <= magnitudeSide1 && projectionOnSide2 <= magnitudeSide2) {
        return true;
    }
    return false;
}

bool quadrilateral::hit_shadow(const ray& ray, float t_min, float t_max) {
    vec3 normal = cross(side1, side2);
    float den = dot(ray.direction(), normal);
    if (den == 0) {
        return false;
    }
    float t = dot(p0 - ray.origin(), normal) / den;
    point3d p = ray.point_at_parameter(t);
    if (t < t_min || t > t_max) {
        return false;
    }
    float magnitudeSide1 = magnitude(side1);
    float magnitudeSide2 = magnitude(side2);
    vec3 diagonal = p - p0;
    float projectionOnSide1 = abs(dot(side1, diagonal) / magnitude(side1));
    float projectionOnSide2 = abs(dot(side2, diagonal) / magnitude(side2));
    if (projectionOnSide1 <= magnitudeSide1 && projectionOnSide2 <= magnitudeSide2) {
        return true;
    }
    return false;
}




