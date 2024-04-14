// bug.h
#ifndef BUG_H
#define BUG_H

#include <utility> // For std::pair
#include <list> // For std::list

enum class Direction {
    North,
    East,
    South,
    West
};

class Bug {
public:
    Bug(int _id, std::pair<int, int> _position, Direction _direction, int _size, bool _alive);
    virtual ~Bug();

    virtual void move() = 0;
    virtual int getId() const;
    virtual std::pair<int, int> getPosition() const;
    virtual Direction getDirection() const;
    virtual int getSize() const;
    virtual bool isAlive() const;
    virtual bool isWayBlocked() = 0;
    virtual void kill(); // Add this method
    std::list<std::pair<int, int>> getPath() const; // Add this method

protected:
    int id;
    std::pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path; // Path taken by a bug
};

#endif
