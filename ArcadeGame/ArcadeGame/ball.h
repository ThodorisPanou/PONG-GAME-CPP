#pragma once
#include "config.h"
#include "gameObject.h"


class Ball : public Collidable , public GameObject
{
private:

	int pos_x = CANVAS_WIDTH / 2;
	int pos_y = CANVAS_HEIGHT / 2;
	bool moveP1 = true;
	float time;
	bool goal = false;
	bool moveP2 = false;
	
public:
	void update(int i);
	void draw(int i);
	void init();
	Ball(const Game& mygame);
	~Ball();
	Disk getCollisionDisc() override;
	Rect getCollisionRect() override;
	void ChangeDirX(float sp);
	void ChangeDirY(float sp);
	void ChangeDirX();
	void ChangeDirY();
	void setX(int x) { pos_x = x; }
	void setY(int y) { pos_y = y; }
	int getScore();
	void reset();
	void place();
	float getSpeedX() {return speedX;}
	float getSpeedY() {return speedY;}
	float getX() { return pos_x; }
	float getY() { return pos_y; }
	int scoreP1 = 0;
	int scoreP2 = 0;
	float speedX = 1.4f;
	float speedY = 1.4f;
};