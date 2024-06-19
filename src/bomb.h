#pragma once
#include <SDL2/SDL.h>

class Bomb {
public:
    Bomb(int x, int y);
    void update();
    void render(SDL_Renderer* renderer);

private:
    int posX, posY;
    int timer;
    SDL_Rect collider;
};
