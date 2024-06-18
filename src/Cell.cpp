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

#include "Cell.h"

// Constructor
Cell::Cell(int x, int y, bool isWalkable) 
    : x(x), y(y), isWalkable(isWalkable), hasPowerUp(false), powerUp(nullptr) {}

// Destructor
Cell::~Cell() {
    delete powerUp;
}

// Coloca un power-up en la celda
void Cell::placePowerUp(PowerUp* powerUp) {
    if (this->powerUp == nullptr) {
        this->powerUp = powerUp;
        hasPowerUp = true;
    }
}

// Elimina el power-up de la celda
void Cell::removePowerUp() {
    if (powerUp != nullptr) {
        delete powerUp;
        powerUp = nullptr;
        hasPowerUp = false;
    }
}

// Actualiza el estado de la celda
void Cell::update() {
    // Lógica para actualizar el estado de la celda si es necesario
}

// Getters y Setters
int Cell::getX() const {
    return x;
}

int Cell::getY() const {
    return y;
}

bool Cell::getIsWalkable() const {
    return isWalkable;
}

void Cell::setIsWalkable(bool walkable) {
    isWalkable = walkable;
}

bool Cell::getHasPowerUp() const {
    return hasPowerUp;
}

PowerUp* Cell::getPowerUp() const {
    return powerUp;
}