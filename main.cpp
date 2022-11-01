#include<iostream>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include"Fruit.c"
#include"Snake.c"
using namespace::std;
bool gameOver;
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

int main()
{
 Debut:
    Snake s;

    hidecursor();
    s.initialiseSnake();
    Fruit f(s.x[0],s.y[0]);
    char key = 0;
    while (!gameOver)
    {
        if (kbhit())
        {
            key = _getch();
        }
        s.captureOldestPosition();
        if (!s.touchSnake(s.x[0], s.y[0]))
            s.moveSnake(&f,key);
        else
        {
            cout << "game over";
            _getch();
            gameOver = true;
            goto Debut;
        }
        s.PositionAccordingActualCoordinatesX(s.x[0],s.y[0]);
        f.placeFruit();
        Sleep(10);
        system("cls");
    }
    return 0;
}
