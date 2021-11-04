#ifndef SNAKE_GAMEMANAGER_H
#define SNAKE_GAMEMANAGER_H

#include "Player.h"
#include "CursesWrapper/Util.h"
#include <unistd.h>



class GameManager
{
private:
    Rect smallFood{2,1,0,0,FOOD_PAIR};
    Rect bigFood{2,1,0,0,BIG_FOOD_PAIR};
    bool hasBigFood = false;
    int curScore = 0;
    void initUI();
    void updateScore(int);
    void run();
    void spawnFood();
    void checkFood();
    void endGame();
    Player player = Player(getRandomVector2(0,0,GW_X - 2,GW_Y));
public:
    void start();
};


#endif
