#include <ncurses.h>
#include <unistd.h>
#include "CursesWrapper/Rect.h"
#include "Player.h"
#include "CursesWrapper/Util.h"

Rect food = Rect(2,1,0,0,FOOD_PAIR);
int score = 0;

void spawnFood(Player& player)
{
    Vector2 newPos = getRandomVector2(0,0,GW_X - 2,GW_Y);

    if (!player.canSpawnObject(newPos))
        spawnFood(player);

    food.moveTo(newPos);

}

void updateScore(int amount)
{
    if (amount < 0) return;
    score += amount;
    attron(COLOR_PAIR(UI_PAIR));
    attron(A_BOLD);
    mvprintw(LINES - 2,5,"Score:%d",score);
    attroff(A_BOLD);
    attroff(COLOR_PAIR(UI_PAIR));
    refresh();
}

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
    init_pair(UI_PAIR,COLOR_WHITE,COLOR_BLACK);
    bkgd(COLOR_PAIR(CLEAR_PAIR));//Set that as the background
    curs_set(0); //Disable the cursor
    clear();//Clear the terminal

    attron(COLOR_PAIR(FOOD_PAIR));
    for (int i = 0; i < GW_X; ++i)
    {
        move(GW_Y,i);
        printw(" ");
    }
    refresh();//Push the changes from the buffer to the terminal
    updateScore(0);
    Player player(COLS/2,LINES/2);

    spawnFood(player);

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
            spawnFood(player);
            player.addNode();
            updateScore(SCORE_SF);
        }

        player.tick();
        usleep(120000);
    }
}


