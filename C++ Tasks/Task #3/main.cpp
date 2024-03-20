//TIC-TAC-TOE 
#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void printBoard() {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 'X') {
                cout << "\033[1;31m" << board[i][j] << "\033[0m"; // Red color
            } else if (board[i][j] == 'O') {
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

int main() {
    char currentPlayer = 'X';
    while (true) {
        printBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        --row; --col;
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        board[row][col] = currentPlayer;
        if (checkWin(currentPlayer)) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        bool isBoardFull = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    isBoardFull = false;
                    break;
                }
            }
            if (!isBoardFull) break;
        }
        if (isBoardFull) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X' ? 'O' : 'X');
    }
    return 0;
}