#include <iostream>

// Discouraged
// using namespace std;

char board[][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
/*
 * 1 2 3
 * 4 5 6
 * 7 8 9
 */

bool hasVal(char c) {
        // search the entire array (inefficient but works, this is quite a
        // simple project). This is O(n^2). Once the element has been found, we
        // can return true.
        for (short i{0}; i < 3; i++) {
                for (short j{0}; j < 3; j++) {
                        if (board[i][j] == c) return true;
                }
        }
        return false;
}

void printBoard() {
        // We print the board by printing every value in the "board" list while
        // creating a new line every 3 values.
        for (short i{0}; i < 3; i++) {
                for (short j{0}; j < 3; j++) {
                        std::cout << board[i][j] << ' ';
                }
                std::cout << '\n';
        }
}
