
#include "FiveXFive_Board.h"
#include <bits/stdc++.h>
using namespace std;

// Set the board
FiveXFive_Board::FiveXFive_Board() {
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool FiveXFive_Board::update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;

}
// Display the board and the pieces on it
void FiveXFive_Board::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
bool FiveXFive_Board::is_draw() {
    return (n_moves == 24 && !is_winner());
}

bool FiveXFive_Board::game_is_over() {
    return n_moves >= 24;
}

void FiveXFive_Board::point_counter() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 'X') {
                int counter = 1;
                int temp = j + 1;
                while ((counter < 3) and (temp < 5) and (board[i][temp] == board[i][j])) {
                    counter++;
                    temp++;
                }
                if (counter == 3) {
                    x_points++;
                }
            }
            if (board[i][j] == 'O') {
                int counter = 1;
                int temp = j + 1;
                while ((counter < 3) and (temp < 5) and (board[i][temp] == board[i][j])) {
                    counter++;
                    temp++;
                }
                if (counter == 3) {
                    o_points++;
                }
            }
        }
    }
    //for comlumns

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 'X') {
                int c = 1;
                int q = i+1;
                while ((c < 3) and (q < 5) and (board[q][j] == board[i][j])) {
                    c++; q++;
                }
                if (c == 3) {
                    x_points++;
                }
            }
            if (board[i][j] == 'O') {
                int c = 1;
                int q = i+1;
                while ((c < 3) and (q < 5) and (board[q][j] == board[i][j])) {
                    c++; q++;
                }
                if (c == 3) {
                    o_points++;
                }
            }
        }
    }

    //Diaganolas
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((board[i][j] == board[i + 1][j + 1]) and (board[i][j] == board[i+2][j+2])) {
                if (board[i][j] == 'X') {
                    x_points++;
                }
                else if (board[i][j] == 'O') {
                    o_points++;
                }
            }
        }
    }
    //Other diag

    for (int  i = 2; i < 5; i++) {
        for (int  j = 0; j < 3; j++) {
            if ((board[i][j] == board[i - 1][j+1]) and (board[i][j] == board[i-2][j+2])) {
                if (board[i][j] == 'X') {
                    x_points++;
                }
                else if (board[i][j] == 'O') {
                    o_points++;
                }
            }
        }
    }
}


bool FiveXFive_Board::Game_Identifier() {
    return 0;
}


bool FiveXFive_Board::is_winner() {
   if (n_moves >= 24) {
       point_counter();
       if (x_points > o_points)
           return 1;


   }
   return false;
}
