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
    
    void draw() override;

    void move(float dx, float dy) override;
    void setSize(int newSize) override;
    void setColor(float r, float g, float b) override;
    bool contains(float x, float y) override;
    float getX() const override;
    float getY() const override;
    float getR() const override;
    float getG() const override;
    float getB() const override;
};

#endif