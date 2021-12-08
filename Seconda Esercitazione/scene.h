#pragma once
#include "camera.h"
#include "light.h"
#include "Object.h"
#include "utilitySDLInline.h"
#include <vector>
#include <ppl.h>



class scene {

	public:
		int nx;
		int ny;

		vector<Object*> objs_vector;

		camera* cam;
		vector<light*> lights;

		scene(){}

		void renderRandom(SDL_Renderer*& renderer, int ns);

		void parallelRenderRandom(SDL_Renderer*& renderer, int ns);

		void parallelRenderJittered(SDL_Renderer*& renderer, int numLayers);

		void parallelRenderNRooks(SDL_Renderer*& renderer, int nRockSize);

		void parallelRenderMultiJittered(SDL_Renderer*& renderer, int nRockPerLayer);

		void addObject(Object* new_object);

		void addLight(light* new_light);
		
		void setCamera(point3d position, point3d lookat, vec3 up, float fov, int res_x, int res_y);

		
	private:
		color shot(const ray& r);
		bool trace_ray(const ray& r, float t_min, float t_max, hit_record& rec) const;
		void updateRendererFromMatrix(int image_height, int image_width, SDL_Renderer*& renderer, vector<color>& matrix);

};

