#include "box.h"


bool box::hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) {
    point3d pMax = pMin + side1 + side2 + side3;

    float tMinX = (pMin.x - ray.origin().x) /  ray.direction().x;
    float tMaxX = (pMax.x - ray.origin().x) /  ray.direction().x;
    float tMinY = (pMin.y - ray.origin().y) /  ray.direction().y;
    float tMaxY = (pMax.y - ray.origin().y) /  ray.direction().y;
    float tMinZ = (pMin.z - ray.origin().z) /  ray.direction().z;
    float tMaxZ = (pMax.z - ray.origin().z) /  ray.direction().z;

    if(tMinX > tMaxX) swap(tMinX, tMaxX);
    if(tMinY > tMaxY) swap(tMinY, tMaxY);
    if(tMinZ > tMaxZ) swap(tMinZ, tMaxZ);

    float tMin = tMinX;
    float tMax = tMaxX;

    if(tMin > tMaxY || tMax < tMinY) return false;

    if(tMinY > tMin) tMin = tMinY;
    if(tMaxY < tMax) tMax = tMaxY;

    if(tMin > tMaxZ || tMax < tMinZ) return false;

    if(tMinZ > tMin) tMin = tMinZ;
//    SE SERVE TORNARE ANCHE IL MASSIMO
//    if(tMaxZ < tMax) tMax = tMaxZ;

    rec.t = tMin;
    rec.p = ray.point_at_parameter(tMin);

    vec3 firstDiagonal = rec.p - pMin;
    vec3 secondDiagonal = rec.p - pMax;

    if(isInfinitesimalNumber(dot(firstDiagonal, side1)) ) {
        rec.normal = -side1;
    } else if(isInfinitesimalNumber(dot(secondDiagonal, side1))) {
        rec.normal = side1;
    } else if(isInfinitesimalNumber(dot(firstDiagonal, side2))) {
        rec.normal = -side2;
    } else if(isInfinitesimalNumber(dot(secondDiagonal, side2))) {
        rec.normal = side2;
    } else if(isInfinitesimalNumber(dot(firstDiagonal, side3))) {
        rec.normal = -side3;
    } else if(isInfinitesimalNumber(dot(secondDiagonal, side3))) {
        rec.normal = side3;
    }
    if(tMin < t_min || tMin > t_max) {
        return false;
    }
    return true;
}


string box::toString() {
    stringstream ss;
    ss << "BOX POINT pMin = (" << ::toString(this->pMin) << ")" << endl
       << "BOX POINT pMax = (" << ::toString(this->pMin + this->side1 + this->side2 + this->side3) << ")" << endl
       << "BOX SIDE 1 = " << ::toString(this->side1) << endl
       << "BOX SIDE 2 = " << ::toString(this->side2) << endl
       << "BOX SIDE 3 = " << ::toString(this->side3) << endl
       << "COLOR -> " << ::toString(this->color) << endl << ")";
    string s = ss.str();
    return s;
}