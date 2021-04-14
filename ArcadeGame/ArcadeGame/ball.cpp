#include "ball.h"
#include "graphics.h"
#include "game.h"
#include "Player.h"



void Ball::update(int i)
{	
	pos_x += speedX * graphics::getDeltaTime()/9;
	pos_y += speedY * graphics::getDeltaTime()/9;

	
	
	
	if (pos_y == CANVAS_HEIGHT && (pos_x < CANVAS_WIDTH || pos_x>0)) {
		ChangeDirY();
	}
	if (pos_y == 0 && (pos_x<CANVAS_WIDTH || pos_x>0)) {
		ChangeDirY();
	}

	if (pos_x == 0) {
		graphics::playSound(std::string(ASSET_PATH) + "din.mp3", 1.0f, false);
		scoreP2 += 1;
		time = graphics::getGlobalTime();
		goal = true;
		
	
		
		
	}

		
	if (pos_x == CANVAS_WIDTH) {
		graphics::playSound(std::string(ASSET_PATH) + "din.mp3", 1.0f, false);
		scoreP1 += 1;
		
		time = graphics::getGlobalTime();
		goal = true;
		
		
	}
	
	float s = graphics::getGlobalTime();
	
		
		if (s - time > 2000 && goal) {
			
			place();
			goal = false;
		}
	}
	
	


void Ball::draw(int i)
{
	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;
	graphics::drawDisk(pos_x, pos_y, 7,br);
	std::string s1 = std::to_string(scoreP1);
	graphics::drawText(150, 140, 40, s1  , br);
	std::string s2 = std::to_string(scoreP2);
	graphics::drawText(CANVAS_WIDTH-150, 140, 40, s2, br);

}

void Ball::init()
{

}



Ball::Ball(const Game& mygame):
	GameObject(mygame)
	
{
}



Ball::~Ball()
{
}

Rect Ball::getCollisionRect()
{
	return Rect();
}

void Ball::ChangeDirX(float sp)
{
	speedX = sp;
}

void Ball::ChangeDirY(float sp)
{
	speedY = sp;
}



void Ball::ChangeDirX()
{
	speedX = -speedX;
}

void Ball::ChangeDirY()
{
	speedY = -speedY;
}

Disk Ball::getCollisionDisc()
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radious = 7.0f;
	return disk;
}

int Ball::getScore() {
	if (scoreP1 >= 5) {
		return 1;
	}
	if (scoreP2 >= 5) {
		return 2;
	}
}

void Ball :: reset() {
	scoreP1 = 0;
	scoreP2 = 0;
	ChangeDirX(-1.3f);
	ChangeDirY(-1.3f);
}

void Ball::place()
{
	 
		setX(CANVAS_WIDTH / 2);
		setY(CANVAS_HEIGHT / 2);
	
}


