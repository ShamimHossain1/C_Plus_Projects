#include <iostream>
#include <vector>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() {
        std::cout << "\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << " " << board[i][j];
                if (j < 2) std::cout << " |";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "---|---|---\n";
        }
        std::cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }

        return false;
    }

    bool isDraw() {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;
    int row, col;

    std::cout << "Welcome to Tic-Tac-Toe!\n";
    game.displayBoard();

    while (true) {
        std::cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (game.makeMove(row - 1, col - 1)) {
            game.displayBoard();

            if (game.checkWin()) {
                std::cout << "Player " << game.getCurrentPlayer() << " wins!\n";
                break;
            }

            if (game.isDraw()) {
                std::cout << "It's a draw!\n";
                break;
            }

            game.switchPlayer();
        }
    }

    return 0;
}
