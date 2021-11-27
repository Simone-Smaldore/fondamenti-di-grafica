#pragma once
#include "vec3.h"
#include "ray.h"
#include "utilitySDLInline.h"

class aabb {
public:
	aabb() {}
	aabb(const point3d& a, const point3d& b) { pmin = a; pmax = b; }

	point3d min() const { return pmin; }
	point3d max() const { return pmax; }

	bool hit(const ray& r, float tmin, float tmax, point3d& hit_point) const {
		for (int a = 0; a < 3; a++) {
			float t0 = ffmin((pmin[a] - r.origin()[a]) / r.direction()[a],
				(pmax[a] - r.origin()[a]) / r.direction()[a]);
			float t1 = ffmax((pmin[a] - r.origin()[a]) / r.direction()[a],
				(pmax[a] - r.origin()[a]) / r.direction()[a]);
			tmin = ffmax(t0, tmin);
			tmax = ffmin(t1, tmax);
			if (tmax <= tmin)
				return false;
		}
		hit_point = r.point_at_parameter(tmin);
		return true;
	}

	point3d pmin;
	point3d pmax;
};

aabb surrounding_box(aabb box0, aabb box1) {
	point3d small(ffmin(box0.pmin.x, box1.pmin.x),
		ffmin(box0.pmin.y, box1.pmin.y),
		ffmin(box0.pmin.z, box1.pmin.z));
	point3d big(ffmax(box0.pmax.x, box1.pmax.x),
		ffmax(box0.pmax.y, box1.pmax.y),
		ffmax(box0.pmax.z, box1.pmax.z));
	return aabb(small, big);
}

