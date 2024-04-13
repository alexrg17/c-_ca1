#include <iostream>
#include <fstream>
#include <vector>
#include "bug.h"
#include "board.h"
#include "crawler.h"
#include "hopper.h"

int main() {
    // Initialize the board and populate the bug vector from "bugs.txt"
    Board board;
    board.initializeBoardFromFile("bugs.txt");

    // Get the populated bug vector from the board
    std::vector<Bug*> bug_vector = board.getBugVector();

    // Display all bugs
    for (Bug* bug : bug_vector) {
        std::cout << bug->getId() << " " << (dynamic_cast<Crawler*>(bug) ? "Crawler" : "Hopper") << " "
                  << "(" << bug->getPosition().first << "," << bug->getPosition().second << ") "
                  << bug->getSize() << " " << static_cast<int>(bug->getDirection()) << " "
                  << (dynamic_cast<Hopper*>(bug) ? dynamic_cast<Hopper*>(bug)->getHopLength() : 0) << " "
                  << (bug->isAlive() ? "Alive" : "Dead") << std::endl;
    }

    // Move all bugs
    for (Bug* bug : bug_vector) {
        bug->move(); // Calls the appropriate move function based on the actual object type
    }

    // Find a bug by ID
    int bugId;
    std::cout << "Enter bug ID to find: ";
    std::cin >> bugId;
    board.displayBugDetails(bugId);

    // Free the memory
    for (Bug* bug : bug_vector) {
        delete bug;
    }

    return 0;
}
