#include "Circle.h"
#include <GL/freeglut.h>
#include <cmath>

Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Circle::Circle(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->r = r;
    this->g = g;
    this->b = b;
    radius = 0.2;
}

void Circle::draw() {
    glColor3f(r, g, b);
    float inc = M_PI / 32;
    glBegin(GL_POLYGON);
    for (float theta = 0; theta <= 2 * M_PI; theta += inc) {
        glVertex2f(x + cos(theta) * radius, y + sin(theta) * radius);
    }
    glEnd();
}

void Circle::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void Circle::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

bool Circle::contains(float px, float py) {
    float dist = std::sqrt((px - x)*(px - x) + (py - y)*(py - y));
    return dist <= radius;
}

void Circle::setSize(bool increase) {
    if (increase) {
        radius += 0.1f;
    }
    else {
        radius = fmax(0.05f, radius - 0.1f);
    }
}


float Circle::getX() const { 
    return x; 
}
float Circle::getY() const { 
    return y; 
}
float Circle::getR() const { 
    return r; 
}
float Circle::getG() const { 
    return g; 
}
float Circle::getB() const { 
    return b; 
}
float Circle::getRadius() const {
    return radius;
}