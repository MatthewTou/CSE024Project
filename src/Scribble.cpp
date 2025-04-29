#include "Scribble.h"

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