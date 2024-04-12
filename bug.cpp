//
// Created by Alex Radu on 12/04/2024.
//

#include "bug.h"

#include <stdexcept>

Bug::Bug(int _id, std::pair<int, int> _position, Direction _direction, int _size)
        : id(_id), position(_position), direction(_direction), size(_size), alive(true) {}

Bug::~Bug() {}

bool Bug::isWayBlocked() {
    int x = position.first;
    int y = position.second;
    int maxX = 20; // Assuming a 20x20 grid
    int maxY = 20;

    switch (direction) {
        case Direction::North:
            return y == 0;
        case Direction::East:
            return x == maxX - 1;
        case Direction::South:
            return y == maxY - 1;
        case Direction::West:
            return x == 0;
        default:
            throw std::logic_error("Invalid direction");
    }
}

int Bug::getId() const {
    return id;
}

std::pair<int, int> Bug::getPosition() const {
    return position;
}

Direction Bug::getDirection() const {
    return direction;
}

int Bug::getSize() const {
    return size;
}

bool Bug::isAlive() const {
    return alive;
}

std::list<std::pair<int, int>> Bug::getPath() const {
    return path;
}
