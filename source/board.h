#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

//declaring the board itself
extern char board[][3];

/**
 * Print the current board state on the screen
 */
void printBoard();

/**
 * Checks if the board has a value in it
 * @return bool
 */
bool hasVal(char);

#endif
