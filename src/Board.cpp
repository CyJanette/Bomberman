#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Cell.h"
#include "Player.h"

class Board {
private:
    int width;                        // Ancho del tablero
    int height;                       // Alto del tablero
    std::vector<std::vector<Cell*>> cells; // Matriz de punteros a celdas
    std::vector<Player*> players;     // Lista de jugadores en el tablero

public:
    // Constructor y Destructor
    Board(int width, int height);
    ~Board();

    // Métodos
    void generateBoard();             // Genera el tablero inicial
    void addPlayer(Player* player);   // Añade un jugador al tablero
    Cell* getCell(int x, int y) const;// Obtiene una celda en las coordenadas dadas

    // Getters
    int getWidth() const;
    int getHeight() const;
    std::vector<Player*> getPlayers() const;
};

#endif // BOARD_H


#include "Board.h"

// Constructor
Board::Board(int width, int height)
    : width(width), height(height), cells(height, std::vector<Cell*>(width, nullptr)) {
    generateBoard();
}

// Destructor
Board::~Board() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            delete cells[y][x];
        }
    }
    for (Player* player : players) {
        delete player;
    }
}

// Genera el tablero inicial
void Board::generateBoard() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cells[y][x] = new Cell(x, y);
        }
    }
}

// Añade un jugador al tablero
void Board::addPlayer(Player* player) {
    players.push_back(player);
    Cell* cell = getCell(player->getPosition()->x, player->getPosition()->y);
}

// Obtiene una celda en las coordenadas dadas
Cell* Board::getCell(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return cells[y][x];
    }
    return nullptr;
}

// Getters
int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}

std::vector<Player*> Board::getPlayers() const {
    return players;
}