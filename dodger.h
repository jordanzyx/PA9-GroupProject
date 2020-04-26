//
// Created by Jordan on 4/26/2020.
//

#ifndef PA9_DODGER_H
#define PA9_DODGER_H

#include "entities.h"
#include "queue.h"

class Dodger {
private:
    int maxX; // Maxiumum X the player can move to this would be as far right as the player can go
    Player player = Player(); // The player of the game
    Queue<Rock> rocks = Queue<Rock>(); //This will store rocks, I chose a queue because the rocks that come in first will hit the ground first and get removed first
    void tick();
public:
    Dodger(int maxX); // Creates a dodger game with a max x value so we know how far the user can move to the right
    void generateNewRocks(int amount,int totalSprites);
    Player getPlayer();
    Queue<Rock> getRocks();
    bool isAlive();
};




#endif //PA9_DODGER_H
