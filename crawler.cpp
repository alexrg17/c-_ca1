#include "crawler.h"

Crawler::Crawler(int _id, std::pair<int, int> _position, Direction _direction, int _size)
        : Bug(_id, _position, _direction, _size) {}

void Crawler::move() {
    if (!isWayBlocked()) {
        position.first++;
        path.push_back(position);
    } else {
        direction = static_cast<Direction>((rand() % 4) + 1);
    }
}

bool Crawler::isWayBlocked() {
    switch (direction) {
        case Direction::North:
            return position.first == 0;
        case Direction::East:
            return position.second == 9;
        case Direction::South:
            return position.first == 9;
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
