#include "Player.h"
#include "graphics.h"
#include "game.h"
#include <string>
#include <iostream>




Player::Player(const Game& mygame,int x,int y )
	: GameObject(mygame)
{
	pos_x = x;
	pos_y = y;
}

void Player::update(int choose)
{
	if (choose==1) {
		if (graphics::getKeyState(graphics::SCANCODE_W))
		{
			pos_y -= speed * graphics::getDeltaTime() / 30;
		}

		if (graphics::getKeyState(graphics::SCANCODE_S))
		{
			pos_y += speed * graphics::getDeltaTime() / 30;
		}
		/*
		if (graphics::getKeyState(graphics::SCANCODE_A))
		{
			pos_x -= speed * graphics::getDeltaTime() / 100;
		}

		if (graphics::getKeyState(graphics::SCANCODE_D))
		{
			pos_x += speed * graphics::getDeltaTime() / 100;
		}
		*/
		
	}

	if (choose == 2) {
		if (graphics::getKeyState(graphics::SCANCODE_UP))
		{
			pos_y -= speed * graphics::getDeltaTime() / 30;
		}

		if (graphics::getKeyState(graphics::SCANCODE_DOWN))
		{
			pos_y += speed * graphics::getDeltaTime() / 30;
		}
		/*
		if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
		{
			pos_x += speed * graphics::getDeltaTime() / 100;
		}

		if (graphics::getKeyState(graphics::SCANCODE_LEFT))
		{
			pos_x -= speed * graphics::getDeltaTime() / 100;
		}
		*/
		
		
	}

	if (pos_x < 0) pos_x = 0;
	if (pos_x > CANVAS_WIDTH) pos_x = CANVAS_WIDTH;
	if (pos_y < 25) pos_y = 25;
	if (pos_y > CANVAS_HEIGHT-25) pos_y = CANVAS_HEIGHT-25;
	
}

	void Player::draw(int i)
	{
		if (i == 1) {
			graphics::Brush br;
			br.outline_opacity = 0.0f;
			br.fill_color[0] = 0.235f;
			br.fill_color[1] = 0.208f;
			br.fill_color[2] = 0.208f;
			br.gradient = true;
			br.gradient_dir_u = 0.74f;
			br.gradient_dir_v = 0.74f;
			br.fill_secondary_color[0] = 1.0f;
			br.fill_secondary_color[1] = 0.0f;
			br.fill_secondary_color[2] = 0.0f;
			graphics::drawRect(pos_x, pos_y, 10, 50, br);
		}
		if (i == 2) {
			graphics::Brush br;
			br.outline_opacity = 0.0f;
			br.fill_color[0] = 0.235f;
			br.fill_color[1] = 0.208f;
			br.fill_color[2] = 0.208f;
			br.gradient = true;
			br.gradient_dir_u = 0.74f;
			br.gradient_dir_v = 0.74f;
			br.fill_secondary_color[0] = 1.0f;
			br.fill_secondary_color[1] = 0.969f;
			br.fill_secondary_color[2] = 0.0f;
			graphics::drawRect(pos_x, pos_y, 10, 50, br);
		}
		

	}

	
	void Player::init()
	{
	}

	Disk Player::getCollisionDisc()
	{
		return Disk();
	}

	Rect Player::getCollisionRect()
	{
		Rect rect;
		rect.centx = pos_x;
		rect.centy = pos_y;
		rect.height = 50;
		rect.width = 10;
		return rect;
	}

	

	
	




	

	


