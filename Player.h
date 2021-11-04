#ifndef SNAKE_PLAYER_H
#define SNAKE_PLAYER_H

#include <vector>
#include <cstdlib>
#include "CursesWrapper/Rect.h"
#include "Consts.h"

class Player
{
private:
    Rect head = Rect(2,1,0,0,SNAKE_PAIR);
    std::vector<Rect> body;
    unsigned char headDir = 0x0;
    Vector2 oldPos;
public:
    Vector2 getHeadPosition();
    explicit Player(Vector2 pos);
    void setDirection(unsigned char newSide);
    bool tick();
    void addNode();
    bool canSpawnObject(Vector2& pos);
    void kill();
};

#endif
