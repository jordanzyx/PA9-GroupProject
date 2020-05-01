//
// Created by Jordan on 5/1/2020.
//
#include <SFML/Graphics.hpp>
#include "tests.h"
#include "GameLogic.h"
#include "entities.h"



bool Tests::testLoadingAssets() {
    sf::Texture background;
    sf::Texture hitmarker;
    sf::Texture player;
    sf::Texture rock;
    sf::Texture mainscreen;

    bool check1,check2,check3,check4,check5;

    //Check if we can load them
    check1 = background.loadFromFile("Assets/background.png");
    check2 = hitmarker.loadFromFile("Assets/hit.png");
    check3 = player.loadFromFile("Assets/player1.png");
    check4 = rock.loadFromFile("Assets/rock.png");
	check5 = mainscreen.loadFromFile("Assets/FallingRocks.png");

    return check1 && check2 && check3 && check4 && check5;
}

bool Tests::testPolymorphism() {
    //Create two Moveable items each of which are different derived classes
    Moveable rock = Rock();
    Moveable player = Player();

    //Check if they both create successfully
    return (&rock != NULL) && (&player != NULL);
}


bool Tests::testAdjustX() {
    //Create rock
    Moveable rock = Rock();

    //Adjust
    int before = rock.getX();
    rock.adjustX(5);
    int after = rock.getX();

    //Check
    return (after - 5) == before;
}

bool Tests::testAdjustY() {
    //Create rock
    Moveable rock = Rock();

    //Adjust
    int before = rock.getY();
    rock.adjustY(5);
    int after = rock.getY();

    //Check
    return (after - 5) == before;
}

bool Tests::testSetOrigin() {
    //Create a moveable object
    Moveable rock = Rock();

    //Adjust origin
    rock.changeOrgin(10,10);

    //Check
    return rock.getX() == 10 && rock.getY() == 10;
}
