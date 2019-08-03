#include <iostream>

using namespace std;

char board[][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// char board[][3] ={'1','2','3','4','5','6','7','8','9'};
// do some research to see how the above apparently works the same
/*
 * 1 2 3
 * 4 5 6
 * 7 8 9
 */

bool hasVal(char c) {
        // search the entire array (inefficient but works, this is quite a
        // simple project). This is O(n^2). Once the element has been found, we
        // can return true.
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        if (board[i][j] == c) return true;
                }
        }
        return false;
}

void printBoard() {
        // print the board state
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        cout << board[i][j] << " ";
                }
                cout << endl;
        }
}
