#include "hopper.h"

Hopper::Hopper(int _id, std::pair<int, int> _position, Direction _direction, int _size, int _hopLength)
        : Bug(_id, _position, _direction, _size, true), hopLength(_hopLength) {}

void Hopper::move() {
    // Implementation of move function
}

int Hopper::getHopLength() const {
    return hopLength;
}

bool Hopper::isWayBlocked() {
    // Implementation of isWayBlocked function
}

std::pair<int, int> Hopper::getPosition() const {
    return position;
}

Direction Hopper::getDirection() const {
    return direction;
}

int Hopper::getId() const {
    return id;
}

int Hopper::getSize() const {
    return size;
}

bool Hopper::isAlive() const {
    return alive;
}
