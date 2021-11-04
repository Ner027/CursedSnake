#include <thread>
#include "GameManager.h"

void GameManager::initUI()
{
    attron(COLOR_PAIR(FOOD_PAIR));
    for (int i = 0; i < GW_X; ++i)
        mvaddch(GW_Y, i, ' ');
    attroff(COLOR_PAIR(FOOD_PAIR));

    updateScore(0);
}

void GameManager::updateScore(int amount)
{
    if (amount < 0) return;
    curScore += amount;
    attron(COLOR_PAIR(UI_PAIR));
    attron(A_BOLD);
    mvprintw(LINES - 2, 5, "Score:%d", curScore);
    attroff(A_BOLD);
    attroff(COLOR_PAIR(UI_PAIR));
    refresh();
}

void GameManager::start()
{
    clear();
    initUI();
    hasBigFood = true;
    spawnFood();
    hasBigFood = false;
    run();
}

void GameManager::run()
{
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
                return;
            default:
                break;
        }
        checkFood();
        if (!player.tick())
        {
            endGame();
            return;
        }
        usleep(75000);
    }
}

void GameManager::spawnFood()
{
    Vector2 newPos = getRandomVector2(0, 0, GW_X - 2, GW_Y - 1);
    smallFood.moveTo(newPos);

    if (!hasBigFood)
    {
        int rng = getRandomInt(0, 100);
        if (rng > 15) return;
        hasBigFood = true;
        Vector2 pos = getRandomVector2(0, 0, GW_X - 2, GW_Y - 1);
        bigFood.moveTo(pos);
    }
}

void GameManager::checkFood()
{
    if (hasHit(player.getHeadPosition(), smallFood.getPos()))
    {
        updateScore(10);
        spawnFood();
        player.addNode();
    }
    else if (hasHit(player.getHeadPosition(), bigFood.getPos()))
    {
        hasBigFood = false;
        updateScore(100);
        bigFood.clear();
        player.addNode();
    }
}

void GameManager::endGame()
{
    player.kill();

    Vector2 pos{COLS / 2,LINES / 2};
    clear();
    loadPixelMap("/home/nero/Desktop/Software Development/C|C++/CursedSnake/PixelMaps/Gameover.txt",pos);

    while(true)
    {
        int input = getch();
        if (input == 10)
            break;
        else if(input == 27)
        {
            endwin();
            exit(1);
        }

    }

    start();
}

