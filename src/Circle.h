#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
    float x;
    float y;
    float radius;
    float r;
    float g;
    float b;

public:
    Circle();
    Circle(float x, float y, float r, float g, float b);
    
    void draw() override;
    
    void setSize(bool increase) override;
    void move(float dx, float dy) override;
    void setColor(float r, float g, float b) override;
    bool contains(float x, float y) override;
    float getX() const override;
    float getY() const override;
    float getR() const override;
    float getG() const override;
    float getB() const override;
    float getRadius() const;

    

};

#endif