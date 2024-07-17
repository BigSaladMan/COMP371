#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>

class Point {
private:
    int x, y, z;

public:
    Point(int x = 0, int y = 0, int z = 0);

    int translate(int d, char axis);
    void display() const;
    ~Point();

    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }

private:
    bool isValidDistance(int d) const;
};

Point::Point(int x, int y, int z) : x(x), y(y), z(z) {}

int Point::translate(int d, char axis) {
    try {
        if (!isValidDistance(d)) {
            throw std::invalid_argument("Invalid distance.");
        }

        switch (axis) {
        case 'x':
            x += d;
            break;
        case 'y':
            y += d;
            break;
        case 'z':
            z += d;
            break;
        default:
            throw std::invalid_argument("Invalid axis.");
        }

        return 0; 
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Translation error: " << e.what() << std::endl;
        return -1; 
    }
}

void Point::display() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

Point::~Point() {
    std::cout << "Point destroyed: (" << x << ", " << y << ", " << z << ")" << std::endl;
}

bool Point::isValidDistance(int d) const {
    return d >= 0; 
}
