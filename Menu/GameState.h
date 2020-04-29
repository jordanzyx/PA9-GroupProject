//
// Created by Cameron on 4/26/2020.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "game.h"

// Game state class
class GameState
{
public:
    Game* game;

    virtual void draw(const double dt) = 0; // Draw to screen
    virtual void update(const double dt) = 0; // Update screen
    virtual void handleInput() = 0; // Handles input
};


#endif //GAMESTATE_H
