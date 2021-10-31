#include "Vector2.h"

Vector2::Vector2(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Vector2::getX() const
{
    return x;
}

int Vector2::getY() const
{
    return y;
}

Vector2 &Vector2::operator+=(const Vector2 &vec)
{
    this->x += vec.x;
    this->y += vec.y;
    return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
    return *this;
}

bool operator==(const Vector2 &a, const Vector2 &b)
{
    return a.x == b.x && a.y == b.y;
}

Vector2 operator-(const Vector2 &a, const Vector2 &b)
{
    Vector2 newVec(a.x - b.x,a.y - b.y);
    return newVec;
}

Vector2 operator+(const Vector2 &a, const Vector2 &b)
{
    Vector2 newVec(a.x + b.x,a.y + b.y);
    return newVec;
}

double Vector2::distanceTo(const Vector2& vec) const
{
    int sqX = (int) pow((this->x - vec.x),2);
    int sqY = (int) pow((this->y - vec.y),2);
    return sqrt(sqX + sqY);
}






