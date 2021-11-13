#include "rayTracingShadow.h"
#include "utilitySDL.h"
#include "scene.h"
#include "Sphere.h"

using namespace std;

void showRayTracingShadow() {

    SDL_Window* window;
    SDL_Renderer* renderer;

    //point3d cameraPosition(13.0f, 2.0f, 3.0f);
    point3d cameraPosition(0.0f, 12.0f, 30.0f);
    point3d cameraOrientation(0.0f, 0.0f, 0.0f);
    vec3 upVector(0.0f, 1.0f, 0.0f);
    float fieldOfView = 20.0f;

    int const image_width = 1000;
    int const image_height = 500;
    const int ns = 1;

    time_t start_time = time(NULL);

    if (init(window, renderer, image_width, image_height) == 1) {
        cout << "Gradient Error! " << std::endl;
        return;
    }

    scene world;

    color gray(0.7f, 0.7f, 0.7f);
    //point3d light_position(6.0f, 6.0f, 0.0f);
    point3d light_position(-6.0f, 6.0f, 0.0f);
    point_light* light = new point_light(light_position, gray, gray, gray);
    world.addLight(light);

    world.setCamera(cameraPosition, cameraOrientation, upVector, fieldOfView, image_width, image_height, ns);


    srand(2);
    color randColor(randZeroToOne(), randZeroToOne(), randZeroToOne());
    world.addObject(new Sphere(point3d(0, -1000, 0), 1000, new material(randColor, randColor , randColor, 4.0)));

    int i = 1;
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            float choose_mat = randZeroToOne();
            point3d center(a + 0.9f * randZeroToOne(), 0.2f, b + 0.9f * randZeroToOne());
            randColor = color(randZeroToOne(), randZeroToOne(), randZeroToOne());
            world.addObject(new Sphere(center, 0.2f, new material(randColor, randColor, randColor, 4.0)));
        }
    }

    randColor = color(randZeroToOne(), randZeroToOne(), randZeroToOne());
    world.addObject(new Sphere(point3d(0, 1, 0), 1.0f, new material(randColor, randColor, randColor, 4.0)));
    randColor = color(randZeroToOne(), randZeroToOne(), randZeroToOne());
    world.addObject(new Sphere(point3d(-4, 1, 0), 1.0f, new material(randColor, randColor, randColor, 4.0)));
    randColor = color(randZeroToOne(), randZeroToOne(), randZeroToOne());
    world.addObject(new Sphere(point3d(4, 1, 0), 1.0f, new material(randColor, randColor, randColor, 4.0)));

    world.parallelRender(renderer);

    time_t current_time = time(NULL);
    cout << "Impiegati " << current_time - start_time << " secondi per il rendering";
    updateAndWait(renderer);
    close(renderer, window);
}

