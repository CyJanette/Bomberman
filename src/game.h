#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "player.h"
#include "bomb.h"
#include "map.h"

class Game {
public:
    Game();
    ~Game();

    bool init();
    void run();
    void clean();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
    Player* player;
    std::vector<Bomb*> bombs;
    Map* map;

    void handleEvents();
    void update();
    void render();
    void spawnBomb();
};
