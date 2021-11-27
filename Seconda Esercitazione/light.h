#pragma once

#include "utilitySDLInline.h"
#include <vector>
#include "Object.h"

class light {
	public:
		color ambient;
		color diffuse;
		color specular;

		float att_a;
		float att_b;
		float att_c;

		virtual bool trace_shadow_ray(hit_record& rec, vector<Object*> objs_vector) = 0;
		virtual vec3 get_light_point_direction(hit_record& rec) = 0;
};