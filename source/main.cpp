#include <iostream>

using namespace std;

bool winnerDiag(int[][3]);
bool winnerCol(int[][3]);
bool winnerRow(int[][3]);
void play(int);
void printBoard();

int board[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
/*
 * 1 2 3
 * 4 5 6
 * 7 8 9
 */
char symbol = 0;

int main() {
        cout << "Would you like to use O or X?" << endl;
        cin >> symbol;

        return 0;
}
bool winnerDiag(int board[][3]) {
        for (int i = 0; i < 2; i++) {
                // The elements of the row are not all equal
                if (board[i][i] != board[i + 1][i + 1]) return false;
        }
        return true;
}
bool winnerCol(int board[][3]) {
        if ((board[0][0] != board[1][0] && board[1][0] != board[2][0]) &&
            (board[0][1] != board[1][1] && board[1][1] != board[2][1]) &&
            (board[0][2] != board[1][2] && board[1][2] != board[2][2]))
                // No columns with all equal symbols
                return false;
        return true;
}
bool winnerRow(int board[][3]) {
        if ((board[0][0] != board[0][1] && board[0][1] != board[0][2]) &&
            (board[1][0] != board[1][1] && board[1][1] != board[1][2]) &&
            (board[2][0] != board[2][1] && board[2][1] != board[2][2]))
                // There are no rows with all equal symbols
                return false;
        return true;
}
void play(int pos) {
        for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                        if (pos == j) {
                                // if the loop found the position requested,
                                // insert the symbol there.
                                board[i][j] = symbol;
                                return;
                        }
                }
}
