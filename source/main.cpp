// TODO
// Check for draws //DONE
// Clear screen //DONE
// Deal with errors //DONE
// A player can't play at a position which was already played at //DONE
// Organize the files a bit better (header files)
#include <iostream>
#include <limits>

// This is a project I'm doing to study what I've learned by now in C++.
// Therefore it doesn't include OOP as I haven't studied how C++ deals with OOP.

using namespace std;

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
 * Print the current board state on the screen
 */
void printBoard();
/**
 * Toggle the player. If the current player is 'X', now it's 'O's turn
 */
void togglePlayer();
/**
 * Checks if the board has a value in it
 * @return bool
 */
bool hasVal(char);

char board[][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// char board[][3] ={'1','2','3','4','5','6','7','8','9'};
// do some research to see how the above apparently works the same
/*
 * 1 2 3
 * 4 5 6
 * 7 8 9
 */
char symbol = 'X';
// X goes first

int main() {
        system("clear");
        char choice = 0;
        cout << "Player X starts!" << endl << endl;
        short total_plays = 0;
        while (!winner()) {
                if (total_plays == 9) {
                        // if there were 9 plays already but there are no
                        // winners then it is a draw.
                        system("clear");
                        printBoard();
                        cout << "Draw!" << endl;
                        return 0;
                }
                cout << "Player " << symbol << "'s turn!" << endl;
                cout << "What's the position you want to play at?" << endl;
                cout << "Please say the correspondent number!" << endl;
                printBoard();
                cin >> choice;
                while ((choice < 49 || choice > 57) || !hasVal(choice)) {
                        // if the choice isn't a character '1' to '9' or isn't
                        // in the board anymore(already has been played), it
                        // isn't a valid play. So we can't proceed to increment
                        // total_plays yet or else we might get a draw sooner
                        // than expected.
                        cout << "Please enter a valid position (1-9) and make "
                                "sure it hasn't been played yet."
                             << endl;
                        // cleaning the cin state and stream
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cin >> choice;
                }
                // When everything is fine, we can finally proceed to play and
                // increase the total plays.
                play(choice);
                total_plays += 1;
                // After everything has been done, it is now the opponent's
                // turn. So we change the current player.
                togglePlayer();
                system("clear");
        }

        // at the end show the board and who won.
        system("clear");
        printBoard();
        cout << "Player " << winner() << " wins!" << endl;
        // system("pause");
        return 0;
}
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
void togglePlayer() {
        // Pretty self explanatory
        if (symbol == 'X')
                symbol = 'O';
        else
                symbol = 'X';
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

        // no winner
        return 0;
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
void play(char pos) {
        // search through the entire array for the position (inefficient but
        // works for this simple exercise) and plays the symbol at that
        // position.
        for (short i = 0; i < 3; i++)
                for (short j = 0; j < 3; j++) {
                        if (pos == board[i][j]) {
                                // if the loop found the position requested,
                                // insert the symbol.
                                board[i][j] = symbol;
                                return;
                        }
                }
}
