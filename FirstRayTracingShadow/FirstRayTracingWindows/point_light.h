#pragma once
#include "light.h"
#include "utilitySDLInline.h"

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

};
