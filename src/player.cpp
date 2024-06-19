#include "player.h"

Player::Player(int x, int y) : posX(x), posY(y), velX(0), velY(0) {
    collider.w = 32;
    collider.h = 32;
    collider.x = x;
    collider.y = y;
}

void Player::handleEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: velY -= 5; break;
            case SDLK_DOWN: velY += 5; break;
            case SDLK_LEFT: velX -= 5; break;
            case SDLK_RIGHT: velX += 5; break;
        }
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym) {
            case SDLK_UP: velY += 5; break;
            case SDLK_DOWN: velY -= 5; break;
            case SDLK_LEFT: velX += 5; break;
            case SDLK_RIGHT: velX -= 5; break;
        }
    }
}

void Player::move() {
    posX += velX;
    posY += velY;
    collider.x = posX;
    collider.y = posY;
}

void Player::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &collider);
}

int Player::getX() const {
    return posX;
}

int Player::getY() const {
    return posY;
}
