//TODO
//Check for draws
//Clear screen 
//Deal with errors
#include <iostream>

using namespace std;

char winner();
void play(char);
void printBoard();
void togglePlayer();

char board[][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// char board[][3] ={'1','2','3','4','5','6','7','8','9'};
// do some research to see how the above apparentlyworks the same
/*
 * 1 2 3
 * 4 5 6
 * 7 8 9
 */
char symbol = 'X';
// X goes first

int main() {
        char choice = 0;
        cout << "Player X starts!";
        while (!winner()) {
                cout << "Player " << symbol << "'s turn!" << endl;
                cout << "What's the position you want to play at?" << endl;
                cout << "Please say the correspondent number!" << endl;
                printBoard();
                cin >> choice;
                play(choice);
                togglePlayer();
        }

        cout << "Player " << winner() << " wins!" << endl;
        system("pause");
        return 0;
}
void togglePlayer() {
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
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        cout << board[i][j] << " ";
                }
                cout << endl;
        }
}
void play(char pos) {
        for (short i = 0; i < 3; i++)
                for (short j = 0; j < 3; j++) {
                        if (pos == board[i][j]) {
                                // if the loop found the position requested,
                                // insert the symbol there.
                                board[i][j] = symbol;
                                return;
                        }
                }
}
