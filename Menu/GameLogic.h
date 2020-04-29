#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu/game.h"
#include "entities.h"
#include <vector>
#include <cmath>

class GameLogic
{
private:
	Game* game;
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
	GameLogic(Game* game, int windowX, int windowY, sf::Texture background);
	void setGame(Game* game);
	void setWindowSize(int X, int Y);
	void SetBackground(sf::Texture Background);
	void GetPlayerInput();
	void SetPlayerDir();
	void ComputeScore();
	void DrawSprites();
	void SetDiffuculty();
	bool CheckCollition();
	void SpawnRocks();
	void MakeRocks(int number);
	void setDir(int left, int right);

};