#ifndef SNAKE_PLAYER_H
#define SNAKE_PLAYER_H

#include <vector>
#include <cstdlib>
#include "CursesWrapper/Rect.h"
#include "CursesWrapper/Util.h"

class Player
{
private:
    Rect head = Rect(2,1,0,0,SNAKE_PAIR);
    std::vector<Rect> body;
    unsigned char headDir = 0x0;
    Vector2 oldPos;
public:
    Vector2 getHeadPosition();
    Player(int x,int y);
    void setDirection(unsigned char newSide);
    void tick();
    void addNode();
};

#endif
