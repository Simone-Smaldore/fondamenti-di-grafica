#include "blurSphere.h"

bool blurSphere::hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) {
    float time = timeStart + ((timeEnd - timeStart) * randZeroToOne());
    vec3 oc = ray.origin() - move_sphere(time);
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
            rec.normal = (rec.p - move_sphere(time)) / radius;
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
            rec.normal = (rec.p - move_sphere(time)) / radius;
            return true;
        }
    }
    return false;
}

bool blurSphere::hit_shadow(const ray& ray, float t_min, float t_max) {
    //float time = timeStart + ((timeEnd - timeStart) * randZeroToOne());
    //vec3 oc = ray.origin() - move_sphere(time);
    //float a = dot(ray.direction(), ray.direction());
    //float b = dot(oc, ray.direction());
    //float c = dot(oc, oc) - radius * radius;
    //float discriminant = b * b - a * c;
    //if (discriminant > 0) {
    //    float temp = (-b - sqrt(discriminant)) / a;
    //    if (temp < t_max && temp > t_min) {
    //        return true;
    //    }
    //    temp = (-b + sqrt(discriminant)) / a;
    //    if (temp < t_max && temp > t_min) {
    //        return true;
    //    }
    //}
    return false;
}

point3d blurSphere::move_sphere(float time) const {
    return centerStart + ((timeStart + time * (timeEnd - timeStart)) * (centerEnd - centerStart));
}



