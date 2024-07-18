#pragma once

#include "point.h"

class Triangle {
private:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

public:
    Triangle(Point* v1 = nullptr, Point* v2 = nullptr, Point* v3 = nullptr);
    ~Triangle();

    void translate(int d, char axis);
    double calcArea() const;
    void display() const;
};
