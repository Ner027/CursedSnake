#include <ncurses.h>
#include <unistd.h>
#include "CursesWrapper/Rect.h"
#include "Player.h"
#include "CursesWrapper/Util.h"


int main()
{
    initscr();
    start_color();

    raw(); //Enable raw input mode
    nodelay(stdscr,TRUE); //Disable input buffering
    noecho(); //Disable other outputs
    keypad(stdscr, true); //Enable keypad on the main windows

    //Initiate the color pair for the background color
    init_pair(CLEAR_PAIR,COLOR_BLACK,COLOR_BLACK);
    //Init the remaining pairs
    init_pair(SNAKE_PAIR,COLOR_RED,COLOR_RED);
    init_pair(FOOD_PAIR,COLOR_WHITE,COLOR_WHITE);
    bkgd(COLOR_PAIR(CLEAR_PAIR));//Set that as the background
    curs_set(0); //Disable the cursor
    clear();//Clear the terminal
    refresh();//Push the changes from the buffer to the terminal

    Player player(COLS/2,LINES/2);

    Rect food = Rect(2,1,0,0,FOOD_PAIR);
    Vector2 newPos = getRandomVector2(0,0,COLS,LINES);
    food.translate(newPos);

    while (true)
    {
        int ch = getch();
        switch (ch)
        {
            case KEY_LEFT:
                player.setDirection(0x3);
                break;
            case KEY_RIGHT:
                player.setDirection(0x1);
                break;
            case KEY_UP:
                player.setDirection(0x0);
                break;
            case KEY_DOWN:
                player.setDirection(0x2);
                break;
            case KEY_EXIT:
                return 0;
            default:
                break;
        }

        if (hasHit(player.getHeadPosition(),food.getPos()))
        {
            player.addNode();
            newPos = getRandomVector2(0,0,COLS,LINES);
            food.moveTo(newPos);
        }

        player.tick();
        usleep(150000);
    }
}


