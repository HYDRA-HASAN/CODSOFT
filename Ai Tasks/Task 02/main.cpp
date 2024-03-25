#include <iostream>
#include <climits>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void printBoard() {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 'X') {
                cout << "\033[1;31m" << board[i][j] << "\033[0m"; // Red color
            } else if (board[i][j] == 'O') {~
                cout << "\033[1;33m" << board[i][j] << "\033[0m"; // Orange color
            } else {
                cout << board[i][j];
            }
            cout << (j < 2 ? "|" : "");
        }
        cout << "\n" << (i < 2 ? "  -----\n" : "\n");
    }
}

bool checkWin(char player) {
    for (int i = 0; i < 3; ++i)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool isBoardFull() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

int evaluate() {
    for (int row = 0; row < 3; ++row) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == 'X')
                return 10;
            else if (board[row][0] == 'O')
                return -10;
        }
    }

    for (int col = 0; col < 3; ++col) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == 'X')
                return 10;
            else if (board[0][col] == 'O')
                return -10;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X')
            return 10;
        else if (board[0][0] == 'O')
            return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X')
            return 10;
        else if (board[0][2] == 'O')
            return -10;
    }

    return 0;
}

int minimax(int depth, bool isMax) {
    int score = evaluate();
    if (score == 10)
        return score - depth;
    if (score == -10)
        return score + depth;
    if (isBoardFull())
        return 0;

    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    best = max(best, minimax(depth + 1, !isMax));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    best = min(best, minimax(depth + 1, !isMax));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

void makeAIMove() {
    int bestMove = INT_MIN;
    int row, col;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                int moveVal = minimax(0, false);
                board[i][j] = ' ';
                if (moveVal > bestMove) {
                    row = i;
                    col = j;
                    bestMove = moveVal;
                }
            }
        }
    }
    board[row][col] = 'X';
}

int main() {
    char currentPlayer = 'O';
    while (true) {
        printBoard();
        if (currentPlayer == 'O') {
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            --row; --col;
            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                cout << "Invalid move! Try again.\n";
                continue;
            }
            board[row][col] = currentPlayer;
        } else {
            makeAIMove();
        }

        if (checkWin(currentPlayer)) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isBoardFull()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
    }
    return 0;
}