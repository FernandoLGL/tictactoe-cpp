// TODO
// Check for draws //DONE
// Clear screen //DONE
// Deal with errors //DONE
// A player can't play at a position which was already played at //DONE
// Organize the files a bit better (header files)
#include <iostream>
#include <limits>
#include "game.h"
#include "board.h"

// This is a project I'm doing to study what I've learned by now in C++.
// Therefore it doesn't include OOP as I haven't studied how C++ deals with OOP.

using namespace std;

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
