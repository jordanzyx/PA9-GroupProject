//
// Created by Jordan on 4/26/2020.
//

#include "entities.h"
Moveable::Moveable(string filename, int posX, int posY)
{
	
	if (!texture.loadFromFile(filename)) { cout << "FAILED"; }		
	sprite.setTexture(texture);
	position.x = posX;
	position.y = posY;
	sprite.setPosition(position);
}
/*Moveable::Moveable(const Moveable& m2)
{
	texture = m2.texture;
	position = m2.position;
	sprite = m2.sprite;
	direction = m2.direction;
}*/

void Moveable::resizeSpriteScale(double x, double y)
{
	sf::Vector2f v(x, y);
	sprite.setScale(v);
}
void Moveable::rotateSprite(double degree)
{
	sprite.setRotation(degree);
}
int Moveable::getDirection() {
    return direction;
}

void Moveable::changeTex(string file)
{
	texture.loadFromFile(file);
}

void Moveable::changeOrgin(double x, double y)
{
	sf::Vector2f v(x, y);
	sprite.setOrigin(v);
}

void Moveable::setDirection(int direction) {
    this->direction = direction;
}

int Moveable::getX() {
	position = sprite.getPosition();
    return position.x;
}

int Moveable::getY() {
	position = sprite.getPosition();
    return position.y;
}

void Moveable::adjustX(int distance) {
    this->position.x = distance;
	sprite.setPosition(position.x, position.y);
}

void Moveable::adjustY(int distance) {
    this->position.y = distance;
	sprite.setPosition(position.x, position.y);
}

void Moveable::updateSprite()
{
	switch (direction)
	{
	case 1:
		sprite.move(0.f, 0.f);
		break;
	case 2:
		sprite.move(-0.25f, 0.f);
		break;
	case 3:
		sprite.move(0.25f, 0.f);
		break;
	case 0:
		sprite.move(0.0f, 0.15f);
		break;
	}
	
}
sf::Sprite Moveable::getSprite()
{
	return sprite;
}
Player::Player(string filename, int posX, int posY) :Moveable(filename, posX, posY)
{
	setDirection(1);
}
Player::Player() : Moveable("player.png",0,0)
{
	setDirection(1);
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

Rock::Rock(int spriteNumber) : Moveable("rock.png",0,0) {
    setDirection(0);
}
Rock::Rock() :Moveable("rock.png", 0 ,0)
{
	setDirection(0);
}
Rock::Rock(int spriteNumber, string filename, int posX, int posY) : Moveable(filename, posX, posY) {
	setDirection(0);
}
