#ifndef CRAWLER_H
#define CRAWLER_H

#include "bug.h"

class Crawler : public Bug {
public:
    Crawler(int _id, std::pair<int, int> _position, Direction _direction, int _size);

    void move() override;
    int getId() const override;
    std::pair<int, int> getPosition() const override;
    Direction getDirection() const override;
    int getSize() const override;
    bool isAlive() const override;
    bool isWayBlocked() override;
};

#endif // CRAWLER_H
