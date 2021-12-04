#include "secondaEsercitazione.h"
#include "utilitySDL.h"
#include "scene.h"
#include "Sphere.h"
#include "blurSphere.h"
#include "cylinder.h"
#include "instance.h"
#include "spot_light.h"
#include "point_light.h"
#include "direction_light.h"
#include "mesh.h"

using namespace std;

void showSecondaEsercitazione() {

    SDL_Window* window;
    SDL_Renderer* renderer;

    //point3d cameraPosition(13.0f, 2.0f, 3.0f);
    point3d cameraPosition(0.0f, 15.0f, 35.0f);
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
    color lightgray(0.75f, 0.75f, 0.75f);
    color black(0.0f, 0.0f, 0.0f);
    color black20(0.2f, 0.2f, 0.2f);
    vec3 light_direction(1, 1, 0);

    srand(3);
    color randColor(randZeroToOne(), randZeroToOne(), randZeroToOne());

    
    point3d light_position(0.0f, 10.0f, 90.0f);
    point_light* light = new point_light(light_position, black, lightgray, black);
    world.addLight(light);

    point3d lookfrom(0, 4, 13);
    point3d lookat(0, 0, -1);
    vec3 up(0, 1, 0);
    world.setCamera(lookfrom, lookat, up, 20, image_width, image_height);

    Object* model3d = new mesh("./models/cat.obj", "./models/");
    texture* cat_texture = new image_texture("./models/texturecat.jpg");
    //texture* earth_texture = new image_texture("./models/earth.jpg");
    texture* earth_texture = new image_texture("./models/biliard.jpg");
    //material* m = new material();
    //m->alpha = 100000;
    //m->mat_texture = cat_texture;
    //m->ka = lightgray;
    //m->ks = lightgray;
    //instance* mesh_ptr = new instance(model3d, m);

    //mesh_ptr->scale(0.4, 0.4, 0.4);
    //
    //mesh_ptr->rotate_x(-90.0f);
    //mesh_ptr->rotate_y(60.0f);
    //mesh_ptr->translate(0.0f, -40.0f, -120.0f);
    //world.addObject(mesh_ptr);



    Object* sphere_model_f = new Sphere(point3d(0, 0, 0), 1.0f);
    Object* sphere_model = new blurSphere(point3d(0, 0, 0), point3d(1.0f, 0, 0.0f), 0, 1.0f, 1.0f);
    //Object* sphere_model = new cylinder(-1.0f, 1.0f, 1.0f);
    material* sphere_m = new material();  
    sphere_m->mat_texture = earth_texture;
    sphere_m->ka = lightgray;
    sphere_m->ks = lightgray;
    instance* sphere_ptr = new instance(sphere_model, sphere_m);
    //sphere_ptr->rotate_y(90);
    //sphere_ptr->translate(-4.0f ,0,-10.0f);
  
    world.addObject(sphere_ptr);

    material* floor_m = new material();
    instance* sphere_floor = new instance(sphere_model_f, floor_m);
    texture* floor_texture = new constant_texture(color(0,1.0f,0.0f));
    floor_m->mat_texture = floor_texture;
    floor_m->ka = lightgray;
    floor_m->ks = lightgray;
    sphere_floor->scale(1000.0, 1000.0, 1000.0);
    sphere_floor->translate(0, -1005, 0);
    world.addObject(sphere_floor);



    //world.parallelRenderRandom(renderer, ns);
    //world.parallelRenderMultiJittered(renderer, 3);
    world.parallelRenderBlur(renderer, 300);

    time_t current_time = time(NULL);
    cout << "Impiegati " << current_time - start_time << " secondi per il rendering";
    updateAndWait(renderer);
    close(renderer, window);
}

