//
// Created by Alex Radu on 12/04/2024.
//

#include "crawler.h"
#include <cstdlib> // for rand()

Crawler::Crawler(int _id, std::pair<int, int> _position, Direction _direction, int _size)
        : Bug(_id, _position, _direction, _size) {}

void Crawler::move() {
    if (alive) {
        if (!isWayBlocked()) {
            switch (direction) {
                case Direction::North:
                    position.second--;
                    break;
                case Direction::East:
                    position.first++;
                    break;
                case Direction::South:
                    position.second++;
                    break;
                case Direction::West:
                    position.first--;
                    break;
                default:
                    throw std::logic_error("Invalid direction");
            }
            path.push_back(position);
        } else {
            // Generate random direction
            int randomDir = rand() % 4 + 1; // 1-4
            direction = static_cast<Direction>(randomDir);
            move(); // Recursively call move until bug can move forward
        }
    }
}
