#include <iostream>
#include <list>
#include <ctime>
#include "rayTracing.h"
#include "SDL.h"
#include "utilitySDL.h"
#include "Sphere.h"
#include "camera.h"
#include "parallelCamera.h"
#include "plane.h"
#include "disk.h"
#include "quadrilateral.h"
#include "box.h"
#include "triangle.h"
#include <vector>
#include <windows.h>
#include <ppl.h>
#include <random>

using namespace std;
using namespace concurrency;

void showRayTracing() {

    SDL_Window* window;
    SDL_Renderer* renderer;

    point3d cameraPosition(0.0f, 0.0f, 6.0f);
    point3d cameraOrientation(0.0f, 0.0f, 0.0f);
    vec3 upVector(0.0f, 1.0f, 0.0f);
    float fieldOfView = 40.0f;
    float aspectRatio = 16 / 8;

    //    PROSPECTIVE CAMERA
    camera cam(cameraPosition, cameraOrientation, upVector, fieldOfView, aspectRatio);
    //    PARALLEL CAMERA
    //parallelCamera cam(cameraPosition, cameraOrientation, upVector, fieldOfView, aspectRatio);

    int const image_width = 1000;
    int const image_height = 500;

    time_t start_time = time(NULL);

    if (init(window, renderer, image_width, image_height) == 1) {
        cout << "Gradient Error! " << std::endl;
        return;
    }

    //    USE NORMAL_COLOR false FOR THE SECTION WITH CUSTOM COLOR

    bool NORMAL_COLOR = true;

    //    COMMENT AND DECOMMENT SECTION TO SEE DIFFERENT RENDERING

    //    PLANE LIMITED BY TMAX (NORMAL COLOR);
    //const int num_elements = 1;
    //Object* list[num_elements];
    //list[0] = new plane(point3d(0.0f, -2.0f, 0.0f), vec3(0, 1, 0));

    //    DISK (CUSTOM COLOR)
    //const int num_elements = 6;
    //Object* list[num_elements];
    //list[0] = new disk(point3d(0.0f, 0.0f, -10.0f), vec3(0, 0, 1), 5);
    //list[1] = new disk(point3d(-1.5f, 1.0f, -5.0f), vec3(0.3, 0.9, 1), 1);
    //list[2] = new disk(point3d(1.5f, 1.0f, -5.0f), vec3(-0.3, 0.9, 1), 1);
    //list[3] = new disk(point3d(0.0f, -2.0f, -5.0f), vec3(0.0, 1, 0.4), 0.7);
    //list[4] = new disk(point3d(-1.0f, 0.9f, -3.0f), vec3(0.0, 0, 1), 0.25);
    //list[5] = new disk(point3d(1.3f, 1.0f, -3.0f), vec3(0.0, 0, 1), 0.25);
    //list[0]->color = vec3(1, 1, 0);
    //list[1]->color = vec3(1, 1, 1);
    //list[2]->color = vec3(1, 1, 1);
    //list[3]->color = vec3(1, 0, 0);
    //list[4]->color = vec3(0, 0, 0);
    //list[5]->color = vec3(0, 0, 0);

    //    QUADRILATERAL (CUSTOM COLOR)
    //const int num_elements = 2;
    //Object* list[num_elements];
    //list[0] = new quadrilateral(point3d(1.5f, 0.0f, 0.0f), vec3(.5, .5, .5), vec3(0, 1, 0));
    //list[0]->color = vec3(1.0, 0.0, 0.0);
    //list[1] = new quadrilateral(point3d(-1.5f, 0.0f, 0.0f), vec3(0, 1, 0), vec3(.5, .5, .5));
    //list[1]->color = vec3(0.0, 1.0, 0.0);

    //    BOX (NORMAL COLOR)
    //const int num_elements = 27;
    //Object* list[num_elements];
    //cam.position = point3d(7.0f, 8.0f, 11.0f);
    //cam.lookPoint = point3d(-2.2f, 0.0f, -4.0f);
    //cam.update_camera();
    //list[0] = new box(point3d(-2.0f, -1.5f, -3.0f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[1] = new box(point3d(-3.04f, -1.5f, -3.0f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[2] = new box(point3d(-4.08f, -1.5f, -3.0f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[3] = new box(point3d(-2.0f, -0.46f, -3.0f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[4] = new box(point3d(-3.04f, -0.46f, -3.0f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[5] = new box(point3d(-4.08f, -0.46f, -3.0f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[6] = new box(point3d(-2.0f, 0.58f, -3.0f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[7] = new box(point3d(-3.04f, 0.58f, -3.0f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[8] = new box(point3d(-4.08f, 0.58f, -3.0f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[9] = new box(point3d(-2.0f, -1.5f, -4.04f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[10] = new box(point3d(-3.04f, -1.5f, -4.04f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[11] = new box(point3d(-4.08f, -1.5f, -4.04f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[12] = new box(point3d(-2.0f, -0.46f, -4.04f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[13] = new box(point3d(-3.04f, -0.46f, -4.04f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[14] = new box(point3d(-4.08f, -0.46f, -4.04f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[15] = new box(point3d(-2.0f, 0.58f, -4.04f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[16] = new box(point3d(-3.04f, 0.58f, -4.04f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[17] = new box(point3d(-4.08f, 0.58f, -4.04f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[18] = new box(point3d(-2.0f, -1.5f, -5.08f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[19] = new box(point3d(-3.04f, -1.5f, -5.08f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[20] = new box(point3d(-4.08f, -1.5f, -5.08f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[21] = new box(point3d(-2.0f, -0.46f, -5.08f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[22] = new box(point3d(-3.04f, -0.46f, -5.08f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[23] = new box(point3d(-4.08f, -0.46f, -5.08f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[24] = new box(point3d(-2.0f, 0.58f, -5.08f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[25] = new box(point3d(-3.04f, 0.58f, -5.08f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));
    //list[26] = new box(point3d(-4.08f, 0.58f, -5.08f), vec3(1.0f, 0, 0), vec3(0, 1.00, 0), vec3(0, 0, 1.0f));

    //    TRIANGLE (NORMAL COLOR)
    //const int num_elements = 9;
    //Object* list[num_elements];
    //list[0] = new triangle(point3d(-2.0f, -1.0f, -1.0f), point3d(-1.0f, -0.5f, -1.1f), point3d(-1.0f, 0.0f, -1.0f));
    //list[1] = new triangle(point3d(-1.0f, -0.5f, -1.1f), point3d(-1.0f, 0.0f, -1.0f), point3d(0.0f, -1.0f, -1.0f));
    //list[2] = new triangle(point3d(-2.0f, -1.0f, -1.0f), point3d(-1.0f, -0.5f, -1.1f), point3d(0.0f, -1.0f, -1.0f));
    //list[3] = new triangle(point3d(0.0f, -1.0f, -1.0f), point3d(1.0f, -0.5f, -1.1f), point3d(1.0f, 0.0f, -1.0f));
    //list[4] = new triangle(point3d(1.0f, -0.5f, -1.1f), point3d(1.0f, 0.0f, -1.0f), point3d(2.0f, -1.0f, -1.0f));
    //list[5] = new triangle(point3d(0.0f, -1.0f, -1.0f), point3d(1.0f, -0.5f, -1.1f), point3d(2.0f, -1.0f, -1.0f));
    //list[6] = new triangle(point3d(-1.0f, 0.0f, -1.0f), point3d(0.0f, 0.5f, -1.1f), point3d(0.0f, 1.0f, -1.0f));
    //list[7] = new triangle(point3d(0.0f, 0.5f, -1.1f), point3d(0.0f, 1.0f, -1.0f), point3d(1.0f, 0.0f, -1.0f));
    //list[8] = new triangle(point3d(-1.0f, 0.0f, -1.0f), point3d(0.0f, 0.5f, -1.1f), point3d(1.0f, 0.0f, -1.0f));

    //    EXAMPLE PARALLEL CAMERA (NORMAL COLOR) (CHANGE CAMERA TYPE TO SEE DIFFERENCES)
    const int num_elements = 2;
    Object* list[num_elements];
    list[0] = new Sphere(point3d(-0.35f, 0.0f, 5.0f), 0.3);
    list[1] = new Sphere(point3d(0.35f, 0.0f, -2.0f), 0.3);


    object_list* scene = new object_list(list, num_elements);

    vec3 startBackgroundColor(1.0f, 1.0f, 1.0f);
    vec3 endBackgroundColor(0.5f, 0.7f, 1.0f);

    // RANDOM 
    const int ns = 32;
    //renderFrameRandom(cam, ns, image_height, image_width, renderer, scene, startBackgroundColor, endBackgroundColor, NORMAL_COLOR);

    // JITTERED 
    const int numLayers = 4;
    //renderFrameJittered(cam, numLayers, image_height, image_width, renderer, scene, startBackgroundColor, endBackgroundColor, NORMAL_COLOR);
 
    // N-ROCK 
    const int nRockSize = 25;
    //renderFrameNRooks(cam, nRockSize, image_height, image_width, renderer, scene, startBackgroundColor, endBackgroundColor, NORMAL_COLOR);

    // MULTI JITTERED 
    const int nRockPerLayer = 5;
    renderFrameMultiJittered(cam, nRockPerLayer, image_height, image_width, renderer, scene, startBackgroundColor, endBackgroundColor, NORMAL_COLOR);

    time_t current_time = time(NULL);
    cout << "Impiegati " << current_time - start_time << " secondi per il rendering";
    updateAndWait(renderer);
    close(renderer, window);
}
