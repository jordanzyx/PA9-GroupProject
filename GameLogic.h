#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu/game.h"
#include "entities.h"
#include <vector>
#include <cmath>
using namespace std;

class GameLogic
{
private:
	sf::RenderWindow* game;
	sf::Font font;
	bool left, right;
	int windowX, windowY, counter, counter2, spawnValue, diff, fps;
	vector<Rock*> rocks;
	sf::Texture bkgd;
	sf::Sprite background;
	sf::Text score;
	Player p;

public:
	GameLogic();
	GameLogic(sf::RenderWindow* game, int windowX, int windowY, sf::Texture background);
	void setWindow(sf::RenderWindow* game);
	void setWindowSize(int X, int Y);
	void SetBackground(sf::Texture Background);
	void GetPlayerInput(sf::Event event);
	void SetPlayerDir();
	void ComputeScore();
	void DrawSprites();
	void SetDiffuculty();
	bool CheckCollition();
	void SpawnRocks();
	void MakeRocks(int number);
	void setDir(int left, int right);

};