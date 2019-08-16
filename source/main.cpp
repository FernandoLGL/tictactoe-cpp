#include <iostream>
#include <limits>
#include "board.h"
#include "game.h"

// This is a project I'm doing to study what I've learned by now in C++.
// Therefore it doesn't include OOP as I haven't studied how C++ deals with OOP.

// Please note that this version (v1.3) uses system() and therefore is unsafe
// and overall bad

// Doing this is not encouraged.
// using namespace std;

// if the user is using Windows, the "clear" command should be "cls"
#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)

#define CLEAR_COMMAND "cls"

#else

#define CLEAR_COMMAND "clear"

#endif

int main() {
        // Clearing the screen (Linux/MacOS)
        system(CLEAR_COMMAND);
        char choice{0};
        std::cout << "Player X starts!" << '\n' << '\n';
        // The game just started so there has been 0 plays.
        short total_plays{0};
        while (!winner()) {
                // total_plays is only equal to 9 when the entire board has been
                // used. This "if" statement will only run when there are no
                // winners and every board position has been filled (Draw)
                if (total_plays == 9) {
                        system(CLEAR_COMMAND);
                        printBoard();
                        std::cout << "Draw!" << '\n';
                        return 0;
                }
                std::cout << "Player " << symbol << "'s turn!" << '\n';
                std::cout << "What's the position you want to play at?" << '\n';
                std::cout << "Please say the correspondent number!" << '\n';
                printBoard();
                std::cin >> choice;
                // if the choice isn't a character '1' to '9' or isn't
                // in the board anymore(already has been played), it
                // isn't a valid play. So we can't proceed to increment
                // total_plays yet or else we might get a draw sooner
                // than expected (because total_plays will be incremented).
                while ((choice < 49 || choice > 57) || !hasVal(choice)) {
                        std::cout
                            << "Please enter a valid position (1-9) and make "
                               "sure it hasn't been played yet."
                            << '\n';
                        // cleaning the cin state and stream so it doesn't
                        // behave in an unintended way.
                        std::cin.clear();
                        std::cin.ignore(
                            std::numeric_limits<std::streamsize>::max(), '\n');

                        std::cin >> choice;
                }
                // When everything is fine, we can finally proceed to play and
                // increase the total plays.
                play(choice);
                total_plays += 1;
                // After everything has been done, it is now the opponent's
                // turn. So we change the current player.
                togglePlayer();
                system(CLEAR_COMMAND);
        }

        // at the end show the board and who won.
        system(CLEAR_COMMAND);
        printBoard();
        std::cout << "Player " << winner() << " wins!" << '\n';
        return 0;
}
