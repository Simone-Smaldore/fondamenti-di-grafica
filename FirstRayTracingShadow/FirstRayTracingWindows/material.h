#pragma once
#include "utilitySDLInline.h"

class material {

	public:
		color ka;
		color kd;
		color ks;
		float alpha;

		material() {}

		material(color ambient, color diffuse, color specular, float a) {
			ka = ambient;
			kd = diffuse;
			ks = specular;
			alpha = a;
		}

};