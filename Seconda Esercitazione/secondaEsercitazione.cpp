#include "secondaEsercitazione.h"
#include "utilitySDL.h"
#include "scene.h"
#include "Sphere.h"
#include "blurSphere.h"
#include "quadrilateral.h"
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
    const int ns = 5;

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
    color violet(0.56f, 0.0f, 1.0f);
    //color blue(0.1725f, 0.149f, 0.3647f);
    color blue(0.4039f, 0.3372f, 0.745f);
    color f_blue(0, 0, 1);
    color f_red(1, 0, 0);
    color f_green(0, 1, 0);
    color f_yellow(1, 1, 0);
    vec3 light_direction(1, 1, 0);

    srand(2);
    color randColor(randZeroToOne(), randZeroToOne(), randZeroToOne());

    
    point3d light_position1(0.3f, 2.2f, -1.2f);
    point3d light_position2(-0.3f, 2.2f, -1.2f);
    point3d light_position3(-1.0f, 2.2f, -1.2f);
    point3d light_position4(1.0f, 2.2f, -1.2f);
    //point_light* light1 = new point_light(light_position1, black20, lightgray, black);
    //point_light* light2 = new point_light(light_position2, black20, lightgray, black);    
    //spot_light* light1 = new spot_light(light_position1, vec3(0,0,-1) ,90, 1,black20, lightgray, black);
    //spot_light* light2 = new spot_light(light_position2, vec3(0, 0,1),180, 1,black20, lightgray, black);
    direction_light* light1 = new direction_light(vec3(0,1,1), black20, black20, black20);
    spot_light* s_light1 = new spot_light(light_position1, vec3(-0.2f, 1, -0.5f), 8, 1, f_red, f_red, f_red);
    spot_light* s_light2 = new spot_light(light_position2, vec3(0.2f, 1, -0.5f), 8, 1, f_green, f_green, f_green);
    spot_light* s_light3 = new spot_light(light_position3, vec3(0.5f, 1, 0), 8, 1, f_blue, f_blue, f_blue);
    spot_light* s_light4 = new spot_light(light_position4, vec3(-0.5f, 1, 0), 8, 1, f_yellow, f_yellow, f_yellow);
    world.addLight(light1);
    world.addLight(s_light1);
    world.addLight(s_light2);
    world.addLight(s_light3);
    world.addLight(s_light4);
    //world.addLight(light2);


    point3d lookfrom(0, 4, 13);
    point3d lookat(0, 0, -1);
    vec3 up(0, 1, 0);
    world.setCamera(lookfrom, lookat, up, 20, image_width, image_height);

    //Object* model3d = new mesh("./models/cat.obj", "./models/");
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
    //Object* sphere_model = new blurSphere(point3d(0, 0, 0), point3d(1.0f, 0, 0.0f), 0, 1.0f, 1.0f);
    Object* cylinder_model_f = new cylinder(-1.0f, 1.0f, 1.0f);
    material* sphere_m = new material();  
    sphere_m->mat_texture = earth_texture;
    sphere_m->ka = lightgray;
    sphere_m->ks = lightgray;
    instance* sphere_ptr = new instance(sphere_model_f, sphere_m);
    //sphere_ptr->rotate_y(90);
    sphere_ptr->translate(-4.0f ,0.0f,-10.0f);
  
    //world.addObject(sphere_ptr);

    int numDifferentPersonColor = 20;
    float stepAnim = 0.03;
    float firstAnimation[2] = { stepAnim, 0 };
    float personAnimation[2][2] = { 
        {stepAnim, -stepAnim},
        {-stepAnim, stepAnim},
    };

    //MODELS
    Object* quadrilateral_model = new quadrilateral(point3d(0, 0, 0), vec3(1, 0, 0), vec3(0, 1, 0));
    Object* sphere_model = new Sphere(point3d(0, 0, 0), 1.0f);
    Object* cylinder_model = new cylinder(-1.0f, 1.0f, 1.0f);
    Object* model3dBase = new mesh("./models/base.obj", "./models/");
    Object* model3dLights = new mesh("./models/luci.obj", "./models/");
    //Object* model3dPalco = new mesh("./models/palco.obj", "./models/");
    //Object* model3dPalco = new mesh("./models/palco2.obj", "./models/");
    Object* modelFloor = new mesh("./models/floor.obj", "./models/");
    Object* modelRoof = new mesh("./models/roof.obj", "./models/");
    Object* modelSide1 = new mesh("./models/side1.obj", "./models/");
    Object* modelSide2 = new mesh("./models/side2.obj", "./models/");



    //TEXTURE
    texture* club_texture = new constant_texture(color(0.2,0.2,0.2));
    texture* club_texture_back = new constant_texture(color(0.1,0.1,0.1));
    texture* person_texture = new constant_texture(f_red);
    texture* disco_texture = new image_texture("./models/disco.jpg");
    texture* speaker_texture = new image_texture("./models/speaker2.jpg");
    texture* stage_base_texture = new constant_texture(black20);
    texture* stage_lights_texture = new constant_texture(black20);
    texture* stage_palco_texture = new constant_texture(black20);

    //MATERIALS
    material* club_m = new material();
    club_m->mat_texture = club_texture;
    club_m->ka = lightgray;
    club_m->ks = lightgray;
    material* club_m_back = new material();
    club_m_back->mat_texture = club_texture_back;
    club_m_back->ka = lightgray;
    club_m_back->ks = lightgray;
    material* person_m = new material();
    person_m->mat_texture = person_texture;
    person_m->ka = lightgray;
    person_m->ks = lightgray;
    material* disco_m = new material();
    disco_m->mat_texture = disco_texture;
    disco_m->ka = blue;
    disco_m->ks = blue;
    material* stage_base_m = new material();
    stage_base_m->mat_texture = stage_base_texture;
    stage_base_m->ka = black20;
    stage_base_m->ks = black20;
    material* stage_lights_m = new material();
    stage_lights_m->mat_texture = stage_lights_texture;
    stage_lights_m->ka = black20;
    stage_lights_m->ks = black20;
    material* stage_palco_m = new material();
    stage_palco_m->mat_texture = stage_palco_texture;
    stage_palco_m->ka = black20;
    stage_palco_m->ks = black20;

    material* speaker_m = new material();
    speaker_m->mat_texture = speaker_texture;
    speaker_m->ka = black20;
    speaker_m->ks = black20;

    vector<material*> materials = vector<material*>();
    for (int i = 0; i < numDifferentPersonColor; i++) {
        material* m = new material();
        randColor = color(randZeroToOne(), randZeroToOne(), randZeroToOne());
        m->mat_texture = new constant_texture(randColor);
        m->ka = black20;
        m->ks = black20;
        materials.push_back(m);
    }

    //INSTANCE
    instance* floor = new instance(quadrilateral_model, club_m);
    floor->scale(5.0, 6.0, 1.0);
    floor->rotate_x(-90);
    instance* r_wall = new instance(quadrilateral_model, club_m);
    r_wall->scale(5.0, 6.0, 1.0);
    r_wall->rotate_y(90);
    r_wall->translate(-5, 1, -1);
    instance* l_wall = new instance(quadrilateral_model, club_m);
    l_wall->scale(5.0, 6.0, 1.0);
    l_wall->rotate_y(-90);
    l_wall->translate(5, 1, -1);
    instance* b_wall = new instance(quadrilateral_model, club_m_back);
    b_wall->scale(5.0, 6.0, 1.0);
    b_wall->translate(0, 1, -5);


    instance* disco_sphere1 = new instance(sphere_model, disco_m);
    disco_sphere1->scale(0.5, 0.5, 0.5);
    disco_sphere1->translate(4, 2.2f, 1);

    instance* disco_sphere2 = new instance(sphere_model, disco_m);
    disco_sphere2->scale(0.5, 0.5, 0.5);
    disco_sphere2->translate(4, 2.0f, -2);

    instance* disco_sphere3 = new instance(sphere_model, disco_m);
    disco_sphere3->scale(0.5, 0.5, 0.5);
    disco_sphere3->translate(-4, 2.2f, 1);

    instance* disco_sphere4 = new instance(sphere_model, disco_m);
    disco_sphere4->scale(0.5, 0.5, 0.5);
    disco_sphere4->translate(-4, 2.0f, -2);

    instance* mesh_base = new instance(model3dBase, stage_base_m);
    mesh_base->scale(0.18, 0.18, 0.18);
    mesh_base->translate(0.2, 0.2, -1);

    instance* mesh_lights = new instance(model3dLights, stage_lights_m);
    mesh_lights->scale(0.18, 0.18, 0.18);
    mesh_lights->translate(0.2, 0.2, -1);

    instance* mesh_floor = new instance(modelFloor, stage_palco_m);
    mesh_floor->scale(0.18, 0.18, 0.18);
    mesh_floor->translate(0.2, 0.2, -1);

    instance* mesh_roof = new instance(modelRoof, stage_palco_m);
    mesh_roof->scale(0.18, 0.18, 0.18);
    mesh_roof->translate(0.2, 0.2, -1);

    instance* mesh_side1 = new instance(modelSide1, stage_palco_m);
    mesh_side1->scale(0.18, 0.18, 0.18);
    mesh_side1->translate(0.2, 0.2, -1);

    instance* mesh_side2 = new instance(modelSide2, stage_palco_m);
    mesh_side2->scale(0.18, 0.18, 0.18);
    mesh_side2->translate(0.2, 0.2, -1);



    //instance* mesh_palco = new instance(model3dPalco, stage_palco_m);
    //mesh_palco->scale(0.18, 0.18, 0.18);
    //mesh_palco->translate(0.2, 0.2, -1);

    instance* speaker1 = new instance(cylinder_model, speaker_m);
    speaker1->scale(0.17, 0.30, 0.17);
    speaker1->translate(-1.0, 0.70, 0);

    instance* speaker2 = new instance(cylinder_model, speaker_m);
    speaker2->scale(0.17, 0.30, 0.17);
    speaker2->translate(1.0, 0.70, 0);

    instance* speaker3 = new instance(cylinder_model, speaker_m);
    speaker3->scale(0.17, 0.30, 0.17);
    speaker3->translate(0.5, 0.70, -1.5);

    instance* speaker4 = new instance(cylinder_model, speaker_m);
    speaker4->scale(0.17, 0.30, 0.17);
    speaker4->translate(-0.5, 0.70, -1.5);

    instance* person;

    int maxA = 7;
    int minA = -7;
    int maxB = 11;
    int minB = 3;

    for (int a = minA; a < maxA; a++) {
        for (int b = minB; b < maxB; b++) {
            int n = int(randZeroToOne() * numDifferentPersonColor);
            material* mat = materials[n];
            point3d center(a*0.7 + 0.4f * randZeroToOne(),
                0.1f,
                b*0.6 + 0.3f * randZeroToOne());
            person = new instance(sphere_model, mat);
            person->scale(0.1f, 0.2f, 0.1f);
            person->translate(center.x, center.y, center.z);
            world.addObject(person);
        }
    }

    int numSpheres = (maxA - minA) * (maxB - minB);


    //ADD INSTANCE
    world.addObject(floor);
    world.addObject(r_wall);
    world.addObject(l_wall);
    world.addObject(b_wall);
    world.addObject(disco_sphere1);
    world.addObject(disco_sphere2);    
    world.addObject(disco_sphere3);
    world.addObject(disco_sphere4);
    world.addObject(mesh_base);
    world.addObject(mesh_lights);

    world.addObject(mesh_roof);
    world.addObject(mesh_floor);
    world.addObject(mesh_side1);
    world.addObject(mesh_side2);

    //world.addObject(mesh_palco);
    world.addObject(speaker1);
    world.addObject(speaker2);
    world.addObject(speaker3);
    world.addObject(speaker4);

    int N_FRAMES = 100;
    for (int i = 0; i < N_FRAMES; i++) {
        float anim[2];
        if (i == 0) {
            anim[0] = firstAnimation[0];
            anim[1] = firstAnimation[1];
        } else {
            anim[0] = personAnimation[i % 2][0];
            anim[1] = personAnimation[i % 2][1];
        }
        for (int j= 0; j < numSpheres; j++) {
            instance* p = dynamic_cast<instance *>(world.objs_vector[j]);        
            p->translate(0, anim[j%2], 0);
            world.objs_vector[j] = p;
        }

        world.parallelRenderRandom(renderer, 1);
        update(renderer);
    }


    world.parallelRenderRandom(renderer, ns);
    
    //world.parallelRenderMultiJittered(renderer, 3);

    time_t current_time = time(NULL);
    cout << "Impiegati " << current_time - start_time << " secondi per il rendering";
    updateAndWait(renderer);
    close(renderer, window);
}

