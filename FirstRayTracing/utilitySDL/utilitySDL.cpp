#include <iostream>
#include "SDL.h"

using namespace std;

int init(SDL_Window*& window, SDL_Renderer*& renderer, int screenWidth, int screenHeight) {
    /* // Initialize SDL2. */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    /* Create the window where we will draw. */
    window = SDL_CreateWindow("SDL_RenderClear", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight,SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
/* We must call SDL_CreateRenderer in order for draw calls to affect this window. */
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    return 0;
}


void close(SDL_Renderer* renderer, SDL_Window* window) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void update(SDL_Renderer*& renderer) {
    SDL_RenderPresent(renderer);
    SDL_Event e;
    SDL_PollEvent(&e);
    while (e.type != SDL_QUIT) {
        SDL_PollEvent(&e);
    }
}
