
#include <iostream>
#include <fstream>
#include <vector>
#include "bug.h"
#include "board.h"
#include "crawler.h"
#include "hopper.h"
#include <thread>
int main() {
    Board board;

    board.initializeBoardFromFile("/Users/alex/CLionProjects/cpp_ca1/bugs.txt");

    while (true) {
        std::cout
                << "Please enter an option (1: Display bug, 2: Display life history, 3: Move bug, 4: Kill bug, 5: Display board, 6: Tap board, 7: Write life history to file, 8: Run Simulation, 0: Exit): ";
        int option;
        std::cin >> option;

        if (option == 0) {
            break;
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
        } else if (option == 7) {
            board.writeLifeHistoryToFile();
        } else if (option == 8) {
            // Run simulation
            while (!board.isGameOver()) {
                board.tapBoard();
                board.displayBoard();
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }


            board.writeLifeHistoryToFile();

            std::cout << "Simulation ended. Results written to file." << std::endl;
            break;
        }
    }
}