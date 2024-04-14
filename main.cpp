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

    // Ask the user for the bug ID
    std::cout << "Please enter the ID of the bug you want to display: ";
    int bugId;
    std::cin >> bugId;

    // Display the details of the bug with the input ID
    board.displayBugDetails(bugId);

    // Display the life history of all bugs
    board.displayLifeHistory();

    return 0;
}
