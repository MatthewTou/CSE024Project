#include "Polygon.h"
#include <GL/freeglut.h>
#include <cmath>

Polygon::Polygon() {
    x = 0.0;
    y = 0.0;
    radius = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    sides = 5;
}

Polygon::Polygon(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    radius = 0.2;
    this->r = r;
    this->g = g;
    this->b = b;
    sides = 5; 
}

void Polygon::draw() {
    glColor3f(r, g, b);
    float angleInc = 2.0f * M_PI / sides;

    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; i++) {
        float angle = i * angleInc + M_PI / 2.0f;
        float px = x + cos(angle) * radius;
        float py = y + sin(angle) * radius;
        glVertex2f(px, py);
    }
    glEnd();
}

void Polygon::setSize(bool increase) {
    if (increase) {
        radius += 0.1f;
    }
    else {
        radius = fmax(0.1f, radius - 0.1f);
    }
}


void Polygon::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void Polygon::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

bool Polygon::contains(float px, float py) {
    float dist = std::sqrt((px - x)*(px - x) + (py - y)*(py - y));
    return dist <= radius;
}

float Polygon::getX() const { 
    return x; 
    }
float Polygon::getY() const { 
    return y; 
}
float Polygon::getR() const { 
    return r; 
}
float Polygon::getG() const { 
    return g; 
}
float Polygon::getB() const {
    return b;
}
float Polygon::getRadius() const {
    return radius;
}
