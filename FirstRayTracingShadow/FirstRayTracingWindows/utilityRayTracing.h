#pragma once

#include "utilitySDLInline.h";
#include "object_list.h";
#include "camera.h";
#include <ppl.h>
#include <vector>
#include <random>

bool saveScreenshotBMP(std::string filepath, SDL_Window* SDLWindow, SDL_Renderer* SDLRenderer);