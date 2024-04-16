#ifndef BUG_H
#define BUG_H

#include <utility> // For std::pair
#include <list> // For std::list

enum class Direction {
    North = 1,
    East,
    South,
    West
};

class Bug {
public:
    Bug(int _id, std::pair<int, int> _position, Direction _direction, int _size);
    virtual ~Bug();

    virtual void move() = 0;
    virtual bool isWayBlocked() = 0;
    int getId() const;
    std::pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    void kill();
    std::list<std::pair<int, int>> getPath() const;

protected:
    int id;
    std::pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path;
};

#endif
