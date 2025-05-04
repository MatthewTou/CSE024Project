#include "Rectangle.h"
#include <GL/freeglut.h>
#include <cmath>

Rectangle::Rectangle() {
    x = 0.0;
    y = 0.0;
    width = 0.4;
    height = 0.4;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Rectangle::Rectangle(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    width = 0.4;
    height = 0.4;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Rectangle::draw() {
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}

void Rectangle::setSize(bool increase) {
    if (increase) {
        width += 0.1f;
        height += 0.1f;
    } else {
        width = fmax(0.1f, width - 0.1f);
        height = fmax(0.1f, height - 0.1f);
    }
}


void Rectangle::move(float x, float y) {
    x += x;
    y += y;
}

void Rectangle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

bool Rectangle::contains(float x, float y) {
    return x >= x - width/2 && x <= x + width/2 &&
           y >= y - height/2 && y <= y + height/2;
}

float Rectangle::getX() const { 
    return x; 
}
float Rectangle::getY() const { 
    return y; 
}
float Rectangle::getR() const { 
    return r; 
}
float Rectangle::getG() const { 
    return g; 
}
float Rectangle::getB() const {
    return b;
}
float Rectangle::getWidth() const {
    return width;
}
float Rectangle::getHeight() const {
    return height;
}
