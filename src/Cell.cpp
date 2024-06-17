#ifndef CELL_H
#define CELL_H

#include "PowerUp.h"

class Cell {
private:
    int x;                          // Coordenada x de la celda en el tablero
    int y;                          // Coordenada y de la celda en el tablero
    bool isWalkable;                // Indica si la celda es transitable
    bool hasPowerUp;                // Indica si la celda contiene un power-up
    PowerUp* powerUp;               // Puntero al power-up contenido en la celda, si lo hay

public:
    // Constructor y Destructor
    Cell(int x, int y, bool isWalkable = true);
    ~Cell();

    // Métodos
    void placePowerUp(PowerUp* powerUp); // Coloca un power-up en la celda
    void removePowerUp();                // Elimina el power-up de la celda
    void update();                       // Actualiza el estado de la celda

    // Getters y Setters
    int getX() const;
    int getY() const;
    bool getIsWalkable() const;
    void setIsWalkable(bool walkable);
    bool getHasPowerUp() const;
    PowerUp* getPowerUp() const;
};

#endif // CELL_H