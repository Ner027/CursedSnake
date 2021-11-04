#ifndef SNAKE_UTIL_H
#define SNAKE_UTIL_H
#include <random>
#include "Vector2.h"
#include "Rect.h"
#include <ncurses.h>
#include <iostream>
#include <fstream>
using namespace std;
//Macros for the color pairs

using namespace std;
void loadPixelMap(const string& path,Vector2& pos);
int getRandomInt(int,int);
Vector2 getRandomVector2(int xF,int yF,int xC,int yC);
bool hasHit(Vector2 pPos,Vector2 fPos);
#endif
