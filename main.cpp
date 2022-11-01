#include<iostream>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include"Fruit.c"
#include"Snake.c"
using namespace::std;
void gotoxy(int x, int y)
{
    COORD coor;
    coor.X = x;
    coor.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
}
void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
int PositionAccordingActualCoordinatesX(int& xSnake)
{
    if(xSnake == 120)
         xSnake = 0;
    else if(xSnake == 0)
          xSnake= 120;
}
int PositionAccordingActualCoordinatesY(int& ySnake)
{
    if(ySnake == 0)
        ySnake = 30;
    else if(ySnake == 30)
        ySnake = 0;
}
int main()
{
 Debut:
    Snake s;
    int up = 0;
    int left = 0;
    int down = 0;
    int right = 0;
    hidecursor();
    s.initialiseSnake();
    Fruit f(s.x[0],s.y[0]);
    char key = 0;
    while (1)
    {
        if (kbhit())
        {
            key = _getch();
        }
        s.captureOldestPosition();
        switch (tolower(key))
        {
        case 'z':
        {
            if (down == 0)
            {
                s.turnSnakeUp();
                up = 1;
                left = right = 0;
            }
            else s.turnSnakeDown();
        } break;
        case 'q':
        {
            if (left == 0)
            {
                s.turnSnakeLeft();
                right = 1;
                up = down = 0;
            }
            else s.turnSnakeRight();
        } break;
        case 'd':
        {
            if (right == 0)
            {
                s.turnSnakeRight();
                left = 1;
                up = down = 0;
            }
            else s.turnSnakeLeft();
        } break;
        case 's':
        {
            if (up == 0)
            {
                s.turnSnakeDown();
                down = 1;
                left = right = 0;
            }
            else s.turnSnakeUp();
        }
        }
        if (!s.touchSnake(s.x[0], s.y[0]))
            s.moveSnake(&f);
        else
        {
            cout << "game over";
            _getch();
            goto Debut;
        }
        if (s.touchEdgeScreen(s.x[0], s.y[0]))
        {
            PositionAccordingActualCoordinatesX(s.x[0]);
            PositionAccordingActualCoordinatesY(s.y[0]);
        }
        f.placeFruit();
        Sleep(10);
        s.afficher();
        system("cls");
    }
    return 0;
}
