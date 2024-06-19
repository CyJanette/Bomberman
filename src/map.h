#pragma once
#include <SDL2/SDL.h>

class Map {
public:
    Map();
    void render(SDL_Renderer* renderer);

private:
    SDL_Rect tiles[20][15];
};
