#include <iostream>
#include <fstream>
#include <vector>
#include "bug.h"
#include "crawler.h"
#include "hopper.h"
#include "board.h"

int main() {
    // Initialize the board and populate the bug vector from "bugs.txt"
    Board board;
    board.initializeBoardFromFile("bugs.txt");

    // Get the populated bug vector from the board
    std::vector<Bug*> bug_vector = board.getBugVector();

    // Move all bugs
    for (Bug* bug : bug_vector) {
        bug->move(); // Calls the appropriate move function based on the actual object type
    }

    // Free the memory
    for (Bug* bug : bug_vector) {
        delete bug;
    }

    return 0;
}
