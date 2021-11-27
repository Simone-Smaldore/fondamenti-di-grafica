#pragma once

#include "light.h"
#include "utilitySDLInline.h"

using namespace std;

class direction_light : public light {

public:
	vec3 direction;

	direction_light() {}

	direction_light(vec3 dir, color a, color d, color s) {
		direction = dir;
		ambient = a;
		diffuse = d;
		specular = s;
	}

	bool trace_shadow_ray(hit_record& rec, vector<Object*> objs_vector) {
		ray shadow_ray(rec.p, direction);
		for (int i = 0; i < objs_vector.size(); i++) {
			if (objs_vector[i]->hit_shadow(shadow_ray, 0.01f, FLT_MAX)) {
				return true;
			}
		}
		return false;
	}

	vec3 get_light_point_direction(hit_record& rec) {
		return direction;
	}

};