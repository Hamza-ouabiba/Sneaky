#include<iostream>
#include"Snake.h"
using namespace::std;

//constructor :
Snake::Snake()
{
    snakeSize__ = 1;
    x[0] = generateRandomeLocation().x;
    y[0] = generateRandomeLocation().y;
}
//storing the x and y positions within the console :
void Snake::initialiseSnake()
{
    for (auto i = 1;i <= snakeSize__;i++)
    {
        x[i] = 0;
        y[i] = 0;
    }
}
void Snake::Draw(int x, int y)
{
    gotoxy(x, y);cout << "S";
}
void Snake::turnSnakeRight()
{
    x[0]++;
}
void Snake::turnSnakeLeft()
{
    x[0]--;
}
void Snake::turnSnakeUp()
{
    y[0]--;
}
void Snake::turnSnakeDown()
{
    y[0]++;
}
//moving the snake :
void Snake::captureOldestPosition()
{
    //keep all the predecessors of the snake follows the tail
    for (auto i = snakeSize__; i > 0;i--)
    {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
}
void Snake::moveSnake(Fruit* f)
{
    //testing colliding with fruit :
    auto xFr = f->getxAxis();
    auto yFr = f->getyAxis();
    if (xFr == x[0] && yFr == y[0])
    {
        //increment the size :
        snakeSize__++;
        while (f->checkAxis(x, y, snakeSize__))
        {

        }
        f->placeFruit();
    }

    for (auto i = 0; i < snakeSize__; i++)
    {
        if (i == 0)
        {
            gotoxy(x[i], y[i]);cout << "T";
        }
        else Draw(x[i], y[i]);
    }
}

bool Snake::touchSnake(int x_, int y_)
{
    for (int i = 1;i < snakeSize__;i++)
    {
        if (x_ == x[i] && y_ == y[i])
            return true;
    }
    return false;
}
bool Snake::touchEdgeScreen(int x_, int y_)
{
    if (x_ == 0 || y_ == 0 || x_ == 120 || y_ == 30)
        return true;
    return false;
}
void Snake::afficher()
{
}

