#include "GameLogic.h"

GameLogic::GameLogic()
{
	bool left = false, right = false;
	int windowX = 800, windowY = 600, counter = 0, counter2 = 0, spawnValue = 500, diff = 0, fps = 0;
	bkgd.loadFromFile("background.png");
	background.setTexture(bkgd);
	font.loadFromFile("arial.ttf");
	score.setFont(font);
	score.setCharacterSize(25);
	p.changeTex("player.png");
	p.adjustX(400);
	p.adjustY(475);
	p.resizeSpriteScale(.25, .25);
}
GameLogic::GameLogic(Game* game_I, int windowX_I, int windowY_I, sf::Texture background_I)
{
	game = game_I;
	bool left = false, right = false;
	int windowX = windowX_I, windowY = windowY_I, counter = 0, counter2 = 0, spawnValue = 500, diff = 0, fps = 0;
	bkgd = background_I;
	background.setTexture(bkgd);
	font.loadFromFile("arial.ttf");
	score.setFont(font);
	score.setCharacterSize(25);
	p.changeTex("player.png");
	p.adjustX(400);
	p.adjustY(475);
	p.resizeSpriteScale(.25, .25);
}

void GameLogic::GetPlayerInput()
{
	sf::Event event;
	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Left)
			{
				left = true;

			}
			if (event.key.code == sf::Keyboard::Right)
			{
				right = true;

			}
			break;
		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::Left)
			{
				left = false;

			}
			if (event.key.code == sf::Keyboard::Right)
			{
				right = false;

			}
			break;
		}


	}
	cout << "Left " << left << " Right " << right << endl;
}
void GameLogic::SetPlayerDir()
{
	if (left == true)
	{
		p.setDirection(2);
	}
	else if (right == true)
	{
		p.setDirection(3);
	}
	else
	{
		p.setDirection(1);
	}
}
void GameLogic::ComputeScore()
{

}
void GameLogic::DrawSprites()
{
	game->window.draw(score);
	game->window.draw(background);
	game->window.draw(p.getSprite());
	p.updateSprite();
}
void GameLogic::SetDiffuculty()
{
	diff = p.getScore() / 100;
}
bool GameLogic::CheckCollition()
{
	sf::FloatRect playerbounds = p.getSprite().getGlobalBounds();
	for (int x = 0; x < rocks.size(); x++)
	{
		//rocks.at(x)->getSprite().setTexture();
		game->window.draw(rocks.at(x)->getSprite());
		rocks.at(x)->updateSprite();
		if (rocks.at(x)->getY() > windowY)
		{
			rocks.erase(rocks.begin() + x);
			p.increaseScore();
			spawnValue--;
			break;
		}
		sf::FloatRect rockBounds = rocks.at(x)->getSprite().getGlobalBounds();
		double dx = (p.getX() + (playerbounds.width / 2)) - (rocks.at(x)->getX());
		double dy = (p.getY() + (playerbounds.height / 2)) - (rocks.at(x)->getY());
		double distance = sqrt((dx * dx) + (dy * dy));
		if (distance <= (playerbounds.width / 2) + (rockBounds.width / 2) - 20)
		{
			/*
			sf::CircleShape newShape;
			sf::Vector2f v(rockBounds.width / 2, rockBounds.height / 2);
			newShape.setPosition(rocks.at(x)->getX(), rocks.at(x)->getY());
			newShape.setOrigin(rockBounds.width / 2, rockBounds.width / 2);
			newShape.setRadius(rockBounds.width / 2);
			*/

			rocks.at(x)->changeTex("hit.png");
			game->window.draw(rocks.at(x)->getSprite());

			//window.draw(text);
			//window.draw(newShape);
			//window.display();
			return true;
		}
		
	}
	return false;
}
void GameLogic::SpawnRocks()
{
	if (counter >= 500)
	{
		MakeRocks(rand()%(2+diff));
		counter = 0;
	}
	else
	{
		counter += 1;
	}
}

void GameLogic::setDir(int left_I, int right_I)
{
	if (left_I == 1)
	{
		left = true;
	}
	else if (left_I == 0)
	{
		left = false;
	}
	if (right_I == 1)
	{
		right = true;
	}
	else if (right_I == 0)
	{
		right = false;
	}
}

void GameLogic::MakeRocks(int random)
{
	for (int x = 0; x < random; x++)
	{
		int pos = (rand() % windowX);
		int degree = rand() % 360;
		Rock* r = new Rock(0, "rock.png", pos, 0);
		r->changeOrgin(r->getSprite().getGlobalBounds().width / 2, r->getSprite().getGlobalBounds().height / 2);

		//cout << r->getSprite().getGlobalBounds().width << "," << r->getSprite().getOrigin().y << " ";
		cout << r->getSprite().getOrigin().x << "," << r->getSprite().getOrigin().y << " ";
		r->resizeSpriteScale(.2, .2);
		r->rotateSprite(degree);

		rocks.push_back(r);
	}
}

void GameLogic::setGame(Game* game_I)
{
	game = game_I;
}
void GameLogic::setWindowSize(int X, int Y)
{
	windowX = X;
	windowY = Y;
}
void GameLogic::SetBackground(sf::Texture Background)
{
	bkgd = Background;
}