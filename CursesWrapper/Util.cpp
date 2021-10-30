#include "Util.h"

using namespace std;

/// getRandomInt allows to generate a random integer
/// TODO:Using deprecated C style random generation
/// \param floor the minimum value that will be generated
/// \param ceiling the maximum value that will be generated
/// \return Returns an integer between floor and ceiling
int getRandomInt(int floor,int ceiling)
{
    srand(time(nullptr));
    return (floor + ( rand() % ( ceiling - floor + 1 )));
}

/// getRandomVector2 allows to generate a vector2 with random coordinates
/// \param xF the minimum value for the x coordinate
/// \param yF the minimum value for the y coordinate
/// \param xC the maximum value for the x coordinate
/// \param yC the maximum value for the y coordinate
/// \return Returns a vector with coordinates between the specified limits
Vector2 getRandomVector2(int xF,int yF,int xC,int yC)
{
    Vector2 vec(getRandomInt(xF,xC), getRandomInt(yF,yC));
    return vec;
}

/// hasHit allows to check if the snake has hit a food ball
/// \param pPos Object 1 position
/// \param fPos Object 2 position
/// \return Returns true if collided or false if not
bool hasHit(Vector2 pPos,Vector2 fPos)
{
    Vector2 res = pPos - fPos;
    int absX = abs(res.getX());
    return (res.getY() == 0 && (absX == 0 || absX == 1));
}

