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