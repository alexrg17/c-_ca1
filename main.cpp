// main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include "bug.h"
#include "board.h"
#include "crawler.h"
#include "hopper.h"

int main() {
    // Create a board object
    Board board;

    // Initialize the board from a file
    board.initializeBoardFromFile("/Users/alex/CLionProjects/cpp_ca1/bugs.txt");

    // Add a loop to continuously ask the user for input
    while (true) {
        std::cout << "Please enter an option (1: Display bug, 2: Display life history, 3: Move bug, 4: Kill bug, 5: Display board, 6: Tap board, 0: Exit): ";
        int option;
        std::cin >> option;

        if (option == 0) {
            break; // Exit the program
        } else if (option == 1) {
            std::cout << "Please enter the ID of the bug you want to display: ";
            int bugId;
            std::cin >> bugId;
            board.displayBugDetails(bugId);
        } else if (option == 2) {
            board.displayLifeHistory();
        } else if (option == 3) {
            std::cout << "Please enter the ID of the bug you want to move: ";
            int bugId;
            std::cin >> bugId;
            board.moveBug(bugId);
        } else if (option == 4) {
            std::cout << "Please enter the ID of the bug you want to kill: ";
            int bugId;
            std::cin >> bugId;
            board.killBug(bugId);
        } else if (option == 5) {
            board.displayBoard();
        } else if (option == 6) {
            board.tapBoard();
        }
    }

    return 0;
}
