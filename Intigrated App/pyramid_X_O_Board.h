
#ifndef A3_PYRAMID_X_O_BOARD_H
#define A3_PYRAMID_X_O_BOARD_H
#include "include/BoardGame_Classes.hpp"

class pyramid_X_O_Board :public Board {
public:
    pyramid_X_O_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    bool Game_Identifier();
};
#endif //A3_PYRAMID_X_O_BOARD_H
