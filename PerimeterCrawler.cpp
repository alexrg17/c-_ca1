// PerimeterCrawler.cpp
#include "PerimeterCrawler.h"
#include "bug.h"

PerimeterCrawler::PerimeterCrawler(int id, std::pair<int, int> position, Direction direction, int size, std::pair<int, int> boardSize, Board& board)
        : Bug(id, position, direction, size, boardSize, board) {}

std::pair<int, int> PerimeterCrawler::move() {
    if (position.first == 0 && direction == Direction::North ||
        position.second == boardSize.second - 1 && direction == Direction::East ||
        position.first == boardSize.first - 1 && direction == Direction::South ||
        position.second == 0 && direction == Direction::West) {
        changeDirection();
    }

    // Implement the logic to move the bug here
    // For example, if the bug moves one step in the current direction:
    switch (direction) {
        case Direction::North:
            position.first--;
            break;
        case Direction::East:
            position.second++;
            break;
        case Direction::South:
            position.first++;
            break;
        case Direction::West:
            position.second--;
            break;
    }

    // After moving, add the new position to the path
    path.push_back(position);

    return position;
}

void PerimeterCrawler::changeDirection() {
    if (position.first == 0 && direction == Direction::North) {
        direction = Direction::East;
    } else if (position.second == boardSize.second - 1 && direction == Direction::East) {
        direction = Direction::South;
    } else if (position.first == boardSize.first - 1 && direction == Direction::South) {
        direction = Direction::West;
    } else if (position.second == 0 && direction == Direction::West) {
        direction = Direction::North;
    }
}

bool PerimeterCrawler::isWayBlocked() {
    return false;
}

char PerimeterCrawler::getType() const {
    return 'P';
}
