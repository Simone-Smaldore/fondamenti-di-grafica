#include "utilityRayTracing.h"
#include "point_light.h"
#include <algorithm>

#pragma once

color phong_shading(point_light& light, hit_record& hr, camera& cam) {
	color ambient(0.0, 0.0, 0.0);
	color diffuse(0.0, 0.0, 0.0);
	color specular(0.0, 0.0, 0.0);

	ambient = hr.m.ka * light.ambient;

	vec3 L = normalize(light.position - hr.p);
	float LDotN = max(dot(L, hr.normal), 0.0f);

	if (LDotN > 0) {
		// TODO AGGIUNGERE L'ATTENUAZIONE QUADRATICA ?
		diffuse = hr.m.kd * light.diffuse * LDotN;

		vec3 R = reflect(L, hr.normal);

		vec3 V = normalize(cam.position - hr.p);
		float VDotR = std::pow(max(dot(V, R), 0.0f), hr.m.alpha);

		specular = hr.m.ks * light.specular * VDotR;

		return ambient + diffuse + specular;
	}
	else
		return ambient;
}

color ambient_shading(point_light& light, hit_record& hr) {
	color ambient(0.0, 0.0, 0.0);
	ambient = hr.m.ka * light.ambient;
	return ambient;
}
