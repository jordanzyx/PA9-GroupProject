//
// Created by Jordan on 4/26/2020.
//

#include "entities.h"

int Moveable::getDirection() {
    return direction;
}

void Moveable::setDirection(int direction) {
    this->direction = direction;
}

int Moveable::getX() {
    return x;
}

int Moveable::getY() {
    return y;
}

void Moveable::adjustX(int distance) {
    this->x += distance;
}

void Moveable::adjustY(int distance) {
    this->y += distance;
}

int Player::getScore() {
    return score;
}

void Player::goLeft() {
    setDirection(2);
}

void Player::goRight() {
    setDirection(3);
}

void Player::stayStill() {
    setDirection(1);
}

void Player::increaseScore() {
    score++;
}

int Rock::getSpriteNumber() {
    return spriteNumber;
}

Rock::Rock(int spriteNumber) : spriteNumber(spriteNumber) {
    setDirection(0);
}
