//
// Created by Alex Radu on 19/04/2024.
//

#ifndef CPP_CA1_PERIMETERCRAWLER_H
#define CPP_CA1_PERIMETERCRAWLER_H

#include "bug.h"
#include <utility>

class PerimeterCrawler : public Bug {
public:
    PerimeterCrawler(int id, std::pair<int, int> position, Direction direction, int size, std::pair<int, int> boardSize, Board& board);

    std::pair<int, int> move() override;
    bool isWayBlocked() override;
    char getType() const override;

private:
    void changeDirection();
};

#endif //CPP_CA1_PERIMETERCRAWLER_H
