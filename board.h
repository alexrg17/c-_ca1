#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include "bug.h"

class Board {
private:
    std::vector<Bug*> bugVector;
    std::map<std::pair<int, int>, std::vector<Bug*>> board;

public:
    Board(); // Constructor
    ~Board(); // Destructor

    void initializeBoardFromFile(const std::string& filename);
    std::vector<Bug*> getBugVector() const;
    void displayBugDetails(int bugId) const;
    void displayLifeHistory() const;
    void moveBug(int bugId);
    void killBug(int bugId);
    void displayBoard() const;
    Bug* getBugAtPosition(std::pair<int, int> position) const;
    void tapBoard();
    void writeLifeHistoryToFile() const;
};

#endif // BOARD_H
