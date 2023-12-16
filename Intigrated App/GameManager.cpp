// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"include/BoardGame_Classes.hpp"
#include "FiveXFive_Board.h"
using namespace std;

GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->Game_Identifier() == 1) {
                if (boardPtr->is_winner()) {
                    cout << players[i]->to_string() << " wins\n";
                    return;
                }
                if (boardPtr->is_draw()) {
                    cout << "Draw!\n";
                    return;
                }
            }

        }
    }
    if (boardPtr->Game_Identifier() == 0) {
        if (boardPtr->is_winner() == 1) {
            cout << "X wins ^^" << endl;
        }
        else if (boardPtr->is_draw())       cout << "DRAW" << endl;
            else
                cout <<"O wins" << endl;
    }
}
