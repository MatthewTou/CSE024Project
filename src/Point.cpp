#include "Point.h"
#include <GL/freeglut.h>

Point::Point(float x, float y, float r, float g, float b, int size) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->g = g;
    this->b = b;
    this->size = size;
}

void Point::draw() {
    glColor3f(r, g, b);
    glPointSize(size);

    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

float Point::getX() const { 
    return x; }
float Point::getY() const { 
    return y; }
float Point::getR() const { 
    return r; }
float Point::getG() const { 
    return g; }
float Point::getB() const { 
    return b; }
int Point::getSize() const { 
    return size; }