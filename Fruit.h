#ifndef FRUIT_H_INCLUDED
#define FRUIT_H_INCLUDED
typedef struct position
{
    int x;
    int y;
} position;
class Fruit
{
private:
    int x;
    int y;
public:

    Fruit(int xSnake,int ySnake);
    bool checkAxis(int* xSnake, int* ySnake, int snakeSize);
    int getxAxis();
    int getyAxis();
    void setxAxis(int X);
    void setyAxis(int Y);
    void placeFruit();
};

#endif // FRUIT_H_INCLUDED
