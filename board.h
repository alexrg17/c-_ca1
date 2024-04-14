// board.h
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <vector>

#include "bug.h"

class Board {
private:
    std::vector<Bug*> bugVector;

public:
    Board(); // Constructor
    ~Board(); // Destructor

    void initializeBoardFromFile(const std::string& filename); // Function to initialize board from file
    std::vector<Bug*> getBugVector() const; // Declaration of getBugVector function
    void displayBugDetails(int bugId) const; // Declaration to find and display bug details
    void displayLifeHistory() const; // Display life history of all bugs
    void moveBug(int bugId); // Add this method
    void killBug(int bugId); // Add this method
    void displayBoard() const; // Add this method
    Bug* getBugAtPosition(std::pair<int, int> position) const; // Add this method
    void tapBoard(); // Add this method
    void writeLifeHistoryToFile() const; // Add this method
};

#endif // BOARD_H
