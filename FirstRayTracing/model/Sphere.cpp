#include "Sphere.h"

bool Sphere::hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) {
//    vec3 oc = ray.origin() - center;
//    float a = dot(ray.direction(), ray.direction());
//    float b = 2.0 * dot(oc, ray.direction());
//    float c = dot(oc, oc) - radius * radius;
//    float discriminant = b * b - 4 * a * c;
//    return (discriminant > 0);
    vec3 oc = ray.origin() - center;
    float a = dot(ray.direction(), ray.direction());
    float b = dot(oc, ray.direction());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - a*c;
    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = ray.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = ray.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
    }
    return false;
}


string Sphere::toString() {
    stringstream ss;
    ss << "SPHERE CENTER = (" << ::toString(this->center) << ")" << endl
       << "SHERE RADIUS = " << this->radius << endl
       << "COLOR -> " << ::toString(this->color) << endl << ")";
    string s = ss.str();
    return s;
}
