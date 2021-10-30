#include "Rect.h"
#include "Util.h"

Rect::Rect(Vector2& size, Vector2& pos,short colorPair)
{
    this->color = colorPair;
    this->size = size;
    this->pos = pos;
}

Rect::Rect(int sizeX, int sizeY, int posX, int posY,short colorPair)
{
    Vector2 sz(sizeX,sizeY);
    Vector2 ps(posX,posY);
    this->color = colorPair;
    this->pos = ps;
    this->size = sz;
}

void Rect::draw()
{
    iterateRect(color);
}

//TODO:Check size
void Rect::resize(Vector2& newSize)
{
    this->size = newSize;
    this->draw();
}

void Rect::resize(int x, int y)
{
    Vector2 newSize(x,y);
    this->resize(newSize);
}

/// Rect::translate allows to translate the rectangle
/// TODO:Check for screen bounds
/// TODO:Could be optimized if the translated object overlaps with the original
/// \param [in] dislocation How much the rectangle should move

void Rect::translate(Vector2& dislocation)
{
    this->clear();//Remove the old object
    this->pos += dislocation;
    this->draw();//Redraw the object
}

void Rect::translate(int x, int y)
{
    Vector2 newPos(x,y);
    this->clear();
    this->translate(newPos);
}

///Rect::clear clears the object from the screen, but keeps all of the object data

void Rect::clear()
{
    //Iterate through the rect "blocks" and print a char the same color as the background
    //delch doesn't work because it deletes the char and shifts everything back
    iterateRect(CLEAR_PAIR);
}

Vector2 Rect::getPos()
{
    return pos;
}

int Rect::getX()
{
    return pos.getX();
}

int Rect::getY()
{
    return pos.getY();
}

/// Rect::moveTo allows to move a Rect object to a screen position
/// TODO:Check position for boundaries
/// \param newPos The screen coordinates where the object should be moved to
void Rect::moveTo(Vector2& newPos)
{
    this->clear();
    this->pos = newPos;
    this->draw();
}

void Rect::moveTo(int x, int y)
{
    Vector2 vec(x,y);
    moveTo(vec);
}

/// Rect::iterateRect iterates each "block" of the Rect,enable the color pair and pushes the buffer content to the screen
/// \param colorPair the color pair to use
void Rect::iterateRect(const short colorPair)
{
    attron(COLOR_PAIR(colorPair));
    for (int i = pos.getY(); i < pos.getY() + size.getY(); ++i)
    {
        for (int j = pos.getX(); j < pos.getX() + size.getX(); ++j)
        {
            move(i,j);
            printw(" ");
        }
    }
    attroff(COLOR_PAIR(colorPair));
    refresh();
}

