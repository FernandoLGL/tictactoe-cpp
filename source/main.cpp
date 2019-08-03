// TODO
// Check for draws //DONE
// Clear screen //DONE
// Deal with errors
#include <iostream>

using namespace std;

char winner();
void play(char);
void printBoard();
void togglePlayer();
bool draw();

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
        system("clear");
        char choice = 0;
        cout << "Player X starts!" << endl;
        short total_plays = 0;
        while (!winner()) {
                if (total_plays == 9) {
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
                play(choice);
                total_plays += 1;
                /*if (draw()){
                        cout << "Draw!" << endl;
                        return 0;
                }*/
                togglePlayer();
                system("clear");
        }

        system("clear");
        printBoard();
        cout << "Player " << winner() << " wins!" << endl;
        system("pause");
        return 0;
}
/*
bool draw() {
        short total_plays = 0;
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        // checking if the element is not a number
                        if (board[i][j] <= 48 || board[i][j] > 57)
                                total_plays += 1;
                }
        }

        if (total_plays == 9) return true;
        return false;
}
*/
// a smarter way to check the draw was done.
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
