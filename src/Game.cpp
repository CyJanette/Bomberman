#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "Board.h"
#include "Player.h"
#include "Timer.h"

class Game {
private:
    int currentLevel;                 // Nivel actual del juego
    std::vector<Player*> players;     // Lista de jugadores
    Board* board;                     // Tablero del juego
    Timer* gameTimer;                 // Temporizador del juego

public:
    // Constructor y Destructor
    Game(int level, int numPlayers);
    ~Game();

    // Métodos
    void startGame();                 // Inicia el juego
    void endGame();                   // Termina el juego
    void update();                    // Actualiza el estado del juego
    void addPlayer(Player* player);   // Añade un jugador al juego
    void removePlayer(Player* player);// Elimina un jugador del juego
    void nextLevel();                 // Avanza al siguiente nivel

    // Getters y Setters
    int getCurrentLevel() const;
    void setCurrentLevel(int level);
    std::vector<Player*> getPlayers() const;
    Board* getBoard() const;
    Timer* getTimer() const;
};

#endif // GAME_H

#include "Game.h"

// Constructor
Game::Game(int level, int numPlayers) 
    : currentLevel(level), board(new Board()), gameTimer(new Timer()) {
    for (int i = 0; i < numPlayers; ++i) {
        players.push_back(new Player("Player" + std::to_string(i + 1)));
    }
}

// Destructor
Game::~Game() {
    delete board;
    delete gameTimer;
    for (Player* player : players) {
        delete player;
    }
}

// Inicia el juego
void Game::startGame() {
    gameTimer->start();
    // Lógica adicional para iniciar el juego
}

// Termina el juego
void Game::endGame() {
    gameTimer->stop();
    // Lógica adicional para terminar el juego
}

// Actualiza el estado del juego
void Game::update() {
    // Lógica de actualización del juego
    board->updateBoard();
    for (Player* player : players) {
        // Actualizar estado del jugador
    }
    gameTimer->tick();
}

// Añade un jugador al juego
void Game::addPlayer(Player* player) {
    players.push_back(player);
}

// Elimina un jugador del juego
void Game::removePlayer(Player* player) {
    auto it = std::find(players.begin(), players.end(), player);
    if (it != players.end()) {
        players.erase(it);
    }
}

// Avanza al siguiente nivel
void Game::nextLevel() {
    currentLevel++;
    board->generateBoard();
    // Lógica adicional para avanzar al siguiente nivel
}

// Getters y Setters
int Game::getCurrentLevel() const {
    return currentLevel;
}

void Game::setCurrentLevel(int level) {
    currentLevel = level;
}

std::vector<Player*> Game::getPlayers() const {
    return players;
}

Board* Game::getBoard() const {
    return board;
}

Timer* Game::getTimer() const {
    return gameTimer;
}