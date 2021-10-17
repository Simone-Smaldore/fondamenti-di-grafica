#pragma once
#include "SDL.h"

using namespace std;

int init(SDL_Window*& window, SDL_Renderer*& renderer, int screenWidth, int screenHeight);

void close(SDL_Renderer* renderer, SDL_Window* window);

void update(SDL_Renderer*& renderer);
