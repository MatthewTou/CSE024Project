#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    public:
        virtual void draw() = 0;
        virtual void move(float dx, float dy) = 0;
        virtual void setColor(float r, float g, float b) = 0;
        virtual bool contains(float x, float y) = 0;
        virtual float getX() const = 0;
        virtual void setSize(bool increase) = 0;
        virtual float getY() const = 0;
        virtual float getR() const = 0;
        virtual float getG() const = 0;
        virtual float getB() const = 0;
        virtual ~Shape() {};
    
};

#endif