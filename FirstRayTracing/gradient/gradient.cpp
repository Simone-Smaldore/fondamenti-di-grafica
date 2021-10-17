#include <iostream>
#include "SDL.h"
#include "../utilitySDL/utilitySDL.h"
#include "../utilitySDL/utilitySDLInline.h"
#include "gradient.h"
#include "../constants.h"

using namespace std;

void showGradient() {
    SDL_Window* window;
    SDL_Renderer* renderer;
    if (init(window, renderer, WindowConstants::SCREEN_WIDTH, WindowConstants::SCREEN_HEIGHT) == 1) {
        cout << "Gradient Error! " << std::endl;
        return;
    }
    for (int j = 0; j < WindowConstants::SCREEN_HEIGHT; j++) {
        for (int i = 0; i < WindowConstants::SCREEN_WIDTH; i++) {
            float r = float(i) / float(WindowConstants::SCREEN_WIDTH);
            float g = float(j) / float(WindowConstants::SCREEN_HEIGHT);
            float b = 0.5f;
            setColor(renderer, r, g, b);
            setPixel(renderer, i, j, WindowConstants::SCREEN_HEIGHT);
        }
    }
    update(renderer);
    close(renderer, window);
    return;
}