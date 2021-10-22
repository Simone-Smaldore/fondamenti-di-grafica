#include <iostream>
#include <list>
#include <ctime>
#include "rayTracing.h"
#include "SDL.h"
#include "../utilitySDL/utilitySDL.h"
#include "../model/Sphere.h"
#include "../model/camera.h"
#include "../model/plane.h"
#include "../model/disk.h"
#include "../model/quadrilateral.h"

using namespace std;

void showRayTracing() {

    SDL_Window* window;
    SDL_Renderer* renderer;

    point3d cameraPosition(0.0f,0.0f,6.0f);
    point3d cameraOrientation(0.0f,0.0f,0.0f);
    vec3 upVector(0.0f, 1.0f,0.0f);
    float fieldOfView = 40.0f;
    float aspectRatio = 16/8;

    camera cam(cameraPosition, cameraOrientation, upVector, fieldOfView, aspectRatio);

    int const image_width = 800;
    int const image_height = 400;
    int ns = 16;

    time_t start_time = time(NULL);

    if (init(window, renderer, image_width, image_height) == 1) {
        cout << "Gradient Error! " << std::endl;
        return;
    }

    int num_elements = 1;
    Object *list[num_elements];
//    list[0] = new Sphere(point3d(-1.1f, 0.0f, -2.0f), 1.0);
//    list[1] = new Sphere(point3d(1.1f, 0.0f, -2.0f), 1.0);
//    list[2] = new Sphere(point3d(-3.4f, 0.0f, -2.0f), 1.0);
//    list[3] = new Sphere(point3d(3.4f, 0.0f, -2.0f), 1.0);

//    Per i colori custom
//    list[0] -> color = vec3(1.0,0.0,0.0);
//    list[1] -> color = vec3(0.0,0.0,1.0);

//  QUALUNQUE SIA IL PIANO AVRO UN LIMITE DATO DA TMAX
//    list[0] = new plane(point3d(0.0f, -2.0f, 0.0f), vec3(0,1,0));

//   DISCO
//    list[0] = new disk(point3d(-1.0f, -1.0f, -5.0f), vec3(0.7,1,0), 2);

//  QUADRILATERO
//    list[0] = new quadrilateral(point3d(1.5f, 0.0f, 0.0f), vec3(.5,.5,.5),  vec3(0,1,0));
//    list[0] -> color = vec3(1.0,0.0,0.0);
//    list[1] = new quadrilateral(point3d(-1.5f, 0.0f, 0.0f), vec3(0,1,0), vec3(.5,.5,.5));
//    list[1] -> color = vec3(0.0,1.0,0.0);

    list[0] = new quadrilateral(point3d(1.5f, 0.0f, 0.0f), vec3(.5,.5,.5),  vec3(0,1,0));
    list[0] -> color = vec3(1.0,0.0,0.0);

    object_list *scene = new object_list(list, num_elements);

    vec3 startBackgroundColor(1.0f, 1.0f, 1.0f);
    vec3 endBackgroundColor(0.5f, 0.7f, 1.0f);

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            vec3 color(0.0, 0.0, 0.0);
            for (int s = 0; s < ns; s++) {
                ray r = cam.get_ray(float((i + randZeroToOne()) / image_width), float((j + randZeroToOne()) / image_height));
                color += getColor(scene, r, startBackgroundColor, endBackgroundColor);
            }
            color = color / float(ns);
            color = vec3(sqrt(color[0]), sqrt(color[1]), sqrt(color[2])); //GAMMA CORRECTION
            setColor(renderer, color.x, color.y, color.z);
            setPixel(renderer, i, j, image_height);
        }
    }

    time_t current_time = time(NULL);
    cout << "Impiegati " << current_time - start_time << " secondi per il rendering";
    update(renderer);
    close(renderer, window);
}

vec3 getColor(object_list* scene, ray &r, vec3 &startColor, vec3 &endColor, float t_min, float t_max){
    hit_record hit;
    if(scene->trace_ray(r, t_min, t_max, hit)) {
        return scene->list[hit.object_index]->color;
//        return 0.5f * (vec3(hit.normal.x, hit.normal.y, hit.normal.z) + vec3(1.0, 1.0, 1.0));
    } else {
        return colorLerpY(r, startColor, endColor);
    }
}

float randZeroToOne() {
    return ((float) rand()) / (float) RAND_MAX;
}

