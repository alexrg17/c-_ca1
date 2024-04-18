#include "crawler.h"
#include "board.h"

Crawler::Crawler(int _id, std::pair<int, int> _position, Direction _direction, int _size, std::pair<int, int> _boardSize, Board& _board)
        : board(_board), Bug(_id, _position, _direction, _size, _boardSize, _board) {}

std::pair<int, int> Crawler::move() {
    std::pair<int, int> newPosition;
    do {
        newPosition = position;
        direction = static_cast<Direction>((rand() % 4) + 1);
        switch (direction) {
            case Direction::North:
                newPosition.first--;
                break;
            case Direction::East:
                newPosition.second++;
                break;
            case Direction::South:
                newPosition.first++;
                break;
            case Direction::West:
                newPosition.second--;
                break;
        }
    } while (isWayBlocked());


    if (newPosition.first >= 0 && newPosition.first < boardSize.first &&
        newPosition.second >= 0 && newPosition.second < boardSize.second) {
        position = newPosition;
        path.push_back(position);
        std::cout << "Crawler " << id << " moved to position: (" << position.first << ", " << position.second << ")" << std::endl;
    } else {
        std::cout << "Crawler " << id << " couldn't move to position: (" << newPosition.first << ", " << newPosition.second << ") - Out of bounds!" << std::endl;
    }

    return position;
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