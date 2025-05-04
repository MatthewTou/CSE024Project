#ifndef SELECTOR_H
#define SELECTOR_H

#include <vector>
#include "Shape.h"

class Selector {
    std::vector<Shape*>& shapes;
    Shape* selected;

public:
    Selector(std::vector<Shape*>& shapes);

    void resize(bool increase);
    void select(float x, float y);
    void move(float dx, float dy);
    void recolor(float r, float g, float b);
    void bringToFront();
    void sendToBack();
    Shape* getSelected() const;
    bool hasSelection() const;
};

#endif