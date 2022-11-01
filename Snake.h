#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

//creating snake class :
class Snake
{
    //the snake size will be 1 by default and it will be incremented when the snake eats a fruit :

public:
    int snakeSize__;
    int x[1000];
    int y[1000];
    //constructor :
    Snake();
    //storing the x and y positions within the console :
    void initialiseSnake();
    void Draw(int x, int y);
    void turnSnakeRight();
    void turnSnakeLeft();
    void turnSnakeUp();
    void turnSnakeDown();
    //moving the snake :
    void captureOldestPosition();
    void moveSnake(Fruit* f);
    bool touchSnake(int x_, int y_);
    bool touchEdgeScreen(int x_, int y_);
    void afficher();
    //Destructor :
    ~Snake() {};
};
#endif // SNAKE_H_INCLUDED
