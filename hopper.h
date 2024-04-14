#ifndef HOPPER_H
#define HOPPER_H

#include "bug.h"

class Hopper : public Bug {
public:
    Hopper(int _id, std::pair<int, int> _position, Direction _direction, int _size, int _hopLength);

    void move() override;
    int getId() const override;
    std::pair<int, int> getPosition() const override;
    Direction getDirection() const override;
    int getSize() const override;
    bool isAlive() const override;
    bool isWayBlocked() override;
    int getHopLength() const;

private:
    int hopLength;
};

#endif // HOPPER_H
