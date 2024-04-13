
#include "board.h"
#include "crawler.h"
#include "hopper.h"

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

void Board::displayBugDetails(int bugId) const {
    bool found = false;
    for (const Bug* bug : bugVector) {
        if (bug->getId() == bugId) {
            found = true;
            std::cout << "Bug " << bugId << " found. Details:" << std::endl;
            std::cout << "ID: " << bug->getId() << std::endl;
            std::cout << "Type: " << (dynamic_cast<const Crawler*>(bug) ? "Crawler" : "Hopper") << std::endl;
            std::cout << "Location: (" << bug->getPosition().first << "," << bug->getPosition().second << ")" << std::endl;
            std::cout << "Size: " << bug->getSize() << std::endl;
            std::cout << "Direction: " << static_cast<int>(bug->getDirection()) << std::endl;
            if (dynamic_cast<const Hopper*>(bug)) {
                std::cout << "Hop Length: " << dynamic_cast<const Hopper*>(bug)->getHopLength() << std::endl;
            }
            std::cout << "Status: " << (bug->isAlive() ? "Alive" : "Dead") << std::endl;
            break;
        }
    }
    if (!found) {
        std::cout << "Bug " << bugId << " not found." << std::endl;
    }
}

void Board::displayLifeHistory() const {
    for (const Bug* bug : bugVector) {
        std::cout << "Bug " << bug->getId() << " Path: ";
        const std::list<std::pair<int, int>>& path = bug->getPath();
        for (const auto& pos : path) {
            std::cout << "(" << pos.first << "," << pos.second << "),";
        }
        std::cout << " " << (bug->isAlive() ? "Alive!" : "Dead") << std::endl;
    }
}
