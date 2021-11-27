#include "scene.h"
#include "shader.h"

using namespace Concurrency;

void scene::addObject(Object* new_object) {
	objs_vector.push_back(new_object);
}

void scene::addLight(light* new_light) {
	lights.push_back(new_light);
}


void scene::setCamera(point3d position, point3d lookat, vec3 up, float fov, int res_x, int res_y) {
	nx = res_x;
	ny = res_y;
	float ratio = float(res_x) / float(res_y);
	cam = new camera(position, lookat, up, fov, ratio);
}

color scene::shot(const ray& r) {
	hit_record rec;
	if (trace_ray(r, 0.0f, FLT_MAX, rec)) {
		if (lights.size() == 0) {
			return color(0.7f, 0.7f, 0.7f);
		}
		color col = ambient_shading(*lights[0], rec);
		for (int i = 0; i < lights.size(); i++) {
			if (!lights[i]->trace_shadow_ray(rec, objs_vector)) {
				col += phong_shading(*lights[i], rec, *cam, lights[i]->get_light_point_direction(rec));
			}
		}
		return col;
	}
	else {
		return colorLerpY(r,  color(1.0f, 1.0f, 1.0f), color(0.5f, 0.7f, 1.0f));
	}
}

void scene::renderRandom(SDL_Renderer*& renderer, int ns) {
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

void scene::parallelRenderRandom(SDL_Renderer*& renderer, int ns) {
	vector<color> matrix(nx * ny);
	parallel_for(int(0), ny, [&](int j) {
		for (int i = 0; i < nx; i++) {
			color col(0.0, 0.0, 0.0);
			for (int s = 0; s < ns; s++) {
				ray r = cam->get_ray(float((i + randZeroToOne()) / nx), float((j + randZeroToOne()) / ny));
				col += scene::shot(r);
			}
			col /= float(ns);
			col = color(sqrt(col.r), sqrt(col.g), sqrt(col.b));
			matrix[j * nx + i] = col;
		}
	});
	updateRendererFromMatrix(ny, nx, renderer, matrix);
}

void scene::parallelRenderJittered(SDL_Renderer*& renderer, int numLayers) {
	vector<color> matrix(nx * ny);
	parallel_for(int(0), ny, [&](int j) {
		for (int i = 0; i < nx; i++) {
			color col(0.0, 0.0, 0.0);
			for (int l1 = 0; l1 < numLayers; l1++) {
				for (int l2 = 0; l2 < numLayers; l2++) {
					ray r = cam->get_ray(float((i + (randZeroToOne() + l1) / numLayers) / nx), float((j + (randZeroToOne() + l2) / numLayers) / ny));
					col += scene::shot(r);
				}
			}
			col = col / float(numLayers * numLayers);
			col = color(sqrt(col.r), sqrt(col.g), sqrt(col.b));
			matrix[j * nx + i] = col;
		}
	});
	updateRendererFromMatrix(ny, nx, renderer, matrix);
}

void scene::parallelRenderNRooks(SDL_Renderer*& renderer, int nRockSize) {
	vector<int> rowIndices;
	vector<int> columnIndices;
	vector<color> matrix(nx * ny);
	for (int k = 0; k < nRockSize; k++) {
		rowIndices.push_back(k);
		columnIndices.push_back(k);
	}
	parallel_for(int(0), ny, [&](int j) {
		for (int i = 0; i < nx; i++) {
			color col(0.0, 0.0, 0.0);
			std::random_device rd;
			std::default_random_engine rng(rd());
			std::shuffle(std::begin(rowIndices), std::end(rowIndices), rng);
			std::shuffle(std::begin(columnIndices), std::end(columnIndices), rng);
			for (int l = 0; l < nRockSize; l++) {
				float u = (float(i) + (randZeroToOne() + rowIndices[l]) / float(nRockSize)) / nx;
				float v = (float(j) + (randZeroToOne() + columnIndices[l]) / float(nRockSize)) / ny;
				ray r = cam->get_ray(u, v);
				col += scene::shot(r);
			}
			col = col / float(nRockSize);
			col = color(sqrt(col.r), sqrt(col.g), sqrt(col.b));
			matrix[j * nx + i] = col;
		}
	});
	updateRendererFromMatrix(ny, nx, renderer, matrix);
}

void scene::parallelRenderMultiJittered(SDL_Renderer*& renderer, int nRockPerLayer) {
	std::vector<int> multiJitteredMatrix(nRockPerLayer * nRockPerLayer * 2);
	for (int i = 0; i < nRockPerLayer; i++) {
		int cont = 0;
		for (int j = 0; j < nRockPerLayer; j++) {
			if ((i + j) < nRockPerLayer) {
				multiJitteredMatrix.at(nRockPerLayer * i + j) = i + j;
				multiJitteredMatrix.at(nRockPerLayer * i + j + nRockPerLayer * nRockPerLayer) = i + j;
			}
			else {
				multiJitteredMatrix.at(nRockPerLayer * i + j) = cont;
				multiJitteredMatrix.at(nRockPerLayer * i + j + nRockPerLayer * nRockPerLayer) = cont;
				cont++;
			}
		}
	}
	vector<int> rowIndices;
	vector<int> columnIndices;
	for (int k = 0; k < nRockPerLayer; k++) {
		rowIndices.push_back(k);
		columnIndices.push_back(k);
	}
	vector<color> matrix(nx * ny);
	parallel_for(int(0), ny, [&](int j) {
		for (int i = 0; i < nx; i++) {
			color col(0.0, 0.0, 0.0);
			std::random_device rd;
			std::default_random_engine rng(rd());
			for (int k = 0; k < nRockPerLayer; k++) {
				std::shuffle(std::begin(rowIndices), std::end(rowIndices), rng);
				std::shuffle(std::begin(columnIndices), std::end(columnIndices), rng);
				for (int l = 0; l < nRockPerLayer; l++) {
					multiJitteredMatrix.at(nRockPerLayer * k + l) = rowIndices[l];
					multiJitteredMatrix.at(nRockPerLayer * l + k + nRockPerLayer * nRockPerLayer) = columnIndices[l];
				}
			}
			for (int k = 0; k < nRockPerLayer; k++) {
				for (int l = 0; l < nRockPerLayer; l++) {
					float u = (i + l / float(nRockPerLayer) + (randZeroToOne() + multiJitteredMatrix.at(nRockPerLayer * k + l)) / pow(nRockPerLayer, 2)) / nx;
					float v = (j + (nRockPerLayer - k) / float(nRockPerLayer) + (randZeroToOne() + multiJitteredMatrix.at(nRockPerLayer * k + l + nRockPerLayer * nRockPerLayer)) / pow(nRockPerLayer, 2)) / ny;
					ray r = cam->get_ray(u, v);
					col += scene::shot(r);
				}
			}
			col = col / float(nRockPerLayer * nRockPerLayer);
			col = color(sqrt(col.r), sqrt(col.g), sqrt(col.b));
			matrix[j * nx + i] = col;
		}
	});
	updateRendererFromMatrix(ny, nx, renderer, matrix);

}

void scene::updateRendererFromMatrix(int image_height, int image_width, SDL_Renderer*& renderer, vector<color>& matrix) {
	for (int j = 0; j < image_height; j++) {
		for (int i = 0; i < image_width; i++) {
			color col = matrix[j * image_width + i];
			setColor(renderer, col.r, col.g, col.b);
			setPixel(renderer, i, j, image_height);
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
		}
	}
	return hit_anything;
}
