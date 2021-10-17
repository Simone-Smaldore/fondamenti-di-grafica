#include <iostream>
#include <list>
#include <ctime>
#include "rayTracing.h"
#include "SDL.h"
#include "utilitySDL.h"
#include "Sphere.h"
#include "camera.h"
#include <vector>
#include <windows.h>
#include <ppl.h>

using namespace std;
using namespace concurrency;

void showRayTracing() {

    SDL_Window* window;
    SDL_Renderer* renderer;
    camera cam;

    int const image_width = 800;
    int const image_height = 400;

    time_t start_time = time(NULL);

    if (init(window, renderer, image_width, image_height) == 1) {
        cout << "Gradient Error! " << std::endl;
        return;
    }

    Object* list[2];
    list[0] = new Sphere(point3d(0.0f, 0.0f, -2.0f), 1.0);
    list[1] = new Sphere(point3d(0.0f, -4.0f, -8.0f), 2.0);
    list[0]->color = vec3(1.0, 0.0, 0.0);
    list[1]->color = vec3(0.0, 0.0, 1.0);
    object_list* scene = new object_list(list, 2);

    vec3 startBackgroundColor(1.0f, 1.0f, 1.0f);
    vec3 endBackgroundColor(0.5f, 0.7f, 1.0f);

    int ns = 16;

    //vector<vec3> matrix(image_width*image_height);

    //parallel_for(int(0), image_height, [&](int j) {
    //    for (int i = 0; i < image_width; i++) {
    //        vec3 color(0.0, 0.0, 0.0);
    //        for (int s = 0; s < ns; s++) {
    //            ray r = cam.get_ray(float((i + randZeroToOne()) / image_width), float((j + randZeroToOne()) / image_height));
    //            color += getColor(scene, r, startBackgroundColor, endBackgroundColor);;
    //        }
    //        matrix[j * image_width + i] = color / float(ns);
    //    }
    //});

    //for (int j = 0; j < image_height; j++) {
    //    for (int i = 0; i < image_width; i++) {
    //        vec3 color = matrix[j * image_width + i];
    //        setColor(renderer, color.x, color.y, color.z);
    //        setPixel(renderer, i, j, image_height);
    //    }
    //}
    

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            vec3 color(0.0, 0.0, 0.0);
            for (int s = 0; s < ns; s++) {
                ray r = cam.get_ray(float((i + randZeroToOne()) / image_width), float((j + randZeroToOne()) / image_height));
                color += getColor(scene, r, startBackgroundColor, endBackgroundColor);;
            }
            color = color / float(ns);
            setColor(renderer, color.x, color.y, color.z);
            setPixel(renderer, i, j, image_height);
        }
    }

    time_t current_time = time(NULL);
    cout << "Impiegati " << current_time - start_time << " secondi per il rendering";
    update(renderer);
    close(renderer, window);
}

vec3 getColor(object_list* scene, ray& r, vec3& startColor, vec3& endColor, float t_min, float t_max) {
    hit_record hit;
    if (scene->trace_ray(r, t_min, t_max, hit)) {
        return scene->list[hit.object_index]->color;
    }
    else {
        return colorLerpY(r, startColor, endColor);
    }
}

float randZeroToOne() {
    return ((float)rand()) / (float)RAND_MAX;
}

