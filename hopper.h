#ifndef HOPPER_H
#define HOPPER_H

#include "bug.h"

class Hopper : public Bug {
private:
    int hopLength;

public:
    Hopper(int _id, std::pair<int, int> _position, Direction _direction, int _size, int _hopLength);
    void move() override;
    int getHopLength() const; // Added member function declaration
};

#endif // HOPPER_H
