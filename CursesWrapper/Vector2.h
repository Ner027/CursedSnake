#ifndef SNAKE_VECTOR2_H
#define SNAKE_VECTOR2_H


///Vector 2 is a class that allows to represent 2D coordinates and do operations between them
class Vector2
{
private:
    int x,y;//Terminal only uses integer values
public:
    Vector2(int x,int y);
    Vector2(){x = 0;y=0;}
    //nodiscard can only be used with a compiler that supports C++17 and superior
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;

    //Operator overloading to make working with this easier
    Vector2& operator+=(const Vector2& vec);
    Vector2& operator-=(const Vector2& vec);
    friend bool operator ==(const Vector2& a,const Vector2& b);
    friend Vector2 operator -(const Vector2& a,const Vector2& b);
    friend Vector2 operator +(const Vector2& a,const Vector2& b);

};


#endif
