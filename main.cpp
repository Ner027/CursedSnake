#include <ncurses.h>
#include "CursesWrapper/Rect.h"
#include "GameManager.h"
#include "Utils.h"
#include "pthread.h"
using namespace std;


void* foo(void*)
{
    for (int i = 32; i < 255; ++i)
    {
        printw("%c ",i);
    }
}

int main()
{
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)

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
    init_pair(BIG_FOOD_PAIR,COLOR_WHITE,COLOR_GREEN);
    init_pair(UI_PAIR,COLOR_WHITE,COLOR_BLACK);
    init_pair(BLUE_PAIR,COLOR_BLUE,COLOR_BLUE);
    init_pair(YELLOW_PAIR,COLOR_YELLOW,COLOR_YELLOW);
    bkgd(COLOR_PAIR(CLEAR_PAIR));//Set that as the background
    curs_set(0); //Disable the cursor
    clear();//Clear the terminal
    refresh();//Push the changes from the buffer to the terminal

    refresh();

     GameManager gameManager{};
     gameManager.start();

  /*
    pthread_t thread;
    pthread_create(&thread,nullptr,foo, nullptr);
*/
}


