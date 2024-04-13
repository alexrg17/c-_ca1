//
// Created by Alex Radu on 12/04/2024.
//

#ifndef BUG_H
#define BUG_H

#include <utility>
#include <list>

// Enum class for direction
enum class Direction {
    North, East, South, West
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

    virtual void move() = 0; // Pure virtual function

    bool isWayBlocked();

    int getId() const;
    std::pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    const std::list<std::pair<int, int>>& getPath() const; // Return list
};

#endif // BUG_H
