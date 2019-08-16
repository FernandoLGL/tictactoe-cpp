#include <iostream>
#include "board.h"

// Initial value of symbol is 'X' because 'X' is going to always start the game!
char symbol{'X'};

void togglePlayer() {
        // Pretty self explanatory
        if (symbol == 'X')
                symbol = 'O';
        else
                symbol = 'X';
}

void play(char pos) {
        // To play a symbol at the position passed as an argument, we search
        // through the entire array for the position (inefficient but works for
        // this simple exercise) and play the symbol at that position.
        for (short i{0}; i < 3; i++)
                for (short j{0}; j < 3; j++) {
                        if (pos == board[i][j]) {
                                // if the loop found the position requested,
                                // insert the symbol.
                                board[i][j] = symbol;
                                return;
                        }
                }
}

char winner() {
        // X WINS

        // Row win for X
        if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
                return 'X';
        if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
                return 'X';
        if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
                return 'X';

        // Column win for X
        if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
                return 'X';
        if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
                return 'X';
        if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
                return 'X';

        // Diagonal win for X
        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
                return 'X';
        if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
                return 'X';

        // O WINS

        // Row win for O
        if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
                return 'O';
        if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
                return 'O';
        if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
                return 'O';

        // Column win for O
        if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
                return 'O';
        if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
                return 'O';
        if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
                return 'O';

        // Diagonal win for O
        if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
                return 'O';
        if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
                return 'O';

        // There is no winner:
        return 0;
}
