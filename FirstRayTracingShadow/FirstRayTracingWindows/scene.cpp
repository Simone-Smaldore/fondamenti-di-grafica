#include "scene.h"
#include "shader.h"

using namespace Concurrency;

void scene::addObject(Object* new_object) {
	objs_vector.push_back(new_object);
}

void scene::addLight(point_light* new_light) {
	light = new_light;
}

void scene::setCamera(point3d position, point3d lookat, vec3 up, float fov, int res_x, int res_y, int n_sampling) {
	nx = res_x;
	ny = res_y;
	ns = n_sampling;
	float ratio = float(res_x) / float(res_y);
	cam = new camera(position, lookat, up, fov, ratio);
}

color scene::shot(const ray& r) {
	hit_record rec;
	if (trace_ray(r, 0.0f, FLT_MAX, rec)) {
		ray shadow_ray(rec.p, normalize(light->position - rec.p));
		float closest_light = shadow_ray.t_at_point(light->position);

		if (trace_shadow_ray(shadow_ray, closest_light, rec.object_index))
			return ambient_shading(*light, rec);
		else
			return phong_shading(*light, rec, *cam);
	}
	else {
		return colorLerpY(r,  color(1.0f, 1.0f, 1.0f), color(0.5f, 0.7f, 1.0f));
	}
}

//TO DO AGGIUNGERE TUTTI GLI ALGORITMI
void scene::render(SDL_Renderer*& renderer) {
	for (int j = 0; j < ny; j++) {
		for (int i = 0; i < nx; i++) {
			color col(0.0, 0.0, 0.0);
			for (int s = 0; s < ns; s++) {
				ray r = cam->get_ray(float((i + randZeroToOne()) / nx), float((j + randZeroToOne()) / ny));
				col += scene::shot(r);
			}
			col /= float(ns);
			setColor(renderer, sqrt(col.r), sqrt(col.g), sqrt(col.b));
			setPixel(renderer, i, j, ny);
		}
	}
}

void scene::parallelRender(SDL_Renderer*& renderer) {
	vector<color> matrix(nx * ny);
	parallel_for(int(0), ny, [&](int j) {
		for (int i = 0; i < nx; i++) {
			color col(0.0, 0.0, 0.0);
			for (int s = 0; s < ns; s++) {
				ray r = cam->get_ray(float((i + randZeroToOne()) / nx), float((j + randZeroToOne()) / ny));
				col += scene::shot(r);
			}
			col /= float(ns);
			col = color(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
			matrix[j * nx + i] = col;
		}
	});
	for (int j = 0; j < ny; j++) {
		for (int i = 0; i < nx; i++) {
			color col = matrix[j * nx + i];
			setColor(renderer, col.r, col.g, col.b);
			setPixel(renderer, i, j, ny);
		}
	}
}

bool scene::trace_ray(const ray& r, float t_min, float t_max, hit_record& rec) const {
	hit_record temp_rec;
	bool hit_anything = false;
	float closest_so_far = t_max;

	for (int i = 0; i < objs_vector.size(); i++) {
		if (objs_vector[i]->hit_object(r, t_min, closest_so_far, temp_rec)) {
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
			rec.object_index = i;
		}
	}
	return hit_anything;
}


bool scene::trace_shadow_ray(const ray& r, const float closest_light, int hit_index) const {
	hit_record temp_rec;
	for (int i = 0; i < objs_vector.size(); i++) {
		if (i == hit_index) {
			continue;
		}
		if (objs_vector[i]->hit_object(r, 0.0f, closest_light, temp_rec)) {
			return true;
		}
	}
	return false;
}