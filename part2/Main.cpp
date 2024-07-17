#include "point.h"
#include "triangle.h"
#include <iostream>

int main() {
    // User input for points
    int x, y, z;
    std::cout << "Enter coordinates for Point 1 (x y z): ";
    std::cin >> x >> y >> z;
    Point* p1 = new Point(x, y, z);

    std::cout << "Enter coordinates for Point 2 (x y z): ";
    std::cin >> x >> y >> z;
    Point* p2 = new Point(x, y, z);

    std::cout << "Enter coordinates for Point 3 (x y z): ";
    std::cin >> x >> y >> z;
    Point* p3 = new Point(x, y, z);

    // Create a Triangle object
    Triangle t(p1, p2, p3);
    
    // Display initial triangle
    std::cout << "Initial triangle:" << std::endl;
    t.display();

    // User input for translation
    int d;
    char axis;
    std::cout << "Enter distance to translate and axis (d axis): ";
    std::cin >> d >> axis;
    t.translate(d, axis);
    std::cout << "After translating " << d << " units along " << axis << "-axis:" << std::endl;
    t.display();

    // Calculate the area
    double area = t.calcArea();
    std::cout << "Area of the triangle: " << area << std::endl;

    return 0;
}
