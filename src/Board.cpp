#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Cell.h"

class Board {
private:
    int width;                       // Ancho del tablero
    int height;                      // Altura del tablero
    std::vector<std::vector<Cell*>> cells;  // Matriz de celdas que componen el tablero

public:
    // Constructor y Destructor
    Board(int width, int height);
    ~Board();

    // Métodos
    void generateBoard();            // Genera el tablero inicial
    void updateBoard();              // Actualiza el estado del tablero

    // Getters y Setters
    int getWidth() const;
    int getHeight() const;
    Cell* getCell(int x, int y) const;
    void setCell(int x, int y, Cell* cell);
};

#endif // BOARD_H