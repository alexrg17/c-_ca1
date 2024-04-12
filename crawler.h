//
// Created by Alex Radu on 12/04/2024.
//

#ifndef CPP_CA1_CRAWLER_H
#define CPP_CA1_CRAWLER_H


#ifndef CRAWLER_H
#define CRAWLER_H

#include "Bug.h"

class Crawler : private Bug {
public:
    Crawler(int _id, std::pair<int, int> _position, Direction _direction, int _size);
    void move() override;

    using Bug::isWayBlocked; // Inherit isWayBlocked from Bug
};

#endif //CPP_CA1_CRAWLER_H
