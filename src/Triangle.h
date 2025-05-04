#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
        float x;
        float y;
        float size;
        float r;
        float g;
        float b;
    public:
        Triangle();
        Triangle(float x, float y, float r, float g, float b);
        
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
        float getSize() const;

};

#endif