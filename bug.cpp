// bug.cpp
#include "bug.h"
#include <stdexcept>

Bug::Bug(int _id, std::pair<int, int> _position, Direction _direction, int _size, bool _alive)
        : id(_id), position(_position), direction(_direction), size(_size), alive(_alive) {}

Bug::~Bug() {}

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

void Bug::kill() { // Implement this method
    alive = false;
}

std::list<std::pair<int, int>> Bug::getPath() const { // Implement this method
    return path;
}
