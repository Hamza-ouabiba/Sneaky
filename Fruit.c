#include<iostream>
#include"Fruit.h"
using namespace::std;

position generateRandomeLocation()
{
    srand(time(NULL));
    position p;
    p.x = (rand() % (70 - 30 + 1)) + 30;
    p.y = (rand() % (22 - 11 + 1)) + 11;
    return p;
}
Fruit::Fruit(int xSnake,int ySnake)
{
    x = generateRandomeLocation().x;
    while (x == xSnake)
    {
        x = generateRandomeLocation().x;
    }
    y = generateRandomeLocation().y;
}
bool Fruit::checkAxis(int* xSnake, int* ySnake, int snakeSize)
{
    int xFruit = generateRandomeLocation().x;
    int yFruit = generateRandomeLocation().y;
    bool flag = false;
    for (auto i = 0;i < snakeSize;i++)
    {
        if (xSnake[i] == xFruit && ySnake[i] == yFruit)
        {
            flag = true;
        }
    }
    if (flag == false)
    {
        x = xFruit;
        y = yFruit;
    }
    return flag;
}
int Fruit::getxAxis() { return x; }
int Fruit::getyAxis() { return y; }
void Fruit::setxAxis(int X) { x = X; }
void Fruit::setyAxis(int Y) { y = Y; }
void Fruit::placeFruit()
{
    gotoxy(x, y);cout << "\xFE";
}
