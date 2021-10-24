#include "rayTracingAnimationCube.h"
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

void showRayTracingAnimationCube() {

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
    const int num_elements = 27;
    Object *list[num_elements];
    cam.position = point3d(7.0f, 8.0f, 11.0f);
    cam.lookPoint = point3d(-2.2f, 0.0f, -4.0f);
    cam.update_camera();
    list[0] = new box(point3d(-2.0f, -1.5f, -3.0f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[1] = new box(point3d(-3.04f, -1.5f, -3.0f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[2] = new box(point3d(-4.08f, -1.5f, -3.0f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[3] = new box(point3d(-2.0f, -0.46f, -3.0f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[4] = new box(point3d(-3.04f, -0.46f, -3.0f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[5] = new box(point3d(-4.08f, -0.46f, -3.0f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[6] = new box(point3d(-2.0f, 0.58f, -3.0f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[7] = new box(point3d(-3.04f, 0.58f, -3.0f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[8] = new box(point3d(-4.08f, 0.58f, -3.0f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[9] = new box(point3d(-2.0f, -1.5f, -4.04f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[10] = new box(point3d(-3.04f, -1.5f, -4.04f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[11] = new box(point3d(-4.08f, -1.5f, -4.04f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[12] = new box(point3d(-2.0f, -0.46f, -4.04f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[13] = new box(point3d(-3.04f, -0.46f, -4.04f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[14] = new box(point3d(-4.08f, -0.46f, -4.04f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[15] = new box(point3d(-2.0f, 0.58f, -4.04f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[16] = new box(point3d(-3.04f, 0.58f, -4.04f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[17] = new box(point3d(-4.08f, 0.58f, -4.04f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[18] = new box(point3d(-2.0f, -1.5f, -5.08f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[19] = new box(point3d(-3.04f, -1.5f, -5.08f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[20] = new box(point3d(-4.08f, -1.5f, -5.08f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[21] = new box(point3d(-2.0f, -0.46f, -5.08f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[22] = new box(point3d(-3.04f, -0.46f, -5.08f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[23] = new box(point3d(-4.08f, -0.46f, -5.08f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[24] = new box(point3d(-2.0f, 0.58f, -5.08f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[25] = new box(point3d(-3.04f, 0.58f, -5.08f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));
    list[26] = new box(point3d(-4.08f, 0.58f, -5.08f), vec3(1.0f,0,0),  vec3(0,1.00,0), vec3(0,0,1.0f));



    object_list* scene = new object_list(list, num_elements);

    vec3 startBackgroundColor(0.0f, 0.0f, 0.0f);
    vec3 endBackgroundColor(0.1f, 0.05f, 0.1f);

    int ns = 1;
    float maxAngle = 360 * 20 * M_PI / 180.0f;
    int frames = 1280;

    float cameraDistance = 12.0f;
    for (float i = maxAngle / frames; i <= maxAngle; i += maxAngle / frames) {
        cam.position.x = cameraDistance * cos(i + M_PI / 2);
        cam.position.y = cameraDistance * sin(i + M_PI / 2);
        cam.position.z = cameraDistance * sin(i + M_PI / 2);
        cam.update_camera();
        renderFrame(cam, ns, image_height, image_width, renderer, scene, startBackgroundColor, endBackgroundColor);
        update(renderer);
    }

    close(renderer, window);
    time_t current_time = time(NULL);
    cout << "Impiegati " << current_time - start_time << " secondi per il rendering" << endl;
}


