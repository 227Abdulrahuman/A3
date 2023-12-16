
#ifndef A3_FIVEXFIVE_BOARD_H
#define A3_FIVEXFIVE_BOARD_H
#include "include/BoardGame_Classes.hpp"

class FiveXFive_Board: public Board{
public:
    int x_points = 0, o_points= 0;
    FiveXFive_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    void point_counter();
    bool Game_Identifier();
};




#endif
