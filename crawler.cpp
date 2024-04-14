#include "crawler.h"

Crawler::Crawler(int _id, std::pair<int, int> _position, Direction _direction, int _size)
        : Bug(_id, _position, _direction, _size, true) {}

void Crawler::move() {
    // Implementation of move function
}

bool Crawler::isWayBlocked() {
    // Implementation of isWayBlocked function
}

std::pair<int, int> Crawler::getPosition() const {
    return position;
}

Direction Crawler::getDirection() const {
    return direction;
}

int Crawler::getId() const {
    return id;
}

int Crawler::getSize() const {
    return size;
}

bool Crawler::isAlive() const {
    return alive;
}
