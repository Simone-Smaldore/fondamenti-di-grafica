#pragma once
#include "Object.h"
#include "utilitySDLInline.h"

class cylinder : public Object {

public:

	cylinder() {}
	cylinder(const float bottom, const float top, const float r) : y0(bottom), y1(top), radius(r), inv_radius(1.0f / r) {};

	bool hit_object(const ray& r, float t_min, float t_max, hit_record& rec) override;
	bool hit_shadow(const ray& r, float t_min, float t_max) override;

private:
	float		y0;						// bottom y value
	float		y1;						// top y value
	float		radius;				// radius
	float		inv_radius;  	// one over the radius	
};
