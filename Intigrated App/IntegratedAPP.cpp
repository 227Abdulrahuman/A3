#include "include/BoardGame_Classes.hpp"
#include "FiveXFive_Board.h"
#include "Connect_Four_In_Row.h"
#include "pyramid_X_O_Board.h"
#include <bits/stdc++.h>

using namespace std;

int main () {
    cout << "Enter choose the game you want to play: " << endl << endl;
    cout << "1)Normal XO" << endl;
    cout << "2)5x5 XO" << endl;
    cout << "3)ConnectFour" << endl;
    cout << "4)Pyramid" << endl;

    int Input; cin >> Input;

    if (Input == 1) {
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x');

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);

        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
        system ("pause");
    }
    else if (Input == 2) {
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x');

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 5);

        GameManager x_o_game (new FiveXFive_Board(), players);
        x_o_game.run();
        system ("pause");
    }

    else if (Input == 3) {
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x');

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 5);

        GameManager x_o_game (new Connect_Four_In_Row(), players);
        x_o_game.run();
        system ("pause");
    }
    else if (Input == 4) {
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x');

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);

        GameManager x_o_game (new pyramid_X_O_Board(), players);
        x_o_game.run();
        system ("pause");
    }

    else
        cout << "Invalid Choose" << endl;

}