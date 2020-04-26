//
// Created by Jordan on 4/26/2020.
//

#include "dodger.h"
#include <stdlib.h>

void Dodger::tick() {

}

void Dodger::generateNewRocks(int amount,int totalSprites) {
    for (int i = 0; i < amount; ++i) {
        //Randomly chose a sprite for the rock
        int sprite = (rand() % totalSprites);

        //Create the rock
        Rock rock = Rock(sprite);

        //Add the rock to the queue
        getRocks().push(rock);
    }
}

Player Dodger::getPlayer() {
    return player;
}

Queue<Rock> Dodger::getRocks() {
    return rocks;
}

bool Dodger::isAlive() {

    //Check if the top rock is even at y=0
    if(getRocks().top().getY() == 0)return true;

    //Get the lane the player is in
    int x = getPlayer().getX();

    //Check all rocks at y = 0;
    bool level0Rocks = true;

    while(level0Rocks){
        //If we pass through all the rocks at level 0 exit the loop
        if(getRocks().top().getY() != 0){
            level0Rocks = false;
            continue;
        }

        //Check if the rock is on the player
        if(getRocks().top().getX() == x)return false;

        //Get rid of the rock that hit the ground without hurting the player
        getRocks().pop();
    }

    return true;
}

Dodger::Dodger(int maxX) {
    this->maxX = maxX;
}
