#include "hopper.h"

Hopper::Hopper(int _id, std::pair<int, int> _position, Direction _direction, int _size, int _hopLength, std::pair<int, int> _boardSize)
        : Bug(_id, _position, _direction, _size, _boardSize), hopLength(_hopLength) {}

void Hopper::move() {
    if (!isWayBlocked()) {
        int newPosition = position.first + hopLength;
        if (newPosition >= 0 && newPosition < boardSize.first) {
            position.first = newPosition;
            path.push_back(position);
        } else {
            alive = false; // kill the bug if it moves off the board
        }
    } else {
        direction = static_cast<Direction>((rand() % 4) + 1);
    }
}

bool Hopper::isWayBlocked() {
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


int Hopper::getId() const {
    return id;
}

std::pair<int, int> Hopper::getPosition() const {
    return position;
}

Direction Hopper::getDirection() const {
    return direction;
}

int Hopper::getSize() const {
    return size;
}

bool Hopper::isAlive() const {
    return alive;
}

int Hopper::getHopLength() const {
    return hopLength;
}
