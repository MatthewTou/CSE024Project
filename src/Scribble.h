#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

class Scribble : public Shape {
    std::vector<Point*> points;

    public: 
        Scribble();
        ~Scribble();

        void addPoint(float x, float y, float r, float g, float b, int size);
        
        void draw() override;
        
        std::size_t getPointCount() const;

        void move(float dx, float dy) override;
        void setColor(float r, float g, float b) override;
        bool contains(float x, float y) override;
        void setSize(bool increase) override;
        float getX() const override;
        float getY() const override;
        float getR() const override;
        float getG() const override;
        float getB() const override;
       
};



#endif
