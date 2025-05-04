#ifndef POINT_H
#define POINT_H

#include "Shape.h"

class Point : public Shape {
    float x;
    float y;
    float r;
    float g;
    float b;
    int size;

    public: 
        Point();
        Point(float x, float y);
        Point(float x, float y, float r, float g, float b);
        Point(float x, float y, float r, float g, float b, int size);
        
        void draw() override;

        float getX() const override;
        float getY() const override;
        float getR() const override;
        float getG() const override;
        float getB() const override;
        int getSize() const;

        void move(float dx, float dy) override;
        void setColor(float r, float g, float b) override;
        bool contains(float x, float y) override;
        void setSize(bool increase) override;

};

#endif