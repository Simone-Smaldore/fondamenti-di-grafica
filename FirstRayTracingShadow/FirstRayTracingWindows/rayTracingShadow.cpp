#include "rayTracingShadow.h"
#include "utilitySDL.h"
#include "scene.h"
#include "Sphere.h"
#include "cylinder.h"
#include "instance.h"
#include "spot_light.h"
#include "point_light.h"
#include "direction_light.h"
#include "mesh.h"

using namespace std;

void showRayTracingShadow() {

    SDL_Window* window;
    SDL_Renderer* renderer;

    //point3d cameraPosition(13.0f, 2.0f, 3.0f);
    point3d cameraPosition(0.0f, 7.0f, 25.0f);
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
    vec3 light_direction(1, 1, 0);

    point3d light_position(-6.0f, 6.0f, 0.0f);
    point_light* p_light = new point_light(light_position, gray, gray, gray);
    world.addLight(p_light);

    srand(3);
    color randColor(randZeroToOne(), randZeroToOne(), randZeroToOne());


    //Object* model3d = new mesh("./models/bunny2.obj", "/models/");
    Object* model3d = new mesh("./models/bunny2.obj", "/models/");
    instance* mesh_ptr = new instance(model3d, new material(randColor, randColor, randColor, 4.0));
    mesh_ptr->scale(10, 10, 10);
    //mesh_ptr->rotate_y(45.0f);
    //mesh_ptr->translate(0.0f, -25.0f, -230.0f);

    //world.addObject(mesh_ptr);

    //point3d light_position(-6.0f, 6.0f, 0.0f);
    //direction_light* d_light = new direction_light(normalize(light_direction), gray, gray, gray);
    //world.addLight(d_light);

    //light_position = point3d(-6.0f, 9.0f, 0.0f);
    //spot_light* s_light = new spot_light(light_position, normalize(vec3(0,1,0)), 25.0, 2.7,gray, gray, gray);
    //world.addLight(s_light);

    //light_position = point3d(6.0f, 9.0f, 0.0f);
    //spot_light* s_light_2 = new spot_light(light_position, normalize(vec3(0, 1, 0)), 25.0, 2.7, gray, gray, gray);
    //world.addLight(s_light_2);

    world.setCamera(cameraPosition, cameraOrientation, upVector, fieldOfView, image_width, image_height);

    Object* sphere_model = new Sphere(point3d(0,0,0), 1.0f); 
    randColor = color(randZeroToOne(), randZeroToOne(), randZeroToOne());
    instance* sphere_ptr = new instance(sphere_model, new material(randColor, randColor, randColor, 4.0));
    sphere_ptr->scale(1000.0, 1000.0, 1000.0);
    sphere_ptr->translate(0, -1000, 0);
    world.addObject(sphere_ptr);

    Object* cylinder_model = new cylinder(1.0f, 3.0f, 1.0f);
    randColor = color(randZeroToOne(), randZeroToOne(), randZeroToOne());
    instance* cylinder_ptr = new instance(cylinder_model, new material(randColor, randColor, randColor, 4.0));
    //sphere_ptr->scale(1000.0, 1000.0, 1000.0);
    cylinder_ptr->rotate_x(45);
    cylinder_ptr->translate(0, 1.0f, 0);
    world.addObject(cylinder_ptr);

    //randColor = color(randZeroToOne(), randZeroToOne(), randZeroToOne());
    //sphere_ptr = new instance(sphere_model, new material(randColor, randColor, randColor, 4.0));
    //sphere_ptr->translate(0, 1, 0);
    //world.addObject(sphere_ptr);

    //randColor = color(randZeroToOne(), randZeroToOne(), randZeroToOne());
    //sphere_ptr = new instance(sphere_model, new material(randColor, randColor, randColor, 4.0));
    //sphere_ptr->translate(-4, 1, 0);
    //world.addObject(sphere_ptr);

    //randColor = color(randZeroToOne(), randZeroToOne(), randZeroToOne());
    //sphere_ptr = new instance(sphere_model, new material(randColor, randColor, randColor, 4.0));
    //sphere_ptr->translate(4, 1, 0);
    //world.addObject(sphere_ptr);

    //for (int a = -11; a < 11; a++) {
    //    for (int b = -11; b < 11; b++) {
    //        point3d center(a + 0.9f * randZeroToOne(),
    //            0.2f,
    //            b + 0.9f * randZeroToOne());
    //        randColor = color(randZeroToOne(), randZeroToOne(), randZeroToOne());
    //        sphere_ptr = new instance(sphere_model, new material(randColor, randColor, randColor, 4.0));
    //        sphere_ptr->scale(0.2f, 0.4f, 0.2f);
    //        sphere_ptr->translate(center.x, center.y, center.z);
    //        world.addObject(sphere_ptr);
    //    }
    //}


    world.parallelRenderRandom(renderer, ns);
    //world.parallelRenderMultiJittered(renderer, 3);

    time_t current_time = time(NULL);
    cout << "Impiegati " << current_time - start_time << " secondi per il rendering";
    updateAndWait(renderer);
    close(renderer, window);
}

