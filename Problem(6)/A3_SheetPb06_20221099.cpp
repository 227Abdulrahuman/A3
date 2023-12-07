// File name:A3_SheetPb06_20221099
// Purpose:Game_of_life_Simulator
// Author(s): Abdulrahaman Mohammed
// ID(s): 20221099
// Section:S5
// Date:7/12/2023

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class Universe{
    int temp[10][10];
    int arr[10][10];
    
public:
    //Generates Starting layouts
    void intialize(int i, int j) {
        arr[i][j] = 1;
    }
//Sets all cells to zero
    void reset() {
        for (int i = 0; i <10; i++)
            for(int j = 0; j <10; j++) {
                arr[i][j] = 0;
            }
    }
    //return all number of alive cells
    int count_alive() {
        int count{0};
        for (int i = 0; i <10; i++)
            for(int j = 0; j <10; j++) {
                if (arr[i][j] == 1)
                    count ++;
            }
        return count;
    }

bool is_valid(int x, int y) const{
    return x>0 && y>0 && x<10 && y<10;
}
    int count_neighbours(int cordx, int cordy) {

        int dx[] = {0, -1, 0, 1, 1, 1, -1, -1};
        int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};
        int cnt =0;
        for (int k = 0  ;k<8 ; k++) {
            int currx = cordx + dx[k], curry = cordy + dy[k];
            if(is_valid(currx,curry) && arr[currx][curry]){
                cnt++;
            }
        }
        return cnt;

    }

    //Produces the state of the next generation
    void next_generation() {
                for (int  i = 0; i < 10; i++) {
                    for (int j = 0 ; j < 10; j++) {
                        temp[i][j] = count_neighbours(i,j);
                    }
                }

                for (int i = 0; i < 10; i++) {
                    for(int j = 0; j < 10; j++) {
                        if (temp[i][j] == 3)    arr[i][j] = 1;
                        else if (temp[i][j] > 3) arr[i][j] = 0;
                        else if (temp[i][j] < 2) arr[i][j] = 0;
                    }
                }

            }

    //Shows the game status on the console after clearing the screen.
    void display() {
        cout << endl << endl << endl;
        for (int i = 0; i  < 10; i++) {
            for (int j = 0; j < 10;j++) {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }

    }
    //Start the game for certain number of truns.
    void run () {

       //Clear the Unviverse
       reset();

       //Initialize the alive cells;
       cout << "Enter the number of cells you want to make alive:  " << endl;
       int alive_cells;
       cin >> alive_cells;
       while (alive_cells--) {
           cout << "Enter the i, j coordinates of the cell: " << endl;
           int i, j;
           cin >> i >> j;
           intialize(i,j);
       }
//show Initial condition
       display();

    cout << "Enter number of turns" << endl;
    int turns; cin >> turns;

    while (turns--) {
        next_generation();
        display();
        cout << endl << endl;
        Sleep(2000);
    }




    }
};



int main () {
    Universe u;
    u.run();

}