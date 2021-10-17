#pragma once

#include "utilitySDLInline.h"
#include "Object.h"
#include "object_list.h"

float randZeroToOne();

vec3 getColor(object_list* scene, ray& r, vec3& startColor, vec3& endColor, float t_min = 0, float t_max = FLT_MAX);

void showRayTracing();

