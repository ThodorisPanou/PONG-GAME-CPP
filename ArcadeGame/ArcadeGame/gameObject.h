#pragma once
#include "util.h"
class Collidable {

public:
	virtual Disk getCollisionDisc() = 0;
	virtual Rect getCollisionRect() = 0;
};




class GameObject 
{
protected:
	const class Game& game;
	
public:
	GameObject(const class Game & mygame);
	virtual void update(int choose) =0;
	virtual void draw(int i)=0;
	virtual void init()=0;


};