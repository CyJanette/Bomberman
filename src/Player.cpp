#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Bomb.h"
#include "Position.h"
#include "PowerUp.h"

class Player {
private:
    std::string name;                    // Nombre del jugador
    int score;                           // Puntaje del jugador
    int lives;                           // Número de vidas del jugador
    Position* position;                  // Posición actual del jugador en el tablero
    std::vector<Bomb*> bombs;            // Bombas colocadas por el jugador
    std::vector<PowerUp*> powerUps;      // Power-ups recogidos por el jugador

public:
    // Constructor y Destructor
    Player(const std::string& name, int startX, int startY);
    ~Player();

    // Métodos
    void move(int deltaX, int deltaY);     // Mueve al jugador en el tablero
    void placeBomb();                      // Coloca una bomba en la posición actual del jugador
    void pickPowerUp(PowerUp* powerUp);    // Recoge un power-up
    void loseLife();                       // Reduce el número de vidas del jugador
    bool isAlive() const;                  // Verifica si el jugador está vivo

    // Getters y Setters
    std::string getName() const;
    int getScore() const;
    void setScore(int score);
    int getLives() const;
    void setLives(int lives);
    Position* getPosition() const;
    void setPosition(int x, int y);
    std::vector<Bomb*> getBombs() const;
    std::vector<PowerUp*> getPowerUps() const;
};

#endif // PLAYER_H

#include "Player.h"

// Constructor
Player::Player(const std::string& name, int startX, int startY) 
    : name(name), score(0), lives(3), position(new Position(startX, startY)) {}

// Destructor
Player::~Player() {
    delete position;
    for (Bomb* bomb : bombs) {
        delete bomb;
    }
    for (PowerUp* powerUp : powerUps) {
        delete powerUp;
    }
}

// Mueve al jugador en el tablero
void Player::move(int deltaX, int deltaY) {
    position->x += deltaX;
    position->y += deltaY;
    // Lógica adicional para manejar colisiones y límites del tablero
}

// Coloca una bomba en la posición actual del jugador
void Player::placeBomb() {
    Bomb* newBomb = new Bomb(position->x, position->y, this);
    bombs.push_back(newBomb);
}

// Recoge un power-up
void Player::pickPowerUp(PowerUp* powerUp) {
    powerUps.push_back(powerUp);
    powerUp->apply(this); // Aplica el efecto del power-up al jugador
}

// Reduce el número de vidas del jugador
void Player::loseLife() {
    if (lives > 0) {
        lives--;
    }
}

// Verifica si el jugador está vivo
bool Player::isAlive() const {
    return lives > 0;
}

// Getters y Setters
std::string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

void Player::setScore(int score) {
    this->score = score;
}

int Player::getLives() const {
    return lives;
}

void Player::setLives(int lives) {
    this->lives = lives;
}

Position* Player::getPosition() const {
    return position;
}

void Player::setPosition(int x, int y) {
    position->x = x;
    position->y = y;
}

std::vector<Bomb*> Player::getBombs() const {
    return bombs;
}

std::vector<PowerUp*> Player::getPowerUps() const {
    return powerUps;
}