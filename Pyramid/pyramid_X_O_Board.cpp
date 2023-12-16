//
// Created by gamme on 12/16/2023.
//

#include "pyramid_X_O_Board.h"

#include<iostream>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;

pyramid_X_O_Board::pyramid_X_O_Board() {
    n_rows =  3;
    n_cols =  5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool pyramid_X_O_Board::update_board(int x, int y, char mark){
    if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == 0)
        &&!((x==0 && y==0) || (x==0 && y==1) || (x==1 && y==0))
        &&!((x==0 && y==3) || (x==0 && y==4) || (x==1 && y==4))) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
void pyramid_X_O_Board::display_board(){
    for (int i: {0, 1, 2}) {
        cout << "\n";
        for (int j: {0, 1, 2}) {
            if(i == 0 && j== 0 || i == 0 && j== 1 || i == 1 && j==0  ){
                cout<<"         ";
            }
            else
            {
                if(i == 2 && j == 0 || i == 1 && j ==1 || i == 0 && j == 1 ) cout<<"|";
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] ;
                if(i == 0 && j == 2 ) cout<<"";
                else cout<<"|";
            }
        }
        for (int j: {3,4}) {
            if(i == 0 && j== 3 || i == 0 && j== 4 || i == 1 && j==4  ){
                cout<<"         ";
            }
            else
            {
                if(i == 2 && j == 0 || i == 1 && j ==1 || i == 0 && j == 1) cout<<"|";
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] ;
                if((i == 1 && j == 3) || (i == 2 && j==4) ) cout<<"";
                else cout<<"|";
            }
        }
        cout << "\n-------------------------------------------------";
    }
    cout << endl;
}
bool pyramid_X_O_Board::is_winner(){
    int winningConditions[7][3][2] = {
            {{0,2}, {1,2}, {2,2}},
            {{0,2}, {1,1}, {1,0}},
            {{0,2}, {1,3}, {2,4}},
            {{1,1}, {1,2}, {1,3}},
            {{2,0}, {2,1}, {2,2}},
            {{2,1},{2,2},{2,3}},
            {{2,2},{2,3},{2,4}}

    };
    for(int i=0 ; i<7 ; i++)
    {
        if(board[winningConditions[i][0][0]][winningConditions[i][0][1]] == board[winningConditions[i][1][0]][winningConditions[i][1][1]]
           && board[winningConditions[i][0][0]][winningConditions[i][0][1]] == board[winningConditions[i][2][0]][winningConditions[i][2][1]]
           && board[winningConditions[i][0][0]][winningConditions[i][0][1]] != 0)
            return true;
    }
    return false;
}
bool pyramid_X_O_Board::is_draw(){
    return (n_moves == 9 && !is_winner());
}
bool pyramid_X_O_Board::game_is_over(){
    return n_moves >= 9;
}

bool pyramid_X_O_Board::Game_Identifier() {
    return 1;
}