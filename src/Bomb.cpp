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

void Bomb::explode() {
    if (isExploded()) {
        // Obtener la posición de la bomba
        int bombX = position->getX();
        int bombY = position->getY();

        // Afectar la celda de la bomba
        Cell* centerCell = GameManager::getInstance()->getBoard()->getCell(bombX, bombY);
        if (centerCell) {
            centerCell->explode(); // Suponiendo que la celda tiene un método para manejar la explosión
        }

        // Afectar las celdas en el radio de explosión
        for (int dx = -blastRadius; dx <= blastRadius; ++dx) {
            for (int dy = -blastRadius; dy <= blastRadius; ++dy) {
                // Calcular las coordenadas de la celda afectada
                int affectedX = bombX + dx;
                int affectedY = bombY + dy;

                // Verificar si la celda está dentro del tablero
                if (affectedX >= 0 && affectedX < GameManager::getInstance()->getBoard()->getWidth() &&
                    affectedY >= 0 && affectedY < GameManager::getInstance()->getBoard()->getHeight()) {
                    Cell* affectedCell = GameManager::getInstance()->getBoard()->getCell(affectedX, affectedY);
                    if (affectedCell) {
                        affectedCell->explode(); // Lógica de explosión de la celda afectada
                    }
                }
            }
        }

        // Afectar a los jugadores en el radio de explosión
        for (Player* player : GameManager::getInstance()->getPlayers()) {
            Position* playerPosition = player->getPosition();
            int playerX = playerPosition->getX();
            int playerY = playerPosition->getY();

            // Calcular la distancia entre el jugador y la bomba
            int distanceX = std::abs(playerX - bombX);
            int distanceY = std::abs(playerY - bombY);

            // Verificar si el jugador está dentro del radio de explosión
            if (distanceX <= blastRadius && distanceY <= blastRadius) {
                player->loseLife(); // Reducir las vidas del jugador (ejemplo)
            }
        }
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