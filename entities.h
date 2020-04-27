//
// Created by Jordan on 4/26/2020.
//

#ifndef PA9_ENTITIES_H
#define PA9_ENTITIES_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Moveable {
private:
	sf::Texture texture;
	sf::Vector2f position;
	sf::Sprite sprite;
    int direction; //0,1,2,3 FALLING,STILL,LEFT,RIGHT
	
public:
	Moveable(string, int,int);
	//Moveable(const Moveable& m2);
    int getDirection();
    void setDirection(int direction);
    int getX();
    int getY();
    void adjustX(int distance);
    void adjustY(int distance);
	void updateSprite();
	void resizeSpriteScale(double,double);
	sf::Sprite getSprite();
};

class Rock : public Moveable {
private:
    int spriteNumber;
public:
	Rock();
    Rock(int spriteNumber);
	Rock(int spriteNumber, string filename, int posX, int posY);
    int getSpriteNumber();
};

class Player : public Moveable {
private:
    int score;
public:
	Player(string filename, int posX, int posY);
	Player();
    int getScore();
    void goLeft();
    void goRight();
    void stayStill();
    void increaseScore();
};
#endif //PA9_ENTITIES_H
