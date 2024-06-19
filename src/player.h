#pragma once
#include <SDL2/SDL.h>

class Player {
public:
    Player(int x, int y);
    void handleEvent(SDL_Event& e);
    void move();
    void render(SDL_Renderer* renderer);

private:
    int posX, posY;
    int velX, velY;
    SDL_Rect collider;
};
