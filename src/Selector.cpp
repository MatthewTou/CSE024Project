#include "Selector.h"
#include <algorithm>

Selector::Selector(std::vector<Shape*>& shapes) : shapes(shapes), selected(nullptr) {}

void Selector::select(float x, float y) {
    for (int i = shapes.size() - 1; i >= 0; --i) {
        if (shapes[i]->contains(x, y)) {
            selected = shapes[i];
            return;
        }
    }
    selected = nullptr;
}

void Selector::move(float x, float y) {
    if (selected) {
        selected->move(x, y);
    }
}

void Selector::resize(int newSize) {
    if (selected) {
    selected->setSize(newSize);
    }
}

void Selector::recolor(float r, float g, float b) {
    if (selected) {
        selected->setColor(r, g, b);
    }
}

void Selector::bringToFront() {
    if (!selected || shapes.size() < 2) {
        return;
    }

    for (unsigned int i = 0; i < shapes.size() - 1; i++) {
        if (shapes[i] == selected) {
            std::swap(shapes[i], shapes[i + 1]); 
            break;
        }
    }
}

void Selector::sendToBack() {
    if (!selected || shapes.size() < 2) {
        return;
    }

    for (unsigned int i = 0; i < shapes.size(); i++) {
        if (shapes[i] == selected && i > 0) {
            std::swap(shapes[i], shapes[i - 1]); 
            break;
        }
    }
}

Shape* Selector::getSelected() const {
    return selected;
}

bool Selector::hasSelection() const {
    return selected != nullptr;
}
