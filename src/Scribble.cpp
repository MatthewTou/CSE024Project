#include "Scribble.h"
#include <cmath>

Scribble::Scribble() {}

Scribble::~Scribble() {
    for (unsigned int i = 0; i < points.size(); i++) {
        delete points[i];
    }
    points.clear();
}

void Scribble::addPoint(float x, float y, float r, float g, float b, int size) {
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw() {
    for (unsigned int i = 0; i < points.size(); i++) {
        points[i]->draw();
    }
}

std::size_t Scribble::getPointCount() const {
    return points.size();
}

void Scribble::setSize(bool increase) {
    for (Point* p : points) {
        int newSize = p->getSize() + (increase ? 1 : -1);
        newSize = std::max(1, newSize);
        *p = Point(p->getX(), p->getY(), p->getR(), p->getG(), p->getB(), newSize);
    }
}


void Scribble::move(float dx, float dy) {
    for (Point* p : points) {
        float newX = p->getX() + dx;
        float newY = p->getY() + dy;
        *p = Point(newX, newY, p->getR(), p->getG(), p->getB(), p->getSize());
    }
}

void Scribble::setColor(float r, float g, float b) {
    for (Point* p : points) {
        *p = Point(p->getX(), p->getY(), r, g, b, p->getSize());
    }
}

bool Scribble::contains(float x, float y) {
    for (Point* p : points) {
        float dx = x - p->getX();
        float dy = y - p->getY();
        float dist = std::sqrt(dx * dx + dy * dy);
        if (dist <= p->getSize() / 5.0f) return true;  
    }
    return false;
}

float Scribble::getX() const {
    return points.empty() ? 0 : points[0]->getX();
}

float Scribble::getY() const {
    return points.empty() ? 0 : points[0]->getY();
}

float Scribble::getR() const {
    if (!points.empty()) return points[0]->getR();
    return 0.0f;
}

float Scribble::getG() const {
    if (!points.empty()) return points[0]->getG();
    return 0.0f;
}

float Scribble::getB() const {
    if (!points.empty()) return points[0]->getB();
    return 0.0f;
}
