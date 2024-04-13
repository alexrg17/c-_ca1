//
// Created by Alex Radu on 12/04/2024.
//

#include "hopper.h"

Hopper::Hopper(int _id, std::pair<int, int> _position, Direction _direction, int _size, int _hopLength)
        : Bug(_id, _position, _direction, _size), hopLength(_hopLength) {}

void Hopper::move() {
    if (alive) {
        if (!isWayBlocked()) {
            int hopDistance = std::min(hopLength, 20); // Assuming a 20x20 grid
            switch (direction) {
                case Direction::North:
                    position.second -= hopDistance;
                    break;
                case Direction::East:
                    position.first += hopDistance;
                    break;
                case Direction::South:
                    position.second += hopDistance;
                    break;
                case Direction::West:
                    position.first -= hopDistance;
                    break;
                default:
                    throw std::logic_error("Invalid direction");
            }
            path.push_back(position);
        } else {
            // Handle if way is blocked
        }
    }
}

