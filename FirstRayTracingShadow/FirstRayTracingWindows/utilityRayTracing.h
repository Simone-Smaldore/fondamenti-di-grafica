#pragma once

#include "utilitySDLInline.h";
#include "object_list.h";
#include "camera.h";
#include <ppl.h>
#include <vector>
#include <random>


vec3 getColor(object_list* scene, ray& r, vec3& startColor, vec3& endColor, bool normalColor,float t_min, float t_max);

void renderFrameRandom(genericCamera& cam, int ns, int image_height, int image_width, SDL_Renderer*& renderer, object_list*& scene, vec3& startBackgroundColor, vec3& endBackgroundColor, bool normalColor, float t_min = 0, float t_max = FLT_MAX);

void renderFrameJittered(genericCamera& cam, int numLayers, int image_height, int image_width, SDL_Renderer*& renderer, object_list*& scene, vec3& startBackgroundColor, vec3& endBackgroundColor, bool normalColor, float t_min = 0, float t_max = FLT_MAX);

void renderFrameNRooks(genericCamera& cam, int nRockSize, int image_height, int image_width, SDL_Renderer*& renderer, object_list*& scene, vec3& startBackgroundColor, vec3& endBackgroundColor, bool normalColor, float t_min = 0, float t_max = FLT_MAX);

void renderFrameMultiJittered(genericCamera& cam, int nRockPerLayer, int image_height, int image_width, SDL_Renderer*& renderer, object_list*& scene, vec3& startBackgroundColor, vec3& endBackgroundColor, bool normalColor, float t_min = 0, float t_max = FLT_MAX);

void updateRendererFromMatrix(int image_height, int image_width, SDL_Renderer*& renderer, vector<vec3>& matrix);

bool saveScreenshotBMP(std::string filepath, SDL_Window* SDLWindow, SDL_Renderer* SDLRenderer);