//
// Created by Alex Radu on 12/04/2024.
//

#ifndef CPP_CA1_BUG_H
#define CPP_CA1_BUG_H

#ifndef BUG_H
#define BUG_H

#include <utility>
#include <list>

// Enum class for direction
enum class Direction {
    North = 1,
    East,
    South,
    West
};

class Bug {
protected:
    int id;
    std::pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path;

public:
    Bug(int _id, std::pair<int, int> _position, Direction _direction, int _size);
    virtual ~Bug();

    virtual void move() = 0;
    bool isWayBlocked();

    int getId() const;
    std::pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    std::list<std::pair<int, int>> getPath() const;
};

#endif // BUG_H



#endif //CPP_CA1_BUG_H
