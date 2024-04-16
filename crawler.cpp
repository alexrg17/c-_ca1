#include "crawler.h"

Crawler::Crawler(int _id, std::pair<int, int> _position, Direction _direction, int _size, std::pair<int, int> _boardSize)
        : Bug(_id, _position, _direction, _size, _boardSize) {}

void Crawler::move() {
    if (!isWayBlocked()) {
        position.first++;
        if (position.first >= 0 && position.first < boardSize.first) {
            path.push_back(position);
        } else {
            alive = false; // kill the bug if it moves off the board
        }
    } else {
        direction = static_cast<Direction>((rand() % 4) + 1);
    }
}

bool Crawler::isWayBlocked() {
    switch (direction) {
        case Direction::North:
            return position.first == 0;
        case Direction::East:
            return position.second == boardSize.second - 1;
        case Direction::South:
            return position.first == boardSize.first - 1;
        case Direction::West:
            return position.second == 0;
        default:
            return false;
    }
}

int Crawler::getId() const {
    return id;
}

std::pair<int, int> Crawler::getPosition() const {
    return position;
}

Direction Crawler::getDirection() const {
    return direction;
}

int Crawler::getSize() const {
    return size;
}

bool Crawler::isAlive() const {
    return alive;
}
