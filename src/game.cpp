#include "game.h"

Game::Game() : window(nullptr), renderer(nullptr), isRunning(false), player(nullptr), map(nullptr) {}

Game::~Game() {
    delete player;
    for (Bomb* bomb : bombs) {
        delete bomb;
    }
    delete map;
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return false;
    }
    window = SDL_CreateWindow("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if (!window) {
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        return false;
    }
    player = new Player(100, 100);
    map = new Map();
    isRunning = true;
    return true;
}

void Game::run() {
    while (isRunning) {
        handleEvents();
        update();
        render();
    }
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        player->handleEvent(event);
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
            spawnBomb();
        }
    }
}

void Game::update() {
    player->move();
    for (Bomb* bomb : bombs) {
        bomb->update();
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    map->render(renderer);
    player->render(renderer);
    for (Bomb* bomb : bombs) {
        bomb->render(renderer);
    }
    SDL_RenderPresent(renderer);
}

void Game::spawnBomb() {
    bombs.push_back(new Bomb(player->getX(), player->getY()));
}
