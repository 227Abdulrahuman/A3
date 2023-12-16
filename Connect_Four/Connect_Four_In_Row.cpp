

#include "Connect_Four_In_Row.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;

Connect_Four_In_Row::Connect_Four_In_Row () {
    n_rows = 6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool Connect_Four_In_Row::update_board(int x, int y, char mark) {
    if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0)) {
        while (x < n_rows - 1 && board[x + 1][y] == 0) {
            x++;
        }
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else {
        return false;
    }
}


void Connect_Four_In_Row::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------------------";
    }
    cout << endl;
}

bool Connect_Four_In_Row::is_winner() {
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols - 3; j++) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }

    for (int i = 0; i < n_rows - 3; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }

    for (int i = 0; i < n_rows - 3; i++) {
        for (int j = 0; j < n_cols - 3; j++) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] &&
                board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
            if (board[i][j + 3] != 0 &&
                board[i][j + 3] == board[i + 1][j + 2] &&
                board[i][j + 3] == board[i + 2][j + 1] &&
                board[i][j + 3] == board[i + 3][j]) {
                return true;
            }
        }
    }

    return false;
}


bool Connect_Four_In_Row::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Connect_Four_In_Row::game_is_over () {
    return n_moves >= 42;
}

bool Connect_Four_In_Row::Game_Identifier() {
    return 1;
}