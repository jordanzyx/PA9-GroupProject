//
// Created by Jordan on 4/26/2020.
//

#ifndef PA9_ENTITIES_H
#define PA9_ENTITIES_H
class Moveable {
private:
    int x;
    int y;
    int direction; //0,1,2,3 FALLING,STILL,LEFT,RIGHT
public:
    int getDirection();
    void setDirection(int direction);
    int getX();
    int getY();
    void adjustX(int distance);
    void adjustY(int distance);
};

class Rock : public Moveable {
private:
    int spriteNumber;
public:
    Rock(int spriteNumber);
    int getSpriteNumber();
};

class Player : public Moveable {
private:
    int score;
public:
    int getScore();
    void goLeft();
    void goRight();
    void stayStill();
    void increaseScore();
};
#endif //PA9_ENTITIES_H
