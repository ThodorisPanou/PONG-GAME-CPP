#include "game.h"
#include "graphics.h"
#include "config.h"
#include "Player.h"
#include "ball.h"
#include <iostream>
#include <map>





float cooltime;
bool cool=false;


void Game::changeDirection(Ball *ball) {
	if (graphics::getGlobalTime() > cooltime + 1000) {
		if (Game::checkCoolision(ball, player1)) {
			ball->ChangeDirX();
		}
	}
	
	if (Game::checkCoolision(ball, player2)) {
		ball->ChangeDirX();
		
	
	}
	
}





bool Game::checkCoolision(Ball *ball, Player *player)
{
	
	Disk pong = ball->getCollisionDisc();
	Rect rect1 = player->getCollisionRect();
	
	float cx = pong.cx;
	float cy = pong.cy;
	float rad = pong.radious;
	float rx = rect1.centx;
	float ry = rect1.centy;
	
	
	if (player == player1) {
		
		float x = abs(rx - cx);
		float y = abs(ry - cy);
		if (x <= rad + rect1.width / 2 && y <= rad + rect1.height / 2) {
			cooltime = graphics::getGlobalTime();
			cool = true;
			return true;
		}
	}
	
	if (player == player2) {
		float x = abs(rx - cx);
		float y = abs(ry - cy);
		if (x <= rad + rect1.width / 2 && y <= rad + rect1.height / 2) {
			return true;
		}
	}
	return false;


}

void Game::updateStartScreen()
{
	graphics::playMusic(std::string(ASSET_PATH) + "intro.mp3", 0.2f, true);
	if (graphics::getKeyState(graphics::SCANCODE_RETURN)) {
		
		status=2;
	}

}

void Game::updateGameScreen()
{
	//graphics::stopMusic();
	//graphics::playMusic(std::string(ASSET_PATH) + "intro.mp3", 0.0f, true);
	games_played++;
	if (player1)
		player1->update(1);
	if (player2)
		player2->update(2);
	if (ball)
	{
		ball->update(1);
		
	}
	
	changeDirection(ball);

	int x = ball->getScore();
	
	if (x == 1) {
		ball->ChangeDirX(0);
		ball->ChangeDirY(0);
		player1->wins++;
		winner = 1;
		games[games_played] = 1;
		status=3;
	}
	if (x == 2) {
		ball->ChangeDirX(0);
		ball->ChangeDirY(0);
		player2->wins++;
		winner = 2;
		games[games_played] = 2;
		status = 3;
	}
}

void Game::updateExitScreen()
{

	
	
	
	if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
		
		ball->reset();
		status=2;
	}
	if (graphics::getKeyState(graphics::SCANCODE_H))
		status = 4;
	

}

void Game::updateHistScreen() {
	if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
		status = 3;
	
}

void Game::drawStartScreen()
{
	graphics::Brush br2;
	br2.texture = std::string(ASSET_PATH) + "back.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br2);
	

}

void Game::drawGameScreen()
{
	
	graphics::Brush br;
	br.outline_opacity = 0;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

//draw player and ball 
	
	if (player1)
		player1->draw(1);
	if (player2)
		player2->draw(2);
	if (ball)
		ball->draw(1);
	
	
	

}

void Game::drawExitScreen()
{
	graphics::Brush br2;
	br2.texture = std::string(ASSET_PATH) + "exit.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br2);
	graphics::Brush br;
	graphics::drawText(CANVAS_WIDTH / 2 - 400, CANVAS_HEIGHT / 2 + 50, 20, "-IF  YOU  WANT  TO  PLAY  AGAIN  PRESS  SPACE", br);
	graphics::drawText(CANVAS_WIDTH / 2 - 400, CANVAS_HEIGHT / 2 + 100,20, "-IF  YOU  WANT  TO  SEE  THE  GAME  HISTORY PRESS H", br);
	if (winner == 1) {
		graphics::drawText(CANVAS_WIDTH / 2 - 230, 200, 50, "PLAYER 1 WINS", br);

	}
	if (winner == 2) {
		graphics::drawText(CANVAS_WIDTH / 2 - 230, 200, 50, "PLAYER 2 WINS", br);
		
	}

	
	

}

void Game::drawHistScreen() {
		graphics::Brush br3;
		br3.texture = std::string(ASSET_PATH) + "exit.png";
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br3);
		graphics::Brush br2;
		std::string w;
		br2.texture = std::string(ASSET_PATH) + "back.png";
		float x = 0.0f;
		br2.fill_color[0] = 1.0f;
		graphics::drawText(CANVAS_WIDTH / 2 + 50 , 30, 20, "press backspace to get back", br2);
		br2.fill_color[0] = 0.0f;
		graphics::drawText(CANVAS_WIDTH / 2 - 280, 100, 50, "GAME    HISTORY", br2);
		br2.fill_color[2] = 0.5f;
		for (std::map<int, int>::iterator it = games.begin(); it != games.end(); ++it) {
			if (it->second == 1) {
				w = "PLAYER 1";
			}
			else if (it->second == 2) {
				w = "PLAYER 2";
			}
			x++;
			int a = (int)x;
			graphics::drawText(CANVAS_WIDTH / 2 - 400, CANVAS_HEIGHT / 2 - 140 + 40 * x, 30, "- GAME   " + std::to_string(a) + "  WINNER WAS   " + w, br2);


		}
	
}

void Game::update()
{
	if (status == 1) {
		updateStartScreen();
	}
	else if (status == 2) {
		updateGameScreen();
	}
	else if (status == 3)
		updateExitScreen();
	else if (status == 4)
		updateHistScreen();
	

	

}

void Game::draw()
{
	if (status == 1)
		drawStartScreen();
	else if (status == 2)
		drawGameScreen();
	else if (status == 3)
		drawExitScreen();
	else if (status == 4)
		drawHistScreen();
	
}

void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "foo.ttf");
	//graphics::playMusic(std::string(ASSET_PATH) + "music.mp3", 1.0f, true);
	//graphics::stopMusic(5000);
}

Game::Game()
{
	player1 = new Player(*this,100,CANVAS_HEIGHT/2);
	player2 = new Player(*this,CANVAS_WIDTH-100,CANVAS_HEIGHT/2);
	ball = new Ball(*this);
}

Game::~Game()
{
	if (player1) {
		delete player1;
	}
	
	if (player2) {
		delete player2;
	}

	if (ball) {
		delete ball;
	}

}
