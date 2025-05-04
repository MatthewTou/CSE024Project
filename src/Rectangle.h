#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
    float x;
    float y;
    float width;
    float height;
    float r;
    float g;
    float b;

public:
    Rectangle();
    Rectangle(float x, float y, float r, float g, float b);
    
    void draw() override;

    void move(float dx, float dy) override;
    void setColor(float r, float g, float b) override;
    bool contains(float x, float y) override;
    void setSize(bool increase) override;
    float getX() const override;
    float getY() const override;
    float getR() const override;
    float getG() const override;
    float getB() const override;
    float getWidth() const;
    float getHeight() const;


};

#endif