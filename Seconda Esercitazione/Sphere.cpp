#include "Sphere.h"

bool Sphere::hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) {
    vec3 oc = ray.origin() - center;
    float a = dot(ray.direction(), ray.direction());
    float b = dot(oc, ray.direction());
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b * b - a * c;
    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = ray.point_at_parameter(rec.t);
            float phi = atan2(rec.p.z, rec.p.x);
            float theta = asin(rec.p.y);
            rec.u = 1 - (phi + M_PI) / (2 * M_PI);
            rec.v = (theta + M_PI / 2) / M_PI;
            rec.normal = (rec.p - center) / radius;
            //rec.u = rec.normal.x / 2 + 0.5;
            //rec.v = rec.normal.y / 2 + 0.5;
            //cout << "U: " << rec.u << " V: " << rec.v << endl;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = ray.point_at_parameter(rec.t);
            float phi = atan2(rec.p.z, rec.p.x);
            float theta = asin(rec.p.y);
            rec.u = 1 - (phi + M_PI) / (2 * M_PI);
            rec.v = (theta + M_PI / 2) / M_PI;
            rec.normal = (rec.p - center) / radius;
            //rec.u = rec.normal.x / 2 + 0.5;
            //rec.v = rec.normal.y / 2 + 0.5;
            //cout << "U: " << rec.u << " V: " << rec.v << endl;
            return true;
        }
    }
    return false;
}

bool Sphere::hit_shadow(const ray& ray, float t_min, float t_max) {
    vec3 oc = ray.origin() - center;
    float a = dot(ray.direction(), ray.direction());
    float b = dot(oc, ray.direction());
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b * b - a * c;
    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            return true;
        }
    }
    return false;
}


string Sphere::toString() {
    stringstream ss;
    ss << "SPHERE CENTER = (" << ::toString(this->center) << ")" << endl
        << "SHERE RADIUS = " << this->radius <<  ")";
    string s = ss.str();
    return s;
}

