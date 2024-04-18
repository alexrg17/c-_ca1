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
#include <thread>
#include <chrono>


Board::Board() {
    board = std::vector<std::vector<std::list<Bug*>>>(10, std::vector<std::list<Bug*>>(10));
}

Board::~Board() {
    for (Bug* bug : bugVector) {
        delete bug;
    }
}

void Board::initializeBoardFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        exit(1);
    }

    std::string line;
    std::pair<int, int> boardSize(10, 10);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char type;
        int id, x, y, size, extra;
        char delimiter;
        if (!(iss >> type >> delimiter >> id >> delimiter >> x >> delimiter >> y >> delimiter >> size >> delimiter >> extra)) { break; } // error

        std::pair<int, int> position(x, y);
        Direction direction = static_cast<Direction>(extra);
        if (type == 'C') {
            Bug* newBug = new Crawler(id, position, direction, size, boardSize, *this);
            bugVector.push_back(newBug);
            board[position.first][position.second].push_back(newBug);
        } else if (type == 'H') {
            Bug* newBug = new Hopper(id, position, direction, size, boardSize, *this, extra);
            bugVector.push_back(newBug);
            board[position.first][position.second].push_back(newBug);
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
        std::cout << "Location: (" << bug->getPosition().first << "," << bug->getPosition().second << ") ";
        std::cout << "Size: " << bug->getSize() << " ";
        std::string direction;
        switch (bug->getDirection()) {
            case Direction::North:
                direction = "North";
                break;
            case Direction::East:
                direction = "East";
                break;
            case Direction::South:
                direction = "South";
                break;
            case Direction::West:
                direction = "West";
                break;
        }
        std::cout << "Direction: " << direction << " ";
        if (const Hopper* hopper = dynamic_cast<const Hopper*>(bug)) {
            std::cout << "HopLength: " << hopper->getHopLength() << " ";
        }
        std::cout << (bug->isAlive() ? "Alive!" : "Dead!") << std::endl;
    }
}

void Board::moveBug(int bugId) {
    Bug* bugToMove = nullptr;
    for (Bug* bug : bugVector) {
        if (bug->getId() == bugId) {
            bugToMove = bug;
            break;
        }
    }

    if (bugToMove == nullptr) {
        std::cout << "No bug found with ID " << bugId << std::endl;
        return;
    }

    if (bugToMove->isAlive()) {
        std::pair<int, int> oldPosition = bugToMove->getPosition();
        std::pair<int, int> newPosition = bugToMove->move();

        std::cout << "Moving bug " << bugId << " from (" << oldPosition.first << ", " << oldPosition.second << ") to (" << newPosition.first << ", " << newPosition.second << ")" << std::endl;

        // Update the board
        board[oldPosition.first][oldPosition.second].remove(bugToMove);
        board[newPosition.first][newPosition.second].push_back(bugToMove);

        // Update the bug's internal position
        bugToMove->setPosition(newPosition);
    }
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
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << "(" << i << "," << j << "): ";
            if (board[i][j].empty()) {
                std::cout << "empty";
            } else {
                for (Bug* bug : board[i][j]) {
                    if (bug->isAlive()) {
                        std::cout << (dynamic_cast<Crawler*>(bug) ? "Crawler " : "Hopper ") << bug->getId() << ", ";
                    }
                }
            }
            std::cout << std::endl;
        }
    }
}

Bug* Board::getBugAtPosition(std::pair<int, int> position) const {
    for (Bug* bug : bugVector) {
        if (bug->getPosition() == position && bug->isAlive()) {
            return bug;
        }
    }
    return nullptr;
}

void Board::tapBoard() {
    // Move all bugs first
    for (Bug* bug : bugVector) {
        if (bug->isAlive()) {
            std::pair<int, int> oldPosition = bug->getPosition();
            std::pair<int, int> newPosition = bug->move();
            board[oldPosition.first][oldPosition.second].remove(bug);
            board[newPosition.first][newPosition.second].push_back(bug);
        }
    }

    // Perform fights after all bugs have moved
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (board[i][j].size() > 1) { // If more than one bug in the cell
                std::vector<Bug*> bugsInCell(board[i][j].begin(), board[i][j].end());
                std::sort(bugsInCell.begin(), bugsInCell.end(), [](Bug* a, Bug* b) {
                    return a->getSize() > b->getSize();
                });

                // The largest bug eats all other bugs of smaller size
                for (size_t k = 1; k < bugsInCell.size(); ++k) {
                    if (bugsInCell[0]->getSize() == bugsInCell[k]->getSize()) {
                        // If the bugs are the same size, one of them randomly dies
                        if (rand() % 2 == 0) {
                            bugsInCell[0]->kill();
                            bugsInCell[k]->grow(bugsInCell[0]->getSize());
                        } else {
                            bugsInCell[k]->kill();
                            bugsInCell[0]->grow(bugsInCell[k]->getSize());
                        }
                        continue;
                    }
                    bugsInCell[0]->grow(bugsInCell[k]->getSize());
                    bugsInCell[k]->kill();
                }

                // Remove dead bugs from the cell
                std::list<Bug*> temp;
                for (Bug* bug : board[i][j]) {
                    if (bug->isAlive()) {
                        temp.push_back(bug);
                    }
                }
                board[i][j] = temp;
            }
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

bool Board::isGameOver() const {
    for (const Bug* bug : bugVector) {
        if (bug->isAlive()) {
            return false; // If any bug is alive, the game is not over
        }
    }
    return true; // If no bugs are alive, the game is over
}