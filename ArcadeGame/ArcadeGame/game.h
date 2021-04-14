#pragma once
#include "Player.h"
#include "ball.h"
#include <iostream>
#include <map>

class Game
{
	int status = 1;
	int winner;
	Player* player1 = nullptr;
	Player* player2 = nullptr;
	Ball* ball = nullptr;
	bool debug_mode = false;
	void updateStartScreen();
	void updateGameScreen();
	void updateExitScreen();
	void updateHistScreen();
	void drawStartScreen();
	void drawGameScreen();
	void drawExitScreen();
	void drawHistScreen();
	int games_played = 0;

	std::map<int, int> games;
	

	
public:
	void SetDebug(bool d) { debug_mode = d; }
	bool getDebug() const { return debug_mode; }
	void update();
	void draw();
	void init();
	Game();
	~Game();
	bool checkCoolision(Ball* ball, Player *player);
	void changeDirection(Ball* ball);
	bool exit = false;

};