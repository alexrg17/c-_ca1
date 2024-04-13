#include "board.h"
#include <fstream>
#include <iostream>
#include "board.h"
#include "crawler.h" // Include the header file for the Crawler class
#include "hopper.h" // Include the header file for the Hopper class

Board::Board() {}

Board::~Board() {
    // Free the memory of bugs in the vector
    for (Bug* bug : bugVector) {
        delete bug;
    }
}

void Board::initializeBoardFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    int id, x, y, direction, size;
    while (file >> id >> x >> y >> direction >> size) {
        Direction dir = static_cast<Direction>(direction);
        Bug* bug;
        if (dir == Direction::North || dir == Direction::South) {
            bug = new Crawler(id, std::make_pair(x, y), dir, size);
        } else {
            bug = new Hopper(id, std::make_pair(x, y), dir, size, 3); // Assuming hop length is 3
        }
        bugVector.push_back(bug);
    }

    file.close();
}

std::vector<Bug*> Board::getBugVector() const {
    return bugVector;
}
