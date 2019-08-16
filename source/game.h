#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

// Represents the current symbol
extern char symbol;

/**
 * Function that returns the winner if there is one
 * @return 0(False),'X','O'
 */
char winner();

/**
 * Play the current symbol at the position passed as an argument
 */
void play(char);

/**
 * Toggle the player. If the current player is 'X', now it's 'O's turn
 */
void togglePlayer();

#endif
