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
const int height = 20;
const int width = 20;
int headX, headY, fruitX, fruitY, score, tail_len, tailY[100], tailX[100];

void setup()
{
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    tail_len = 0;
}
void draw()
{
    system("cls");
    cout << "\t\t";
    // top wall
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    // side walls , Snake and fruit
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // left wall
            if (j == 0)
            {
                cout << "\t\t#";
            }
            // Snake Head
            if (i == headY && j == headX)
            {
                cout << "W";
            }
            // fruit
            else if (i == fruitY && j == fruitX)
            {
                cout << "$";
            }
            // Space , Tail
            else
            {
                bool print = false;
                // Tail
                for (int k = 0; k < tail_len; k++)
                {
                    if (i == tailY[k] && j == tailX[k])
                    {
                        cout << "v";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout <<" ";
                }
            }
            // Right wall
            if (j == width - 1)
            {
                cout << "#";
                cout << endl;
            }
        }
    }

    // bottom wall
    cout << "\t\t";
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "\t\t" << "Score: " << score << endl;
    cout << "\t\t" << "Press 'x' to exit" << endl;
}
void input()
{
    if (_kbhit())

    {
        /* code */
  
    
    switch (getch())
    {
    case 'a':
        dir = LEFT;
        break;
    case 'd':
        dir = RIGHT;
        break;
    case 'w':

        dir = UP;
        break;
    case 's':
        dir = DOWN;
        break;
    case 'x':
        gameOver = true;
        break;
    default:
        break;
    }
}  }
void logic(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = headX;
    tailY[0] = headY;
    for (int i = 1; i < tail_len; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;


    }
    // Direction Logic
    switch (dir)
    {
    case LEFT:
        headX--;
        break;
    case RIGHT:
        headX++;
        break;
    case UP:
        headY--;
        break;
    case DOWN:
        headY++;
        break;
    default:
        break;
    }

    // Touch Wall
    if (headX>=width)
    {
        headX = 0;
    }
    else if (headX<0)
    {
        headX = width-1;
    }
    if (headY>=height)
    {
        headY = 0;
    }
    else if (headY<0)
    {
        headY = height-1;
    }

    // Touch Tail
    for (int i = 0; i < tail_len; i++)
    {
        if (tailX[i] == headX && tailY[i] == headY)
        {
            gameOver = true;
        }
    }
   
    // Touch Fruit
    if (headX == fruitX && headY == fruitY)
    {
        score += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tail_len++;
    }

    

}

int main()
{
    char start;

    cout << "\t---------------------------" << endl;
    cout << "\t\tSnake Game" << endl;
    cout << "\t---------------------------" << endl;
    cout << "\tPress any key to start the game" << endl;
    getch();
    // cin >> start;
    // if (start == 's')
    // {
    cout << "\tGame is starting" << endl;
    Sleep(20);
    setup();
    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(100);
        system("cls");
        // gameOver = true;
    }
    cout << "\tGame Over" << endl;
    cout << "\tYour Score is: " << score << endl;
    cout << "\tPress any key to exit" << endl;
    getch();    
    
    // }

    return 0;
}
