#include "rayTracingAnimationUniverse.h"
#include <iostream>
#include <list>
#include <ctime>
#include <vector>
#include <random>
#include "SDL.h"
#include "utilitySDL.h"
#include "utilitySDLInline.h"
#include "Sphere.h"
#include "camera.h"
#include "parallelCamera.h"
#include "plane.h"
#include "disk.h"
#include "quadrilateral.h"
#include "box.h"

using namespace std;


void showRayTracingAnimationUniverse() {

    string baseUrl = "C:\\Users\\simon\\Desktop\\Universita\\Magistrale\\Quinto anno\\Fondamenti Di Grafica Tridimensionale\\ProgettiGit\\FirstRayTracingWindows\\FirstRayTracingWindows\\img\\";

    SDL_Window* window;
    SDL_Renderer* renderer;

    point3d cameraPosition(-110.0f, 75.0f, 140.0f);
    point3d cameraOrientation(0.0f, 0.0f, 0.0f);
    vec3 upVector(0.0f, 1.0f, 0.0f);
    float fieldOfView = 40.0f;
    float aspectRatio = 16 / 8;

    camera cam(cameraPosition, cameraOrientation, upVector, fieldOfView, aspectRatio);

    int const image_width = 1000;
    int const image_height = 500;

    time_t start_time = time(NULL);

    if (init(window, renderer, image_width, image_height) == 1) {
        cout << "Gradient Error! " << std::endl;
        return;
    }
    const bool NORMAL_COLOR = false;
    const int num_elements = 10;
    Object* list[num_elements];
    list[0] = new Sphere(point3d(0.0f, 0.0f, -6.0f), 12.0);
    list[0]->color = vec3(1, 0.9, 0.2);
    list[1] = new Sphere(point3d(7.0f, 0.0f, -6.0f), 2.0);
    list[1]->color = vec3(0, 0, 1);
    list[2] = new Sphere(point3d(8.5f, 0.0f, 0.0f), 0.5);
    list[2]->color = vec3(0.9, 0.9, 0.9);
    list[3] = new Sphere(point3d(0.0f, 0.0f, 0.0f), 1.0);
    list[3]->color = vec3(0.5, 0.5, 0.5);
    list[4] = new Sphere(point3d(0.0f, 0.0f, 0.0f), 1.5);
    list[4]->color = vec3(1, 1, 0);
    list[5] = new Sphere(point3d(0.0f, 0.0f, 0.0f), 3.5);
    list[5]->color = vec3(1, 0, 0);
    list[6] = new Sphere(point3d(0.0f, 0.0f, 0.0f), 8.5);
    list[6]->color = vec3(0.68, 0.48, 0.20);
    list[7] = new Sphere(point3d(0.0f, 0.0f, 0.0f), 8.0);
    list[7]->color = vec3(0.84, 0.75, 0.69);
    list[8] = new Sphere(point3d(0.0f, 0.0f, 0.0f), 6.0);
    list[8]->color = vec3(0.49, 0.85, 0.85);
    list[9] = new Sphere(point3d(0.0f, 0.0f, 0.0f), 5.0);
    list[9]->color = vec3(0.215, 0.43, 0.85);

    object_list* scene = new object_list(list, num_elements);

    vec3 startBackgroundColor(0.0f, 0.0f, 0.0f);
    vec3 endBackgroundColor(0.1f, 0.05f, 0.1f);

    const int ns = 1;
    const int nRockPerLayer = 5;
    float maxAngle = 360 * 20 * M_PI / 180.0f;
    int frames = 1280;
    int cont = 0;

    float sphereCenterDistanceEarth = 30.0f;
    float sphereCenterDistanceMoon = 3.0f;
    float sphereCenterDistanceMercury = 15.0f;
    float sphereCenterDistanceVenus = 20.0f;
    float sphereCenterDistanceMars = 40.0f;
    float sphereCenterDistanceJupiter = 55.0f;
    float sphereCenterDistanceSaturn = 75.0f;
    float sphereCenterDistanceUranus = 90.0f;
    float sphereCenterDistanceNeptune = 105.0f;

    float speedEarthRatio = 1.0;
    float speedMoonRatio = 3.0;
    float speedMercuryRatio = 2.5;
    float speedVenusRatio = 2.0;
    float speedMarsRatio = 0.7;
    float speedJupiterRatio = 0.6;
    float speedSaturnRatio = 0.5;
    float speedUranusRatio = 0.4;
    float speedNeptuneRatio = 0.3;

    for (float i = maxAngle / frames; i <= maxAngle; i += maxAngle / frames) {
        Sphere* sun = dynamic_cast<Sphere*>(scene->list[0]);
        Sphere* earth = dynamic_cast<Sphere*>(scene->list[1]);
        Sphere* moon = dynamic_cast<Sphere*>(scene->list[2]);
        Sphere* mercury = dynamic_cast<Sphere*>(scene->list[3]);
        Sphere* venus = dynamic_cast<Sphere*>(scene->list[4]);
        Sphere* mars = dynamic_cast<Sphere*>(scene->list[5]);
        Sphere* jupiter = dynamic_cast<Sphere*>(scene->list[6]);
        Sphere* saturn = dynamic_cast<Sphere*>(scene->list[7]);
        Sphere* uranus = dynamic_cast<Sphere*>(scene->list[8]);
        Sphere* neptune = dynamic_cast<Sphere*>(scene->list[9]);
        earth->center.x = sun->center.x + sphereCenterDistanceEarth * cos(i * speedEarthRatio + M_PI / 2);
        earth->center.z = sun->center.z + sphereCenterDistanceEarth * sin(i * speedEarthRatio + M_PI / 2);
        moon->center.x = earth->center.x + sphereCenterDistanceMoon * cos(i * speedMoonRatio + M_PI / 2);
        moon->center.z = earth->center.z + sphereCenterDistanceMoon * sin(i * speedMoonRatio + M_PI / 2);
        mercury->center.x = sun->center.x + sphereCenterDistanceMercury * cos(i * speedMercuryRatio + M_PI / 2);
        mercury->center.z = sun->center.z + sphereCenterDistanceMercury * sin(i * speedMercuryRatio + M_PI / 2);
        venus->center.x = sun->center.x + sphereCenterDistanceVenus * cos(i * speedVenusRatio + M_PI / 2);
        venus->center.z = sun->center.z + sphereCenterDistanceVenus * sin(i * speedVenusRatio + M_PI / 2);
        mars->center.x = sun->center.x + sphereCenterDistanceMars * cos(i * speedMarsRatio + M_PI / 2);
        mars->center.z = sun->center.z + sphereCenterDistanceMars * sin(i * speedMarsRatio + M_PI / 2);
        jupiter->center.x = sun->center.x + sphereCenterDistanceJupiter * cos(i * speedJupiterRatio + M_PI / 2);
        jupiter->center.z = sun->center.z + sphereCenterDistanceJupiter * sin(i * speedJupiterRatio + M_PI / 2);
        saturn->center.x = sun->center.x + sphereCenterDistanceSaturn * cos(i * speedSaturnRatio + M_PI / 2);
        saturn->center.z = sun->center.z + sphereCenterDistanceSaturn * sin(i * speedSaturnRatio + M_PI / 2);
        uranus->center.x = sun->center.x + sphereCenterDistanceUranus * cos(i * speedUranusRatio + M_PI / 2);
        uranus->center.z = sun->center.z + sphereCenterDistanceUranus * sin(i * speedUranusRatio + M_PI / 2);
        neptune->center.x = sun->center.x + sphereCenterDistanceNeptune * cos(i * speedNeptuneRatio + M_PI / 2);
        neptune->center.z = sun->center.z + sphereCenterDistanceNeptune * sin(i * speedNeptuneRatio + M_PI / 2);
        renderFrameRandom(cam, ns, image_height, image_width, renderer, scene, startBackgroundColor, endBackgroundColor, NORMAL_COLOR);
        //renderFrameMultiJittered(cam, nRockPerLayer, image_height, image_width, renderer, scene, startBackgroundColor, endBackgroundColor, NORMAL_COLOR);
        update(renderer);

        //RIGHE PER LA GENERAZIONE DEI FRAME
        //string url = baseUrl + to_string(cont) + ".bmp";
        //saveScreenshotBMP(url, window, renderer);
        //cont++;
        //cout << "SAVED FRAME IN " << url << endl;
    }

    close(renderer, window);
    time_t current_time = time(NULL);
    cout << "Impiegati " << current_time - start_time << " secondi per il rendering" << endl;
}




