#include "Triangle.h"
#include <GL/freeglut.h>
#include <cmath>

Triangle::Triangle() {
    x = 0.0;
    y = 0.0;
    size = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Triangle::Triangle(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    size = 0.2;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Triangle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x, y + size);
        glVertex2f(x - size, y - size);
        glVertex2f(x + size, y - size);
    glEnd();
}

void Triangle::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void Triangle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

bool Triangle::contains(float px, float py) {
    return abs(px - x) <= size && abs(py - y) <= size;
}

void Triangle::setSize(bool increase) {
    if (increase) {
        size += 0.1f;
    }
    else {
        size = fmax(0.05f, size - 0.1f);
    }
}

float Triangle::getX() const { 
    return x; 
}
float Triangle::getY() const { 
    return y; 
}
float Triangle::getR() const { 
    return r; 
}
float Triangle::getG() const { 
    return g; 
}
float Triangle::getB() const { 
    return b; 
}
float Triangle::getSize() const {
    return size;
}


