//
// Created by gamme on 12/16/2023.
//

#ifndef A3_CONNECT_FOUR_IN_ROW_H
#define A3_CONNECT_FOUR_IN_ROW_H
#include "include/BoardGame_Classes.hpp"

class Connect_Four_In_Row : public Board {
public:
Connect_Four_In_Row();
bool update_board (int x, int y, char mark);
void display_board();
bool is_winner();
bool is_draw();
bool game_is_over();
bool Game_Identifier();
};

#endif //A3_CONNECT_FOUR_IN_ROW_H
