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
int up;
int down;
int left_;
int right_;

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
    char key = 'd';
    while (!gameOver)
    {
        if (kbhit())
        {
            key = _getch();
        }
        if(!s.touchSnake(s.x[0],s.y[0]))
            s.moveSnake(&f,key,up,down,left_,right_);
        else
        {
            cout << "game over";
            sleep(10);
            _getch();
            gameOver = true;
            goto Debut;
        }
        s.PositionAccordingActualCoordinatesX(s.x[0],s.y[0]);
        f.placeFruit();
        //setting the speed of snake :
        Sleep(1);
        system("cls");
    }
    return 0;
}
