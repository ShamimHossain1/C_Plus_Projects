#include <iostream>
#include <conio.h> // For _kbhit() and _getch()
#include <windows.h> // For Sleep()

class SnakeGame {
private:
    int width, height;
    int x, y, fruitX, fruitY, score;
    int tailX[100], tailY[100];
    int tailLength;
    enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
    Direction dir;
    bool gameOver;

    void generateFruit() {
        fruitX = rand() % width;
        fruitY = rand() % height;
    }

public:
    SnakeGame(int w, int h) : width(w), height(h), score(0), tailLength(0), gameOver(false), dir(STOP) {
        x = width / 2;
        y = height / 2;
        generateFruit();
    }

    void draw() {
        system("cls");
        for (int i = 0; i < width + 2; ++i) std::cout << "#";
        std::cout << "\n";

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (j == 0) std::cout << "#";
                if (i == y && j == x)
                    std::cout << "O"; // Snake head
                else if (i == fruitY && j == fruitX)
                    std::cout << "F"; // Fruit
                else {
                    bool printTail = false;
                    for (int k = 0; k < tailLength; ++k) {
                        if (tailX[k] == j && tailY[k] == i) {
                            std::cout << "o"; // Snake body
                            printTail = true;
                        }
                    }
                    if (!printTail) std::cout << " ";
                }
                if (j == width - 1) std::cout << "#";
            }
            std::cout << "\n";
        }

        for (int i = 0; i < width + 2; ++i) std::cout << "#";
        std::cout << "\n";
        std::cout << "Score: " << score << "\n";
    }

    void input() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
            }
        }
    }

    void logic() {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;

        for (int i = 1; i < tailLength; ++i) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        switch (dir) {
        case LEFT: --x; break;
        case RIGHT: ++x; break;
        case UP: --y; break;
        case DOWN: ++y; break;
        default: break;
        }

        if (x >= width) x = 0; else if (x < 0) x = width - 1;
        if (y >= height) y = 0; else if (y < 0) y = height - 1;

        for (int i = 0; i < tailLength; ++i)
            if (tailX[i] == x && tailY[i] == y) gameOver = true;

        if (x == fruitX && y == fruitY) {
            ++score;
            ++tailLength;
            generateFruit();
        }
    }

    bool isGameOver() const {
        return gameOver;
    }

    int getScore() const {
        return score;
    }
};

int main() {
    SnakeGame game(20, 20);

    while (!game.isGameOver()) {
        game.draw();
        game.input();
        game.logic();
        Sleep(100); // Adjust speed of the game
    }

    std::cout << "Game Over! Final Score: " << game.getScore() << "\n";
    return 0;
}
