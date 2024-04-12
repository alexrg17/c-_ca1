//
// Created by Alex Radu on 12/04/2024.
//

#ifndef CPP_CA1_HOPPER_H
#define CPP_CA1_HOPPER_H


#ifndef HOPPER_H
#define HOPPER_H

#include "Bug.h"

class Hopper : private Bug {
private:
    int hopLength;

public:
    Hopper(int _id, std::pair<int, int> _position, Direction _direction, int _size, int _hopLength);
    void move() override;

    using Bug::isWayBlocked; // Inherit isWayBlocked from Bug
};

#endif //CPP_CA1_HOPPER_H
