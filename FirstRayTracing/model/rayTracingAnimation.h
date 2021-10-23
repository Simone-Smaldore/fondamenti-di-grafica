
#ifndef FIRSTRAYTRACING_RAYTRACINGANIMATION_H
#define FIRSTRAYTRACING_RAYTRACINGANIMATION_H

#include  "../utilitySDL/utilitySDLInline.h"
#include "Object.h"
#include "object_list.h"
#include "camera.h"

void renderFrame(camera& cam, float ns, int image_height, int image_width, SDL_Renderer*& renderer, object_list*& scene, vec3& startBackgroundColor, vec3& endBackgroundColor);

vec3 getAnimationColor(object_list* scene, ray &r, vec3 &startColor, vec3 &endColor, float t_min = 0, float t_max = FLT_MAX);

void showRayTracingAnimation();


#endif //FIRSTRAYTRACING_RAYTRACINGANIMATION_H
