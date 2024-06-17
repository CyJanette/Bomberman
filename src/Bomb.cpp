#ifndef BOMB_H
#define BOMB_H

#include "Position.h"
#include "Player.h"

class Bomb {
private:
    Position* position;            // Posición de la bomba en el tablero
    int countdown;                 // Tiempo en segundos hasta que la bomba explote
    int blastRadius;               // Radio de explosión de la bomba
    Player* owner;                 // Jugador que colocó la bomba

public:
    // Constructor y Destructor
    Bomb(int x, int y, Player* owner, int countdown = 3, int blastRadius = 1);
    ~Bomb();

    // Métodos
    void tick();                   // Decrementa el contador de la bomba
    bool isExploded() const;       // Verifica si la bomba ha explotado
    void explode();                // Maneja la explosión de la bomba

    // Getters y Setters
    Position* getPosition() const;
    int getCountdown() const;
    void setCountdown(int countdown);
    int getBlastRadius() const;
    void setBlastRadius(int blastRadius);
    Player* getOwner() const;
};

#endif // BOMB_H

#include "Bomb.h"

// Constructor
Bomb::Bomb(int x, int y, Player* owner, int countdown, int blastRadius)
    : position(new Position(x, y)), countdown(countdown), blastRadius(blastRadius), owner(owner) {}

// Destructor
Bomb::~Bomb() {
    delete position;
}

// Decrementa el contador de la bomba
void Bomb::tick() {
    if (countdown > 0) {
        countdown--;
    }
}

// Verifica si la bomba ha explotado
bool Bomb::isExploded() const {
    return countdown <= 0;
}

// Maneja la explosión de la bomba
void Bomb::explode() {
    if (isExploded()) {
        // Lógica de la explosión: afectar celdas y jugadores en el radio de la explosión
        // Este método se llamaría desde el controlador del juego cuando el contador llegue a cero
    }
}

// Getters y Setters
Position* Bomb::getPosition() const {
    return position;
}

int Bomb::getCountdown() const {
    return countdown;
}

void Bomb::setCountdown(int countdown) {
    this->countdown = countdown;
}

int Bomb::getBlastRadius() const {
    return blastRadius;
}

void Bomb::setBlastRadius(int blastRadius) {
    this->blastRadius = blastRadius;
}

Player* Bomb::getOwner() const {
    return owner;
}