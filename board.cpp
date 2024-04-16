#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "bug.h"
#include "board.h"
#include "crawler.h"
#include "hopper.h"

Board::Board() {}

Board::~Board() {
    for (Bug* bug : bugVector) {
        delete bug;
    }
}

void Board::initializeBoardFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        exit(1); // call system to stop if file not found
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char type;
        int id, x, y, size, extra;
        char delimiter;
        if (!(iss >> type >> delimiter >> id >> delimiter >> x >> delimiter >> y >> delimiter >> size >> delimiter >> extra)) { break; } // error

        std::pair<int, int> position(x, y);
        Direction direction = static_cast<Direction>(extra);
        if (type == 'C') {
            bugVector.push_back(new Crawler(id, position, direction, size));
        } else if (type == 'H') {
            bugVector.push_back(new Hopper(id, position, direction, size, extra));
        }
    }

    file.close();
}

std::vector<Bug*> Board::getBugVector() const {
    return bugVector;
}

void Board::displayBugDetails(int bugId) const {
    for (const Bug* bug : bugVector) {
        if (bug->getId() == bugId) {
            std::cout << "Bug ID: " << bug->getId() << std::endl;
            std::cout << "Position: (" << bug->getPosition().first << ", " << bug->getPosition().second << ")" << std::endl;
            std::cout << "Size: " << bug->getSize() << std::endl;
            std::cout << "Alive: " << (bug->isAlive() ? "Yes" : "No") << std::endl;
            // Add more details as needed...
            return;
        }
    }
    std::cout << "No bug found with ID " << bugId << std::endl;
}

void Board::displayLifeHistory() const {
    for (const Bug* bug : bugVector) {
        std::cout << bug->getId() << " ";
        if (dynamic_cast<const Crawler*>(bug)) {
            std::cout << "Crawler ";
        } else if (dynamic_cast<const Hopper*>(bug)) {
            std::cout << "Hopper ";
        }
        std::cout << "Path: ";
        for (const auto& position : bug->getPath()) {
            std::cout << "(" << position.first << "," << position.second << "),";
        }
        std::cout << " " << (bug->isAlive() ? "Alive!" : "Dead!") << std::endl;
    }
}

void Board::moveBug(int bugId) {
    for (Bug* bug : bugVector) {
        if (bug->getId() == bugId) {
            if (bug->isWayBlocked()) {
                std::cout << "Bug " << bugId << " cannot move" << std::endl;
            } else {
                // Remove the bug from its current cell
                board[bug->getPosition()].erase(std::remove(board[bug->getPosition()].begin(), board[bug->getPosition()].end(), bug), board[bug->getPosition()].end());

                // Move the bug
                bug->move();

                // Add the bug to its new cell
                board[bug->getPosition()].push_back(bug);

                std::cout << "Bug " << bugId << " has moved to (" << bug->getPosition().first << ", " << bug->getPosition().second << ")" << std::endl;
            }
            return;
        }
    }
    std::cout << "No bug found with ID " << bugId << std::endl;
}

void Board::killBug(int bugId) {
    for (Bug* bug : bugVector) {
        if (bug->getId() == bugId) {
            if (!bug->isAlive()) {
                std::cout << "Bug " << bugId << " is already dead" << std::endl;
            } else {
                bug->kill();
                std::cout << "Bug " << bugId << " has been killed" << std::endl;
            }
            return;
        }
    }
    std::cout << "No bug found with ID " << bugId << std::endl;
}

void Board::displayBoard() const {
    // Assuming the board is a 10x10 grid
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            Bug* bug = getBugAtPosition(std::make_pair(i, j));
            if (bug != nullptr) {
                std::cout << bug->getId() << " ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

Bug* Board::getBugAtPosition(std::pair<int, int> position) const {
    for (Bug* bug : bugVector) {
        if (bug->getPosition() == position) {
            return bug;
        }
    }
    return nullptr;
}

void Board::tapBoard() {
    for (Bug* bug : bugVector) {
        if (bug->isAlive()) {
            bug->move();
        }
    }
}

void Board::writeLifeHistoryToFile() const {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S");
    auto str = oss.str();

    std::ofstream file("bugs_life_history_" + str + ".out");
    if (!file) {
        std::cerr << "Unable to open file for writing" << std::endl;
        return;
    }

    for (const Bug* bug : bugVector) {
        file << bug->getId() << " ";
        if (dynamic_cast<const Crawler*>(bug)) {
            file << "Crawler ";
        } else if (dynamic_cast<const Hopper*>(bug)) {
            file << "Hopper ";
        }
        file << "Path: ";
        for (const auto& position : bug->getPath()) {
            file << "(" << position.first << "," << position.second << "),";
        }
        file << " " << (bug->isAlive() ? "Alive!" : "Dead!") << std::endl;
    }

    file.close();
}
