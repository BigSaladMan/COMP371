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

Triangle::Triangle(Point* v1, Point* v2, Point* v3)
    : vertex_1(v1), vertex_2(v2), vertex_3(v3) {}

Triangle::~Triangle() {
    delete vertex_1;
    delete vertex_2;
    delete vertex_3;
    std::cout << "Triangle destroyed." << std::endl;
}

void Triangle::translate(int d, char axis) {
    if (vertex_1) vertex_1->translate(d, axis);
    if (vertex_2) vertex_2->translate(d, axis);
    if (vertex_3) vertex_3->translate(d, axis);
}

double Triangle::calcArea() const {
    if (vertex_1 && vertex_2 && vertex_3) {
        int x1 = vertex_1->getX();
        int y1 = vertex_1->getY();
        int x2 = vertex_2->getX();
        int y2 = vertex_2->getY();
        int x3 = vertex_3->getX();
        int y3 = vertex_3->getY();
        return std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
    }
    return 0.0;
}

void Triangle::display() const {
    std::cout << "Triangle vertices:" << std::endl;
    if (vertex_1) vertex_1->display();
    if (vertex_2) vertex_2->display();
    if (vertex_3) vertex_3->display();
}
