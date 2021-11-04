#include <unistd.h>
#include "Player.h"
#include "CursesWrapper/Util.h"

Vector2 Player::getHeadPosition()
{
    return head.getPos();
}

/// Player::setDirection allows to change the snake direction
/// \param newSide the side that the snake should turn to

void Player::setDirection(const unsigned char newSide)
{
    //Check if the passed value is a valid new side if not return
    if (!(newSide == 0x0 || newSide == 0x1 || newSide == 0x2 || newSide == 0x3))
        return;
    //If the snake is only 1 block long,aka it doesn't have a body, then the snake can move in any direction
    if (abs(headDir - newSide) == 2 && !body.empty())
        return;

    headDir = newSide;
}

///
/// \param shouldAdd
bool Player::tick()
{
    oldPos = head.getPos();

    //The direction is an unsigned char, 1 byte so its memory efficient
    //UP:0x0 DOWN:0x2 RIGHT:0x1 LEFT:0x3
    //Since the opposite direction are shifted by a value of 2 it allows for some fast comparisons and calculations

    /*Translate the snake head according to the direction it should head to
     When a screen border is reached the snake is transported to the other side of the screen
     just like in classic snake
    */
    switch (headDir)
    {
        case 0x0:
            if ((head.getY() - 1) < 0)
                head.translate(0,GW_Y - 1);
            else head.translate(0,-1);
            break;
        case 0x1:
            if ((head.getX() + 2) >= GW_X)
                head.moveTo(0,head.getY());
            else head.translate(2,0);
            break;
        case 0x2:
            if ((head.getY() + 1) >= GW_Y)
                head.translate(0,-GW_Y + 1);
            else head.translate(0,1);
            break;
        case 0x3:
            if ((head.getX() - 1) <= 0)
                head.moveTo(GW_X - 2,head.getY());
            else head.translate(-2,0);
            break;
    }

    //Iterate each block of the body
    for (Rect& node : body)
    {
        //Check if the head collides with any block of the body, if so you loose the game
        if (hasHit(node.getPos(),head.getPos()))
            return false;
        //Store the current block position
        Vector2 temp = node.getPos();
        //Move it to the last block position
        node.moveTo(oldPos);
        //Set the last block position to the last current block position
        oldPos = temp;
    }

    return true;
}

///Player::addNode adds a block to the back of the snake
void Player::addNode()
{
    Rect newNode = Rect(2,1,0,0,SNAKE_PAIR);
    newNode.moveTo(oldPos);
    body.push_back(newNode);
}

//TODO:USE THIS THING IN FOOD SPAWN
bool Player::canSpawnObject(Vector2& pos)
{
    if (hasHit(head.getPos(),pos)) return false;

    for(Rect& node : body)
        if (hasHit(pos,node.getPos())) return false;

    return true;
}

Player::Player(Vector2 pos)
{
    this->head.translate(pos);
}

void Player::kill()
{
    for (size_t i = body.size() - 1;i > 0; --i)
    {
        body[i].clear();
        usleep(K_DELAY);
    }
    body.clear();
    headDir = 0x0;
    Vector2 pos = getRandomVector2(0,0,GW_X - 2,GW_Y-1);
    head.moveTo(pos);
}
