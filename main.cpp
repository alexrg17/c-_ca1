#include <iostream>
#include <vector>
#include "bug.h"
#include "crawler.h"
#include "hopper.h"

int main() {
    std::vector<Bug*> bug_vector;

    // Read data from "bugs.txt" and create Bug objects dynamically on the heap
    // Example:
    Bug* crawler = new Crawler(1, std::make_pair(0, 0), Direction::North, 1);
    Bug* hopper = new Hopper(2, std::make_pair(5, 5), Direction::East, 2, 3);

    bug_vector.push_back(crawler);
    bug_vector.push_back(hopper);

    // Move all bugs
    for (Bug* bug : bug_vector) {
        bug->move(); // Calls the appropriate move function based on the actual object type
    }

    // Free the memory
    for (Bug* bug : bug_vector) {
        delete bug;
    }

    return 0;
}
