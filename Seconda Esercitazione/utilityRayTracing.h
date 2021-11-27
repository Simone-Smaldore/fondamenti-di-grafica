#pragma once

#include "utilitySDLInline.h";
#include "camera.h";
#include <ppl.h>
#include <vector>
#include <random>

bool saveScreenshotBMP(std::string filepath, SDL_Window* SDLWindow, SDL_Renderer* SDLRenderer);

Uint32 getpixel(SDL_Surface* surface, int x, int y);

SDL_Surface* loadTexture(const char* image_path, int& imageWidth, int& imageHeight);