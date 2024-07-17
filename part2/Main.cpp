#include "point.h"
#include "triangle.h"
#include <iostream>

int main() {
    // Creating Point objects
    Point* p1 = new Point(1, 2, 0);
    Point* p2 = new Point(4, 5, 0);
    Point* p3 = new Point(6, 2, 0);

    // Create a Triangle object
    Triangle t(p1, p2, p3);
    
    // Display initial triangle
    std::cout << "Initial triangle:" << std::endl;
    t.display();

    // Translate the triangle
    t.translate(2, 'x');
    std::cout << "After translating 2 units along x-axis:" << std::endl;
    t.display();

    // Calculate the area
    double area = t.calcArea();
    std::cout << "Area of the triangle: " << area << std::endl;

    
    return 0;
}
