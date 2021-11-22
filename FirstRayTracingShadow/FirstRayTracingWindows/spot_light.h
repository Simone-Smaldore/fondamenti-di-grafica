#pragma once

#include "light.h"
#include "utilitySDLInline.h"


using namespace std;

class spot_light : public light {

public:
	point3d position;
	vec3 direction;
	float theta;
	float e;

	spot_light() {}

	spot_light(point3d p, vec3 dir, float t, float att, color a, color d, color s) {
		position = p;
		direction = dir;
		theta = t;
		e = att;
		ambient = a;
		diffuse = d;
		specular = s;
	}

	bool trace_shadow_ray(hit_record& rec, vector<Object*> objs_vector) {
		ray shadow_ray(rec.p, normalize(position - rec.p));
		float cosFi = dot(shadow_ray.d, direction);
		float cosTheta = cos(deg2rad(theta));
		if (cosFi <= cosTheta) {
			return true;
		}
		int closest_light = shadow_ray.t_at_point(position);
		for (int i = 0; i < objs_vector.size(); i++) {
			if (i == rec.object_index) {
				continue;
			}
			if (objs_vector[i]->hit_shadow(shadow_ray, 0.0f, closest_light)) {
				return true;
			}
		}
		return false;
	}

	vec3 get_light_point_direction(hit_record& rec) {
		return normalize(position - rec.p);
	}

};

