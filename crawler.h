//
// Created by Alex Radu on 12/04/2024.
//

#ifndef CRAWLER_H
#define CRAWLER_H

#include "bug.h"

class Crawler : public Bug {
public:
    Crawler(int _id, std::pair<int, int> _position, Direction _direction, int _size);
    void move() override;
};

#endif // CRAWLER_H

