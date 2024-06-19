#include "map.h"

Map::Map() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 15; j++) {
            tiles[i][j].w = 40;
            tiles[i][j].h = 40;
            tiles[i][j].x = i * 40;
            tiles[i][j].y = j * 40;
        }
    }
}

void Map::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 15; j++) {
            SDL_RenderFillRect(renderer, &tiles[i][j]);
        }
    }
}
