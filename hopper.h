#ifndef HOPPER_H
#define HOPPER_H

#include "bug.h"
#include <cstdlib>

class Hopper : public Bug {
public:
    Hopper(int _id, std::pair<int, int> _position, Direction _direction, int _size, int _hopLength);

    void move() override;
    bool isWayBlocked() override;
    int getId() const;
    std::pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    int getHopLength() const;

private:
    int hopLength;
};

#endif // HOPPER_H
