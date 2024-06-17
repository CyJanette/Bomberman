#ifndef POWERUP_H
#define POWERUP_H

#include "Player.h"

class PowerUp {
private:
    int x;                              // Coordenada x del power-up en el tablero
    int y;                              // Coordenada y del power-up en el tablero
    std::string type;                   // Tipo de power-up (por ejemplo, "extra_bomb", "increase_range")
    bool isActive;                      // Indica si el power-up está activo

public:
    // Constructor y Destructor
    PowerUp(int x, int y, const std::string& type);
    ~PowerUp();

    // Métodos
    void apply(Player* player);         // Aplica el efecto del power-up al jugador
    void deactivate();                  // Desactiva el power-up

    // Getters y Setters
    int getX() const;
    int getY() const;
    std::string getType() const;
    bool getIsActive() const;
};

#endif // POWERUP_H

#include "PowerUp.h"

// Constructor
PowerUp::PowerUp(int x, int y, const std::string& type) 
    : x(x), y(y), type(type), isActive(true) {}

// Destructor
PowerUp::~PowerUp() {}

// Aplica el efecto del power-up al jugador
void PowerUp::apply(Player* player) {
    if (isActive) {
        if (type == "extra_bomb") {
            // Lógica para incrementar la capacidad de bombas del jugador
            player->increaseBombCapacity();
        } else if (type == "increase_range") {
            // Lógica para incrementar el radio de explosión de las bombas del jugador
            player->increaseBlastRadius();
        }
        // Otros tipos de power-ups se pueden manejar aquí

        deactivate(); // Desactiva el power-up después de aplicarlo
    }
}

// Desactiva el power-up
void PowerUp::deactivate() {
    isActive = false;
}

// Getters y Setters
int PowerUp::getX() const {
    return x;
}

int PowerUp::getY() const {
    return y;
}

std::string PowerUp::getType() const {
    return type;
}

bool PowerUp::getIsActive() const {
    return isActive;
}