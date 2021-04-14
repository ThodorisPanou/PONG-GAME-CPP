#include "graphics.h"
#include "game.h"
#include "config.h"
#include <iostream>
#include "Player.h"



void update(float ms)
{
    Game* game = reinterpret_cast<Game *>(graphics::getUserData());
    game->update();
    
}


void draw()
{
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    game->draw();
  
}



int main()
{
    Game mygame;
    //start();
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "PONG");
    graphics::setUserData(&mygame);
    graphics::setUpdateFunction(update);
    graphics::setDrawFunction(draw);
  
    graphics::setCanvasSize(CANVAS_WIDTH,CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_STRETCH);
    
    mygame.SetDebug(true);

    mygame.init();
    graphics::startMessageLoop();
   
    


    return 0;
}