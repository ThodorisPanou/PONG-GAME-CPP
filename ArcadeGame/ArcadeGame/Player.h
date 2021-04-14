#pragma once
#include "gameObject.h"
#include "config.h"


class Player : public GameObject , public Collidable
{
	float pos_x;  
	float pos_y;
	float speed = 10.0f;
	

public:
	Player(const Game& mygame, int x, int y);
	void update(int choose) override;
	void draw(int i) override;
	void init() override;
	float getX() { return pos_x; }
	float getY() { return pos_y; }
	Rect getCollisionRect() override;
	Disk getCollisionDisc() override;
	int score;
	void reset();
	int wins = 0;
};