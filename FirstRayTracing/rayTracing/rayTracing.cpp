#include <iostream>
#include <list>
#include <ctime>
#include <vector>
#include <random>
#include "rayTracing.h"
#include "SDL.h"
#include "../utilitySDL/utilitySDL.h"
#include "../utilitySDL/utilitySDLInline.h"
#include "../model/Sphere.h"
#include "../model/camera.h"
#include "../model/parallelCamera.h"
#include "../model/plane.h"
#include "../model/disk.h"
#include "../model/quadrilateral.h"
#include "../model/box.h"
#include "../model/triangle.h"

using namespace std;

void printVectorElements(vector<int> &vec)
{
    for (auto i = 0; i < vec.size(); ++i) {
        cout << vec.at(i) << "; ";
    }
    cout << endl;
}

void showRayTracing() {

    SDL_Window* window;
    SDL_Renderer* renderer;

    point3d cameraPosition(0.0f,0.0f,6.0f);
    point3d cameraOrientation(0.0f,0.0f,0.0f);
    vec3 upVector(0.0f, 1.0f,0.0f);
    float fieldOfView = 40.0f;
    float aspectRatio = 16/8;

    camera cam(cameraPosition, cameraOrientation, upVector, fieldOfView, aspectRatio);
//    parallelCamera cam(cameraPosition, cameraOrientation, upVector, fieldOfView, aspectRatio);

    int const image_width = 1000;
    int const image_height = 500;


    time_t start_time = time(NULL);

    if (init(window, renderer, image_width, image_height) == 1) {
        cout << "Gradient Error! " << std::endl;
        return;
    }

    int num_elements = 4;
    Object *list[num_elements];
    list[0] = new Sphere(point3d(-1.1f, 0.0f, -2.0f), 1.0);
    list[1] = new Sphere(point3d(1.1f, 0.0f, -2.0f), 1.0);
    list[2] = new Sphere(point3d(-3.4f, 0.0f, -2.0f), 1.0);
    list[3] = new Sphere(point3d(3.4f, 0.0f, -2.0f), 1.0);

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

// BOX INUTILE PER ASSEGNARE IL COLOR USO LA STRATEGIA DI COLORE CON LA NORMALE
//    list[0] = new box(point3d(2.0f, -1.50f, -3.0f), vec3(1.0f,0,0),  vec3(0,1.0f,0), vec3(0,0,1.0f));
//    list[1] = new box(point3d(-5.0f, 1.0f, -5.0f), vec3(1.0f,0,0),  vec3(0,1.0f,0), vec3(0,0,1.0f));
//    list[2] = new box(point3d(-2.0f, -1.5f, -1.0f), vec3(1.0f,0,0),  vec3(0,1.0f,0), vec3(0,0,1.0f));

// TRIANGLE
//    list[0] = new triangle(point3d(0.0f, -1.0f, -1.0f),  point3d(1.0f, 2.0f, -1.0f),point3d(0.0f, 2.0f, -1.0f));
//    list[0] -> color = vec3(1.0,0.0,0.0);

// EXAMPLE PARALLEL CAMERA
//    list[0] = new Sphere(point3d(-1.1f, 0.0f, -2.0f), 1.0);
//    list[1] = new Sphere(point3d(1.1f, 0.0f, -20.0f), 1.0);
    object_list *scene = new object_list(list, num_elements);

    vec3 startBackgroundColor(1.0f, 1.0f, 1.0f);
    vec3 endBackgroundColor(0.5f, 0.7f, 1.0f);

// RANDOM ONLY
    int ns = 32;

// JITTERED ONLY
//    int numLayers = 4;

// N-ROCK ONLY
//    int nRockSize = 25;
//    vector<int> rowIndices;
//    vector<int> columnIndices;
//    for( int k = 0; k < nRockSize; k++) {
//        rowIndices.push_back(k);
//        columnIndices.push_back(k);
//    }

// MULTI JITTERED ONLY
//    int nRockPerLayer = 5;
//    int multiJitteredMatrix[nRockPerLayer][nRockPerLayer][2];
//    for(int i = 0; i < nRockPerLayer; i++) {
//        int cont = 0;
//        for(int j = 0; j < nRockPerLayer; j++) {
//            if((i + j) < nRockPerLayer) {
//                multiJitteredMatrix[i][j][0] = i + j;
//                multiJitteredMatrix[i][j][1] = i + j;
//            } else {
//                multiJitteredMatrix[i][j][0] = cont;
//                multiJitteredMatrix[i][j][1] = cont;
//                cont++;
//            }
//        }
//    }
//    vector<int> rowIndices;
//    vector<int> columnIndices;
//    for( int k = 0; k < nRockPerLayer; k++) {
//        rowIndices.push_back(k);
//        columnIndices.push_back(k);
//    }


    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            vec3 color(0.0, 0.0, 0.0);
//            RANDOM
            for (int s = 0; s < ns; s++) {
                ray r = cam.get_ray(float((i + randZeroToOne()) / image_width), float((j + randZeroToOne()) / image_height));
                color += getColor(scene, r, startBackgroundColor, endBackgroundColor);
            }
            color = color / float(ns);

//            JITTERED
//            for (int l1 = 0; l1 < numLayers; l1++) {
//                for (int l2 = 0; l2 < numLayers; l2++) {
//                    ray r = cam.get_ray(float((i + (randZeroToOne() + l1)/numLayers) / image_width), float((j + (randZeroToOne() + l2)/numLayers) / image_height));
//                    color += getColor(scene, r, startBackgroundColor, endBackgroundColor);
//                }
//            }
//            color = color / float(numLayers*numLayers);

//            N-ROOKS
//            std::random_device rd;
//            std::default_random_engine rng(rd());
//            std::shuffle(std::begin(rowIndices), std::end(rowIndices), rng);
//            std::shuffle(std::begin(columnIndices), std::end(columnIndices), rng);
//            for(int l = 0; l < nRockSize; l++) {
//                ray r = cam.get_ray(float((i + (randZeroToOne() + rowIndices[l])/nRockSize) / image_width), float((j + (randZeroToOne() + columnIndices[l])/nRockSize) / image_height));
//                color += getColor(scene, r, startBackgroundColor, endBackgroundColor);
//            }
//            color = color / float(nRockSize);

//          MULTI - JITTERED
//            std::random_device rd;
//            std::default_random_engine rng(rd());
//            for(int k = 0; k < nRockPerLayer; k++) {
//                std::shuffle(std::begin(rowIndices), std::end(rowIndices), rng);
//                std::shuffle(std::begin(columnIndices), std::end(columnIndices), rng);
//                for(int l = 0; l < nRockPerLayer; l++) {
//                    multiJitteredMatrix[k][l][0] = rowIndices[l];
//                    multiJitteredMatrix[l][k][1] = columnIndices[l];
//                }
//            }
//
//            for(int k = 0; k < nRockPerLayer; k++) {
//                for(int l = 0; l < nRockPerLayer; l++) {
//                    float u = (i + l/nRockPerLayer + (randZeroToOne() + multiJitteredMatrix[k][l][0])/pow(nRockPerLayer, 2)) / image_width;
//                    float v = (j + (nRockPerLayer - k)/nRockPerLayer + (randZeroToOne() + multiJitteredMatrix[k][l][1])/pow(nRockPerLayer, 2)) / image_height;
//                    ray r = cam.get_ray(u, v);
//                    color += getColor(scene, r, startBackgroundColor, endBackgroundColor);
//                }
//            }
//            color = color / float(nRockPerLayer*nRockPerLayer);

            //  COMMON PARTS
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
//        return scene->list[hit.object_index]->color;
        return 0.5f * (vec3(hit.normal.x, hit.normal.y, hit.normal.z) + vec3(1.0, 1.0, 1.0));
    } else {
        return colorLerpY(r, startColor, endColor);
    }
}


//cout << multiJitteredMatrix[0][0][1] << " " << multiJitteredMatrix[0][1][1] << " " << multiJitteredMatrix[0][2][1] << " " << multiJitteredMatrix[0][3][1] << " " << multiJitteredMatrix[0][4][1] << endl;
//cout << multiJitteredMatrix[1][0][1] << " " << multiJitteredMatrix[1][1][1] << " " << multiJitteredMatrix[1][2][1] << " " << multiJitteredMatrix[1][3][1] << " " << multiJitteredMatrix[1][4][1] << endl;
//cout << multiJitteredMatrix[2][0][1] << " " << multiJitteredMatrix[2][1][1] << " " << multiJitteredMatrix[2][2][1] << " " << multiJitteredMatrix[2][3][1] << " " << multiJitteredMatrix[2][4][1] << endl;
//cout << multiJitteredMatrix[3][0][1] << " " << multiJitteredMatrix[3][1][1] << " " << multiJitteredMatrix[3][2][1] << " " << multiJitteredMatrix[3][3][1] << " " << multiJitteredMatrix[3][4][1] << endl;
//cout << multiJitteredMatrix[4][0][1] << " " << multiJitteredMatrix[4][1][1] << " " << multiJitteredMatrix[4][2][1] << " " << multiJitteredMatrix[4][3][1] << " " << multiJitteredMatrix[4][4][1] << endl;

