#pragma once
#include "camera.h"
#include "point_light.h"
#include "Object.h"
#include "utilitySDLInline.h"
#include <vector>
#include <ppl.h>

//TO DO Implementare in renderer in una classe di utilità con le varie strategie
// Cambiare i riferimenti alle interfacce (GENERIC CAMERA E LIGHT)
// CAMBIARE NS in un nome generico per tutti gli algoritmi di sampling 

class scene {

	public:
		int nx;
		int ny;
		int ns;

		vector<Object*> objs_vector;

		camera* cam;
		point_light* light;

		scene(){}

		void render(SDL_Renderer*& renderer);

		void parallelRender(SDL_Renderer*& renderer);

		void addObject(Object* new_object);

		void addLight(point_light* new_light);
		
		void setCamera(point3d position, point3d lookat, vec3 up, float fov, int res_x, int res_y, int n_sampling);

		
	private:
		color shot(const ray& r);
		bool trace_ray(const ray& r, float t_min, float t_max, hit_record& rec) const;
		bool trace_shadow_ray(const ray& r, const float closest_light, int hit_index) const;

};

