//
// Created by Alex Radu on 12/04/2024.
//

#include "board.h"

#include "board.h"
#include <fstream>
#include <iostream>

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
        Bug* bug = new Bug(id, std::make_pair(x, y), dir, size);
        bugVector.push_back(bug);
    }

    file.close();
}
