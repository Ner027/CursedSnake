#ifndef SNAKE_UTIL_H
#define SNAKE_UTIL_H
#include <random>
#include "Vector2.h"
#include <ncurses.h>

//Macros for the color pairs
#define CLEAR_PAIR 1
#define SNAKE_PAIR 2
#define FOOD_PAIR 3
#define UI_PAIR 4
#define GW_X (COLS)
#define GW_Y (LINES - 5)
#define SCORE_SF 10

using namespace std;
int getRandomInt(int,int);
Vector2 getRandomVector2(int xF,int yF,int xC,int yC);
bool hasHit(Vector2 pPos,Vector2 fPos);
#endif
