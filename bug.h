#ifndef BUG_H
#define BUG_H

#include <utility>
#include <list>

class Board;  // Forward declaration of Board

enum class Direction {
    North = 1,
    East,
    South,
    West
};

class Bug {
public:
    Bug(int _id, std::pair<int, int> _position, Direction _direction, int _size, std::pair<int, int> _boardSize, Board& _board);
    virtual ~Bug();

    virtual std::pair<int, int> move() = 0;  // Change return type to std::pair<int, int>
    virtual bool isWayBlocked() = 0;
    int getId() const;
    std::pair<int, int> getPosition() const;
    void setPosition(std::pair<int, int> newPosition);  // New function to set position
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    void kill();
    void grow(int size);
    std::list<std::pair<int, int>> getPath() const;

protected:
    int id;
    std::pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    std::pair<int, int> boardSize;
    std::list<std::pair<int, int>> path;
    Board& board;  // Add a reference to the Board class
};

#endif // BUG_H
