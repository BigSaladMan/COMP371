#pragma once

// point.h
#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x, y, z;

public:
    Point(int x = 0, int y = 0, int z = 0);

    int translate(int d, char axis);
    void display() const;
    ~Point();

private:
    bool isValidDistance(int d) const;
};

#endif // POINT_H
