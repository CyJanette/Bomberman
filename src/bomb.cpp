#include "bomb.h"

Bomb::Bomb(int x, int y) : posX(x), posY(y), timer(300) {
    collider.w = 32;
    collider.h = 32;
    collider.x = x;
    collider.y = y;
}

void Bomb::update() {
    if (timer > 0) {
        timer--;
    } else {
        // Explosión
    }
}

void Bomb::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &collider);
}
