
#include "bug.h"
#include <stdexcept>

Bug::Bug(int _id, std::pair<int, int> _position, Direction _direction, int _size, std::pair<int, int> _boardSize)
        : id(_id), position(_position), direction(_direction), size(_size), boardSize(_boardSize), alive(true) {}

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

void Bug::kill() {
    alive = false;
}

std::list<std::pair<int, int>> Bug::getPath() const {
    return path;
}
