#include "Canvas.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x,  y, w, h) {
    currentScribble = nullptr;
    selected = nullptr;
    selector = new Selector(shapes);
}

void Canvas::render()  { 
    for (unsigned int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
    }
    if (currentScribble) {
        currentScribble->draw();
    }
}

void Canvas::startScribble() { 
    currentScribble = new Scribble();
}

void Canvas::updateScribble(float x, float y, float r, float g, float b, int size) {
    if (currentScribble) {
        currentScribble->addPoint(x,y,r,g,b,size);
    }
}

void Canvas::endScribble() { 
    if (currentScribble) {
        shapes.push_back(currentScribble);
        currentScribble = nullptr;
    }
}

void Canvas::addTriangle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Triangle(x, y, r, g, b));
}

void Canvas::addCircle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Circle(x, y, r, g, b));
}

void Canvas::addPolygon(float x, float y, float r, float g, float b) {
    shapes.push_back(new Polygon(x, y, r, g, b));
}

void Canvas::addRectangle(float x, float y, float r, float g, float b) {
    shapes.push_back(new Rectangle(x, y, r, g, b));
}

void Canvas::clear() {
    for (unsigned int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();
}

void Canvas::undo() {
    if (!shapes.empty()) {
        delete shapes.back();
        shapes.pop_back();
    }
}

void Canvas::select(float x, float y) {
    selector->select(x, y);
    selected = selector->getSelected();
}

void Canvas::moveSelected(float dx, float dy) {
    if (selected) {
        selector->move(dx, dy);
    }
}

void Canvas::resizeSelected(int size) {
    if (selected) {
        selector->resize(size);
    }
}

void Canvas::recolorSelected(float r, float g, float b) {
    if (selected) {
        selector->recolor(r, g, b);
    }
}

void Canvas::bringSelectedToFront() {
    if (selected) {
        selector->bringToFront();
    }
}

void Canvas::sendSelectedToBack() {
    if (selected) {
        selector->sendToBack();
    }
}

Shape* Canvas::getSelected() const {
    return selected;
}

