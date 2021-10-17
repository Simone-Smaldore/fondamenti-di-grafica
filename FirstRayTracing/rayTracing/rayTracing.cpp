#include <iostream>
#include <list>
#include "rayTracing.h"
#include "SDL.h"
#include "../utilitySDL/utilitySDL.h"
#include "../model/Sphere.h"

using namespace std;

void showRayTracing() {

    SDL_Window* window;
    SDL_Renderer* renderer;

    int const image_width = 1200;
    int const image_height = 600;

    if (init(window, renderer, image_width, image_height) == 1) {
        cout << "Gradient Error! " << std::endl;
        return;
    }
    float left = -2.0;
    float right = 2.0;
    float bottom = -1.0;
    float top = 1.0;
    float d = 1.0;
    //ORIGINE
    point3d o(0.0, 0.0, 0.0);
    //VERSORI
    vec3 un(1.0, 0.0, 0.0);
    vec3 vn(0.0, 1.0, 0.0);
    vec3 wn(0.0, 0.0, 1.0);
    float horizontal = right - left;
    float vertical = top - bottom;

    Object *list[2];

    list[0] = new Sphere(point3d(0.0f, 0.0f, -2.0f), 1.0);
    list[1] = new Sphere(point3d(1.0f, -4.0f, -8.0f), 2.0);
    list[0] -> color = vec3(1.0,0.0,0.0);
    list[1] -> color = vec3(0.0,0.0,1.0);
    object_list *scene = new object_list(list, 2);


    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            float u = left + (float(i + 0.5)  * horizontal / float(image_width));
            float v = bottom + (float(j + 0.5) * vertical / float(image_height));
            ray r(o, -d*wn + u*un + v*vn);
            vec3 startColor(1.0f, 1.0f, 1.0f);
            vec3 endColor(0.5f, 0.7f, 1.0f);
            vec3 color = getColor(scene, r, startColor, endColor);
            setColor(renderer, color.x, color.y, color.z);
            setPixel(renderer, i, j, image_height);
        }
    }

    update(renderer);
    close(renderer, window);
}

vec3 getColor(object_list* scene, ray &r, vec3 &startColor, vec3 &endColor, float t_min, float t_max){
    hit_record hit;
    if(scene->trace_ray(r, t_min, t_max, hit)) {
        return scene->list[hit.object_index]->color;
    } else {
        return colorLerpY(r, startColor, endColor);
    }
}

