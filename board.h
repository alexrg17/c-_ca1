
#ifndef CPP_CA1_BOARD_H
#define CPP_CA1_BOARD_H

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
};

#endif //CPP_CA1_BOARD_H
