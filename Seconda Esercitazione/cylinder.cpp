#include "cylinder.h"

bool cylinder::hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) {
	float temp;
	float ox = ray.o.x;
	float oy = ray.o.y;
	float oz = ray.o.z;
	float dx = ray.d.x;
	float dy = ray.d.y;
	float dz = ray.d.z;

	float a = dx * dx + dz * dz;
	float b = 2.0f * (ox * dx + oz * dz);
	float c = ox * ox + oz * oz - radius * radius;
	float disc = b * b - 4.0f * a * c;

	if (disc < 0.0)
		return(false);
	else {
		float e = sqrt(disc);
		float denom = 2.0f * a;
		temp = (-b - e) / denom;    // smaller root

		if (temp < t_max && temp > t_min) {
			float yhit = oy + temp * dy;

			if (yhit > y0 && yhit < y1) {
				rec.t = temp;
				rec.normal = normalize(vec3((ox + temp * dx) * inv_radius, 0.0f, (oz + temp * dz) * inv_radius));
				rec.p = ray.point_at_parameter(rec.t);
				float azimuth = atan2(rec.p.z, rec.p.x);
				rec.u = azimuth / (2 * M_PI);
				rec.v = (rec.p.y + 1) / 2;
				//rec.m = mat;

				// test for hitting from inside
				if (dot(-ray.d, rec.normal) < 0.0f)
					rec.normal = -rec.normal;

				return (true);
			}
		}

		temp = (-b + e) / denom;    // larger root

		if (temp < t_max && temp > t_min) {
			float yhit = oy + temp * dy;

			if (yhit > y0 && yhit < y1) {
				rec.t = temp;
				rec.normal = normalize(vec3((ox + temp * dx) * inv_radius, 0.0f, (oz + temp * dz) * inv_radius));
				rec.p = ray.point_at_parameter(rec.t);
				float azimuth = atan2(rec.p.z, rec.p.x);
				rec.u = azimuth / (2 * M_PI);
				rec.v = (rec.p.y + 1) / 2;
				//rec.m = mat;

				// test for hitting inside surface
				if (dot(-ray.d, rec.normal) < 0.0f)
					rec.normal = -rec.normal;

				return (true);
			}
		}
	}

	return (false);
}

bool cylinder::hit_shadow(const ray& ray, float t_min, float t_max) {
	float temp;
	float ox = ray.o.x;
	float oy = ray.o.y;
	float oz = ray.o.z;
	float dx = ray.d.x;
	float dy = ray.d.y;
	float dz = ray.d.z;

	float a = dx * dx + dz * dz;
	float b = 2.0f * (ox * dx + oz * dz);
	float c = ox * ox + oz * oz - radius * radius;
	float disc = b * b - 4.0f * a * c;

	if (disc < 0.0f)
		return(false);
	else {
		float e = sqrt(disc);
		float denom = 2.0f * a;
		temp = (-b - e) / denom;    // smaller root

		if (temp < t_max && temp > t_min) {
			float yhit = oy + temp * dy;

			if (yhit > y0 && yhit < y1) {
				//rec.t = temp;
				//rec.normal = normalize(vector3D((ox + t * dx) * inv_radius, 0.0, (oz + t * dz) * inv_radius));

				// test for hitting from inside

				//if (dot(-ray.d, rec.normal) < 0.0)
				//	rec.normal = -rec.normal;

				//rec.p = ray.point_at_parameter(rec.t);

				return (true);
			}
		}

		temp = (-b + e) / denom;    // larger root

		if (temp < t_max && temp > t_min) {
			float yhit = oy + temp * dy;

			if (yhit > y0 && yhit < y1) {
				//rec.t = temp;
				//rec.normal = normalize(vector3D((ox + t * dx) * inv_radius, 0.0, (oz + t * dz) * inv_radius));

				// test for hitting inside surface

				//if (dot(-ray.d, rec.normal) < 0.0)
				//	rec.normal = -rec.normal;

				//rec.p = ray.point_at_parameter(rec.t);

				return (true);
			}
		}
	}
	return (false);
}
