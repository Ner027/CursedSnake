#ifndef SNAKE_RECT_H
#define SNAKE_RECT_H
#include "Vector2.h"
#include <ncurses.h>
#include "Util.h"
#include "../Consts.h"

/*
 * This class allows to create a rectangular object in the terminal
 * TODO:Check for negative sizes
 * TODO:Fix color not working correctly
 * */

class Rect
{
private:
    Vector2 size = Vector2(0, 0);
    Vector2 pos = Vector2(0, 0);
    short color;
    void iterateRect(short);

public:
    Rect(Vector2& size,Vector2& pos,short colorPair = 1);
    Rect(int,int,int=0,int=0,short colorPair = 1);
    void draw();
    void resize(Vector2&);
    void resize(int,int);
    void translate(Vector2&);
    void translate(int,int);
    void clear();
    [[nodiscard]]Vector2 getPos() const;
    int getX();
    int getY();
    [[nodiscard]] Vector2 getSize() const;
    void moveTo(Vector2&);
    void moveTo(int,int);
};


#endif
