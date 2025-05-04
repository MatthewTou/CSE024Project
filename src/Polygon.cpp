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
        float angle = i * angleInc;
        float px = x + cos(angle) * radius;
        float py = y + sin(angle) * radius;
        glVertex2f(px, py);
    }
    glEnd();
}