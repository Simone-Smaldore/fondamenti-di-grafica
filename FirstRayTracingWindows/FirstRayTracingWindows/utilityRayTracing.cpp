#include "utilityRayTracing.h"

using namespace concurrency;

vec3 getColor(object_list* scene, ray& r, vec3& startColor, vec3& endColor, float t_min, float t_max) {
    hit_record hit;
    if (scene->trace_ray(r, t_min, t_max, hit)) {
        //return scene->list[hit.object_index]->color;
        return 0.5f * (vec3(hit.normal.x, hit.normal.y, hit.normal.z) + vec3(1.0, 1.0, 1.0));
    }
    else {
        return colorLerpY(r, startColor, endColor);
    }
}

void renderFrame(camera& cam, float ns, int image_height, int image_width, SDL_Renderer*& renderer, object_list*& scene, vec3& startBackgroundColor, vec3& endBackgroundColor) {
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
}

//void renderFrame(camera& cam, float ns, int image_height, int image_width, SDL_Renderer*& renderer, object_list*& scene, vec3& startBackgroundColor, vec3& endBackgroundColor) {
//    vector<vec3> matrix(image_width * image_height);
//    parallel_for(int(0), image_height, [&](int j) {
//        for (int i = 0; i < image_width; i++) {
//            vec3 color(0.0, 0.0, 0.0);
//            for (int s = 0; s < ns; s++) {
//                ray r = cam.get_ray(float((i + randZeroToOne()) / image_width), float((j + randZeroToOne()) / image_height));
//                color += getColor(scene, r, startBackgroundColor, endBackgroundColor);
//            }
//            matrix[j * image_width + i] = color / float(ns);
//            for (int j = 0; j < image_height; j++) {
//                for (int i = 0; i < image_width; i++) {
//                    vec3 color = matrix[j * image_width + i];
//                    color = vec3(sqrt(color[0]), sqrt(color[1]), sqrt(color[2])); //GAMMA CORRECTION
//                    setColor(renderer, color.x, color.y, color.z);
//                    setPixel(renderer, i, j, image_height);
//                }
//            }
//        }
//     });
//}