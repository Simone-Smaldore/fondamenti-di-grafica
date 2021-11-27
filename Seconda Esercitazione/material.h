#pragma once
#include "utilitySDLInline.h"
#include "texture.h"
#include "record.h"

//struct hit_record {
//	float t;
//	point3d p;
//	vec3 normal;
//	material m;
//	float u;
//	float v;
//};


class material {

	public:
		color ka;
		color kd;
		color ks;
		float alpha;

		texture* texture;


		material() {
			random_material();
		}

		material(color ambient, color diffuse, color specular, float a) {
			ka = ambient;
			kd = diffuse;
			ks = specular;
			alpha = a;
		}

		void random_material() {
			ka.r = randZeroToOne();
			ka.g = randZeroToOne();
			ka.b = randZeroToOne();

			kd.r = randZeroToOne();
			kd.g = randZeroToOne();
			kd.b = randZeroToOne();

			ks.r = randZeroToOne();
			ks.g = randZeroToOne();
			ks.b = randZeroToOne();

			alpha = 20 + randZeroToOne() * 200;
		}

		
};