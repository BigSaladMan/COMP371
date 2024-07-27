// main.cpp
#include "point.h"
#include <iostream>

int main() {
    // Creating a Point object
    Point p1(1, 2, 3);

    // Display 
    std::cout << "Initial coordinates: ";
    p1.display();

    // Translate the point
    if (p1.translate(5, 'x') == 0) {
        std::cout << "After translating 5 units along x-axis: ";
        p1.display();
    }

    if (p1.translate(3, 'y') == 0) {
        std::cout << "After translating 3 units along y-axis: ";
        p1.display();
    }

    if (p1.translate(10, 'z') == 0) {
        std::cout << "After translating -2 units along z-axis: ";
        p1.display();
    }

    //// this is to translate invalid axis
    //if (p1.translate(4, 'a') == -1) {
    //    std::cout << "Attempt to translate 4 units along invalid axis." << std::endl;
    //}

    //// Translate with invalid distance
    //if (p1.translate(-4, 'x') == -1) {
    //    std::cout << "Attempt to translate -4 units along x-axis." << std::endl;
    //}

    return 0;
}
