#pragma once
#include "light.h"
#include "utilitySDLInline.h"

using namespace std;

class point_light : public light {

	public:
		point3d position;

		point_light() {}

		point_light(point3d p, color a, color d, color s) {
			position = p;
			ambient = a;
			diffuse = d;
			specular = s;
		}

		bool trace_shadow_ray(hit_record& rec, vector<Object*> objs_vector) {
			ray shadow_ray(rec.p, normalize(position - rec.p));
			int closest_light = shadow_ray.t_at_point(position);
			for (int i = 0; i < objs_vector.size(); i++) {
				if (objs_vector[i]->hit_shadow(shadow_ray, 0.01f, closest_light)) {
					return true;
				}
			}
			return false;
		}

		vec3 get_light_point_direction(hit_record& rec) {
			return normalize(position - rec.p);
		}

};
