#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

Direction dir;
bool gameOver;
const int height = 40;
const int width = 50;
int headX, headY, fruitX, fruitY, score, tail_len, tailY[100], tailX[100];
void setup()
{
}

main()
{

    cout << "\t---------------------------" << endl;
    cout << "\t\tSnake Game" << endl;
    cout << "\t---------------------------" << endl;
    cout << "\tPress any key to start the game" << endl;
    getch();
    cout << "\tGame is starting" << endl;
    Sleep(20);
    setup();

    return 0;
}