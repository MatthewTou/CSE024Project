#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"

class Polygon : public Shape {
    float x;
    float y;
    float radius;
    float r;
    float g;
    float b;
    int sides;

public:
    Polygon();
    Polygon(float x, float y, float r, float g, float b);
    void draw();
};

#endif