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